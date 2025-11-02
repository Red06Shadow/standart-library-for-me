#include <stda/sstrings/converter.hpp>
#include <exception>
#include <string>
#include <cstring>

#ifndef EXCEPTIONSME
#define EXCEPTIONSME

namespace ios
{
    class exception : public std::exception
    {
    public:
        enum class error : unsigned int
        {
            __none,
            __iofaul,
            __notfolderdestine,
            __notgetfilesize,
            __notfileupdater,
            __invalidopmovecopy,
            __notexistingfolder,
            __other,
        };

    private:
#define __SIZE__ 6
        static char const *const errors[__SIZE__];
        error __error__;
    protected:
        char* __other__;

    public:
        exception() noexcept : __error__(error::__none), __other__(nullptr) {}
        explicit exception(const error __message) : __error__(__message), __other__(nullptr) {}
        explicit exception(const error __message, const char* other_message) : __error__(__message), __other__(const_cast<char*>(other_message)) {}
        explicit exception(const char* __message) : __error__(error::__other), __other__(const_cast<char*>(__message)) {}
        explicit exception(const std::string __message) : __error__(error::__other) {
            __other__ = new char[__message.size() + 1];
            __other__[__message.size()] = 0;
            std::strcpy(__other__, __message.c_str());
        }
        explicit exception(const std::wstring __message) : __error__(error::__other) {
            __other__ = new char[__message.size() + 1];
            __other__[__message.size()] = 0;
            char* str = stringconverter::convert_utf8_to_ascii(__message.c_str());
            std::strcpy(__other__, str);
            delete[](str);
        }
        exception &operator=(exception const &_Other) noexcept
        {
            if (this == &_Other)
            {
                return *this;
            }
            this->__error__ = _Other.__error__;
            return *this;
        }
        const char *what() const noexcept override;
        virtual ~exception() noexcept {
        }
        error get_code() const { return __error__; }
    };
}
#endif