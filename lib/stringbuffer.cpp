#include <stda/sstrings/stringbuffer.hpp>

stringbuffer::stringbuffer(const char *__str)
{
    size_t size = std::strlen(__str);
    buffer = Trails<char>(size + 1);
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
    buffer = Trails<char>(size + 1);
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
char &stringbuffer::operator[](size_t position)
{
    return buffer[position];
}
const char stringbuffer::at(size_t position) const
{
    return buffer.at(position);
}
void stringbuffer::copy(const stringbuffer &str)
{
    buffer = str.buffer;
}
void stringbuffer::copy(const stringbuffer &str, size_t nelements)
{
    size_t size = ((str.size() > nelements) ? nelements : str.size());
    buffer = Trails<char>(size + 1);
    buffer[size] = '\0';
    std::strncpy(const_cast<char *>(*buffer), str.c_str(), size);
}
stringbuffer stringbuffer::substr(size_t __pos, size_t __n)
{
    Iterators::Iterator<char> point_start = this->begin() + __pos, point_end = point_start;
    if (point_end > this->end())
        throw std::runtime_error("Overflow memory in stringbuffer::substr, pos greather than it end");
    while (point_end != this->end() && (point_end - point_start + __pos) < __n)
        point_end++;
    size_t size = (point_end - point_start);
    stringbuffer new_str = stringbuffer(size);
    new_str.copy(this->c_str() + __pos, size);
    return new_str;
}
/////////////////////////////////////
size_t stringbuffer::find_first_of(char caracter, size_t position)
{
    Iterators::Iterator<char> pivot = this->begin() + position;
    while (*pivot != 0)
    {
        if (*pivot == caracter)
            return pivot - this->begin();
        pivot++;
    }
    return stringbuffer::npos;
}
size_t stringbuffer::find_first_of(bool (*cmp)(char), size_t position)
{
    Iterators::Iterator<char> pivot = this->begin() + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot))
            return pivot - this->begin();
        pivot++;
    }
    return stringbuffer::npos;
}
size_t stringbuffer::find_first_not_of(char caracter, size_t position)
{
    Iterators::Iterator<char> pivot = this->begin() + position;
    while (*pivot != 0)
    {
        if (*pivot != caracter)
            return pivot - this->begin();
        pivot++;
    }
    return stringbuffer::npos;
}
size_t stringbuffer::find_first_not_of(bool (*cmp)(char), size_t position)
{
    Iterators::Iterator<char> pivot = this->begin() + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot))
            return pivot - this->begin();
        pivot++;
    }
    return stringbuffer::npos;
}
size_t stringbuffer::find_last_of(char caracter, size_t position)
{
    Iterators::Iterator<char> point = end() + position;
    if (point > end())
        throw std::runtime_error("Overflow memory in stringbuffer::substr, pos greather than it end");
    while (point != begin())
    {
        point--;
        if (*point == caracter)
            return point - begin();
    }
    return stringbuffer::npos;
}
size_t stringbuffer::find_last_of(bool (*cmp)(char), size_t position)
{
    Iterators::Iterator<char> point = end() + position;
    if (point > end())
        throw std::runtime_error("Overflow memory in stringbuffer::substr, pos greather than it end");
    while (point != begin())
    {
        point--;
        if (cmp(*point))
            return point - begin();
    }
    return stringbuffer::npos;
}
size_t stringbuffer::find_last_not_of(char caracter, size_t position)
{
    Iterators::Iterator<char> point = end() + position;
    if (point > end())
        throw std::runtime_error("Overflow memory in stringbuffer::substr, pos greather than it end");
    while (point != begin())
    {
        point--;
        if (*point != caracter)
            return point - begin();
    }
    return stringbuffer::npos;
}
size_t stringbuffer::find_last_not_of(bool (*cmp)(char), size_t position)
{
    Iterators::Iterator<char> point = end() + position;
    if (point > end())
        throw std::runtime_error("Overflow memory in stringbuffer::substr, pos greather than it end");
    while (point != begin())
    {
        point--;
        if (cmp(*point))
            return point - begin();
    }
    return stringbuffer::npos;
}

