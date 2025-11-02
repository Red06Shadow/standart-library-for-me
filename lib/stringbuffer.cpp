#include <stda/sstrings/stringbuffer.hpp>

stringbuffer::stringbuffer(const char *__str)
{
    size_t size = std::strlen(__str);
    buffer = trails<char>(size + 1);
    buffer[size] = '\0';
    std::strcpy(const_cast<char *>(*buffer), __str);
}

stringbuffer::stringbuffer(const char *__str, size_t size)
{
    if (size == 0)
        return;
    if (!__str)
        throw std::runtime_error("Array sources is null");
    size_t size__str = std::strlen(__str);
    buffer = trails<char>(size + 1);
    buffer[size] = '\0';
    std::strncpy(const_cast<char *>(*buffer), __str, ((size > size__str) ? size__str : size));
}
stringbuffer::stringbuffer(const stringbuffer &other) : buffer(other.buffer) {}
stringbuffer::stringbuffer(stringbuffer &&other) : buffer(std::move(other.buffer)) {}
stringbuffer &stringbuffer::operator=(const stringbuffer &other)
{
    if (this != &other)
    {
        buffer = other.buffer;
    }
    return *this;
}
stringbuffer &stringbuffer::operator=(stringbuffer &&other)
{
    if (this != &other)
    {
        buffer = std::move(other.buffer);
    }
    return *this;
}
void stringbuffer::copy(const char *__str)
{
    *this = stringbuffer(__str);
}
void stringbuffer::copy(const char *__str, size_t nelements)
{
    *this = stringbuffer(__str, nelements);
}
char& stringbuffer::operator[](size_t position) {
    return buffer[position];
}
const char stringbuffer::at(size_t position) const {
    return buffer.at(position);
}
void stringbuffer::copy(const stringbuffer& str) {
    buffer = str.buffer;
}
void stringbuffer::copy(const stringbuffer& str, size_t nelements) {
    size_t size = ((str.size() > nelements) ? nelements : str.size());
    buffer = trails<char>(size + 1);
    buffer[size] = '\0';
    std::strncpy(const_cast<char *>(*buffer), str.c_str(), size);
}


wstringbuffer::wstringbuffer(const wchar_t *__str)
{
    size_t size = std::wcslen(__str);
    buffer = trails<wchar_t>(size + 1);
    buffer[size] = '\0';
    std::wcscpy(const_cast<wchar_t *>(*buffer), __str);
}

wstringbuffer::wstringbuffer(const wchar_t *__str, size_t size)
{
    if (size == 0)
        return;
    if (!__str)
        throw std::runtime_error("Array sources is null");
    size_t size__str = std::wcslen(__str);
    buffer = trails<wchar_t>(size + 1);
    buffer[size] = '\0';
    std::wcsncpy(const_cast<wchar_t *>(*buffer), __str, ((size > size__str) ? size__str : size));
}
wstringbuffer::wstringbuffer(const wstringbuffer &other) : buffer(other.buffer) {}
wstringbuffer::wstringbuffer(wstringbuffer &&other) : buffer(std::move(other.buffer)) {}
wstringbuffer &wstringbuffer::operator=(const wstringbuffer &other)
{
    if (this != &other)
    {
        buffer = other.buffer;
    }
    return *this;
}
wstringbuffer &wstringbuffer::operator=(wstringbuffer &&other)
{
    if (this != &other)
    {
        buffer = std::move(other.buffer);
    }
    return *this;
}
void wstringbuffer::copy(const wchar_t *__str)
{
    *this = wstringbuffer(__str);
}
void wstringbuffer::copy(const wchar_t *__str, size_t nelements)
{
    *this = wstringbuffer(__str, nelements);
}
wchar_t& wstringbuffer::operator[](size_t position) {
    return buffer[position];
}
const wchar_t wstringbuffer::at(size_t position) const {
    return buffer.at(position);
}
void wstringbuffer::copy(const wstringbuffer& str) {
    buffer = str.buffer;
}
void wstringbuffer::copy(const wstringbuffer& str, size_t nelements) {
    size_t size = ((str.size() > nelements) ? nelements : str.size());
    buffer = trails<wchar_t>(size + 1);
    buffer[size] = '\0';
    std::wcsncpy(const_cast<wchar_t *>(*buffer), str.c_str(), size);
}