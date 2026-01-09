#include <stda/system/files/url/url.hpp>
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

const bool is_exist(const __caracter *path)
{
    WIN32_FIND_DATAW findFileData;
    if (path == nullptr)
        return false;
#if defined(USINGWCARACTER)
    HANDLE hfind = FindFirstFileExW(path, FindExInfoStandard, &findFileData, FindExSearchNameMatch, nullptr, 0);
#else
    HANDLE hfind = FindFirstFileExA(path, FindExInfoStandard, &findFileData, FindExSearchNameMatch, nullptr, 0);
#endif
    if (hfind != INVALID_HANDLE_VALUE)
    {
        CloseHandle(hfind);
        return true;
    }
    return false;
}

void System::Url::__generate__(__caracter **destine, const __caracter *sources)
{
    size_t s = __size(sources);
    *destine = new __caracter[s + 1];
    (*destine)[s] = 0;
    __copy(*destine, sources);
}
void System::Url::__generate__(__caracter **destine, const __caracter *sources, size_t size)
{
    *destine = new __caracter[size + 1];
    (*destine)[size] = 0;
    __copy(*destine, sources);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
System::Url::Url(const __caracter *path, bool checkExistUrl) : __consta__(true)
{
    size_t size = 0;
    if (path == nullptr)
        throw System::Exception("Error: Path vacio en System::Url contructor");
    if ((size = __size(path)) == 0)
        throw System::Exception("Error: Path vacio en System::Url contructor");
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    if (!System::Url::is_corret(path))
        throw System::Exception("Error: La ruta no es valida sintacticamente; " + __exceptiosconvert(path));
    if (checkExistUrl && !is_exist(path))
        throw System::Exception("Error: La direcion asiganda no existe; " + __exceptiosconvert(path));
    __path__ = path;
}

System::Url::Url(__caracter *path, bool checkExistUrl) : __consta__(false)
{
    size_t size = 0;
    if (path == nullptr)
        throw System::Exception("Error: Path vacio en System::Url contructor");
    if ((size = __size(path)) == 0)
        throw System::Exception("Error: Path vacio en System::Url contructor");
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    if (!System::Url::is_corret(path))
        throw System::Exception("Error: La ruta no es valida sintacticamente; " + __exceptiosconvert(path));
    if (checkExistUrl && !is_exist(path))
        throw System::Exception("Error: La direcion asiganda no existe; " + __exceptiosconvert(path));
    System::Url::__generate__(const_cast<__caracter **>(&__path__), path);
}
System::Url::Url(const __string &path, bool checkExistUrl) : System::Url(const_cast<__caracter *>(path.c_str()), checkExistUrl) {}
System::Url::Url(const __stringbuffer &path, bool checkExistUrl)
{
    if (path.empty())
        throw System::Exception("Error: Path vacio en System::Url contructor");
    if (!System::Url::is_corret(path.c_str()))
        throw System::Exception("Error: La ruta no es valida sintacticamente; " + __exceptiosconvert(path.c_str()));
    if (checkExistUrl && !is_exist(path.c_str()))
        throw System::Exception("Error: La direcion asiganda no existe; " + __exceptiosconvert(path.c_str()));
    System::Url::__generate__(const_cast<__caracter **>(&__path__), path.c_str(), path.size());
}

System::Url::Url(const System::Url &other) : __consta__(other.__consta__)
{
    if (other.__consta__)
    {
        __path__ = other.__path__;
    }
    else
    {
        __path__ = nullptr;
        __generate__(const_cast<__caracter **>(&__path__), other.__path__);
    }
}
System::Url::Url(System::Url &&other) : __consta__(other.__consta__)
{
    __path__ = other.__path__;
    other.__path__ = nullptr;
}
System::Url &System::Url::operator=(const System::Url &other)
{
    if (this != &other)
    {

        if (__path__ != nullptr && !this->__consta__)
            delete[] (__path__);
        this->__consta__ = other.__consta__;
        if (other.__consta__)
            this->__path__ = other.__path__;
        else
            Url::__generate__(const_cast<__caracter **>(&__path__), other.__path__);
    }
    return *this;
}
System::Url &System::Url::operator=(System::Url &&other)
{
    if (this != &other)
    {
        if (__path__ != nullptr && !this->__consta__)
            delete[] (__path__);
        this->__consta__ = other.__consta__;
        this->__path__ = other.__path__;
        other.__path__ = nullptr;
    }
    return *this;
}
bool System::Url::equals(const System::Url &url1, const System::Url &url2)
{
    return __compare(url1.__path__, url2.__path__) == 0;
}
bool System::Url::equals(const System::Url &url1, const __caracter *strurl)
{
    return __compare(url1.__path__, strurl) == 0;
}

const __caracter *System::Url::name() const
{
    return System::Url::name(this->__path__);
}
const System::Url System::Url::root() const
{
    return System::Url::root(this->__path__);
}
const System::Url System::Url::parent() const
{
    return System::Url::parent(this->__path__);
}

const __caracter *System::Url::name(const __caracter *path)
{
    size_t size = __size(path), pos = 0;
    __caracter v = path[size - 1];
    if (path[size - 1] == '/' || path[size - 1] == '\\')
        size--;
    pos = String::find_last_of(path, [](__caracter v) -> bool
                                { return v == '/' || v == '\\'; }, size);
    if (pos == size_t(-1))
        pos = 0;
    pos++;
    __caracter *cstr = new __caracter[size - pos];
    __ncopy(cstr, path + pos, size - pos);
    cstr[size - pos] = '\0';
    return const_cast<const __caracter *>(cstr);
}
const System::Url System::Url::root(const __caracter *path)
{
    __caracter *cstr = new __caracter[4];
    __ncopy(cstr, path, 3);
    cstr[3] = '\0';
    return const_cast<const __caracter *>(cstr);
}
const System::Url System::Url::parent(const __caracter *path)
{
    size_t size = __size(path), pos = 0;
    if (path[size - 1] == '/' || path[size - 1] == '\\')
        size--;
    pos = String::find_last_of(path, [](__caracter v) -> bool
                                { return v == '/' || v == '\\'; }, size);
    if (pos == size_t(-1))
        pos = 0;
    __caracter *cstr = new __caracter[pos + 2];
    __ncopy(cstr, path, pos + 1);
    cstr[pos + 1] = '\0';
    return const_cast<const __caracter *>(cstr);
}

const bool System::Url::is_corret(const System::Url &url)
{
    return is_corret(url.__path__);
}
const bool System::Url::is_corret(const __caracter *path)
{
    if (path == nullptr)
        return false;
    WCHAR buffer[MAX_PATH];
#if defined(USINGWCARACTER)
    HRESULT hr = PathCchCanonicalize(buffer, MAX_PATH, path);
#else
    wchar_t *__str__ = String::convert_ascii_to_uft8(path);
    HRESULT hr = PathCchCanonicalize(buffer, MAX_PATH, __str__);
    delete[] (__str__);
#endif
    return !FAILED(hr);
#if FALSE
    const wchar_t *invalidCaracters = L"<>:\"|?*";
    while (*path)
    {
        if (wcschr(invalidCaracters, *path))
            return false;
    }
    return true;
#endif
}
const bool System::Url::is_corret(const __string &path)
{
    return is_corret(path.c_str());
}
const void System::Url::get_tokens(const System::Url &url, std::vector<const __caracter *> &__vect)
{
    size_t size = __size(url.c_str());
    size_t before = 0;
    for (size_t i = 0; i < size; i++)
    {
        __caracter c = url.c_str()[i];
        if (c == '\\' || c == '/')
        {
            if (i - before == 0)
            {
                before = i + 1;
                continue;
            }
            size_t sstr = i - before;
            __vect.push_back(new __caracter[sstr]);
            const_cast<__caracter *>(__vect.back())[sstr] = '\0';
            __ncopy(const_cast<__caracter *>(__vect.back()), url.c_str() + before, i - before);
            before = i + 1;
        }
    }
    __vect.push_back(new __caracter[size - before]);
    const_cast<__caracter *>(__vect.back())[size - before] = '\0';
    __ncopy(const_cast<__caracter *>(__vect.back()), url.c_str() + before, size - before);
}
