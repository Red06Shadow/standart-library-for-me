#include <stda/sstrings/sstrings.hpp>

void String::remove_espaces(std::string &str)
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
void String::remove_espaces(std::wstring &str)
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
void String::remove_begin_espaces(std::string &str)
{
    while (str.begin() != str.end())
    {
        if (*str.begin() == ' ' || *str.begin() == '\t' || *str.begin() == '\n' || *str.begin() == '\n')
            str.erase(str.begin());
        else
            break;
    }
}
void String::remove_begin_espaces(std::wstring &str)
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
void String::remove_end_espaces(std::string &str)
{
    if (!str.empty())
    {
        do
        {
            if (*(str.end() - 1) != ' ')
                break;
            str.erase(str.end() - 1);
        } while (str.end() != str.begin());
    }
}
void String::remove_end_espaces(std::wstring &str)
{
    if (!str.empty())
    {
        do
        {
            str.erase(str.end());
        } while (str.end() != str.begin());
    }
}
/////////////////////////////////////
bool String::isalfanum(char caracter)
{
    return ((caracter >= '0' && caracter <= '9') || (caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'));
}
bool String::isalfanum(wchar_t caracter)
{
    return ((caracter >= L'0' && caracter <= L'9') || (caracter >= L'A' && caracter <= L'Z') || (caracter >= L'a' && caracter <= L'z'));
}
bool String::isalfanum(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isalfanum(str[i]))
            return false;
    return true;
}
bool String::isalfanum(const std::wstring &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isalfanum(str[i]))
            return false;
    return true;
}
/////////////////////////////////////
bool String::isalfa(char caracter)
{
    return ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'));
}
bool String::isalfa(wchar_t caracter)
{
    return ((caracter >= L'A' && caracter <= L'Z') || (caracter >= L'a' && caracter <= L'z'));
}
bool String::isalfa(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isalfa(str[i]))
            return false;
    return true;
}
bool String::isalfa(const std::wstring &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isalfa(str[i]))
            return false;
    return true;
}
/////////////////////////////////////
bool String::isnum(char caracter)
{
    return (caracter >= '0' && caracter <= '9');
}
bool String::isnum(wchar_t caracter)
{
    return (caracter >= L'0' && caracter <= L'9');
}
bool String::isnum(const std::string &str, unsigned char base)
{
    switch (base)
    {
    case 2:
        return String::isnum_binary(str);
        break;
    case 8:
        return String::isnum_octal(str);
        break;
    case 10:
    {
        return String::isnum_decimal(str);
        break;
    }
    case 16:
        return String::isnum_hexadecimal(str);
        break;
    case 'e':
        return String::isnum_exponente(str);
        break;
    case 'E':
        return String::isnum_exponente(str);
        break;
    default:
        throw std::runtime_error("No se inserto una base valida en String::iisnum");
        break;
    }
    return false;
}
bool String::isnum(const std::wstring &str, unsigned char base)
{
    switch (base)
    {
    case 2:
        return String::isnum_binary(str);
        break;
    case 8:
        return String::isnum_octal(str);
        break;
    case 10:
        return String::isnum_decimal(str);
        break;
    case 16:
        return String::isnum_hexadecimal(str);
        break;
    case 'e':
        return String::isnum_exponente(str);
        break;
    case 'E':
        return String::isnum_exponente(str);
        break;
    default:
        throw std::runtime_error("No se inserto una base valida en String::iisnum");
        break;
    }
    return false;
}
bool String::isnum_binary(const std::string &str)
{
    if (str.size() < 3 || str[0] != '0' || (str[1] != 'b' && str[1] != 'B'))
        return false;
    for (size_t i = 2; i < str.size(); i++)
        if (str[i] != '0' && str[i] != '1')
            return false;
    return true;
}
bool String::isnum_binary(const std::wstring &str)
{
    if (str.size() < 3 || str[0] != L'0' || (str[1] != L'b' && str[1] != L'B'))
        return false;
    for (size_t i = 2; i < str.size(); i++)
        if (str[i] != L'0' && str[i] != L'1')
            return false;
    return true;
}
bool String::isnum_octal(const std::string &str)
{
    if (str.size() < 3 || str[0] != '0' || (str[1] != 'o' && str[1] != 'O'))
        return false;
    for (size_t i = 2; i < str.size(); i++)
        if (!(str[i] >= '0' && str[i] <= '7'))
            return false;
    return true;
}
bool String::isnum_octal(const std::wstring &str)
{
    if (str.size() < 3 || str[0] != L'0' || (str[1] != L'o' && str[1] != L'O'))
        return false;
    for (size_t i = 2; i < str.size(); i++)
        if (!(str[i] >= L'0' && str[i] <= L'7'))
            return false;
    return true;
}
bool String::isnum_decimal(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isnum(str[i]))
            return false;
    return true;
}
bool String::isnum_decimal(const std::wstring &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isnum(str[i]))
            return false;
    return true;
}
bool String::isnum_hexadecimal(const std::string &str)
{
    if (str.size() < 3 || str[0] != '0' || (str[1] != 'x' && str[1] != 'X'))
        return false;
    for (size_t i = 2; i < str.size(); i++)
        if ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'F') && (str[i] < 'a' || str[i] > 'f'))
            return false;
    return true;
}
bool String::isnum_hexadecimal(const std::wstring &str)
{
    if (str.size() < 3 || str[0] != L'0' || (str[1] != L'x' && str[1] != L'X'))
        return false;
    for (size_t i = 2; i < str.size(); i++)
        if ((str[i] < L'0' || str[i] > L'9') && (str[i] < L'A' || str[i] > L'F') && (str[i] < L'a' || str[i] > L'f'))
            return false;
    return true;
}
bool String::isnum_exponente(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isnum(str[i]) && str[i] != 'e' && str[i] != 'E')
            return false;
    return true;
}
bool String::isnum_exponente(const std::wstring &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isnum(str[i]) && str[i] != L'e' && str[i] != L'E')
            return false;
    return true;
}
/////////////////////////////////////
void String::tooper(std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
        if (str[i] > 96 && str[i] < 123)
            str[i] = 'A' + (str[i] - 'a');
}
/////////////////////////////////////
void String::word(const char *sources, char *&destine, size_t index)
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
void String::word(const wchar_t *sources, wchar_t *&destine, size_t index)
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
void String::word(const std::string &sources, std::string &destine, size_t index)
{
    for (size_t i = index; i < sources.size(); i++)
    {
        if (isalfanum(sources[i]))
            destine.push_back(sources[i]);
        else
            break;
    }
}
void String::word(const std::wstring &sources, std::wstring &destine, size_t index)
{
    for (size_t i = index; i < sources.size(); i++)
    {
        if (isalfanum(sources[i]))
            destine.push_back(sources[i]);
        else
            break;
    }
}
void String::word(const stringbuffer &sources, stringbuffer &destine, size_t index)
{
    size_t counter = 0;
    while (isalfanum(sources.at(index++)))
        counter++;
    destine = stringbuffer(counter);
    destine.copy(sources, counter);
}
void String::word(const wstringbuffer &sources, wstringbuffer &destine, size_t index)
{
    size_t counter = 0;
    while (isalfanum(sources.at(index++)))
        counter++;
    destine = wstringbuffer(counter);
    destine.copy(sources, counter);
}

