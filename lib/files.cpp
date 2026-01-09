#include <stda/system/Files/Filesystem.hpp>

#define repetnotblockask labeljump1
#define outignore labeljump2
#define ejecuteaction labeljump3

#define NotExistingFolder "No existe ese directorio"
#define NotupdateOperation "No se ejecutar la opcion actualizar(update) en la funcion de copiar archivos"

// System::Url System::Files::recylePath = System::Files::getPathRecycle();

void __stdcall System::Files::copy_and_move_progress_interface(LARGE_INTEGER __totalFileSize,
                                                                LARGE_INTEGER __totalBytesTransferrend,
                                                                LARGE_INTEGER __streamSize,
                                                                LARGE_INTEGER __StreamBytesTransferrend,
                                                                DWORD __dwStreamNumber,
                                                                DWORD __callBackReason,
                                                                HANDLE __hSorcesFile,
                                                                HANDLE __hDestinationFile,
                                                                LPVOID lpData)
{
    double porcentaje = (double)__totalBytesTransferrend.QuadPart * 100 / __totalFileSize.QuadPart;
    if (System::Files::__interfaces_avilite__)
        __standartcout << L"\rProgreso: " << porcentaje << L"%" << std::flush;
}
template <typename T, typename Q>
T System::Files::cases_optimizate(Q input, Q invalid_values_of_greath_equals)
{
    if (input >= invalid_values_of_greath_equals)
        throw System::Exception("Invalid operand for this funtion");
    return static_cast<T>(input);
}

System::Files::options_for_copy_and_move System::Files::ask_options_for_copy_and_move_file()
{
    __standartcout << "Que opcion desea realizar" << std::endl;
    __standartcout << "1: Duplicar" << std::endl;
    __standartcout << "2: Sobreescribir" << std::endl;
    __standartcout << "3: Actualizar(Solo para carpetas)" << std::endl;
    __standartcout << "0: Preguntar en el proximo" << std::endl;
    __standartcout << ": ";
    unsigned int v;
    __standartcin >> v;
    __standartcin.clear();
    return cases_optimizate<System::Files::options_for_copy_and_move, unsigned int>(v, 4);
}

System::Files::options_for_create System::Files::ask_options_for_create()
{
    __standartcout << "Que opcion desea realizar" << std::endl;
    __standartcout << "1: Duplicar" << std::endl;
    __standartcout << "2: Sobreescribir" << std::endl;
    __standartcout << "0: Preguntar en el proximo" << std::endl;
    __standartcout << ": ";
    unsigned int v;
    __standartcin >> v;
    __standartcin.clear();
    return cases_optimizate<System::Files::options_for_create, unsigned int>(v, 3);
}

__string System::Files::get_last_error()
{
    DWORD errorCode = GetLastError();
    __caracter *errorMessage = nullptr;
    DWORD size =
#if defined(USINGWCARACTER)
        FormatMessageW
#else
        FormatMessageA
#endif
        (
            FORMAT_MESSAGE_ALLOCATE_BUFFER |
                FORMAT_MESSAGE_FROM_SYSTEM |
                FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            errorCode,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (__caracter *)&errorMessage,
            0,
            NULL);

    if (size > 0 && errorMessage != nullptr)
    {
        errorMessage[size - 1] = '\0';
        return __string(errorMessage);
    }
    return __string("");
}

size_t System::Files::size(const System::Url &url)
{
    size_t size = 0;
    if (is_directory(url.c_str()))
    {
        for (auto &&ifile : System::Files::container(url))
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
                size += System::Files::size(url + ifile.cFileName);
    }
    else
    {
        size += System::Files::size_file(url);
    }
    return size;
}

size_t System::Files::size_file(const System::Url &url)
{
    LARGE_INTEGER tamano;
    tamano.QuadPart = 0;
#if defined(USINGWCARACTER)
    if (!GetFileSizeEx(CreateFileW(url.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL), &tamano))
        throw System::Windows_Exceptions(GetLastError(), "System::Files::size_file");
#else
    if (!GetFileSizeEx(CreateFileA(url.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL), &tamano))
        throw System::Windows_Exceptions(GetLastError(), "System::Files::size_file");
#endif
    return size_t(tamano.QuadPart);
}
// #if defined(USINGWCARACTER)

