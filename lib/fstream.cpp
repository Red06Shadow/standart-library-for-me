#include <stda/system/files/fstream/fstream.hpp>

const u8 System::Ios::fstream::mode(System::Ios::base __base)
{
    u8 base = 0;
    if ((__base & System::Ios::app) && (__base & System::Ios::out))
        throw System::Exception("Invalid operation for arguments");
    if (__base & System::Ios::base::bin)
        base = 6, __base ^= System::Ios::base::bin;
    if (!(__base & System::Ios::base::trunc))
        return base + static_cast<u8>(__base) - 1;
    __base ^= System::Ios::base::trunc;
    if (!(__base & 0b11))
        throw System::Exception("Invalid operation for arguments");
    else
        base += 0b110;
    return base - 1;
}

System::Ios::fstream::fstream(const System::Ios::fstream &other)
{
    if (__fptr__ != nullptr)
        fclose(__fptr__);
    __fptr__ = std::move(other.__fptr__);
    __binary__ = other.__binary__;
    __endstr__ = other.__endstr__;
    __position_aux__ = other.__position_aux__;
    __position_before__ = other.__position_before__;
}
System::Ios::fstream::fstream(System::Ios::fstream &&other)
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
System::Ios::fstream &System::Ios::fstream::operator=(const System::Ios::fstream &other)
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
System::Ios::fstream &System::Ios::fstream::operator=(System::Ios::fstream &&other)
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

System::Ios::fstream::fstream(const __caracter *__path, System::Ios::base __mode)
{
    __binary__ = __mode & System::Ios::bin;
#if defined(USINGWCARACTER)
    char *__str__ = std::String::convert_utf8_to_ascii(__path);
    __fptr__ = fopen(__str__, System::Ios::fstream::__mode__[System::Ios::fstream::mode(__mode)]);
    delete[] (__str__);
#else
    u8 base = System::Ios::fstream::mode(__mode);
    if((__fptr__ = fopen(__path, System::Ios::fstream::__mode__[base])) == nullptr)
        throw System::Exception(ferror(__fptr__), "System::Ios::fstream::fstream");
#endif
    __position_aux__ = __position_before__ = ftell(__fptr__);
}

