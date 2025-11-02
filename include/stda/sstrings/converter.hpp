#include <iostream>
#include <cstring>
#include <string>
#include "stringbuffer.hpp"

#ifndef FORMATSTRING
#define FORMATSTRING
namespace stringconverter
{
    wchar_t *convert_ascii_to_uft8(const char *str, bool freeMemory = false);
    std::wstring convert_string_to_wstring(const std::string &str);
    wstringbuffer convert_stringbuffer_to_wstringbuffer(const stringbuffer&);
    //////////////////////////////////////////////////////////////////////////
    char *convert_utf8_to_ascii(const wchar_t *wstr, bool freeMemory = false);
    std::string convert_wstring_to_string(const std::wstring &str);
    stringbuffer convert_wstringbuffer_to_stringbuffer(const wstringbuffer&);
}
#endif