// #else

// #endif
void System::Files::copy_file(const System::Url &sources, const System::Url &destine, Files::options_for_copy_and_move options)
{
    __string newfile = (destine.string() + __concaturl + sources.name());
    if (!is_directory(destine))
        throw System::Exception(NotExistingFolder);
    if (is_exist(newfile.c_str()) && options_for_copy_and_move::overwrite != options)
    {
    repetnotblockask:
        switch (options)
        {
        case options_for_copy_and_move::duplicate:
        {
            System::Files::__generate__fast__rename__(newfile, newfile.find_last_of(__dot));
            break;
        }
        case options_for_copy_and_move::update:
            throw System::Exception(NotupdateOperation);
        case options_for_copy_and_move::overwrite:
        {
            System::Files::remove_file(newfile.c_str());
            break;
        }
        default:
        {
            __standartcout << __string("El archivo \"") + sources.name() + __string("\" ya existe en el direcrorio \"") + destine.string() << std::endl;
            options = ask_options_for_copy_and_move_file();
            if (options != System::Files::options_for_copy_and_move::asking_before)
                goto repetnotblockask;
            break;
        }
        }
    }
    else
    {
#if defined(USINGWCARACTER)
        CopyFileExW(sources.c_wstr(), newfile.c_str(), NULL, NULL, FALSE, COPY_FILE_NO_BUFFERING);
#else
        CopyFileExA(sources.c_str(), newfile.c_str(), NULL, NULL, FALSE, COPY_FILE_NO_BUFFERING);
#endif
    }
}
void System::Files::copy(const System::Url &sources, const System::Url &destine, System::Files::options_for_copy_and_move options)
{
    if (!is_directory(destine))
        throw System::Exception(NotExistingFolder);
    if (is_directory(sources))
    {
        System::Url newdestine;
        System::Files::create_directory(destine, sources.name(), static_cast<options_for_create>(options), &newdestine);
        for (auto &&ifile : System::Files::container(sources))
        {
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
            {
                __string newsources = sources.string() + __concaturl + ifile.cFileName;
                System::Files::copy(newsources, newdestine, options);
            }
        }
    }
    else
        copy_file(sources, destine, options == options_for_copy_and_move::update ? options_for_copy_and_move::duplicate : options);
}

void System::Files::move_file(const System::Url &sources, const System::Url &destine, Files::options_for_copy_and_move options)
{
    __string newfile = (destine.string() + __concaturl + sources.name());
    if (!is_directory(destine))
        throw System::Exception(NotExistingFolder);
    if (is_exist(newfile.c_str()) && options_for_copy_and_move::overwrite != options)
    {
    repetnotblockask:
        switch (options)
        {
        case options_for_copy_and_move::duplicate:
        {
            System::Files::__generate__fast__rename__(newfile, newfile.find_last_of(__dot));
            break;
        }
        case options_for_copy_and_move::update:
            throw System::Exception(NotupdateOperation);
        case options_for_copy_and_move::overwrite:
        {
            System::Files::remove_file(newfile.c_str());
            break;
        }
        default:
        {
            __standartcout << __string("El archivo \"") + sources.name() + __string("\" ya existe en el direcrorio \"") + destine.string() << std::endl;
            options = ask_options_for_copy_and_move_file();
            if (options != System::Files::options_for_copy_and_move::asking_before)
                goto repetnotblockask;
            break;
        }
        }
    }
    else
    {
#if defined(USINGWCARACTER)
        MoveFileExW(sources.c_wstr(), newfile.c_str(), MOVEFILE_COPY_ALLOWED | MOVEFILE_WRITE_THROUGH);
#else
        MoveFileExA(sources.c_str(), newfile.c_str(), MOVEFILE_COPY_ALLOWED | MOVEFILE_WRITE_THROUGH);
#endif
    }
}
void System::Files::move(const System::Url &sources, const System::Url &destine, System::Files::options_for_copy_and_move options)
{
    if (!is_directory(destine))
        throw System::Exception(NotExistingFolder);
    if (is_directory(sources))
    {
        System::Url newdestine;
        System::Files::create_directory(destine, sources.name(), static_cast<options_for_create>(options), &newdestine);
        for (auto &&ifile : System::Files::container(sources))
        {
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
            {
                __string newsources = sources.string() + __concaturl + ifile.cFileName;
                System::Files::move(newsources, newdestine, options);
            }
        }
    }
    else
        move_file(sources, destine, options == options_for_copy_and_move::update ? options_for_copy_and_move::duplicate : options);
}

