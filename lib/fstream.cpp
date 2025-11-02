#include <stda/system/files/fstream/fstream.hpp>

const u8 ios::fstream::mode(ios::base __base)
{
    if((__base & ios::app) && (__base & ios::out))
        throw std::runtime_error("Invalid operation for arguments");
    if ((__base & 0b10) && (__base & 0b01) && (__base & ios::base::trunc))
        __base = ios::base(0b11) + (__base ^ ios::base::trunc);
    return (__base - ((__base & ios::bin) ? u8(3) : u8(1)));
}

ios::fstream::fstream(const ios::fstream &other)
{
    if (__fptr__ != nullptr)
        fclose(__fptr__);
    __fptr__ = std::move(other.__fptr__);
    __binary__ = other.__binary__;
    __endstr__ = other.__endstr__;
    __position_aux__ = other.__position_aux__;
    __position_before__ = other.__position_before__;
}
ios::fstream::fstream(ios::fstream &&other)
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
ios::fstream &ios::fstream::operator=(const ios::fstream &other)
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
ios::fstream &ios::fstream::operator=(ios::fstream &&other)
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

ios::fstream::fstream(const __caracter *__path, ios::base __mode)
{
    __binary__ = __mode & ios::bin;
#if defined(USINGWCARACTER)
    char *__str__ = std::stringconverter::convert_utf8_to_ascii(__path);
    __fptr__ = fopen(__str__, ios::fstream::__mode__[ios::fstream::mode(__mode)]);
    delete[] (__str__);
#else
    __fptr__ = fopen(__path, ios::fstream::__mode__[ios::fstream::mode(__mode)]);
#endif
    __position_aux__ = __position_before__ = ftell(__fptr__);
}

const char *const ios::fstream::__mode__[12] = {
    "r", //0
    "w", //1
    "r+", //2
    "a", //3
    "a+", //4
    "w+", //5
    ///////////
    "rb", //6
    "wb", //7
    "rb+", //8
    "ab", //9
    "ab+", //10
    "wb+" //11
};

void ios::fstream::setpos(size_t position, bool actual)
{
    fseek(__fptr__, position, actual ? SEEK_CUR : SEEK_SET);
}
void ios::fstream::setposaux(size_t position, bool actual)
{
    __position_aux__ = position + (actual ? ftell(__fptr__) : 0);
}
void ios::fstream::setpos(size_t position, size_t size, bool actual)
{
    fseek(__fptr__, position * size, actual ? SEEK_CUR : SEEK_SET);
}
void ios::fstream::setposaux(size_t position, size_t size, bool actual)
{
    __position_aux__ = position * size + (actual ? ftell(__fptr__) : 0);
}
size_t ios::fstream::getpos()
{
    return ftell(__fptr__);
}
size_t ios::fstream::getposreal()
{
    return fgetpos(__fptr__, 0L);
}
size_t ios::fstream::getposbe()
{
    return 0;
}
size_t ios::fstream::getposaux()
{
    return __position_aux__;
}
void ios::fstream::setendchar(int _c)
{
    __endstr__ = _c;
}
int ios::fstream::getendchar()
{
    return __endstr__;
}
bool ios::fstream::isopen() { return __fptr__ == nullptr; }
bool ios::fstream::iseof() { return feof(__fptr__) != 0; }
void ios::fstream::setstartp() { rewind(__fptr__); }
void ios::fstream::setendp() { fseek(__fptr__, 0L, SEEK_END); }
void ios::fstream::fsflush() { fflush(__fptr__); }
void ios::fstream::clearerror() { clearerr(__fptr__); }

void ios::fstream::copy(ios::fstream *ptrfstream, ios::fstream &reffstream)
{
    ptrfstream->__binary__ = reffstream.__binary__;
    ptrfstream->__endstr__ = reffstream.__endstr__;
    ptrfstream->__fptr__ = reffstream.__fptr__;
    ptrfstream->__position_aux__ = reffstream.__position_aux__;
    ptrfstream->__position_before__ = reffstream.__position_before__;
}

ios::fstream ios::fstream::open(const __caracter *__path, ios::base __mode)
{
    return ios::fstream(__path, __mode);
}
void ios::fstream::reopen(const __caracter *__path, ios::base __mode, fstream &__fstream__)
{
    if (__fstream__.isopen())
        throw std::runtime_error("Error: El archivo aun esta abierto");
#if defined(USINGWCARACTER)
    char *__str__ = std::stringconverter::convert_utf8_to_ascii(__path);
    __fptr__ = fopen(__str__, ios::fstream::__mode__[__mode - u8(1)]);
    delete[] (__str__);
#else
    __fstream__.__fptr__ = fopen(__path, ios::fstream::__mode__[__mode - u8(1)]);
#endif
    __fstream__.__binary__ = __mode & ios::base::bin;
    __fstream__.__position_aux__ = __fstream__.__position_before__ = ftell(__fstream__.__fptr__);
}
void ios::fstream::close(fstream &__fstream__)
{
    fclose(__fstream__.__fptr__);
}
void ios::fstream::changemode(ios::base __mode)
{
    __binary__ = __mode & ios::base::bin;
    __fptr__ = freopen(nullptr, ios::fstream::__mode__[__mode - u8(1)], __fptr__);
    __position_aux__ = __position_before__ = ftell(__fptr__);
}

