#include <cstring>
#include <iostream>
#include <stdexcept>
#include <stda/trails/trails.hpp>

#ifndef STRINGBUFFER
#define STRINGBUFFER

class stringbuffer
{
private:
    trails<char> buffer;
public:
    stringbuffer() : buffer() {}
    stringbuffer(size_t size) : buffer(size + 1) {}
    stringbuffer(const char *__str);
    stringbuffer(const char *__str, size_t size);
    stringbuffer(const stringbuffer& other);
    stringbuffer(stringbuffer&& other);
    stringbuffer& operator=(const stringbuffer& other);
    stringbuffer& operator=(stringbuffer&& other);
    const char* c_str() const {return *buffer;}
    char& operator[](size_t position);
    const char at(size_t position) const;
    bool empty() const {return buffer.empty();}
    size_t size() const {return ((buffer.empty()) ? 0 : buffer.size() - 1);}
    void copy(const char *__str);
    void copy(const char *__str, size_t nelements);
    void copy(const stringbuffer& str);
    void copy(const stringbuffer& str, size_t nelements);
    friend std::ostream &operator<<(std::ostream &os, const stringbuffer& str)
    {
        os << *str.buffer;
        return os;
    }
    class reverse
    {
    private:
        const char *__arrarptr__;
        size_t __size__;

    public:
        reverse(const stringbuffer& __base) : __arrarptr__(*__base.buffer), __size__(__base.size()) {}
        iterators::reverse_iterator<char> begin() const { return iterators::reverse_iterator<char>(__arrarptr__ ? nullptr : __arrarptr__ + __size__ - 1); }
        iterators::reverse_iterator<char> end() const { return iterators::reverse_iterator<char>(__arrarptr__ ? nullptr : __arrarptr__ - 1); }
        ~reverse() {}
    };
    iterators::iterator<char> begin() const { return iterators::iterator<char>(empty() ? nullptr : *buffer); }
    iterators::iterator<char> end() const { return iterators::iterator<char>(empty() ? nullptr : *buffer + buffer.size()); }

    iterators::reverse_iterator<char> rbegin() const { return iterators::reverse_iterator<char>(empty() ? nullptr : *buffer + buffer.size() - 1); }
    iterators::reverse_iterator<char> rend() const { return iterators::reverse_iterator<char>(empty() ? nullptr : *buffer - 1); }
    ~stringbuffer() {}
};

class wstringbuffer
{
private:
    trails<wchar_t> buffer;
public:
    wstringbuffer() : buffer() {}
    wstringbuffer(size_t size) : buffer(size + 1) {}
    wstringbuffer(const wchar_t *__str);
    wstringbuffer(const wchar_t *__str, size_t size);
    wstringbuffer(const wstringbuffer& other);
    wstringbuffer(wstringbuffer&& other);
    wstringbuffer& operator=(const wstringbuffer& other);
    wstringbuffer& operator=(wstringbuffer&& other);
    const wchar_t* c_str() const {return *buffer;}
    wchar_t& operator[](size_t position);
    const wchar_t at(size_t position) const;
    bool empty() const {return buffer.empty();}
    size_t size() const {return (buffer.empty() ? 0 : buffer.size() - 1);}
    void copy(const wchar_t *__str);
    void copy(const wchar_t *__str, size_t nelements);
    void copy(const wstringbuffer& str);
    void copy(const wstringbuffer& str, size_t nelements);
    friend std::ostream &operator<<(std::ostream &os, const wstringbuffer& str)
    {
        os << *str.buffer;
        return os;
    }
    class reverse
    {
    private:
        const wchar_t *__arrarptr__;
        size_t __size__;

    public:
        reverse(const wstringbuffer& __base) : __arrarptr__(*__base.buffer), __size__(__base.size()) {}
        iterators::reverse_iterator<wchar_t> begin() const { return iterators::reverse_iterator<wchar_t>(__arrarptr__ ? nullptr : __arrarptr__ + __size__ - 1); }
        iterators::reverse_iterator<wchar_t> end() const { return iterators::reverse_iterator<wchar_t>(__arrarptr__ ? nullptr : __arrarptr__ - 1); }
        ~reverse() {}
    };
    iterators::iterator<wchar_t> begin() const { return iterators::iterator<wchar_t>(empty() ? nullptr : *buffer); }
    iterators::iterator<wchar_t> end() const { return iterators::iterator<wchar_t>(empty() ? nullptr : *buffer + buffer.size()); }

    iterators::reverse_iterator<wchar_t> rbegin() const { return iterators::reverse_iterator<wchar_t>(empty() ? nullptr : *buffer + buffer.size() - 1); }
    iterators::reverse_iterator<wchar_t> rend() const { return iterators::reverse_iterator<wchar_t>(empty() ? nullptr : *buffer - 1); }
    ~wstringbuffer() {}
};

#endif