void System::Files::back_folder(System::Url &url)
{
    url = url.parent();
}
void System::Files::open_folder(System::Url &url, const __caracter *_str)
{
    url = System::Url(url.string() + __concaturl + _str, true);
}
void System::Files::open_folder(System::Url &url, const __string &_str)
{
    url = System::Url(url.string() + __concaturl + _str, true);
}

void System::Files::view_url(const System::Url &url, bool recursive)
{
    __standartcout << url.name() << std::endl;
    /////////////////////////////////////////////////////////////
    if (is_directory(url))
    {
        for (auto &&ifile : System::Files::container(url))
        {
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
            {
                __string v = url.string() + __concaturl + ifile.cFileName;
                System::Files::__intern__viewer__directory__(v, 2, recursive);
            }
        }
    }
}
bool System::Files::__intern__viewer__directory__(const System::Url &url, size_t n_profundidad, bool recursive)
{
    for (size_t i = 1; i < n_profundidad; i++)
        __standartcout << "  ";
    if (n_profundidad - 1 != 0)
        __standartcout << __caracter(9492) << __caracter(9472);
    /////////////////////////////////////////////////////////////
    __standartcout << url.name() << std::endl;
    /////////////////////////////////////////////////////////////
    if (!recursive)
        return true;
    /////////////////////////////////////////////////////////////
    if (!is_directory(url))
        return true;
    /////////////////////////////////////////////////////////////
    for (auto &&ifile : System::Files::container(url))
    {
        if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
            System::Files::__intern__viewer__directory__(url.string() + __concaturl + ifile.cFileName, n_profundidad + 1, recursive);
    }
    return true;
}

void System::Files::create_directory(const System::Url &url, const __caracter *name, Files::options_for_create options, System::Url *update)
{
    create_directory(url, __string(name), options, update);
}
void System::Files::create_directory(const System::Url &url, const __string &name, Files::options_for_create options, System::Url *update)
{
    __string newpath = url.string() + __concaturl + name;
    if (is_exist(newpath.c_str()))
    {
    repetnotblockask:
        switch (options)
        {
        case Files::options_for_create::duplicate:
        {
            System::Files::__generate__fast__rename__(newpath, newpath.size());
            break;
        }
        case Files::options_for_create::overwrite:
        {
            __standartcout << __string("Esta seguro de sobreescribir el directorio \"") + name + __string("\" se borraran todos los archivos: \nSi: 1\nNo: 0\n>> ");
            unsigned short c;
            __standartcin >> c;
            if (c == 1)
                System::Files::remove(newpath.c_str());
            else
                goto outignore;
            break;
        }
        case Files::options_for_create::overwrite_not_ask:
        {
            System::Files::remove(newpath.c_str());
            break;
        }
        case Files::options_for_create::asking_before:
        {
            __standartcout << __string("El directorio \"") + name + __string("\" ya existe en el direcrorio \"") + url.string() << std::endl;
            options = ask_options_for_create();
            if (options != System::Files::options_for_create::asking_before)
                goto repetnotblockask;
            break;
        }
        default:
            goto outignore;
            break;
        }
    }
    if (
#if defined(USINGWCARACTER)
        !CreateDirectoryExW(newpath.c_str())
#else
        !CreateDirectoryExA(url.c_str(), newpath.c_str(), NULL)
#endif
    )
        throw System::Windows_Exceptions(GetLastError(), "System::Files::create_directory");
    if (update != nullptr)
        *update = newpath;
outignore:
    return;
}
System::Ios::iofstream System::Files::open_file(const System::Url &url, bool binary, bool syncroned_input_output_system)
{
    return System::Ios::iofstream(url, binary, syncroned_input_output_system);
}

