#include <stda/sstrings/converter.hpp>
#include <windows.h>
#include <exception>
#include <string>
#include <cstring>

#ifndef EXCEPTIONSME
#define EXCEPTIONSME

/* @Documentacion:
 * Este archivo contiene el manejo de excepciones para namespace System
 * facilita y ahorra tiempo a la hora de generarlas y aunque aun no este completa
 * tambien puede recibir excepciones fuera de las ya predefinidas
 */

/// @brief Nombres de espacios de variables
namespace System
{
    /// @brief Clase que maneja las expeciones System
    class Exception : public std::exception
    {
    public:
        /// @brief Id para identificar el nuvel del log
        enum class Id : unsigned char
        {
            warning,
            error,
            none
        };

    protected:
        char *__message__;
        Exception::Id __signal;

    public:
        /// @brief Constructor por defecto
        Exception() noexcept : __message__(nullptr) {}
        /// @brief Constructor que usa un mensaje puro para aletras indefinidas
        /// @param __message Mensaje que se desea enviar de tipo (?const char*?)
        explicit Exception(const char *__message, Exception::Id _signal = Exception::Id::error) : __message__(const_cast<char *>(__message)), __signal(_signal) {}
        /// @brief Constructor de errores para el manejo de excepciones con el estandar de C
        /// @param code codigo de error
        /// @param operation operacion donde se emitio el error
        explicit Exception(unsigned int code, const char *operation, Exception::Id _signal = Exception::Id::error) : __signal(_signal)
        {
            std::string msg = "Error en: " + std::string(operation) + " (Codigo: " + std::to_string(code) + ") " + std::string(strerror(code));
            __message__ = new char[msg.size() + 1];
            __message__[msg.size()] = 0;
            std::strcpy(__message__, msg.c_str());
        }
        /// @brief Constructor que usa un mensaje puro para aletras indefinidas
        /// @param __message Mensaje que se desea enviar de tipo (?std::string*?)
        explicit Exception(const std::string &__message, Exception::Id _signal = Exception::Id::error) : __signal(_signal)
        {
            __message__ = new char[__message.size() + 1];
            __message__[__message.size()] = 0;
            std::strcpy(__message__, __message.c_str());
        }
        /// @brief Constructor que usa un mensaje puro para aletras indefinidas
        /// @param __message Mensaje que se desea enviar de tipo (?std::wstring*?)
        explicit Exception(const std::wstring &__message, Exception::Id _signal = Exception::Id::error) : __signal(_signal)
        {
            __message__ = new char[__message.size() + 1];
            __message__[__message.size()] = 0;
            char *str = String::convert_utf8_to_ascii(__message.c_str());
            std::strcpy(__message__, str);
            delete[] (str);
        }
        Exception &operator=(Exception const &_Other) noexcept
        {
            if (this != &_Other)
            {
                size_t s = std::strlen(_Other.__message__);
                this->__message__ = new char[s + 1];
                __message__[s] = 0;
                this->__signal = _Other.__signal;
                std::strcpy(this->__message__, _Other.__message__);
            }
            return *this;
        }
        Exception &operator=(Exception &&_Other) noexcept
        {
            if (this != &_Other)
            {
                this->__signal = _Other.__signal;
                this->__message__ = _Other.__message__;
                _Other.__message__ = nullptr;
            }
            return *this;
        }
        /// @brief Obtiene el mensaje en formato (?const char*?)
        /// @return Devuelve el mensaje
        const char *what() const noexcept override;
        Exception::Id signal() const noexcept { return __signal;}
        virtual ~Exception() noexcept {}
    };
    class Windows_Exceptions : public System::Exception
    {
    public:
        /// @brief Constructor por defecto
        Windows_Exceptions() noexcept : Exception() {}
        Windows_Exceptions(unsigned int code, const char *operation = nullptr, Exception::Id _signal = Exception::Id::error)
        {
            char *errorMsg;
            FormatMessageA(
                FORMAT_MESSAGE_ALLOCATE_BUFFER |
                    FORMAT_MESSAGE_FROM_SYSTEM |
                    FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL,
                code,
                MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                (char *)&errorMsg,
                0,
                NULL);
            size_t size = std::strlen(errorMsg);
            std::string code_message = "Codigo de Error de Windows: " + std::to_string(code) + ((!operation) ? (" en " + std::string(operation)) : "") + "\n";
            __message__ = new char[size + code_message.size() + 1];
            __message__[size + code_message.size()] = 0;
            std::strcpy(__message__, code_message.c_str());
            std::strcpy(__message__ + code_message.size(), errorMsg);
            __signal = _signal;
        }
        ~Windows_Exceptions() {}
    };
}

#endif