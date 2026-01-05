#include <stda/sstrings/converter.hpp>
#include <windows.h>
#include <exception>
#include <string>
#include <cstring>

#ifndef EXCEPTIONSME
#define EXCEPTIONSME

/* @Documentacion:
 * Este archivo contiene el manejo de excepciones para namespace systems
 * facilita y ahorra tiempo a la hora de generarlas y aunque aun no este completa
 * tambien puede recibir excepciones fuera de las ya predefinidas
 */

/// @brief Nombres de espacios de variables
namespace systems
{
    /// @brief Clase que maneja las expeciones systems
    class exception : public std::exception
    {
    protected:
        char *__message__;

    public:
        /// @brief Constructor por defecto
        exception() noexcept : __message__(nullptr) {}
        /// @brief Constructor que usa un mensaje puro para aletras indefinidas
        /// @param __message Mensaje que se desea enviar de tipo (?const char*?)
        explicit exception(const char *__message) : __message__(const_cast<char *>(__message)) {}
        /// @brief Constructor de errores para el manejo de excepciones con el estandar de C
        /// @param code codigo de error
        /// @param operation operacion donde se emitio el error
        explicit exception(unsigned int code, const char* operation) {
            std::string msg = "Error en: " + std::string(operation) + "(Codigo: "+std::to_string(code)+")" + std::string(strerror(code));
            __message__ = new char[msg.size() + 1];
            __message__[msg.size()] = 0;
            std::strcpy(__message__, msg.c_str());
        }
        /// @brief Constructor que usa un mensaje puro para aletras indefinidas
        /// @param __message Mensaje que se desea enviar de tipo (?std::string*?)
        explicit exception(const std::string &__message)
        {
            __message__ = new char[__message.size() + 1];
            __message__[__message.size()] = 0;
            std::strcpy(__message__, __message.c_str());
        }
        /// @brief Constructor que usa un mensaje puro para aletras indefinidas
        /// @param __message Mensaje que se desea enviar de tipo (?std::wstring*?)
        explicit exception(const std::wstring &__message)
        {
            __message__ = new char[__message.size() + 1];
            __message__[__message.size()] = 0;
            char *str = stringconverter::convert_utf8_to_ascii(__message.c_str());
            std::strcpy(__message__, str);
            delete[] (str);
        }
        exception &operator=(exception const &_Other) noexcept
        {
            if (this != &_Other)
            {
                size_t s = std::strlen(_Other.__message__);
                this->__message__ = new char[s + 1];
                __message__[s] = 0;
                std::strcpy(this->__message__, _Other.__message__);
            }
            return *this;
        }
        exception &operator=(exception &&_Other) noexcept
        {
            if (this != &_Other)
            {
                this->__message__ = _Other.__message__;
                _Other.__message__ = nullptr;
            }
            return *this;
        }
        /// @brief Obtiene el mensaje en formato (?const char*?)
        /// @return Devuelve el mensaje
        const char *what() const noexcept override;
        virtual ~exception() noexcept {}
    };
    class windows_exceptions : public systems::exception
    {
    public:
        /// @brief Constructor por defecto
        windows_exceptions() noexcept : exception() {}
        windows_exceptions(unsigned int code, const char* operation = nullptr) {
            char* errorMsg;
            FormatMessageA(
                FORMAT_MESSAGE_ALLOCATE_BUFFER |
                    FORMAT_MESSAGE_FROM_SYSTEM |
                    FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL,
                code,
                MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                (char*)&errorMsg,
                0,
                NULL);
            size_t size = std::strlen(errorMsg);
            std::string code_message = "Codigo de Error de Windows: " + std::to_string(code) + ((!operation)?(" en " + std::string(operation)):"")   + "\n";
            __message__ = new char[size + code_message.size() + 1];
            __message__[size + code_message.size()] = 0;
            std::strcpy(__message__, code_message.c_str());
            std::strcpy(__message__ + code_message.size(), errorMsg);
        }
        ~windows_exceptions() {}
    };
}


        
#endif