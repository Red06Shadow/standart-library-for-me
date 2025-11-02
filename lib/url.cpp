#include <stda/system/files/url/url.hpp>
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

void ios::Url::__generate__(__caracter **destine, const __caracter *sources)
{
    size_t s = __size(sources);
    *destine = new __caracter[s + 1];
    (*destine)[s] = 0;
    __copy(*destine, sources);
}
void ios::Url::__generate__(__caracter **destine, const __caracter *sources, size_t size)
{
    *destine = new __caracter[size + 1];
    (*destine)[size] = 0;
    __copy(*destine, sources);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
ios::Url::Url(const __caracter *path, bool checkExistUrl) : __consta__(true)
{
    size_t size = 0;
    if (path == nullptr)
        throw ios::exception("Error: Path vacio en ios::Url contructor");
    if ((size = __size(path)) == 0)
        throw ios::exception("Error: Path vacio en ios::Url contructor");
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    if (!ios::Url::is_corret(path))
        throw ios::exception("Error: La ruta no es valida sintacticamente; " + __exceptiosconvert(path));
    if (checkExistUrl && !ios::Url::is_exist(path))
        throw ios::exception("Error: La direcion asiganda no existe; " + __exceptiosconvert(path));
    __path__ = path;
}

ios::Url::Url(__caracter *path, bool checkExistUrl) : __consta__(false)
{
    size_t size = 0;
    if (path == nullptr)
        throw ios::exception("Error: Path vacio en ios::Url contructor");
    if ((size = __size(path)) == 0)
        throw ios::exception("Error: Path vacio en ios::Url contructor");
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    if (!ios::Url::is_corret(path))
        throw ios::exception("Error: La ruta no es valida sintacticamente; " + __exceptiosconvert(path));
    if (checkExistUrl && !ios::Url::is_exist(path))
        throw ios::exception("Error: La direcion asiganda no existe; " + __exceptiosconvert(path));
    ios::Url::__generate__(const_cast<__caracter **>(&__path__), path);
}
ios::Url::Url(const __string &path, bool checkExistUrl) : ios::Url(const_cast<__caracter *>(path.c_str()), checkExistUrl) {}
ios::Url::Url(const __stringbuffer &path, bool checkExistUrl) 
{
    if(path.empty())
        throw ios::exception("Error: Path vacio en ios::Url contructor");
    if (!ios::Url::is_corret(path.c_str()))
        throw ios::exception("Error: La ruta no es valida sintacticamente; " + __exceptiosconvert(path.c_str()));
    if (checkExistUrl && !ios::Url::is_exist(path.c_str()))
        throw ios::exception("Error: La direcion asiganda no existe; " + __exceptiosconvert(path.c_str()));
    ios::Url::__generate__(const_cast<__caracter **>(&__path__), path.c_str(), path.size());
}

ios::Url::Url(const ios::Url &other) : __consta__(other.__consta__)
{
    if (other.__consta__)
    {
        __path__ = other.__path__;
    }
    else
    {
        if (__path__ != nullptr)
            delete[] __path__;
        __generate__(const_cast<__caracter **>(&__path__), other.__path__);
    }
}
ios::Url::Url(ios::Url &&other) : __consta__(other.__consta__)
{
    __path__ = other.__path__;
    other.__path__ = nullptr;
}
ios::Url &ios::Url::operator=(const ios::Url &other)
{
    if (this != &other)
    {
        this->__consta__ = other.__consta__;
        if (__path__ != nullptr)
            delete[] (__path__);
        if (other.__consta__)
            this->__path__ = other.__path__;
        else
            Url::__generate__(const_cast<__caracter **>(&__path__), other.__path__);
    }
    return *this;
}
ios::Url &ios::Url::operator=(ios::Url &&other)
{
    if (this != &other)
    {
        if (__path__ != nullptr)
            delete[] (__path__);
        this->__consta__ = other.__consta__;
        this->__path__ = other.__path__;
        other.__path__ = nullptr;
    }
    return *this;
}
bool ios::Url::equals(const ios::Url &url1, const ios::Url &url2)
{
    return __compare(url1.__path__, url2.__path__) == 0;
}
bool ios::Url::equals(const ios::Url &url1, const __caracter *strurl)
{
    return __compare(url1.__path__, strurl) == 0;
}

const __caracter *ios::Url::name() const
{
    return ios::Url::name(this->__path__);
}
const ios::Url ios::Url::absolute() const
{
    return ios::Url::absolute(this->__path__);
}
const ios::Url ios::Url::parent() const
{
    return ios::Url::parent(this->__path__);
}

const __caracter *ios::Url::name(const __caracter *path)
{
    size_t size = __size(path), pos = 0;
    __caracter v = path[size - 1];
    if (path[size - 1] == '/' || path[size - 1] == '\\')
        size--;
    pos = sstring::find_last_of(path, [](__caracter v) -> bool
                   { return v == '/' || v == '\\'; }, size);
    if (pos == size_t(-1))
        pos = 0;
    pos++;
    __caracter *cstr = new __caracter[size - pos];
    __ncopy(cstr, path + pos, size - pos);
    cstr[size - pos] = '\0';
    return const_cast<const __caracter *>(cstr);
}
const ios::Url ios::Url::absolute(const __caracter *path)
{
    __caracter *cstr = new __caracter[4];
    __ncopy(cstr, path, 3);
    cstr[3] = '\0';
    return const_cast<const __caracter *>(cstr);
}
const ios::Url ios::Url::parent(const __caracter *path)
{
    size_t size = __size(path), pos = 0;
    if (path[size - 1] == '/' || path[size - 1] == '\\')
        size--;
    pos = sstring::find_last_of(path, [](__caracter v) -> bool
                   { return v == '/' || v == '\\'; }, size);
    if (pos == size_t(-1))
        pos = 0;
    __caracter *cstr = new __caracter[pos + 2];
    __ncopy(cstr, path, pos + 1);
    cstr[pos + 1] = '\0';
    return const_cast<const __caracter *>(cstr);
}

bool ios::Url::is_directory(const ios::Url &url)
{
    return ios::Url::is_directory(url.c_str());
}
bool ios::Url::is_directory(const __caracter *path)
{
#if defined(USINGWCARACTER)
    DWORD base = GetFileAttributesW(path);
#else
    DWORD base = GetFileAttributesA(path);
#endif
    if (base == INVALID_FILE_ATTRIBUTES)
        throw ios::exception("Error ruta invalida");
    return (base & FILE_ATTRIBUTE_DIRECTORY);
}
bool ios::Url::is_directory(const __string &path)
{
    return ios::Url::is_directory(path);
}

bool ios::Url::is_file(const ios::Url &url)
{
    return ios::Url::is_file(url.c_str());
}
bool ios::Url::is_file(const __caracter *path)
{
#if defined(USINGWCARACTER)
    DWORD base = GetFileAttributesW(path);
#else
    DWORD base = GetFileAttributesA(path);
#endif
    if (base == INVALID_FILE_ATTRIBUTES)
        throw ios::exception("Error ruta invalida");
    return (base & FILE_ATTRIBUTE_ARCHIVE);
}
bool ios::Url::is_file(const __string &path)
{
    return ios::Url::is_file(path);
}

const bool ios::Url::is_corret(const ios::Url &url)
{
    return is_corret(url.__path__);
}
const bool ios::Url::is_corret(const __caracter *path)
{
    if (path == nullptr)
        return false;
    WCHAR buffer[MAX_PATH];
#if defined(USINGWCARACTER)
    HRESULT hr = PathCchCanonicalize(buffer, MAX_PATH, path);
#else
    wchar_t *__str__ = stringconverter::convert_ascii_to_uft8(path);
    HRESULT hr = PathCchCanonicalize(buffer, MAX_PATH, __str__);
    delete[] (__str__);
#endif
    return !FAILED(hr);
    const wchar_t* invalidCaracters = L"<>:\"|?*";
    while (*path)
    {
        if (wcschr(invalidCaracters, *path))
            return false;
    }
    return true;
}
const bool ios::Url::is_corret(const __string &path)
{
    return is_corret(path.c_str());
}
const void ios::Url::get_tokens(const ios::Url &url, std::vector<const __caracter *> &__vect)
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

const bool ios::Url::is_exist(const ios::Url &url)
{
    return is_exist(url.__path__);
}
const bool ios::Url::is_exist(const __caracter *path)
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
const bool ios::Url::is_exist(const __string &path)
{
    return is_exist(path.c_str());
}
bool ios::Url::is_exist() const
{
    return is_exist(__path__);
}
const __string ios::Url::get_file_type(const ios::Url &url)
{
    return url.string().substr(sstring::find_last_of(url.c_str(), __caracter(46), __size(url.c_str())));
}