const char *const System::Ios::fstream::__mode__[12] = {
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

void System::Ios::fstream::setpos(size_t position, bool actual)
{
    fseek(__fptr__, position, actual ? SEEK_CUR : SEEK_SET);
}
void System::Ios::fstream::setposaux(size_t position, bool actual)
{
    __position_aux__ = position + (actual ? ftell(__fptr__) : 0);
}
void System::Ios::fstream::setpos(size_t position, size_t size, bool actual)
{
    fseek(__fptr__, position * size, actual ? SEEK_CUR : SEEK_SET);
}
void System::Ios::fstream::setposaux(size_t position, size_t size, bool actual)
{
    __position_aux__ = position * size + (actual ? ftell(__fptr__) : 0);
}
size_t System::Ios::fstream::getpos()
{
    return ftell(__fptr__);
}
size_t System::Ios::fstream::getposreal()
{
    return fgetpos(__fptr__, 0L);
}
size_t System::Ios::fstream::getposbe()
{
    return 0;
}
size_t System::Ios::fstream::getposaux()
{
    return __position_aux__;
}
void System::Ios::fstream::setendchar(int _c)
{
    __endstr__ = _c;
}
int System::Ios::fstream::getendchar()
{
    return __endstr__;
}
bool System::Ios::fstream::isopen() { return __fptr__ == nullptr; }
bool System::Ios::fstream::iseof() { return feof(__fptr__) != 0; }
void System::Ios::fstream::setstartp() { rewind(__fptr__); }
void System::Ios::fstream::setendp() { fseek(__fptr__, 0L, SEEK_END); }
void System::Ios::fstream::fsflush() { fflush(__fptr__); }
void System::Ios::fstream::clearerror() { clearerr(__fptr__); }

void System::Ios::fstream::copy(System::Ios::fstream *ptrfstream, System::Ios::fstream &reffstream)
{
    ptrfstream->__binary__ = reffstream.__binary__;
    ptrfstream->__endstr__ = reffstream.__endstr__;
    ptrfstream->__fptr__ = reffstream.__fptr__;
    ptrfstream->__position_aux__ = reffstream.__position_aux__;
    ptrfstream->__position_before__ = reffstream.__position_before__;
}

System::Ios::fstream System::Ios::fstream::open(const __caracter *__path, System::Ios::base __mode)
{
    return System::Ios::fstream(__path, __mode);
}
void System::Ios::fstream::reopen(const __caracter *__path, System::Ios::base __mode, fstream &__fstream__)
{
    if (__fstream__.isopen())
        throw System::Exception(ferror(__fstream__.__fptr__), "System::Ios::fstream::reopen");
#if defined(USINGWCARACTER)
    char *__str__ = std::String::convert_utf8_to_ascii(__path);
    __fptr__ = fopen(__str__, System::Ios::fstream::__mode__[__mode - u8(1)]);
    delete[] (__str__);
#else
    __fstream__.__fptr__ = fopen(__path, System::Ios::fstream::__mode__[__mode - u8(1)]);
#endif
    __fstream__.__binary__ = __mode & System::Ios::base::bin;
    __fstream__.__position_aux__ = __fstream__.__position_before__ = ftell(__fstream__.__fptr__);
}
void System::Ios::fstream::close(fstream &__fstream__)
{
    fclose(__fstream__.__fptr__);
}
void System::Ios::fstream::changemode(System::Ios::base __mode)
{
    __binary__ = __mode & System::Ios::base::bin;
    __fptr__ = freopen(nullptr, System::Ios::fstream::__mode__[__mode - u8(1)], __fptr__);
    __position_aux__ = __position_before__ = ftell(__fptr__);
}

bool System::Ios::fstream::isBinary() { return __binary__; }

System::Ios::fstream::~fstream()
{
    fflush(__fptr__);
    fclose(__fptr__);
}

/////////////////////////////////////////////////////////////////////////////////
System::Ios::ifstream::ifstream(const System::Url &url) : fstream(url.c_str(), System::Ios::base::in) {}
System::Ios::ifstream::ifstream(const System::Url &url, bool binary) : fstream(url.c_str(), System::Ios::base::in | System::Ios::base(binary ? System::Ios::base::bin : 0)) {}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////Funciones In////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
void System::Ios::ifstream::read(std::string &str, size_t _start, size_t _end)
{
    char __c;
    while ((__c = fgetc(__fptr__)) != EOF && _start < _end)
        str.push_back(__c);
}
void System::Ios::ifstream::read(std::wstring &str, size_t _start, size_t _end)
{
    wchar_t __c;
    while ((__c = fgetwc(__fptr__)) != EOF && _start < _end)
        str.push_back(__c);
}
void System::Ios::ifstream::read(std::string &str, char caracter_end)
{
    char __c;
    while ((__c = fgetc(__fptr__)) != EOF && __c != caracter_end)
        str.push_back(__c);
}
void System::Ios::ifstream::read(std::string &str, wchar_t caracter_end)
{
    wchar_t __c;
    while ((__c = fgetc(__fptr__)) != EOF && __c != caracter_end)
        str.push_back(__c);
}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////Operadores In////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, char *&__str)
{
    std::string __str_;
    is >> __str_;
    __str = const_cast<char *>(__str_.c_str());
    return is;
}
System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, std::string &__str)
{
    char __c;
    while ((__c = fgetc(is.__fptr__)) != EOF && __c != is.__endstr__)
        __str.push_back(__c);
    return is;
}
System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, std::wstring &__str)
{
    wchar_t __c;
    while ((__c = fgetwc(is.__fptr__)) != EOF && __c != is.__endstr__)
        __str.push_back(__c);
    return is;
}
System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, stringbuffer &__str)
{
    char __c;
    size_t position = 0;
    while ((__c = fgetc(is.__fptr__)) != EOF && __c != is.__endstr__ && position < __str.size())
        __str[position++] = __c;
    return is;
}

System::Ios::ifstream &System::Ios::operator>>(ifstream &is, wstringbuffer &__str)
{
    wchar_t __c;
    size_t position = 0;
    while ((__c = fgetwc(is.__fptr__)) != EOF && __c != is.__endstr__ && position < __str.size())
        __str[position++] = __c;
    return is;
}