/////////////////////////////////////
void String::reverse(const char *sources, char *&destine)
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
void String::reverse(const wchar_t *sources, wchar_t *&destine)
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
void String::reverse(const std::string &sources, std::string &destine)
{
    size_t size = sources.size();
    for (size_t count = 0; count < size; count++)
        destine.push_back(sources[size - 1 - count]);
}
void String::reverse(const std::wstring &sources, std::wstring &destine)
{
    size_t size = sources.size();
    for (size_t count = 0; count < size; count++)
        destine.push_back(sources[size - 1 - count]);
}
void String::reverse(const stringbuffer &sources, stringbuffer &destine)
{
    destine = stringbuffer(sources.size());
    size_t count = 0;
    for (auto &&caracter : stringbuffer::reverse(sources))
        destine[count++] = caracter;
}
void String::reverse(const wstringbuffer &sources, wstringbuffer &destine)
{
    destine = wstringbuffer(sources.size());
    size_t count = 0;
    for (auto &&caracter : wstringbuffer::reverse(sources))
        destine[count++] = caracter;
}
/////////////////////////////////////
void String::replaceAll(char *str, char find, char replacer)
{
    char *pivot = str;
    while (*pivot != 0)
    {
        if (*pivot == find)
            *pivot = replacer;
        pivot++;
    }
}
void String::replaceAll(wchar_t *str, wchar_t find, wchar_t replacer)
{
    wchar_t *pivot = str;
    while (*pivot != 0)
    {
        if (*pivot == find)
            *pivot = replacer;
        pivot++;
    }
}
void String::replaceAll(std::string &str, char find, char replacer)
{
    for (auto &&i : str)
        if (find == i)
            i = replacer;
}
void String::replaceAll(std::wstring &str, wchar_t find, wchar_t replacer)
{
    for (auto &&i : str)
        if (find == i)
            i = replacer;
}
void String::replaceAll(stringbuffer &str, char find, char replacer)
{
    for (auto &&i : str)
        if (find == i)
            i = replacer;
}
void String::replaceAll(wstringbuffer &str, wchar_t find, wchar_t replacer)
{
    for (auto &&i : str)
        if (find == i)
            i = replacer;
}
/////////////////////////////////////
size_t String::find_first_of(const char *str, char caracter, size_t position)
{
    const char *pivot = str + position;
    while (*pivot != 0)
    {
        if (*pivot == caracter)
            return pivot - str;
        pivot++;
    }
    return String::npos;
}
size_t String::find_first_of(const char *str, bool (*cmp)(char), size_t position)
{
    const char *pivot = str + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot))
            return pivot - str;
        pivot++;
    }
    return String::npos;
}
size_t String::find_first_of(const wchar_t *str, wchar_t caracter, size_t position)
{
    const wchar_t *pivot = str + position;
    while (*pivot != 0)
    {
        if (*pivot == caracter)
            return pivot - str;
        pivot++;
    }
    return String::npos;
}
size_t String::find_first_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position)
{
    const wchar_t *pivot = str + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot))
            return pivot - str;
        pivot++;
    }
    return String::npos;
}
/////////////////////////////////////
size_t String::find_first_not_of(const char *str, char caracter, size_t position)
{
    const char *pivot = str + position;
    while (*pivot != 0)
    {
        if (*pivot != caracter)
            return pivot - str;
        pivot++;
    }
    return String::npos;
}
size_t String::find_first_not_of(const char *str, bool (*cmp)(char), size_t position)
{
    const char *pivot = str + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot))
            return pivot - str;
        pivot++;
    }
    return String::npos;
}
size_t String::find_first_not_of(const wchar_t *str, wchar_t caracter, size_t position)
{
    const wchar_t *pivot = str + position;
    while (*pivot != 0)
    {
        if (*pivot != caracter)
            return pivot - str;
        pivot++;
    }
    return String::npos;
}
size_t String::find_first_not_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position)
{
    const wchar_t *pivot = str + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot))
            return pivot - str;
        pivot++;
    }
    return String::npos;
}
/////////////////////////////////////
size_t String::find_last_of(const char *str, char caracter, size_t position)
{
    if (position == String::npos)
        position = std::strlen(str);
    const char *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (*pivot == caracter)
            return pivot - str;
    }
    return String::npos;
}
size_t String::find_last_of(const char *str, bool (*cmp)(char), size_t position)
{
    if (position == String::npos)
        position = std::strlen(str);
    const char *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (cmp(*pivot))
            return pivot - str;
    }
    return String::npos;
}
size_t String::find_last_of(const wchar_t *str, wchar_t caracter, size_t position)
{
    if (position == String::npos)
        position = std::wcslen(str);
    const wchar_t *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (*pivot == caracter)
            return pivot - str;
    }
    return String::npos;
}
size_t String::find_last_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position)
{
    if (position == String::npos)
        position = std::wcslen(str);
    const wchar_t *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (cmp(*pivot))
            return pivot - str;
    }
    return String::npos;
}
/////////////////////////////////////
size_t String::find_last_not_of(const char *str, char caracter, size_t position)
{
    if (position == String::npos)
        position = std::strlen(str);
    const char *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (*pivot != caracter)
            return pivot - str;
    }
    return String::npos;
}
size_t String::find_last_not_of(const char *str, bool (*cmp)(char), size_t position)
{
    if (position == String::npos)
        position = std::strlen(str);
    const char *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (cmp(*pivot))
            return pivot - str;
    }
    return String::npos;
}
size_t String::find_last_not_of(const wchar_t *str, wchar_t caracter, size_t position)
{
    if (position == String::npos)
        position = std::wcslen(str);
    const wchar_t *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (*pivot != caracter)
            return pivot - str;
    }
    return String::npos;
}
size_t String::find_last_not_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position)
{
    if (position == String::npos)
        position = std::wcslen(str);
    const wchar_t *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (cmp(*pivot))
            return pivot - str;
    }
    return String::npos;
}
bool check_str(char car, const char *espacing)
{
    bool launch = true;
    while (*espacing)
    {
        launch = false;
        if (*espacing == car)
        {
            launch = true;
            break;
        }
        espacing++;
    }
    return launch;
}
bool check_str(wchar_t car, const wchar_t *espacing)
{
    bool launch = true;
    while (*espacing)
    {
        launch = false;
        if (*espacing == car)
        {
            launch = true;
            break;
        }
        espacing++;
    }
    return launch;
}
size_t String::find_word(const std::string &word, const std::string &sources, size_t index, const char *espacing)
{
    size_t i = index;
reset:
    size_t count = 0, pos = String::npos;
    while (i < sources.size())
    {
        count = 0;
        while (i < sources.size() && word[count] == sources[i])
        {
            count++;
            i++;
            if (count >= word.size())
            {
                pos = i - count;
                goto check;
            }
        }
        i++;
    }
check:
    if (i < sources.size() && pos != String::npos)
        if (!check_str(sources[i], espacing))
            goto reset;
    if (pos != 0 && pos != String::npos)
        if (!check_str(sources[pos - 1], espacing))
            goto reset;
    return pos;
}

