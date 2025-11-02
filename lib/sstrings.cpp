#include <stda/sstrings/sstrings.hpp>

void sstring::removeespaces(std::string &str)
{
    size_t i = 0;
    while (i < str.size())
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\n')
            str.erase(str.begin() + i);
        else
            i++;
    }
}
void sstring::removeespaces(std::wstring &str)
{
    size_t i = 0;
    while (i < str.size())
    {
        if (str[i] == L' ' || str[i] == L'\t' || str[i] == L'\n' || str[i] == L'\n')
            str.erase(str.begin() + i);
        else
            i++;
    }
}
/////////////////////////////////////
void sstring::removebeginespaces(std::string &str)
{
    while (str.begin() != str.end())
    {
        if (*str.begin() == ' ' || *str.begin() == '\t' || *str.begin() == '\n' || *str.begin() == '\n')
            str.erase(str.begin());
        else
            break;
    }
}
void sstring::removebeginespaces(std::wstring &str)
{
    while (str.begin() != str.end())
    {
        if (*str.begin() == L' ' || *str.begin() == L'\t' || *str.begin() == L'\n' || *str.begin() == L'\n')
            str.erase(str.begin());
        else
            break;
    }
}
/////////////////////////////////////
bool sstring::isalfanum(char caracter)
{
    return ((caracter > 47 && caracter < 58) || (caracter > 64 && caracter < 91) || (caracter > 96 && caracter < 123));
}
bool sstring::isalfanum(wchar_t caracter)
{
    return ((caracter > 47 && caracter < 58) || (caracter > 64 && caracter < 91) || (caracter > 96 && caracter < 123));
}
bool sstring::isalfanum(const std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
        if (!isalfanum(str[i]))
            return false;
    return true;
}
bool sstring::isalfanum(const std::wstring &str)
{
    for (size_t i = 0; i < str.size(); i++)
        if (!isalfanum(str[i]))
            return false;
    return true;
}
/////////////////////////////////////
void sstring::tooper(std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
        if (str[i] > 96 && str[i] < 123)
            str[i] = 'A' + (str[i] - 'a');
}
/////////////////////////////////////
void sstring::word(const char *sources, char *&destine, size_t index)
{
    const char *base = sources + index;
    size_t counter = 0;
    while (!isalfanum(*base))
    {
        counter++;
        base++;
    }
    destine = new char[counter + 1];
    destine[counter] = 0;
    std::strncpy(destine, sources + index, counter);
}
void sstring::word(const wchar_t *sources, wchar_t *&destine, size_t index)
{
    const wchar_t *base = sources + index;
    size_t counter = 0;
    while (isalfanum(*base))
    {
        counter++;
        base++;
    }
    destine = new wchar_t[counter + 1];
    destine[counter] = 0;
    std::wcsncpy(destine, sources + index, counter);
}
void sstring::word(const std::string &sources, std::string &destine, size_t index)
{
    for (size_t i = index; i < sources.size(); i++)
    {
        if (isalfanum(sources[i]))
            destine.push_back(sources[i]);
        else
            break;
    }
}
void sstring::word(const std::wstring &sources, std::wstring &destine, size_t index)
{
    for (size_t i = index; i < sources.size(); i++)
    {
        if (isalfanum(sources[i]))
            destine.push_back(sources[i]);
        else
            break;
    }
}
void sstring::word(const stringbuffer &sources, stringbuffer &destine, size_t index)
{
    size_t counter = 0;
    while (isalfanum(sources.at(index++)))
        counter++;
    destine = stringbuffer(counter);
    destine.copy(sources, counter);
}
void sstring::word(const wstringbuffer &sources, wstringbuffer &destine, size_t index)
{
    size_t counter = 0;
    while (isalfanum(sources.at(index++)))
        counter++;
    destine = wstringbuffer(counter);
    destine.copy(sources, counter);
}

