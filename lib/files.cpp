#include <stda/system/files/filesystem.hpp>

#define repetnotblockask labeljump1
#define outignore labeljump2
#define ejecuteaction labeljump3

// systems::Url systems::files::recylePath = systems::files::getPathRecycle();

void __stdcall systems::files::copy_and_move_progress_interface(LARGE_INTEGER __totalFileSize,
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
    if (systems::files::__interfaces_avilite__)
        __standartcout << L"\rProgreso: " << porcentaje << L"%" << std::flush;
}
template <typename T, typename Q>
T systems::files::cases_optimizate(Q input, Q invalid_values_of_greath_equals)
{
    if (input >= invalid_values_of_greath_equals)
        throw systems::exception(systems::exception::error::__invalidopmovecopy);
    return static_cast<T>(input);
}

systems::files::options_for_copy_and_move systems::files::ask_options_for_copy_and_move_file()
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
    return cases_optimizate<systems::files::options_for_copy_and_move, unsigned int>(v, 4);
}

systems::files::options_for_create systems::files::ask_options_for_create()
{
    __standartcout << "Que opcion desea realizar" << std::endl;
    __standartcout << "1: Duplicar" << std::endl;
    __standartcout << "2: Sobreescribir" << std::endl;
    __standartcout << "0: Preguntar en el proximo" << std::endl;
    __standartcout << ": ";
    unsigned int v;
    __standartcin >> v;
    __standartcin.clear();
    return cases_optimizate<systems::files::options_for_create, unsigned int>(v, 3);
}

__string systems::files::get_last_error()
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

size_t systems::files::size(const systems::Url &url)
{
    size_t size = 0;
    if (is_directory(url.c_str()))
    {
        for (auto &&ifile : systems::files::container(url))
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
                size += systems::files::size(url + ifile.cFileName);
    }
    else
    {
        size += systems::files::size_file(url);
    }
    return size;
}

size_t systems::files::size_file(const systems::Url &url)
{
    LARGE_INTEGER tamano;
    tamano.QuadPart = 0;
#if defined(USINGWCARACTER)
    if (!GetFileSizeEx(CreateFileW(url.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL), &tamano))
        throw systems::exception(systems::exception::error::__notgetfilesize);
#else
    if (!GetFileSizeEx(CreateFileA(url.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL), &tamano))
        throw systems::exception(systems::exception::error::__notgetfilesize);
#endif
    return size_t(tamano.QuadPart);
}
// #if defined(USINGWCARACTER)

// #else