wstringbuffer::wstringbuffer(const wchar_t *__str)
{
    size_t size = std::wcslen(__str);
    buffer = Trails<wchar_t>(size + 1);
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
    buffer = Trails<wchar_t>(size + 1);
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
wchar_t &wstringbuffer::operator[](size_t position)
{
    return buffer[position];
}
const wchar_t wstringbuffer::at(size_t position) const
{
    return buffer.at(position);
}
void wstringbuffer::copy(const wstringbuffer &str)
{
    buffer = str.buffer;
}
void wstringbuffer::copy(const wstringbuffer &str, size_t nelements)
{
    size_t size = ((str.size() > nelements) ? nelements : str.size());
    buffer = Trails<wchar_t>(size + 1);
    buffer[size] = '\0';
    std::wcsncpy(const_cast<wchar_t *>(*buffer), str.c_str(), size);
}
wstringbuffer wstringbuffer::substr(size_t __pos, size_t __n)
{
    Iterators::Iterator<wchar_t> point_start = this->begin() + __pos, point_end = point_start;
    if (point_end > this->end())
        throw std::runtime_error("Overflow memory in stringbuffer::substr, pos greather than it end");
    while (point_end != this->end() && (point_end - point_start + __pos) < __n)
        point_end++;
    size_t size = (point_end - point_start);
    wstringbuffer new_str = wstringbuffer(size);
    new_str.copy(this->c_str() + __pos, size);
    return new_str;
}
size_t wstringbuffer::find_first_of(wchar_t caracter, size_t position)
{
    Iterators::Iterator<wchar_t> pivot = this->begin() + position;
    while (*pivot != 0)
    {
        if (*pivot == caracter)
            return pivot - this->begin();
        pivot++;
    }
    return wstringbuffer::npos;
}
size_t wstringbuffer::find_first_of(bool (*cmp)(wchar_t), size_t position)
{
    Iterators::Iterator<wchar_t> pivot = this->begin() + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot))
            return pivot - this->begin();
        pivot++;
    }
    return wstringbuffer::npos;
}
size_t wstringbuffer::find_first_not_of(wchar_t caracter, size_t position)
{
    Iterators::Iterator<wchar_t> pivot = this->begin() + position;
    while (*pivot != 0)
    {
        if (*pivot != caracter)
            return pivot - this->begin();
        pivot++;
    }
    return wstringbuffer::npos;
}
size_t wstringbuffer::find_first_not_of(bool (*cmp)(wchar_t), size_t position)
{
    Iterators::Iterator<wchar_t> pivot = this->begin() + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot))
            return pivot - this->begin();
        pivot++;
    }
    return wstringbuffer::npos;
}
size_t wstringbuffer::find_last_of(wchar_t caracter, size_t position)
{
    Iterators::Iterator<wchar_t> point = end() + position;
    if (point > end())
        throw std::runtime_error("Overflow memory in wstringbuffer::substr, pos greather than it end");
    while (point != begin())
    {
        point--;
        if (*point == caracter)
            return point - begin();
    }
    return wstringbuffer::npos;
}
size_t wstringbuffer::find_last_of(bool (*cmp)(wchar_t), size_t position)
{
    Iterators::Iterator<wchar_t> point = end() + position;
    if (point > end())
        throw std::runtime_error("Overflow memory in wstringbuffer::substr, pos greather than it end");
    while (point != begin())
    {
        point--;
        if (cmp(*point))
            return point - begin();
    }
    return wstringbuffer::npos;
}
size_t wstringbuffer::find_last_not_of(wchar_t caracter, size_t position)
{
    Iterators::Iterator<wchar_t> point = end() + position;
    if (point > end())
        throw std::runtime_error("Overflow memory in wstringbuffer::substr, pos greather than it end");
    while (point != begin())
    {
        point--;
        if (*point != caracter)
            return point - begin();
    }
    return wstringbuffer::npos;
}
size_t wstringbuffer::find_last_not_of(bool (*cmp)(wchar_t), size_t position)
{
    Iterators::Iterator<wchar_t> point = end() + position;
    if (point > end())
        throw std::runtime_error("Overflow memory in wstringbuffer::substr, pos greather than it end");
    while (point != begin())
    {
        point--;
        if (cmp(*point))
            return point - begin();
    }
    return wstringbuffer::npos;
}