System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, int &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(int), 1, is.__fptr__)) != 1)
            throw System::Exception(ferror(is.__fptr__), "System::Ios::operator>>(System::Ios::ifstream &is, int &__n)");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtol(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, unsigned int &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(int), 1, is.__fptr__)) != 1)
            throw System::Exception(ferror(is.__fptr__), "System::Ios::operator>>(System::Ios::ifstream &is, unsigned int &__n)");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtoul(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, char &__n)
{
    if ((__n = fgetc(is.__fptr__)) == EOF)
    {
        __n = '\0';
    }
    return is;
}

System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, wchar_t &__n)
{
    if ((__n = fgetwc(is.__fptr__)) == EOF)
    {
        __n = '\0';
    }
    return is;
}

System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, unsigned char &__n)
{
    fread(&__n, sizeof(char), 1, is.__fptr__);
    return is;
}
System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, long &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(long), 1, is.__fptr__)) != 1)
            throw System::Exception(ferror(is.__fptr__), "System::Ios::operator>>(System::Ios::ifstream &is, long &__n)");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtol(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, unsigned long &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(long), 1, is.__fptr__)) != 1)
            throw System::Exception(ferror(is.__fptr__), "System::Ios::operator>>(System::Ios::ifstream &is, unsigned long &__n)");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtoul(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, long long &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(long long), 1, is.__fptr__)) != 1)
            throw System::Exception(ferror(is.__fptr__), "System::Ios::operator>>(System::Ios::ifstream &is, long long &__n)");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtoll(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, unsigned long long &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(long long), 1, is.__fptr__)) != 1)
            throw System::Exception(ferror(is.__fptr__), "System::Ios::operator>>(System::Ios::ifstream &is, unsigned long long &__n)");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtoull(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, float &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(float), 1, is.__fptr__)) != 1)
            throw System::Exception(ferror(is.__fptr__), "System::Ios::operator>>(System::Ios::ifstream &is, float &__n)");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtof(cstr__n_.c_str(), nullptr);
    }
    return is;
}
System::Ios::ifstream &System::Ios::operator>>(System::Ios::ifstream &is, double &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(double), 1, is.__fptr__)) != 1)
            throw System::Exception(ferror(is.__fptr__), "System::Ios::operator>>(System::Ios::ifstream &is, double &__n)");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtod(cstr__n_.c_str(), nullptr);
    }
    return is;
}
std::ostream &System::Ios::operator<<(std::ostream &out, System::Ios::ifstream &is)
{
    while (!is.iseof())
    {
        u8 byte;
        is >> byte;
        out << byte;
    }
    return out;
}
System::Ios::ofstream::ofstream(const System::Url &url) : fstream(url.c_str(), System::Ios::base::app) {}
System::Ios::ofstream::ofstream(const System::Url &url, bool binary, Ios::ofstream::options options) : System::Ios::fstream(url.c_str(), (
                                                                                                                                                options == Ios::ofstream::options::write
                                                                                                                                                    ? (System::Ios::out | System::Ios::in)
                                                                                                                                                    : (options == Ios::ofstream::options::override
                                                                                                                                                           ? System::Ios::out
                                                                                                                                                           : System::Ios::app)) |
                                                                                                                                                System::Ios::base(binary ? System::Ios::base::bin : 0)) {}

void System::Ios::ofstream::write(const std::string &str, size_t strstart, size_t strend, size_t start)
{
    size_t size = (strend > str.size() ? str.size() : strend);
    setpos(start, 1, false);
    for (size_t i = 0; i < size; i++)
        fwrite(&str[i], sizeof(char), 1, __fptr__);
}
void System::Ios::ofstream::write(const std::wstring &str, size_t strstart, size_t strend, size_t start)
{
    size_t size = (strend > str.size() ? str.size() : strend);
    setpos(start, 1, false);
    for (size_t i = 0; i < size; i++)
        fwrite(&str[i], sizeof(wchar_t), 1, __fptr__);
}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////Operadores Out///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const char *__str)
{
    size_t n_elements = std::strlen(__str);
    if ((fwrite(__str, sizeof(char), n_elements, os.__fptr__)) != n_elements)
        throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const char* __str)");
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const std::string __str)
{
    if ((fwrite(__str.c_str(), sizeof(char), __str.size(), os.__fptr__)) != __str.size())
        throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const std::string __str)");
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const std::wstring __str)
{
    if ((fwrite(__str.c_str(), sizeof(wchar_t), __str.size(), os.__fptr__)) != __str.size())
        throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const std::wstring __str)");
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const stringbuffer &__str)
{
    if ((fwrite(__str.c_str(), sizeof(char), __str.size(), os.__fptr__)) != __str.size())
        throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const stringbuffer __str)");
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const wstringbuffer &__str)
{
    if ((fwrite(__str.c_str(), sizeof(wchar_t), __str.size(), os.__fptr__)) != __str.size())
        throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const wstringbuffer __str)");
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const int __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(int), 1, os.__fptr__)) != 1)
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const int __n)");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const int __n)");
    }
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const unsigned int __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(unsigned int), 1, os.__fptr__)) != 1)
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const unsigned int __n)");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const unsigned int __n)");
    }
    return os;
}

