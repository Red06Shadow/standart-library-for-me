#include <stda/system/files/fstream/fstream.hpp>

const u8 systems::ios::fstream::mode(systems::ios::base __base)
{
    if ((__base & systems::ios::app) && (__base & systems::ios::out))
        throw std::runtime_error("Invalid operation for arguments");
    if ((__base & 0b10) && (__base & 0b01) && (__base & systems::ios::base::trunc))
        __base = systems::ios::base(0b11) + (__base ^ systems::ios::base::trunc);
    return (__base - ((__base & systems::ios::bin) ? u8(3) : u8(1)));
}

systems::ios::fstream::fstream(const systems::ios::fstream &other)
{
    if (__fptr__ != nullptr)
        fclose(__fptr__);
    __fptr__ = std::move(other.__fptr__);
    __binary__ = other.__binary__;
    __endstr__ = other.__endstr__;
    __position_aux__ = other.__position_aux__;
    __position_before__ = other.__position_before__;
}
systems::ios::fstream::fstream(systems::ios::fstream &&other)
{
    if (__fptr__ != nullptr)
        fclose(__fptr__);
    this->__fptr__ = other.__fptr__;
    other.__fptr__ = nullptr;
    this->__binary__ = other.__binary__;
    this->__endstr__ = other.__endstr__;
    this->__position_aux__ = other.__position_aux__;
    this->__position_before__ = other.__position_before__;
}
systems::ios::fstream &systems::ios::fstream::operator=(const systems::ios::fstream &other)
{
    if (this != &other)
    {
        if (__fptr__ != nullptr)
            fclose(__fptr__);
        this->__fptr__ = std::move(other.__fptr__);
        this->__binary__ = other.__binary__;
        this->__endstr__ = other.__endstr__;
        this->__position_aux__ = other.__position_aux__;
        this->__position_before__ = other.__position_before__;
    }
    return *this;
}
systems::ios::fstream &systems::ios::fstream::operator=(systems::ios::fstream &&other)
{
    if (this != &other)
    {
        if (__fptr__ != nullptr)
            fclose(__fptr__);
        this->__fptr__ = other.__fptr__;
        other.__fptr__ = nullptr;
        this->__binary__ = other.__binary__;
        this->__endstr__ = other.__endstr__;
        this->__position_aux__ = other.__position_aux__;
        this->__position_before__ = other.__position_before__;
    }
    return *this;
}

systems::ios::fstream::fstream(const __caracter *__path, systems::ios::base __mode)
{
    __binary__ = __mode & systems::ios::bin;
#if defined(USINGWCARACTER)
    char *__str__ = std::stringconverter::convert_utf8_to_ascii(__path);
    __fptr__ = fopen(__str__, systems::ios::fstream::__mode__[systems::ios::fstream::mode(__mode)]);
    delete[] (__str__);
#else
    __fptr__ = fopen(__path, systems::ios::fstream::__mode__[systems::ios::fstream::mode(__mode)]);
#endif
    __position_aux__ = __position_before__ = ftell(__fptr__);
}

const char *const systems::ios::fstream::__mode__[12] = {
    "r",  // 0
    "w",  // 1
    "r+", // 2
    "a",  // 3
    "a+", // 4
    "w+", // 5
    ///////////
    "rb",  // 6
    "wb",  // 7
    "rb+", // 8
    "ab",  // 9
    "ab+", // 10
    "wb+"  // 11
};

void systems::ios::fstream::setpos(size_t position, bool actual)
{
    fseek(__fptr__, position, actual ? SEEK_CUR : SEEK_SET);
}
void systems::ios::fstream::setposaux(size_t position, bool actual)
{
    __position_aux__ = position + (actual ? ftell(__fptr__) : 0);
}
void systems::ios::fstream::setpos(size_t position, size_t size, bool actual)
{
    fseek(__fptr__, position * size, actual ? SEEK_CUR : SEEK_SET);
}
void systems::ios::fstream::setposaux(size_t position, size_t size, bool actual)
{
    __position_aux__ = position * size + (actual ? ftell(__fptr__) : 0);
}
size_t systems::ios::fstream::getpos()
{
    return ftell(__fptr__);
}
size_t systems::ios::fstream::getposreal()
{
    return fgetpos(__fptr__, 0L);
}
size_t systems::ios::fstream::getposbe()
{
    return 0;
}
size_t systems::ios::fstream::getposaux()
{
    return __position_aux__;
}
void systems::ios::fstream::setendchar(int _c)
{
    __endstr__ = _c;
}
int systems::ios::fstream::getendchar()
{
    return __endstr__;
}
bool systems::ios::fstream::isopen() { return __fptr__ == nullptr; }
bool systems::ios::fstream::iseof() { return feof(__fptr__) != 0; }
void systems::ios::fstream::setstartp() { rewind(__fptr__); }
void systems::ios::fstream::setendp() { fseek(__fptr__, 0L, SEEK_END); }
void systems::ios::fstream::fsflush() { fflush(__fptr__); }
void systems::ios::fstream::clearerror() { clearerr(__fptr__); }