bool ios::fstream::isBinary() { return __binary__; }

ios::fstream::~fstream()
{
    fflush(__fptr__);
    fclose(__fptr__);
}

/////////////////////////////////////////////////////////////////////////////////
ios::ifstream::ifstream(const ios::Url &url) : fstream(url.c_str(), ios::base::in) {}
ios::ifstream::ifstream(const ios::Url &url, bool binary) : fstream(url.c_str(), ios::base::in | ios::base(binary ? ios::base::bin : 0)) {}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////Operadores In////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
ios::ifstream &ios::operator>>(ios::ifstream &is, char *&__str)
{
    std::string __str_;
    is >> __str_;
    __str = const_cast<char *>(__str_.c_str());
    return is;
}
ios::ifstream &ios::operator>>(ios::ifstream &is, std::string &__str)
{
    char __c;
    while ((__c = fgetc(is.__fptr__)) != EOF && __c != is.__endstr__)
        __str.push_back(__c);
    return is;
}
ios::ifstream &ios::operator>>(ios::ifstream &is, std::wstring &__str)
{
    wchar_t __c;
    while ((__c = fgetwc(is.__fptr__)) != EOF && __c != is.__endstr__)
        __str.push_back(__c);
    return is;
}
ios::ifstream &ios::operator>>(ios::ifstream &is, stringbuffer &__str)
{
    char __c;
    size_t position = 0;
    while ((__c = fgetc(is.__fptr__)) != EOF && __c != is.__endstr__ && position < __str.size())
        __str[position++] = __c;
    return is;
}

ios::ifstream &ios::operator>>(ifstream &is, wstringbuffer &__str)
{
    wchar_t __c;
    size_t position = 0;
    while ((__c = fgetwc(is.__fptr__)) != EOF && __c != is.__endstr__ && position < __str.size())
        __str[position++] = __c;
    return is;
}

