#include <stda/sstrings/sstrings.hpp>

void sstring::remove_espaces(std::string &str)
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
void sstring::remove_espaces(std::wstring &str)
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
void sstring::remove_begin_espaces(std::string &str)
{
    while (str.begin() != str.end())
    {
        if (*str.begin() == ' ' || *str.begin() == '\t' || *str.begin() == '\n' || *str.begin() == '\n')
            str.erase(str.begin());
        else
            break;
    }
}
void sstring::remove_begin_espaces(std::wstring &str)
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
void sstring::remove_end_espaces(std::string &str)
{
    if(!str.empty())
    {
        do
        {
            if (*(str.end() - 1) != ' ')
                break;
            str.erase(str.end() - 1);
        } while (str.end() != str.begin());
    }
}
void sstring::remove_end_espaces(std::wstring &str)
{
    if(!str.empty())
    {
        do
        {
            str.erase(str.end());
        } while (str.end() != str.begin());
    }
}
/////////////////////////////////////
bool sstring::isalfanum(char caracter)
{
    return ((caracter >= '0' && caracter <= '9') || (caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'));
}
bool sstring::isalfanum(wchar_t caracter)
{
    return ((caracter >= L'0' && caracter <= L'9') || (caracter >= L'A' && caracter <= L'Z') || (caracter >= L'a' && caracter <= L'z'));
}
bool sstring::isalfanum(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isalfanum(str[i]))
            return false;
    return true;
}
bool sstring::isalfanum(const std::wstring &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isalfanum(str[i]))
            return false;
    return true;
}
/////////////////////////////////////
bool sstring::isalfa(char caracter)
{
    return ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'));
}
bool sstring::isalfa(wchar_t caracter)
{
    return ((caracter >= L'A' && caracter <= L'Z') || (caracter >= L'a' && caracter <= L'z'));
}
bool sstring::isalfa(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isalfa(str[i]))
            return false;
    return true;
}
bool sstring::isalfa(const std::wstring &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isalfa(str[i]))
            return false;
    return true;
}
/////////////////////////////////////
bool sstring::isnum(char caracter)
{
    return (caracter >= '0' && caracter <= '9');
}
bool sstring::isnum(wchar_t caracter)
{
    return (caracter >= L'0' && caracter <= L'9');
}
bool sstring::isnum(const std::string &str, unsigned char base)
{
    switch (base)
    {
    case 2:
        return sstring::isnum_binary(str);
        break;
    case 8:
        return sstring::isnum_octal(str);
        break;
    case 10:
    {
        return sstring::isnum_decimal(str);
        break;
    }
    case 16:
        return sstring::isnum_hexadecimal(str);
        break;
    case 'e':
        return sstring::isnum_exponente(str);
        break;
    case 'E':
        return sstring::isnum_exponente(str);
        break;
    default:
        throw std::runtime_error("No se inserto una base valida en sstring::iisnum");
        break;
    }
    return false;
}
bool sstring::isnum(const std::wstring &str, unsigned char base)
{
    switch (base)
    {
    case 2:
        return sstring::isnum_binary(str);
        break;
    case 8:
        return sstring::isnum_octal(str);
        break;
    case 10:
        return sstring::isnum_decimal(str);
        break;
    case 16:
        return sstring::isnum_hexadecimal(str);
        break;
    case 'e':
        return sstring::isnum_exponente(str);
        break;
    case 'E':
        return sstring::isnum_exponente(str);
        break;
    default:
        throw std::runtime_error("No se inserto una base valida en sstring::iisnum");
        break;
    }
    return false;
}
bool sstring::isnum_binary(const std::string &str)
{
    if (str.size() < 3 || str[0] != '0' || (str[1] != 'b' && str[1] != 'B'))
        return false;
    for (size_t i = 2; i < str.size(); i++)
        if (str[i] != '0' && str[i] != '1')
            return false;
    return true;
}
bool sstring::isnum_binary(const std::wstring &str)
{
    if (str.size() < 3 || str[0] != L'0' || (str[1] != L'b' && str[1] != L'B'))
        return false;
    for (size_t i = 2; i < str.size(); i++)
        if (str[i] != L'0' && str[i] != L'1')
            return false;
    return true;
}
bool sstring::isnum_octal(const std::string &str)
{
    if (str.size() < 3 || str[0] != '0' || (str[1] != 'o' && str[1] != 'O'))
        return false;
    for (size_t i = 2; i < str.size(); i++)
        if (!(str[i] >= '0' && str[i] <= '7'))
            return false;
    return true;
}
bool sstring::isnum_octal(const std::wstring &str)
{
    if (str.size() < 3 || str[0] != L'0' || (str[1] != L'o' && str[1] != L'O'))
        return false;
    for (size_t i = 2; i < str.size(); i++)
        if (!(str[i] >= L'0' && str[i] <= L'7'))
            return false;
    return true;
}
bool sstring::isnum_decimal(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isnum(str[i]))
            return false;
    return true;
}
bool sstring::isnum_decimal(const std::wstring &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isnum(str[i]))
            return false;
    return true;
}
bool sstring::isnum_hexadecimal(const std::string &str)
{
    if (str.size() < 3 || str[0] != '0' || (str[1] != 'x' && str[1] != 'X'))
        return false;
    for (size_t i = 2; i < str.size(); i++)
        if ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'F') && (str[i] < 'a' || str[i] > 'f'))
            return false;
    return true;
}
bool sstring::isnum_hexadecimal(const std::wstring &str)
{
    if (str.size() < 3 || str[0] != L'0' || (str[1] != L'x' && str[1] != L'X'))
        return false;
    for (size_t i = 2; i < str.size(); i++)
        if ((str[i] < L'0' || str[i] > L'9') && (str[i] < L'A' || str[i] > L'F') && (str[i] < L'a' || str[i] > L'f'))
            return false;
    return true;
}
bool sstring::isnum_exponente(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isnum(str[i]) && str[i] != 'e' && str[i] != 'E')
            return false;
    return true;
}
bool sstring::isnum_exponente(const std::wstring &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!isnum(str[i]) && str[i] != L'e' && str[i] != L'E')
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
        if (*pivot == caracter)
            return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