void systems::ios::fstream::copy(systems::ios::fstream *ptrfstream, systems::ios::fstream &reffstream)
{
    ptrfstream->__binary__ = reffstream.__binary__;
    ptrfstream->__endstr__ = reffstream.__endstr__;
    ptrfstream->__fptr__ = reffstream.__fptr__;
    ptrfstream->__position_aux__ = reffstream.__position_aux__;
    ptrfstream->__position_before__ = reffstream.__position_before__;
}

systems::ios::fstream systems::ios::fstream::open(const __caracter *__path, systems::ios::base __mode)
{
    return systems::ios::fstream(__path, __mode);
}
void systems::ios::fstream::reopen(const __caracter *__path, systems::ios::base __mode, fstream &__fstream__)
{
    if (__fstream__.isopen())
        throw std::runtime_error("Error: El archivo aun esta abierto");
#if defined(USINGWCARACTER)
    char *__str__ = std::stringconverter::convert_utf8_to_ascii(__path);
    __fptr__ = fopen(__str__, systems::ios::fstream::__mode__[__mode - u8(1)]);
    delete[] (__str__);
#else
    __fstream__.__fptr__ = fopen(__path, systems::ios::fstream::__mode__[__mode - u8(1)]);
#endif
    __fstream__.__binary__ = __mode & systems::ios::base::bin;
    __fstream__.__position_aux__ = __fstream__.__position_before__ = ftell(__fstream__.__fptr__);
}
void systems::ios::fstream::close(fstream &__fstream__)
{
    fclose(__fstream__.__fptr__);
}
void systems::ios::fstream::changemode(systems::ios::base __mode)
{
    __binary__ = __mode & systems::ios::base::bin;
    __fptr__ = freopen(nullptr, systems::ios::fstream::__mode__[__mode - u8(1)], __fptr__);
    __position_aux__ = __position_before__ = ftell(__fptr__);
}

bool systems::ios::fstream::isBinary() { return __binary__; }

systems::ios::fstream::~fstream()
{
    fflush(__fptr__);
    fclose(__fptr__);
}

/////////////////////////////////////////////////////////////////////////////////
systems::ios::ifstream::ifstream(const systems::Url &url) : fstream(url.c_str(), systems::ios::base::in) {}
systems::ios::ifstream::ifstream(const systems::Url &url, bool binary) : fstream(url.c_str(), systems::ios::base::in | systems::ios::base(binary ? systems::ios::base::bin : 0)) {}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////Funciones In////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
void systems::ios::ifstream::read(std::string &str, size_t _start, size_t _end)
{
    char __c;
    while ((__c = fgetc(__fptr__)) != EOF && _start < _end)
        str.push_back(__c);
}
void systems::ios::ifstream::read(std::wstring &str, size_t _start, size_t _end)
{
    wchar_t __c;
    while ((__c = fgetwc(__fptr__)) != EOF && _start < _end)
        str.push_back(__c);
}
void systems::ios::ifstream::read(std::string &str, char caracter_end)
{
    char __c;
    while ((__c = fgetc(__fptr__)) != EOF && __c != caracter_end)
        str.push_back(__c);
}
void systems::ios::ifstream::read(std::string &str, wchar_t caracter_end)
{
    wchar_t __c;
    while ((__c = fgetc(__fptr__)) != EOF && __c != caracter_end)
        str.push_back(__c);
}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////Operadores In////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, char *&__str)
{
    std::string __str_;
    is >> __str_;
    __str = const_cast<char *>(__str_.c_str());
    return is;
}
systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, std::string &__str)
{
    char __c;
    while ((__c = fgetc(is.__fptr__)) != EOF && __c != is.__endstr__)
        __str.push_back(__c);
    return is;
}
systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, std::wstring &__str)
{
    wchar_t __c;
    while ((__c = fgetwc(is.__fptr__)) != EOF && __c != is.__endstr__)
        __str.push_back(__c);
    return is;
}
systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, stringbuffer &__str)
{
    char __c;
    size_t position = 0;
    while ((__c = fgetc(is.__fptr__)) != EOF && __c != is.__endstr__ && position < __str.size())
        __str[position++] = __c;
    return is;
}