size_t String::find_word(const std::wstring &word, const std::wstring &sources, size_t index, const wchar_t *espacing)
{
    size_t i = index;
reset:
    size_t count = 0, pos = String::npos;
    while (i < sources.size())
    {
        count = 0;
        while (i < sources.size() && word[count] == sources[i])
        {
            count++;
            i++;
            if (count >= word.size())
            {
                pos = i - count;
                goto check;
            }
        }
        i++;
    }
check:
    if (i < sources.size() && pos != String::npos)
        if (!check_str(sources[i], espacing))
            goto reset;
    if (pos != 0 && pos != String::npos)
        if (!check_str(sources[pos - 1], espacing))
            goto reset;
    return pos;
}

char *String::substr(const char *sources, size_t __pos, size_t __n) {
    const char* point_start = sources + __pos, *point_end = point_start;
    char* new_str;
    while (*point_end && (point_end - point_start + __pos) < __n)
        point_end++;
    size_t size = point_end - point_start;
    new_str = new char[size + 1];
    new_str[size] = 0;
    std::strncpy(new_str, point_start, size);
    return new_str;
}

wchar_t *String::substr(const wchar_t *sources, size_t __pos, size_t __n) {
    const wchar_t* point_start = sources + __pos, *point_end = point_start;
    wchar_t* new_str;
    while (*point_end && (point_end - point_start + __pos) < __n)
        point_end++;
    size_t size = point_end - point_start;
    new_str = new wchar_t[size + 1];
    new_str[size] = 0;
    std::wcsncpy(new_str, point_start, size);
    return new_str;
}

/////////////////////////////////////