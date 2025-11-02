#include <stda/sstrings/converter.hpp>

wchar_t *stringconverter::convert_ascii_to_uft8(const char *str, bool freeMemory)
{
    size_t size = strlen(str);
    const char *__p__str = str;
    wchar_t *wstr = new wchar_t[size + 1];
    for (size_t i = 0; i < size; i++)
        wstr[i] = static_cast<wchar_t>(str[i]);
    wstr[size] = 0;
    if (freeMemory)
        delete[] str;
    return wstr;
}
char *stringconverter::convert_utf8_to_ascii(const wchar_t *wstr, bool freeMemory)
{
    size_t wsize = std::wcslen(wstr);
    char *str = new char[wsize + 1];
    for (size_t i = 0; i < wsize; i++)
        str[i] = static_cast<char>(wstr[i]);
    str[wsize] = 0;
    if (freeMemory)
        delete[] wstr;
    return str;
}
std::wstring stringconverter::convert_string_to_wstring(const std::string &str)
{
    std::wstring wstr = std::wstring();
    wstr.reserve(str.size());
    for (auto &&caracter : str)
        wstr.push_back((wchar_t)(caracter));
    return wstr;
}
std::string stringconverter::convert_wstring_to_string(const std::wstring &wstr)
{
    std::string str = std::string();
    str.reserve(str.size());
    for (auto &&caracter : str)
        str.push_back((char)(caracter));
    return str;
}
wstringbuffer convert_string_to_wstring(const stringbuffer &str)
{
    wstringbuffer wstr(str.size());
    size_t j = 0;
    for (auto &&i : str)
        wstr[j++] = i;
    return wstr;
}
stringbuffer convert_string_to_wstring(const wstringbuffer &wstr)
{
    stringbuffer str(wstr.size());
    size_t j = 0;
    for (auto &&i : str)
        str[j++] = i;
    return str;
}