ios::ifstream &ios::operator>>(ios::ifstream &is, int &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(int), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en int ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtol(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
ios::ifstream &ios::operator>>(ios::ifstream &is, unsigned int &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(int), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en unsigned int ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtoul(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
ios::ifstream &ios::operator>>(ios::ifstream &is, char &__n)
{
    if ((fread(&__n, sizeof(char), 1, is.__fptr__)) != 1)
        throw std::runtime_error("Fallo la operacion de lectura en char ios::operator>>");
    return is;
}

ios::ifstream &ios::operator>>(ios::ifstream &is, wchar_t &__n)
{
    if ((fwrite(&__n, sizeof(wchar_t), 1, is.__fptr__)) != 1)
        throw std::runtime_error("Fallo la operacion de lectura en wchar_t ios::operator>>");
    return is;
}

ios::ifstream &ios::operator>>(ios::ifstream &is, unsigned char &__n)
{
    if ((fread(&__n, sizeof(char), 1, is.__fptr__)) != 1)
        throw std::runtime_error("Fallo la operacion de lectura en char ios::operator>>");
    return is;
}
ios::ifstream &ios::operator>>(ios::ifstream &is, long &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(long), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en long ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtol(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
ios::ifstream &ios::operator>>(ios::ifstream &is, unsigned long &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(long), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en unsigned long ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtoul(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
ios::ifstream &ios::operator>>(ios::ifstream &is, long long &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(long long), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en long long ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtoll(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
ios::ifstream &ios::operator>>(ios::ifstream &is, unsigned long long &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(long long), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en unsigned long long ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtoull(cstr__n_.c_str(), nullptr, 10);
    }
    return is;
}
ios::ifstream &ios::operator>>(ios::ifstream &is, float &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(float), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en float ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtof(cstr__n_.c_str(), nullptr);
    }
    return is;
}
ios::ifstream &ios::operator>>(ios::ifstream &is, double &__n)
{
    if (is.__binary__)
    {
        if ((fread(&__n, sizeof(double), 1, is.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de lectura en double ios::operator>>");
    }
    else
    {
        std::string cstr__n_;
        is >> cstr__n_;
        __n = std::strtod(cstr__n_.c_str(), nullptr);
    }
    return is;
}
// ios::ifstream &ios::operator>>(ios::ifstream& is, const std::istream &ins) {
//     //Don't touch this code
//     // std::streamsize size = ins.gcount();
//     // char* str = new char[size + 1];
//     // str[size] = 0;
//     // ins.
// }

ios::ofstream::ofstream(const ios::Url &url) : fstream(url.c_str(), ios::base::app) {}
ios::ofstream::ofstream(const ios::Url &url, bool binary) : fstream(url.c_str(), ios::base::app | ios::base(binary ? ios::base::bin : 0)) {}
ios::ofstream::ofstream(const ios::Url &url, ios::base __mode)
{
    if (!(__mode & 0b10 || __mode & 0b100))
        throw std::runtime_error("Error: Debegate mode for this constructor");
    fstream(url.c_str(), __mode);
}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////Operadores Out///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
ios::ofstream &ios::operator<<(ios::ofstream &os, const char *__str)
{
    size_t n_elements = std::strlen(__str);
    if ((fwrite(__str, sizeof(char), n_elements, os.__fptr__)) != n_elements)
        throw std::runtime_error("Fallo la operacion de escritura en const char* ios::operator<<");
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const std::string __str)
{
    if ((fwrite(__str.c_str(), sizeof(char), __str.size(), os.__fptr__)) != __str.size())
        throw std::runtime_error("Fallo la operacion de escritura en const std::string ios::operator<<");
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const std::wstring __str)
{
    if ((fwrite(__str.c_str(), sizeof(wchar_t), __str.size(), os.__fptr__)) != __str.size())
        throw std::runtime_error("Fallo la operacion de escritura en const std::wstring ios::operator<<");
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const stringbuffer &__str)
{
    if ((fwrite(__str.c_str(), sizeof(char), __str.size(), os.__fptr__)) != __str.size())
        throw std::runtime_error("Fallo la operacion de escritura en stringbuffer ios::operator<<");
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const wstringbuffer &__str)
{
    if ((fwrite(__str.c_str(), sizeof(wchar_t), __str.size(), os.__fptr__)) != __str.size())
        throw std::runtime_error("Fallo la operacion de escritura en stringbuffer ios::operator<<");
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const int __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(int), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en int ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en int ios::operator<<");
    }
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const unsigned int __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(unsigned int), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en unsigned int ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en unsigned int ios::operator<<");
    }
    return os;
}

ios::ofstream &ios::operator<<(ios::ofstream &os, const char __n)
{
    if ((fwrite(&__n, sizeof(char), 1, os.__fptr__)) != 1)
        throw std::runtime_error("Fallo la operacion de escritura en char ios::operator<<");
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const unsigned char __n)
{
    if ((fwrite(&__n, sizeof(char), 1, os.__fptr__)) != 1)
        throw std::runtime_error("Fallo la operacion de escritura en char ios::operator<<");
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const wchar_t __n)
{
    if ((fwrite(&__n, sizeof(wchar_t), 1, os.__fptr__)) != 1)
        throw std::runtime_error("Fallo la operacion de escritura en wchar_t ios::operator<<");
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const long __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(long), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en long ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en long ios::operator<<");
    }
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const unsigned long __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(unsigned long), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en unsigned long ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en unsigned long ios::operator<<");
    }
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const long long __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(long long), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en long long ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en long long ios::operator<<");
    }
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const unsigned long long __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(unsigned long long), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en unsigned long long ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en unsigned long long ios::operator<<");
    }
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const float __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(float), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en float ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en float ios::operator<<");
    }
    return os;
}
ios::ofstream &ios::operator<<(ios::ofstream &os, const double __n)
{
    if (os.__binary__)
    {
        if ((fwrite(&__n, sizeof(double), 1, os.__fptr__)) != 1)
            throw std::runtime_error("Fallo la operacion de escritura en double ios::operator<<");
    }
    else
    {
        std::string cstr__n_ = std::to_string(__n);
        if ((fwrite(cstr__n_.c_str(), sizeof(char), cstr__n_.size(), os.__fptr__)) != cstr__n_.size())
            throw std::runtime_error("Fallo la operacion de escritura en double operator<<");
    }
    return os;
}

ios::iofstream::iofstream(const ios::Url &url)
{
    __syncroned__file__input__output__ = nullptr;
    __output__ = new ofstream(url);
    __input__ = new ifstream(url);
    __syncroned_input_output_system__ = false;
}
ios::iofstream::iofstream(const ios::Url &url, bool binary, bool syncroned_input_output_system)
{
    __syncroned__file__input__output__ = (syncroned_input_output_system ? new fstream(url.c_str(), binary ? ios::base::in : ios::base::out) : nullptr);
    __output__ = new ofstream(url, binary);
    __input__ = new ifstream(url, binary);
    __syncroned_input_output_system__ = syncroned_input_output_system;
}

ios::iofstream::iofstream(const ios::iofstream &other) : __input__()
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
ios::iofstream::iofstream(ios::iofstream &&other)
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

ios::ifstream &ios::iofstream::in()
{
    return (__syncroned_input_output_system__ ? *static_cast<ios::ifstream *>(__syncroned__file__input__output__) : *__input__);
}
ios::ofstream &ios::iofstream::out()
{
    return (__syncroned_input_output_system__ ? *static_cast<ios::ofstream *>(__syncroned__file__input__output__) : *__output__);
}
bool ios::iofstream::isBinaryFile()
{
    return (__syncroned_input_output_system__ ? __syncroned__file__input__output__->isBinary() : __input__->__binary__ & __output__->__binary__);
}

void ios::iofstream::setSyncronedInputOutputSystem(bool __v, ios::fstream &Syncroned_fstream_reference)
{
    if (__syncroned__file__input__output__ == nullptr && __v)
    {
        __syncroned__file__input__output__ = new fstream();
        ios::fstream::copy(__syncroned__file__input__output__, *__input__);
    }
    __syncroned_input_output_system__ = __v;
}