systems::ios::ifstream &systems::ios::operator>>(ifstream &is, wstringbuffer &__str)
{
    wchar_t __c;
    size_t position = 0;
    while ((__c = fgetwc(is.__fptr__)) != EOF && __c != is.__endstr__ && position < __str.size())
        __str[position++] = __c;
    return is;
}

systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, int &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(int), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en int systems::ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtol(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, unsigned int &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(int), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en unsigned int systems::ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtoul(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, char &__n)
{
    if ((__n = fgetc(is.__fptr__)) == EOF)
    {
        __n = '\0';
    }
    return is;
}

systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, wchar_t &__n)
{
    if ((__n = fgetwc(is.__fptr__)) == EOF)
    {
        __n = '\0';
    }
    return is;
}

systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, unsigned char &__n)
{
    fread(&__n, sizeof(char), 1, is.__fptr__);
    return is;
}
systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, long &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(long), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en long systems::ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtol(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, unsigned long &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(long), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en unsigned long systems::ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtoul(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, long long &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(long long), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en long long systems::ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtoll(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, unsigned long long &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(long long), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en unsigned long long systems::ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtoull(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, float &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(float), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en float systems::ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtof(cstr__n_.c_str(), nullptr);
    }
    return is;
}
systems::ios::ifstream &systems::ios::operator>>(systems::ios::ifstream &is, double &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(double), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en double systems::ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtod(cstr__n_.c_str(), nullptr);
    }
    return is;
}
std::ostream &systems::ios::operator<<(std::ostream &out, systems::ios::ifstream &is)
{
    while (!is.iseof())
    {
        u8 byte;
        is >> byte;
        out << byte;
    }
    return out;
}
systems::ios::ofstream::ofstream(const systems::Url &url) : fstream(url.c_str(), systems::ios::base::app) {}
systems::ios::ofstream::ofstream(const systems::Url &url, bool binary) : fstream(url.c_str(), systems::ios::base::app | systems::ios::base(binary ? systems::ios::base::bin : 0)) {}
systems::ios::ofstream::ofstream(const systems::Url &url, systems::ios::base __mode)
{
    if (!(__mode & 0b10 || __mode & 0b100))
        throw std::runtime_error("Error: Debegate mode for this constructor");
    fstream(url.c_str(), __mode);
}

void systems::ios::ofstream::write(const std::string &str, size_t strstart, size_t strend, size_t start)
{
    size_t size = (strend > str.size() ? str.size() : strend);
    setpos(start, 1, false);
    for (size_t i = 0; i < size; i++)
        fwrite(&str[i], sizeof(char), 1, __fptr__);
}
void systems::ios::ofstream::write(const std::wstring &str, size_t strstart, size_t strend, size_t start)
{
    size_t size = (strend > str.size() ? str.size() : strend);
    setpos(start, 1, false);
    for (size_t i = 0; i < size; i++)
        fwrite(&str[i], sizeof(wchar_t), 1, __fptr__);
}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////Operadores Out///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const char *__str)
{
    size_t n_elements = std::strlen(__str);
    if ((fwrite(__str, sizeof(char), n_elements, os.__fptr__)) != n_elements)
        throw std::runtime_error("Fallo la operacion de escritura en const char* systems::ios::operator<<");
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const std::string __str)
{
    if ((fwrite(__str.c_str(), sizeof(char), __str.size(), os.__fptr__)) != __str.size())
        throw std::runtime_error("Fallo la operacion de escritura en const std::string systems::ios::operator<<");
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const std::wstring __str)
{
    if ((fwrite(__str.c_str(), sizeof(wchar_t), __str.size(), os.__fptr__)) != __str.size())
        throw std::runtime_error("Fallo la operacion de escritura en const std::wstring systems::ios::operator<<");
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const stringbuffer &__str)
{
    if ((fwrite(__str.c_str(), sizeof(char), __str.size(), os.__fptr__)) != __str.size())
        throw std::runtime_error("Fallo la operacion de escritura en stringbuffer systems::ios::operator<<");
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const wstringbuffer &__str)
{
    if ((fwrite(__str.c_str(), sizeof(wchar_t), __str.size(), os.__fptr__)) != __str.size())
        throw std::runtime_error("Fallo la operacion de escritura en stringbuffer systems::ios::operator<<");
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const int __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(int), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en int systems::ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en int systems::ios::operator<<");
    }
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const unsigned int __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(unsigned int), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en unsigned int systems::ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en unsigned int systems::ios::operator<<");
    }
    return os;
}

systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const char __n)
{
    if ((fwrite(&__n, sizeof(char), 1, os.__fptr__)) != 1)
        throw std::runtime_error("Fallo la operacion de escritura en char systems::ios::operator<<");
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const unsigned char __n)
{
    if ((fwrite(&__n, sizeof(char), 1, os.__fptr__)) != 1)
        throw std::runtime_error("Fallo la operacion de escritura en char systems::ios::operator<<");
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const wchar_t __n)
{
    if ((fwrite(&__n, sizeof(wchar_t), 1, os.__fptr__)) != 1)
        throw std::runtime_error("Fallo la operacion de escritura en wchar_t systems::ios::operator<<");
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const long __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(long), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en long systems::ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en long systems::ios::operator<<");
    }
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const unsigned long __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(unsigned long), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en unsigned long systems::ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en unsigned long systems::ios::operator<<");
    }
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const long long __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(long long), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en long long systems::ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en long long systems::ios::operator<<");
    }
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const unsigned long long __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(unsigned long long), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en unsigned long long systems::ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en unsigned long long systems::ios::operator<<");
    }
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const float __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(float), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en float systems::ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en float systems::ios::operator<<");
    }
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &os, const double __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(double), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en double systems::ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en double operator<<");
    }
    return os;
}
systems::ios::ofstream &systems::ios::operator<<(systems::ios::ofstream &out, ifstream &is) {
    while (!is.iseof())
    {
        u8 byte;
        is >> byte;
        out << byte;
    }
    return out;
}
std::istream &systems::ios::operator>>(std::istream &in, systems::ios::ofstream &out) {
    std::string line;
    std::getline(in, line);
    out << line;
    return in;
}
systems::ios::iofstream::iofstream(const systems::Url &url)
{
    __syncroned__file__input__output__ = nullptr;
    __output__ = new ofstream(url);
    __input__ = new ifstream(url);
    __syncroned_input_output_system__ = false;
}
systems::ios::iofstream::iofstream(const systems::Url &url, bool binary, bool syncroned_input_output_system)
{
    __syncroned__file__input__output__ = (syncroned_input_output_system ? new fstream(url.c_str(), binary ? systems::ios::base::in : systems::ios::base::out) : nullptr);
    __output__ = new ofstream(url, binary);
    __input__ = new ifstream(url, binary);
    __syncroned_input_output_system__ = syncroned_input_output_system;
}

systems::ios::iofstream::iofstream(const systems::ios::iofstream &other) : __input__()
{
    if (__input__ != nullptr)
        delete __input__;
    if (__output__ != nullptr)
        delete __output__;
    if (__syncroned__file__input__output__ != nullptr)
        delete __syncroned__file__input__output__;
    __syncroned_input_output_system__ = other.__syncroned_input_output_system__;
    __input__ = std::move(other.__input__);
    __output__ = std::move(other.__output__);
}
systems::ios::iofstream::iofstream(systems::ios::iofstream &&other)
{
    if (__input__ != nullptr)
        delete __input__;
    if (__output__ != nullptr)
        delete __output__;
    if (__syncroned__file__input__output__ != nullptr)
        delete __syncroned__file__input__output__;
    __syncroned_input_output_system__ = other.__syncroned_input_output_system__;
    __syncroned__file__input__output__ = other.__syncroned__file__input__output__;
    other.__syncroned__file__input__output__ = nullptr;
    __input__ = other.__input__;
    other.__input__ = nullptr;
    __output__ = other.__output__;
    other.__output__ = nullptr;
}

systems::ios::ifstream &systems::ios::iofstream::in()
{
    return (__syncroned_input_output_system__ ? *static_cast<systems::ios::ifstream *>(__syncroned__file__input__output__) : *__input__);
}
systems::ios::ofstream &systems::ios::iofstream::out()
{
    return (__syncroned_input_output_system__ ? *static_cast<systems::ios::ofstream *>(__syncroned__file__input__output__) : *__output__);
}
bool systems::ios::iofstream::isBinaryFile()
{
    return (__syncroned_input_output_system__ ? __syncroned__file__input__output__->isBinary() : __input__->__binary__ & __output__->__binary__);
}

void systems::ios::iofstream::setSyncronedInputOutputSystem(bool __v, systems::ios::fstream &Syncroned_fstream_reference)
{
    if (__syncroned__file__input__output__ == nullptr && __v)
    {
        __syncroned__file__input__output__ = new fstream();
        systems::ios::fstream::copy(__syncroned__file__input__output__, *__input__);
    }
    __syncroned_input_output_system__ = __v;
}