size_t sstring::find_frist_of(const char *str, bool (*cmp)(char), size_t position)
{
    const char *pivot = str + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot))
            return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
size_t sstring::find_frist_of(const wchar_t *str, wchar_t caracter, size_t position)
{
    const wchar_t *pivot = str + position;
    while (*pivot != 0)
    {
        if (*pivot == caracter)
            return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
size_t sstring::find_frist_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position)
{
    const wchar_t *pivot = str + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot))
            return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
/////////////////////////////////////
size_t sstring::find_frist_not_of(const char *str, char caracter, size_t position)
{
    const char *pivot = str + position;
    while (*pivot != 0)
    {
        if (*pivot != caracter)
            return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
size_t sstring::find_frist_not_of(const char *str, bool (*cmp)(char), size_t position)
{
    const char *pivot = str + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot))
            return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
size_t sstring::find_frist_not_of(const wchar_t *str, wchar_t caracter, size_t position)
{
    const wchar_t *pivot = str + position;
    while (*pivot != 0)
    {
        if (*pivot != caracter)
            return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
size_t sstring::find_frist_not_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position)
{
    const wchar_t *pivot = str + position;
    while (*pivot != 0)
    {
        if (cmp(*pivot))
            return pivot - str;
        pivot++;
    }
    return size_t(-1);
}
/////////////////////////////////////
size_t sstring::find_last_of(const char *str, char caracter, size_t position)
{
    if (position == size_t(-1))
        position = std::strlen(str);
    const char *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (*pivot == caracter)
            return pivot - str;
    }
    return size_t(-1);
}
size_t sstring::find_last_of(const char *str, bool (*cmp)(char), size_t position)
{
    if (position == size_t(-1))
        position = std::strlen(str);
    const char *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (cmp(*pivot))
            return pivot - str;
    }
    return size_t(-1);
}
size_t sstring::find_last_of(const wchar_t *str, wchar_t caracter, size_t position)
{
    if (position == size_t(-1))
        position = std::wcslen(str);
    const wchar_t *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (*pivot == caracter)
            return pivot - str;
    }
    return size_t(-1);
}
size_t sstring::find_last_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position)
{
    if (position == size_t(-1))
        position = std::wcslen(str);
    const wchar_t *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (cmp(*pivot))
            return pivot - str;
    }
    return size_t(-1);
}
/////////////////////////////////////
size_t sstring::find_last_not_of(const char *str, char caracter, size_t position)
{
    if (position == size_t(-1))
        position = std::strlen(str);
    const char *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (*pivot != caracter)
            return pivot - str;
    }
    return size_t(-1);
}
size_t sstring::find_last_not_of(const char *str, bool (*cmp)(char), size_t position)
{
    if (position == size_t(-1))
        position = std::strlen(str);
    const char *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (cmp(*pivot))
            return pivot - str;
    }
    return size_t(-1);
}
size_t sstring::find_last_not_of(const wchar_t *str, wchar_t caracter, size_t position)
{
    if (position == size_t(-1))
        position = std::wcslen(str);
    const wchar_t *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (*pivot != caracter)
            return pivot - str;
    }
    return size_t(-1);
}
size_t sstring::find_last_not_of(const wchar_t *str, bool (*cmp)(wchar_t), size_t position)
{
    if (position == size_t(-1))
        position = std::wcslen(str);
    const wchar_t *pivot = str + position;
    while (pivot != str)
    {
        pivot--;
        if (cmp(*pivot))
            return pivot - str;
    }
    return size_t(-1);
}
bool check_str(char car, const char* espacing)
{
    bool launch = true;
    while (*espacing)
    {
        launch = false;
        if(*espacing == car)
        {
            launch = true;
            break;
        }
        espacing++;
    }
    return launch;
}
bool check_str(wchar_t car, const wchar_t* espacing)
{
    bool launch = true;
    while (*espacing)
    {
        launch = false;
        if(*espacing == car)
        {
            launch = true;
            break;
        }
        espacing++;
    }
    return launch;
}
size_t sstring::find_word(const std::string& word, const std::string& sources, size_t index, const char* espacing)
{
    size_t i = index;
    reset:
    size_t count = 0, pos = -1ULL;
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
    if(i < sources.size() && pos != -1ULL)
        if (!check_str(sources[i], espacing))
            goto reset;
    if(pos != 0 && pos != -1ULL)
        if (!check_str(sources[pos - 1], espacing))
            goto reset;
    return pos;
}

size_t sstring::find_word(const std::wstring &word, const std::wstring &sources, size_t index, const wchar_t *espacing)
{
    size_t i = index;
    reset:
    size_t count = 0, pos = -1ULL;
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
    if(i < sources.size() && pos != -1ULL)
        if (!check_str(sources[i], espacing))
            goto reset;
    if(pos != 0 && pos != -1ULL)
        if (!check_str(sources[pos - 1], espacing))
            goto reset;
    return pos;
}

/////////////////////////////////////