// #endif
void systems::files::copy_file(const systems::Url &sources, const systems::Url &destine, files::options_for_copy_and_move options)
{
    __string newfile = (destine.string() + __concaturl + sources.name());
    if (!is_directory(destine))
        throw systems::exception(systems::exception::error::__notfolderdestine);
    if (is_exist(newfile.c_str()) && options_for_copy_and_move::overwrite != options)
    {
    repetnotblockask:
        switch (options)
        {
        case options_for_copy_and_move::duplicate:
        {
            systems::files::__generate__fast__rename__(newfile, newfile.find_last_of(__dot));
            break;
        }
        case options_for_copy_and_move::update:
            throw systems::exception(systems::exception::error::__notfileupdater);
        case options_for_copy_and_move::overwrite:
        {
            systems::files::remove_file(newfile.c_str());
            break;
        }
        default:
        {
            __standartcout << __string("El archivo \"") + sources.name() + __string("\" ya existe en el direcrorio \"") + destine.string() << std::endl;
            options = ask_options_for_copy_and_move_file();
            if (options != systems::files::options_for_copy_and_move::asking_before)
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
void systems::files::copy(const systems::Url &sources, const systems::Url &destine, systems::files::options_for_copy_and_move options)
{
    if (!is_directory(destine))
        throw systems::exception(systems::exception::error::__notfolderdestine);
    if (is_directory(sources))
    {
        systems::Url newdestine;
        systems::files::create_directory(destine, sources.name(), static_cast<options_for_create>(options), &newdestine);
        for (auto &&ifile : systems::files::container(sources))
        {
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
            {
                __string newsources = sources.string() + __concaturl + ifile.cFileName;
                systems::files::copy(newsources, newdestine, options);
            }
        }
    }
    else
        copy_file(sources, destine, options == options_for_copy_and_move::update ? options_for_copy_and_move::duplicate : options);
}

void systems::files::move_file(const systems::Url &sources, const systems::Url &destine, files::options_for_copy_and_move options)
{
    __string newfile = (destine.string() + __concaturl + sources.name());
    if (!is_directory(destine))
        throw systems::exception(systems::exception::error::__notfolderdestine);
    if (is_exist(newfile.c_str()) && options_for_copy_and_move::overwrite != options)
    {
    repetnotblockask:
        switch (options)
        {
        case options_for_copy_and_move::duplicate:
        {
            systems::files::__generate__fast__rename__(newfile, newfile.find_last_of(__dot));
            break;
        }
        case options_for_copy_and_move::update:
            throw systems::exception(systems::exception::error::__notfileupdater);
        case options_for_copy_and_move::overwrite:
        {
            systems::files::remove_file(newfile.c_str());
            break;
        }
        default:
        {
            __standartcout << __string("El archivo \"") + sources.name() + __string("\" ya existe en el direcrorio \"") + destine.string() << std::endl;
            options = ask_options_for_copy_and_move_file();
            if (options != systems::files::options_for_copy_and_move::asking_before)
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
void systems::files::move(const systems::Url &sources, const systems::Url &destine, systems::files::options_for_copy_and_move options)
{
    if (!is_directory(destine))
        throw systems::exception(systems::exception::error::__notfolderdestine);
    if (is_directory(sources))
    {
        systems::Url newdestine;
        systems::files::create_directory(destine, sources.name(), static_cast<options_for_create>(options), &newdestine);
        for (auto &&ifile : systems::files::container(sources))
        {
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
            {
                __string newsources = sources.string() + __concaturl + ifile.cFileName;
                systems::files::move(newsources, newdestine, options);
            }
        }
    }
    else
        move_file(sources, destine, options == options_for_copy_and_move::update ? options_for_copy_and_move::duplicate : options);
}

void systems::files::back_folder(systems::Url &url)
{
    url = url.parent();
}
void systems::files::open_folder(systems::Url &url, const __caracter *_str)
{
    url = systems::Url(url.string() + __concaturl + _str, true);
}
void systems::files::open_folder(systems::Url &url, const __string &_str)
{
    url = systems::Url(url.string() + __concaturl + _str, true);
}

void systems::files::view_url(const systems::Url &url, bool recursive)
{
    __standartcout << url.name() << std::endl;
    /////////////////////////////////////////////////////////////
    if (is_directory(url))
    {
        for (auto &&ifile : systems::files::container(url))
        {
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
            {
                __string v = url.string() + __concaturl + ifile.cFileName;
                systems::files::__intern__viewer__directory__(v, 2, recursive);
            }
        }
    }
}
bool systems::files::__intern__viewer__directory__(const systems::Url &url, size_t n_profundidad, bool recursive)
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
    for (auto &&ifile : systems::files::container(url))
    {
        if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
            systems::files::__intern__viewer__directory__(url.string() + __concaturl + ifile.cFileName, n_profundidad + 1, recursive);
    }
    return true;
}

void systems::files::create_directory(const systems::Url &url, const __caracter *name, files::options_for_create options, systems::Url *update)
{
    create_directory(url, __string(name), options, update);
}
void systems::files::create_directory(const systems::Url &url, const __string &name, files::options_for_create options, systems::Url *update)
{
    __string newpath = url.string() + __concaturl + name;
    if (is_exist(newpath.c_str()))
    {
    repetnotblockask:
        switch (options)
        {
        case files::options_for_create::duplicate:
        {
            systems::files::__generate__fast__rename__(newpath, newpath.size());
            break;
        }
        case files::options_for_create::overwrite:
        {
            __standartcout << __string("Esta seguro de sobreescribir el directorio \"") + name + __string("\" se borraran todos los archivos: \nSi: 1\nNo: 0\n:");
            unsigned char c;
            __standartcin >> c;
            if (c == 1)
                systems::files::remove(newpath);
        }
        case files::options_for_create::overwrite_not_ask:
        {
            systems::files::remove(newpath.c_str());
        }
        case files::options_for_create::asking_before:
        {
            __standartcout << __string("El directorio \"") + name + __string("\" ya existe en el direcrorio \"") + url.string() << std::endl;
            options = ask_options_for_create();
            if (options != systems::files::options_for_create::asking_before)
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
        throw systems::exception(systems::exception::error::__notexistingfolder);
    if (update != nullptr)
        *update = newpath;
outignore:
    return;
}
systems::ios::iofstream systems::files::open_file(const systems::Url &url, bool binary, bool syncroned_input_output_system)
{
    return systems::ios::iofstream(url, binary, syncroned_input_output_system);
}

void systems::files::remove(const systems::Url &sources)
{
    if (is_directory(sources))
    {
        for (auto &&ifile : systems::files::container(sources))
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
                systems::files::remove(sources.string() + __concaturl + ifile.cFileName);
        if (
#if defined(USINGWCARACTER)
            !RemoveDirectoryW(sources.c_str())
#else
            !RemoveDirectoryA(sources.c_str())
#endif
        )
            throw systems::exception(__string("Error: No se puede eliminar el directorio, \"") + sources.string() + "\" y el sistema lanzo el siguiente error: \n" + systems::files::get_last_error());
    }
    else
        systems::files::remove_file(sources);
}
void systems::files::remove_file(const systems::Url &sources)
{
    if (is_directory(sources))
        throw systems::exception(systems::exception::error::__notfolderdestine);
    if (
#if defined(USINGWCARACTER)
        !DeleteFileW(sources.c_str())
#else
        !DeleteFileA(sources.c_str())
#endif
    )
        throw systems::exception(__string("Error: No se puede eliminar el directorio, \"") + sources.string() + "\" y el sistema lanzo el siguiente error: \n" + systems::files::get_last_error());
}

void systems::files::rename(const systems::Url &url, const __caracter *new_name, bool ignore_type)
{
    systems::Url newurl = url.parent() + new_name;
    systems::files::move(url, newurl);
}
void systems::files::rename(const systems::Url &url, const __string& new_name, bool ignore_type)
{
    systems::files::rename(url, new_name.c_str(), ignore_type);
}
void systems::files::rename(const systems::Url &url, const __stringbuffer& new_name, bool ignore_type)
{
    systems::files::rename(url, new_name.c_str(), ignore_type);
}

void systems::files::__generate__fast__rename__(__string &str, size_t pos)
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

systems::Url systems::files::getPathRecycle()
{
    wchar_t *ruta = new wchar_t[MAX_PATH];
    HRESULT hr = SHGetKnownFolderPath(FOLDERID_RecycleBinFolder, 0, NULL, &ruta);
    if (SUCCEEDED(hr))
    {
#if defined(USINGWCARACTER)
        wchar_t *__ruta = ruta;
#else
        char *__ruta = stringconverter::convert_utf8_to_ascii(ruta, true);
#endif
        return systems::Url(__ruta);
    }
    throw systems::exception("No se pudo encontrar la ruta de la papelara de reciclaje.");
    return "";
}

void systems::files::create_file(const Url &url, const __caracter *name, options_for_create options, Url *update)
{
    __string newpath = url.string() + __concaturl + name;
    systems::ios::fstream ocl;
    if (is_exist(newpath.c_str()))
    {
    repetnotblockask:
        switch (options)
        {
        case files::options_for_create::duplicate:
        {
            systems::files::__generate__fast__rename__(newpath, newpath.size());
            break;
        }
        case files::options_for_create::overwrite:
        {
            __standartcout << __string("Esta seguro de sobreescribir el directorio \"") + name + __string("\" se borraran todos los archivos: \nSi: 1\nNo: 0\n:");
            unsigned char c;
            __standartcin >> c;
            if (c != 1)
                goto outignore;
        }
        case files::options_for_create::overwrite_not_ask:
        {
            goto ejecuteaction;
        }
        case files::options_for_create::asking_before:
        {
            __standartcout << __string("El directorio \"") + name + __string("\" ya existe en el direcrorio \"") + url.string() << std::endl;
            options = ask_options_for_create();
            if (options != systems::files::options_for_create::asking_before)
                goto repetnotblockask;
            break;
        }
        default:
            goto outignore;
            break;
        }
    }
ejecuteaction:
    ocl = systems::ios::fstream(newpath.c_str(), systems::ios::out);
    systems::ios::fstream::close(ocl);
    if (update != nullptr)
        *update = newpath;
outignore:
    return;
}
void systems::files::create_file(const Url &url, const __string &name, options_for_create options, Url *update)
{
    systems::files::create_file(url, name.c_str(), options, update);
}
systems::Url systems::files::current_directory()
{
    __caracter cwd[MAX_PATH];
    if (
#if USINGWCARACTER
        GetCurrentDirectoryW(MAX_PATH, cwd) != 0
#else
        GetCurrentDirectoryA(MAX_PATH, cwd) != 0
#endif
    )
        return systems::Url(cwd);
    throw systems::exception("No se pudo acceder o identificar la ruta actual.");
    return systems::Url();
}
bool systems::files::is_exist(const Url& path)
{
    return is_exist(path.c_str());
}
bool systems::files::is_exist(const __caracter *path)
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
bool systems::files::is_exist(const __string& path)
{
    return is_exist(path.c_str());
}
bool systems::files::is_exist(const __stringbuffer& path)
{
    return is_exist(path.c_str());
}
bool systems::files::is_directory(const Url &url) {
    return systems::files::is_directory(url.c_str());
}
bool systems::files::is_directory(const __caracter *url) {
    #if defined(USINGWCARACTER)
    DWORD base = GetFileAttributesW(url);
#else
    DWORD base = GetFileAttributesA(url);
#endif
    if (base == INVALID_FILE_ATTRIBUTES)
        throw systems::exception("Error ruta invalida");
    return (base & FILE_ATTRIBUTE_DIRECTORY);
}
bool systems::files::is_directory(const __string &url) {
    return systems::files::is_directory(url.c_str());

}
bool systems::files::is_directory(const __stringbuffer &url) {
    return systems::files::is_directory(url.c_str());
}
bool systems::files::is_regular_file(const Url &url) {
    return systems::files::is_regular_file(url.c_str());
}
bool systems::files::is_regular_file(const __caracter *url) {
    #if defined(USINGWCARACTER)
    DWORD base = GetFileAttributesW(path);
#else
    DWORD base = GetFileAttributesA(url);
#endif
    if (base == INVALID_FILE_ATTRIBUTES)
        throw systems::exception("Error ruta invalida");
    return (base & FILE_ATTRIBUTE_ARCHIVE);
}
bool systems::files::is_regular_file(const __string &url) {
    return systems::files::is_regular_file(url.c_str());
}
bool systems::files::is_regular_file(const __stringbuffer &url) {
    return systems::files::is_regular_file(url.c_str());
}
// bool systems::files::is_symlink(const Url &url) {

// }
// bool systems::files::is_symlink(const __caracter *url) {

// }
// bool systems::files::is_symlink(const __string &url) {

// }
// bool systems::files::is_symlink(const __stringbuffer &url) {

// }