/////////////////////////////////////
void sstring::reverse(const char *sources, char *&destine)
{
    size_t size = std::strlen(sources), count = 0;
    const char *rsources = sources + size;
    destine = new char[size + 1];
    destine[size] = 0;
    while (rsources != sources)
    {
        destine[count] = *rsources;
        count++;
        rsources--;
    }
}
void sstring::reverse(const wchar_t *sources, wchar_t *&destine)
{
    size_t size = std::wcslen(sources), count = 0;
    const wchar_t *rsources = sources + size;
    destine = new wchar_t[size + 1];
    destine[size] = 0;
    while (rsources != sources)
    {
        destine[count] = *rsources;
        count++;
        rsources--;
    }
}
void sstring::reverse(const std::string &sources, std::string &destine)
{
    size_t size = sources.size();
    for (size_t count = 0; count < size; count++)
        destine.push_back(sources[size - 1 - count]);
}
void sstring::reverse(const std::wstring &sources, std::wstring &destine)
{
    size_t size = sources.size();
    for (size_t count = 0; count < size; count++)
        destine.push_back(sources[size - 1 - count]);
}
void sstring::reverse(const stringbuffer &sources, stringbuffer &destine)
{
    destine = stringbuffer(sources.size());
    size_t count = 0;
    for (auto &&caracter : stringbuffer::reverse(sources))
        destine[count++] = caracter;
}
void sstring::reverse(const wstringbuffer &sources, wstringbuffer &destine)
{
    destine = wstringbuffer(sources.size());
    size_t count = 0;
    for (auto &&caracter : wstringbuffer::reverse(sources))
        destine[count++] = caracter;
}
/////////////////////////////////////
void sstring::replaceAll(char *str, char find, char replacer)
{
    char *pivot = str;
    while (*pivot != 0)
    {
        if (*pivot == find)
            *pivot = replacer;
        pivot++;
    }
}
void sstring::replaceAll(wchar_t *str, wchar_t find, wchar_t replacer)
{
    wchar_t *pivot = str;
    while (*pivot != 0)
    {
        if (*pivot == find)
            *pivot = replacer;
        pivot++;
    }
}
void sstring::replaceAll(std::string &str, char find, char replacer)
{
    for (auto &&i : str)
        if (find == i)
            i = replacer;
}
void sstring::replaceAll(std::wstring &str, wchar_t find, wchar_t replacer)
{
    for (auto &&i : str)
        if (find == i)
            i = replacer;
}
void sstring::replaceAll(stringbuffer &str, char find, char replacer)
{
    for (auto &&i : str)
        if (find == i)
            i = replacer;
}
void sstring::replaceAll(wstringbuffer &str, wchar_t find, wchar_t replacer)
{
    for (auto &&i : str)
        if (find == i)
            i = replacer;
}
/////////////////////////////////////
size_t sstring::find_frist_of(const char *str, char caracter, size_t position)
{
    const char *pivot = str + position;
    while (*pivot != 0)
    {
        if (*pivot == caracter) return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
size_t sstring::find_frist_of(const char *str, bool (*cmp)(char), size_t position)
{
    const char *pivot = str + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot)) return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
size_t sstring::find_frist_of(const wchar_t *str, wchar_t caracter, size_t position) {
    const wchar_t *pivot = str + position;
    while (*pivot != 0)
    {
        if (*pivot == caracter) return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
size_t sstring::find_frist_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position) {
    const wchar_t *pivot = str + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot)) return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
/////////////////////////////////////
size_t sstring::find_frist_not_of(const char *str, char caracter, size_t position) {
    const char *pivot = str + position;
    while (*pivot != 0)
    {
        if (*pivot != caracter) return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
size_t sstring::find_frist_not_of(const char *str, bool (*cmp)(char), size_t position) {
    const char *pivot = str + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot)) return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
size_t sstring::find_frist_not_of(const wchar_t *str, wchar_t caracter, size_t position) {
    const wchar_t *pivot = str + position;
    while (*pivot != 0)
    {
        if (*pivot != caracter) return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
size_t sstring::find_frist_not_of(const wchar_t *str, bool(*cmp)(wchar_t), size_t position) {
    const wchar_t *pivot = str + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot)) return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
/////////////////////////////////////
size_t sstring::find_last_of(const char *str, char caracter, size_t position)
{
    if(position == size_t(-1)) position = std::strlen(str);
    const char *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (*pivot == caracter) return pivot - str;
    }
    return size_t(-1);
}
size_t sstring::find_last_of(const char *str, bool(*cmp)(char), size_t position)
{
    if(position == size_t(-1)) position = std::strlen(str);
    const char *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (cmp(*pivot)) return pivot - str;
    }
    return size_t(-1);
}
size_t sstring::find_last_of(const wchar_t *str, wchar_t caracter, size_t position) {
    if(position == size_t(-1)) position = std::wcslen(str);
    const wchar_t *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (*pivot == caracter) return pivot - str;
    }
    return size_t(-1);
}
size_t sstring::find_last_of(const wchar_t *str, bool(*cmp)(wchar_t), size_t position) {
    if(position == size_t(-1)) position = std::wcslen(str);
    const wchar_t *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (cmp(*pivot)) return pivot - str;
    }
    return size_t(-1);
}
/////////////////////////////////////
size_t sstring::find_last_not_of(const char *str, char caracter, size_t position) {
    if(position == size_t(-1)) position = std::strlen(str);
    const char *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (*pivot != caracter) return pivot - str;
    }
    return size_t(-1);
}
size_t sstring::find_last_not_of(const char *str, bool(*cmp)(char), size_t position) {
    if(position == size_t(-1)) position = std::strlen(str);
    const char *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (cmp(*pivot)) return pivot - str;
    }
    return size_t(-1);
}
size_t sstring::find_last_not_of(const wchar_t *str, wchar_t caracter, size_t position) {
    if(position == size_t(-1)) position = std::wcslen(str);
    const wchar_t *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (*pivot != caracter) return pivot - str;
    }
    return size_t(-1);
}
size_t sstring::find_last_not_of(const wchar_t *str, bool(*cmp)(wchar_t), size_t position) {
    if(position == size_t(-1)) position = std::wcslen(str);
    const wchar_t *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (cmp(*pivot)) return pivot - str;
    }
    return size_t(-1);
}
/////////////////////////////////////