System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const char __n)
{
    if ((fwrite(&__n, sizeof(char), 1, os.__fptr__)) != 1)
        throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const char __n)");
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const unsigned char __n)
{
    if ((fwrite(&__n, sizeof(char), 1, os.__fptr__)) != 1)
        throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const unsigned char __n)");
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const wchar_t __n)
{
    if ((fwrite(&__n, sizeof(wchar_t), 1, os.__fptr__)) != 1)
        throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const wchar_t __n)");
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const long __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(long), 1, os.__fptr__)) != 1)
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const long __n)");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const long __n)");
    }
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const unsigned long __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(unsigned long), 1, os.__fptr__)) != 1)
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const unsigned long __n)");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const unsigned long __n)");
    }
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const long long __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(long long), 1, os.__fptr__)) != 1)
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const long long __n)");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const long long __n)");
    }
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const unsigned long long __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(unsigned long long), 1, os.__fptr__)) != 1)
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const unsigned long long __n)");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const unsigned long long __n)");
    }
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const float __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(float), 1, os.__fptr__)) != 1)
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const float __n)");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const float __n)");
    }
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &os, const double __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(double), 1, os.__fptr__)) != 1)
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const double __n)");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw System::Exception(ferror(os.__fptr__), "System::Ios::operator<<(System::Ios::ofstream &os, const double __n)");
    }
    return os;
}
System::Ios::ofstream &System::Ios::operator<<(System::Ios::ofstream &out, ifstream &is)
{
    while (!is.iseof())
    {
        u8 byte;
        is >> byte;
        out << byte;
    }
    return out;
}
std::istream &System::Ios::operator>>(std::istream &in, System::Ios::ofstream &out)
{
    std::string line;
    std::getline(in, line);
    out << line;
    return in;
}
System::Ios::iofstream::iofstream(const System::Url &url)
{
    __syncroned__file__input__output__ = nullptr;
    __output__ = new ofstream(url);
    __input__ = new ifstream(url);
    __syncroned_input_output_system__ = false;
}
System::Ios::iofstream::iofstream(const System::Url &url, bool binary, bool syncroned_input_output_system)
{
    __syncroned__file__input__output__ = (syncroned_input_output_system ? new fstream(url.c_str(), binary ? System::Ios::base::in : System::Ios::base::out) : nullptr);
    __output__ = new ofstream(url, binary);
    __input__ = new ifstream(url, binary);
    __syncroned_input_output_system__ = syncroned_input_output_system;
}

System::Ios::iofstream::iofstream(const System::Ios::iofstream &other) : __input__()
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
System::Ios::iofstream::iofstream(System::Ios::iofstream &&other)
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

System::Ios::ifstream &System::Ios::iofstream::in()
{
    return (__syncroned_input_output_system__ ? *static_cast<System::Ios::ifstream *>(__syncroned__file__input__output__) : *__input__);
}
System::Ios::ofstream &System::Ios::iofstream::out()
{
    return (__syncroned_input_output_system__ ? *static_cast<System::Ios::ofstream *>(__syncroned__file__input__output__) : *__output__);
}
bool System::Ios::iofstream::isBinaryFile()
{
    return (__syncroned_input_output_system__ ? __syncroned__file__input__output__->isBinary() : __input__->__binary__ & __output__->__binary__);
}

void System::Ios::iofstream::setSyncronedInputOutputSystem(bool __v, System::Ios::fstream &Syncroned_fstream_reference)
{
    if (__syncroned__file__input__output__ == nullptr && __v)
    {
        __syncroned__file__input__output__ = new fstream();
        System::Ios::fstream::copy(__syncroned__file__input__output__, *__input__);
    }
    __syncroned_input_output_system__ = __v;
}
