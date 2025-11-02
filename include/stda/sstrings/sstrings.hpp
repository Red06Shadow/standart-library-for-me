#include "stringbuffer.hpp"
#include "converter.hpp"


#ifndef SSTRINGSS
#define SSTRINGSS
namespace sstring
{
    void removeespaces(std::string &str);
    void removeespaces(std::wstring &str);
    /////////////////////////////////////
    void removebeginespaces(std::string &str);
    void removebeginespaces(std::wstring &str);
    /////////////////////////////////////
    bool isalfanum(char caracter);
    bool isalfanum(wchar_t caracter);
    bool isalfanum(const std::string &str);
    bool isalfanum(const std::wstring &str);
    /////////////////////////////////////
    void tooper(std::string &str);
    /////////////////////////////////////
    void word(const char *sources, char *&destine, size_t index = 0);
    void word(const wchar_t *sources, wchar_t *&destine, size_t index = 0);
    void word(const std::string &sources, std::string &destine, size_t index = 0);
    void word(const std::wstring &sources, std::wstring &destine, size_t index = 0);
    void word(const stringbuffer &sources, stringbuffer &destine, size_t index = 0);
    void word(const wstringbuffer &sources, wstringbuffer &destine, size_t index = 0);
    /////////////////////////////////////
    void reverse(const char *str, char *&destine);
    void reverse(const wchar_t *str, wchar_t *&destine);
    void reverse(const std::string &str, std::string &destine);
    void reverse(const std::wstring &str, std::wstring &destine);
    void reverse(const stringbuffer &str, stringbuffer &destine);
    void reverse(const wstringbuffer &str, wstringbuffer &destine);
    /////////////////////////////////////
    void replaceAll(char *str, char find, char replacer);
    void replaceAll(wchar_t *str, wchar_t find, wchar_t replacer);
    void replaceAll(std::string &str, char find, char replacer);
    void replaceAll(std::wstring &str, wchar_t find, wchar_t replacer);
    void replaceAll(stringbuffer &str, char find, char replacer);
    void replaceAll(wstringbuffer &str, wchar_t find, wchar_t replacer);
    /////////////////////////////////////
    size_t find_frist_of(const char *str, char caracter, size_t position = 0);
    size_t find_frist_of(const char *str, bool (*cmp)(char), size_t position = 0);
    size_t find_frist_of(const wchar_t *str, wchar_t caracter, size_t position = 0);
    size_t find_frist_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position = 0);
    /////////////////////////////////////
    size_t find_frist_not_of(const char *str, char caracter, size_t position = 0);
    size_t find_frist_not_of(const char *str, bool (*cmp)(char), size_t position = 0);
    size_t find_frist_not_of(const wchar_t *str, wchar_t caracter, size_t position = 0);
    size_t find_frist_not_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position = 0);
    /////////////////////////////////////
    size_t find_last_of(const char *str, char caracter, size_t position = size_t(-1));
    size_t find_last_of(const char *str, bool (*cmp)(char), size_t position = size_t(-1));
    size_t find_last_of(const wchar_t *str, wchar_t caracter, size_t position = size_t(-1));
    size_t find_last_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position = size_t(-1));
    /////////////////////////////////////
    size_t find_last_not_of(const char *str, char caracter, size_t position = size_t(-1));
    size_t find_last_not_of(const char *str, bool (*cmp)(char), size_t position = size_t(-1));
    size_t find_last_not_of(const wchar_t *str, wchar_t caracter, size_t position = size_t(-1));
    size_t find_last_not_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position = size_t(-1));
    /////////////////////////////////////
} // namespace sstring
#endif