void System::Files::remove(const System::Url &sources)
{
    if (is_directory(sources))
    {
        for (auto &&ifile : System::Files::container(sources))
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
                System::Files::remove(sources.string() + __concaturl + ifile.cFileName);
        if (
#if defined(USINGWCARACTER)
            !RemoveDirectoryW(sources.c_str())
#else
            !RemoveDirectoryA(sources.c_str())
#endif
        )
            throw System::Windows_Exceptions(GetLastError(), "System::Files::create_directory");
    }
    else
        System::Files::remove_file(sources);
}
void System::Files::remove_file(const System::Url &sources)
{
    if (is_directory(sources))
        throw System::Exception(NotExistingFolder);
    if (
#if defined(USINGWCARACTER)
        !DeleteFileW(sources.c_str())
#else
        !DeleteFileA(sources.c_str())
#endif
    )
        throw System::Windows_Exceptions(GetLastError(), "System::Files::remove");
}

void System::Files::rename(const System::Url &url, const __caracter *new_name, bool ignore_type)
{
    System::Url newurl = url.parent() + new_name;
    System::Files::move(url, newurl);
}
void System::Files::rename(const System::Url &url, const __string &new_name, bool ignore_type)
{
    System::Files::rename(url, new_name.c_str(), ignore_type);
}
void System::Files::rename(const System::Url &url, const __stringbuffer &new_name, bool ignore_type)
{
    System::Files::rename(url, new_name.c_str(), ignore_type);
}

void System::Files::__generate__fast__rename__(__string &str, size_t pos)
{
    size_t count = 0;
    while (is_exist(str.c_str()))
    {
        if (pos >= str.size())
            str.append("(" + __to_str(count + 1) + ")");
        else
            str.insert(pos, "(" + __to_str(count + 1) + ")");
        count++;
    }
}

System::Url System::Files::getPathRecycle()
{
    wchar_t *ruta = new wchar_t[MAX_PATH];
    HRESULT hr = SHGetKnownFolderPath(FOLDERID_RecycleBinFolder, 0, NULL, &ruta);
    if (SUCCEEDED(hr))
    {
#if defined(USINGWCARACTER)
        wchar_t *__ruta = ruta;
#else
        char *__ruta = String::convert_utf8_to_ascii(ruta, true);
#endif
        return System::Url(__ruta);
    }
    throw System::Windows_Exceptions(GetLastError(), "System::Files::getPathRecycle");
    return "";
}

