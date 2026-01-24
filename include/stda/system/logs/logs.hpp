#include <stda/system/files/filesystem.hpp>
#include <stda/sstrings/sstrings.hpp>
#include <stda/system/time/time.hpp>
#include <stda/system/memory/memory.hpp>
#include <stda/utilitys/utilitys.hpp>
#include <stda/system/terminal/terminal.hpp>

#ifndef LOGSSTDX
#define LOGSSTDX

/* @Documentacion:
 * Este archivo contiene la clase Log para el manejo de mensajes ya sean
 * comunes o excepciones enviadas por los programs que usen dicho archivo
 */

/// @brief Este es el espacio de nombre que contiene todo lo relacionado con el log
namespace System
{
    /// @brief Clase que maneja
    class Log
    {
    public:
        friend System::Exception;
        friend System::Windows_Exceptions;
        /// @brief Id para identificar el nuvel del log
        enum class Id : u8
        {
            menssage,
            warning,
            error,
            none
        };
        /// @brief Cadena que guarda el mensaje
        __stringbuffer message;
        /// @brief Id del log
        Id id;
        /// @brief Tiempo en el que se emitio el log
        Time::Point time;
        /// @brief Construtor basico para el log
        /// @param _message Mensaje a enviar de tipo(?const __caracter*?)
        /// @param _id Id del log
        Log(const __caracter *_message, Id _id);
        /// @brief Construtor basico para el log
        /// @param _message Mensaje a enviar de tipo(?__string?)
        /// @param _id Id del log
        Log(const __string &_message, Id _id);
        /// @brief Construtor basico para el log
        /// @param _message Mensaje a enviar de tipo(?__stringbuffer?)
        /// @param _id Id del log
        Log(const __stringbuffer &_message, Id _id);
        /// @brief Construtor basico para el log
        /// @param _message Excepcion recibida
        /// @param _id Id del log
        Log(const std::exception &_message, Id _id = Id::error);
        Log(const Exception &_message);
        Log(const Windows_Exceptions &_message);
        Log(const Log &other)
        {
            message = other.message;
            id = other.id;
            time = other.time;
        }
        Log(Log &&other)
        {
            message = other.message;
            id = other.id;
            time = other.time;
        }
        ~Log() {}
    };
    class Log_Manager
    {
    private:
        static System::Terminal::Text::Color codecolor[4];
        static const char *codemensage[4];
        static std::vector<Log> allocator;
        static const char *nameprogram;

    public:
        /// @brief Funcion que exporta todos los mensajes hacia un archivo dentro del la ruta especificada
        /// @param path Ruta del archivo
        static void exportfile(const System::Url &path);
        /// @brief Funcion que muestra todos los Log por consola
        static void view();
        /// @brief Funcion que muestra todos los Log por consola
        /// @param log Un log especifico que haya captado y desee ver
        static void view(const Log& log);
        /// @brief Agrega un log al administrador para luego enviarlo a donde se desee
        /// @param log Log deseado
        static void serialize(const Log &log);
    };
} // namespace Logsystem

#endif