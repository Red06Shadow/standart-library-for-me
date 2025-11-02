#include <stda/system/files/files.hpp>
#include <stda/sstrings/sstrings.hpp>
#include <stda/system/time/time.hpp>
#include <stda/system/memory/memory.hpp>
#include <stda/standart/utilitys.hpp>

#ifndef LOGSSTDX
#define LOGSSTDX

namespace logssystem
{
    class logs
    {
    public:
        enum class type : u8
        {
            menssage,
            warning,
            error,
            none
        };
        __stringbuffer message;
        type id;
        timesystem::time_point time;
        logs(const __caracter* _message, type _id);
        logs(const __string& _message, type _id);
        logs(const __stringbuffer& _message, type _id);
        logs(const std::exception& _message, type _id);
        logs(const logs& other) {
            message = other.message;
            id = other.id;
            time = other.time;
        }
        logs(logs&& other) {
            message = other.message;
            id = other.id;
            time = other.time;
        }
        ~logs() {}
    };
    class manager
    {
    private:
        static const char* codecolor[4];
        static const char* codemensage[4];
        static std::vector<logs> allocator;
        static const char* nameprogram;
    public:
        static void exportfile(const ios::Url& path = ios::Url(__argv[0]));
        static void view();
        static void serialize(const logs& log);
    };
} // namespace logssystem

#endif