void System::Files::create_file(const Url &url, const __caracter *name, options_for_create options, Url *update)
{
    __string newpath = url.string() + __concaturl + name;
    System::Ios::fstream ocl;
    if (is_exist(newpath.c_str()))
    {
    repetnotblockask:
        switch (options)
        {
        case Files::options_for_create::duplicate:
        {
            System::Files::__generate__fast__rename__(newpath, newpath.size());
            break;
        }
        case Files::options_for_create::overwrite:
        {
            __standartcout << __string("Esta seguro de sobreescribir el directorio \"") + name + __string("\" se borraran todos los archivos: \nSi: 1\nNo: 0\n>> ");
            unsigned short c;
            __standartcin >> c;
            if (c != 1)
                goto outignore;
            break;
        }
        case Files::options_for_create::overwrite_not_ask:
        {
            goto ejecuteaction;
            break;
        }
        case Files::options_for_create::asking_before:
        {
            __standartcout << __string("El directorio \"") + name + __string("\" ya existe en el direcrorio \"") + url.string() << std::endl;
            options = ask_options_for_create();
            if (options != System::Files::options_for_create::asking_before)
                goto repetnotblockask;
            break;
        }
        default:
            goto outignore;
            break;
        }
    }
ejecuteaction:
    ocl = System::Ios::fstream(newpath.c_str(), System::Ios::out);
    System::Ios::fstream::close(ocl);
    if (update != nullptr)
        *update = newpath;
outignore:
    return;
}
void System::Files::create_file(const Url &url, const __string &name, options_for_create options, Url *update)
{
    System::Files::create_file(url, name.c_str(), options, update);
}
System::Url System::Files::current_directory()
{
    __caracter cwd[MAX_PATH];
    if (
#if USINGWCARACTER
        GetCurrentDirectoryW(MAX_PATH, cwd) != 0
#else
        GetCurrentDirectoryA(MAX_PATH, cwd) != 0
#endif
    )
        return System::Url(cwd);
    throw System::Windows_Exceptions(GetLastError(), "System::Files::create_file");
    return System::Url();
}
bool System::Files::is_exist(const Url &path)
{
    return is_exist(path.c_str());
}
bool System::Files::is_exist(const __caracter *path)
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
bool System::Files::is_exist(const __string &path)
{
    return is_exist(path.c_str());
}
bool System::Files::is_exist(const __stringbuffer &path)
{
    return is_exist(path.c_str());
}
bool System::Files::is_directory(const Url &url)
{
    return System::Files::is_directory(url.c_str());
}
bool System::Files::is_directory(const __caracter *url)
{
#if defined(USINGWCARACTER)
    DWORD base = GetFileAttributesW(url);
#else
    DWORD base = GetFileAttributesA(url);
#endif
    if (base == INVALID_FILE_ATTRIBUTES)
        throw System::Windows_Exceptions(GetLastError());
    return (base & FILE_ATTRIBUTE_DIRECTORY);
}
bool System::Files::is_directory(const __string &url)
{
    return System::Files::is_directory(url.c_str());
}
bool System::Files::is_directory(const __stringbuffer &url)
{
    return System::Files::is_directory(url.c_str());
}
bool System::Files::is_regular_file(const Url &url)
{
    return System::Files::is_regular_file(url.c_str());
}
bool System::Files::is_regular_file(const __caracter *url)
{
#if defined(USINGWCARACTER)
    DWORD base = GetFileAttributesW(path);
#else
    DWORD base = GetFileAttributesA(url);
#endif
    if (base == INVALID_FILE_ATTRIBUTES)
        throw System::Windows_Exceptions(GetLastError());
    return (base & FILE_ATTRIBUTE_ARCHIVE);
}
bool System::Files::is_regular_file(const __string &url)
{
    return System::Files::is_regular_file(url.c_str());
}
bool System::Files::is_regular_file(const __stringbuffer &url)
{
    return System::Files::is_regular_file(url.c_str());
}
const __string System::Files::extension(const __caracter *path)
{
    if (!System::Files::is_regular_file(path))
        throw System::Exception("La ruta insertada no le corresponde a un archivo regular.");
    size_t size = __size(path);
    size_t dot = String::find_last_of(path, __caracter(46), size);
    size_t l1 = String::find_last_of(path, __caracter('/'), size);
    size_t l2 = String::find_last_of(path, __caracter('\\'), size);
    if ((dot < l1 && l1 != -1ULL) || (dot < l2 && l2 != -1ULL))
        return "";
    return __string(path).substr(dot);
}
const __string System::Files::extension(const System::Url &url)
{
    return System::Files::extension(url.c_str());
}

// bool System::Files::is_symlink(const Url &url) {

// }
// bool System::Files::is_symlink(const __caracter *url) {

// }
// bool System::Files::is_symlink(const __string &url) {

// }
// bool System::Files::is_symlink(const __stringbuffer &url) {

// }