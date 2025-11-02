#include <stda/sstrings/stringbuffer.hpp>

stringbuffer::stringbuffer(const char *__str)
{
    *this = __str;
}

stringbuffer::stringbuffer(const char *__str, size_t size)
{
    if (size == 0)
        return;
    if (!__str)
        throw std::runtime_error("Array sources is null");
    size_t size__str = std::strlen(__str);
    __size__ = size;
    __array__ = new char[size + 1];
    __array__[size] = '\0';
    std::strncpy(__array__, __str, ((size > size__str) ? size__str:size));
}

stringbuffer &stringbuffer::operator=(const stringbuffer &__other)
{
    if (this != &__other)
    {
        if (__array__ != nullptr)
            delete[] (__array__);
        __size__ = __other.__size__;
        if (__size__ > 0)
        {
            __array__ = new char[__size__ + 1];
            __array__[__size__] = '\0';
            std::strncpy(__array__, __other.__array__, __size__);
        }
        else
        {
            __array__ = nullptr;
        }
    }
    return *this;
}
stringbuffer &stringbuffer::operator=(const char *__other)
{
    if (this->__array__ != __other)
    {
        if (__array__ != nullptr)
            delete[] (__array__);
        __size__ = std::strlen(__other);
        if (__size__ > 0)
        {
            __array__ = new char[__size__ + 1];
            __array__[__size__] = '\0';
            std::strcpy(__array__, __other);
        }
        else
        {
            __array__ = nullptr;
        }
    }
    return *this;
}
void stringbuffer::assing(const char *__str)
{
    this->operator=(__str);
}
void stringbuffer::assing(const stringbuffer &__other)
{
    this->operator=(__other);
}
void stringbuffer::copy(const char *__str)
{
    delete[] __array__;
    __size__ = std::strlen(__str);
    __array__ = new char[__size__ + 1];
    __array__[__size__] = '\0';
    std::strcpy(__array__, __str);
}
void stringbuffer::copy(const char *__str, size_t nelements)
{
    __array__;
    if (nelements > std::strlen(__str))
        throw std::runtime_error("Error: Oversize to the size of __str");
    __size__ = nelements;
    __array__ = new char[__size__ + 1];
    __array__[__size__] = '\0';
    std::strncpy(__array__, __str, nelements);
}
void stringbuffer::copy(const stringbuffer &__str)
{
    this->copy(__str.c_str(), __str.__size__);
}
void stringbuffer::copy(const stringbuffer &__str, size_t nelements)
{
    this->copy(__str.c_str(), nelements);
}

wstringbuffer::wstringbuffer(const wchar_t *__str)
{
    *this = __str;
}

wstringbuffer::wstringbuffer(const wchar_t *__str, size_t size)
{
    if (size == 0)
        return;
    if (!__str)
        throw std::runtime_error("Array sources is null");
    size_t size__str = std::wcslen(__str);
    __size__ = size;
    __array__ = new wchar_t[size + 1];
    __array__[size] = L'\0';
    std::wcsncpy(__array__, __str, ((size > size__str) ? size__str:size));
}

wstringbuffer &wstringbuffer::operator=(const wstringbuffer &__other)
{
    if (this != &__other)
    {
        if (__array__ != nullptr)
            delete[] (__array__);
        __size__ = __other.__size__;
        if (__size__ > 0)
        {
            __array__ = new wchar_t[__size__ + 1];
            __array__[__size__] = L'\0';
            std::wcsncpy(__array__, __other.__array__, __size__);
        }
        else
        {
            __array__ = nullptr;
        }
    }
    return *this;
}
wstringbuffer &wstringbuffer::operator=(const wchar_t *__other)
{
    if (this->__array__ != __other)
    {
        if (__array__ != nullptr)
            delete[] (__array__);
        __size__ = std::wcslen(__other);
        if (__size__ > 0)
        {
            __array__ = new wchar_t[__size__ + 1];
            __array__[__size__] = L'\0';
            std::wcscpy(__array__, __other);
        }
        else
        {
            __array__ = nullptr;
        }
    }
    return *this;
}
void wstringbuffer::assing(const wchar_t *__str)
{
    this->operator=(__str);
}
void wstringbuffer::assing(const wstringbuffer &__other)
{
    this->operator=(__other);
}
void wstringbuffer::copy(const wchar_t *__str)
{
    delete[] (this->__array__);
    __size__ = std::wcslen(__str);
    __array__ = new wchar_t[__size__ + 1];
    __array__[__size__] = L'\0';
    std::wcscpy(__array__, __str);
}
void wstringbuffer::copy(const wchar_t *__str, size_t nelements)
{
    delete[] (this->__array__);
    if (nelements > std::wcslen(__str))
        throw std::runtime_error("Error: Oversize to the size of __str");
    __size__ = nelements;
    __array__ = new wchar_t[__size__ + 1];
    __array__[__size__] = L'\0';
    std::wcsncpy(__array__, __str, nelements);
}
void wstringbuffer::copy(const wstringbuffer &__str)
{
    this->copy(__str.c_str(), __str.__size__);
}
void wstringbuffer::copy(const wstringbuffer &__str, size_t nelements)
{
    this->copy(__str.c_str(), nelements);
}