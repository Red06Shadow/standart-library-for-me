#include <stda/system/files/directory/directory.hpp>

#define repetnotblockask labeljump1
#define outignore labeljump2
#define ejecuteaction labeljump3

// ios::Url ios::directory::recylePath = ios::directory::getPathRecycle();

void __stdcall ios::directory::copy_and_move_progress_interface(LARGE_INTEGER __totalFileSize,
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
    if (ios::directory::__interfaces_avilite__)
        __standartcout << L"\rProgreso: " << porcentaje << L"%" << std::flush;
}
template <typename T, typename Q>
T ios::directory::cases_optimizate(Q input, Q invalid_values_of_greath_equals)
{
    if (input >= invalid_values_of_greath_equals)
        throw ios::exception(ios::exception::error::__invalidopmovecopy);
    return static_cast<T>(input);
}

ios::directory::options_for_copy_and_move ios::directory::ask_options_for_copy_and_move_file()
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
    return cases_optimizate<ios::directory::options_for_copy_and_move, unsigned int>(v, 4);
}

ios::directory::options_for_create ios::directory::ask_options_for_create()
{
    __standartcout << "Que opcion desea realizar" << std::endl;
    __standartcout << "1: Duplicar" << std::endl;
    __standartcout << "2: Sobreescribir" << std::endl;
    __standartcout << "0: Preguntar en el proximo" << std::endl;
    __standartcout << ": ";
    unsigned int v;
    __standartcin >> v;
    __standartcin.clear();
    return cases_optimizate<ios::directory::options_for_create, unsigned int>(v, 3);
}

__string ios::directory::get_last_error()
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

size_t ios::directory::size(const ios::Url &url)
{
    size_t size = 0;
    if (ios::Url::is_directory(url.c_str()))
    {
        for (auto &&ifile : ios::directory::container(url))
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
                size += ios::directory::size(url + ifile.cFileName);
    }
    else
    {
        size += ios::directory::size_file(url);
    }
    return size;
}

size_t ios::directory::size_file(const ios::Url &url)
{
    LARGE_INTEGER tamano;
    tamano.QuadPart = 0;
#if defined(USINGWCARACTER)
    if (!GetFileSizeEx(CreateFileW(url.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL), &tamano))
        throw ios::exception(ios::exception::error::__notgetfilesize);
#else
    if (!GetFileSizeEx(CreateFileA(url.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL), &tamano))
        throw ios::exception(ios::exception::error::__notgetfilesize);
#endif
    return size_t(tamano.QuadPart);
}
// #if defined(USINGWCARACTER)

// #else

// #endif
void ios::directory::copy_file(const ios::Url &sources, const ios::Url &destine, directory::options_for_copy_and_move options)
{
    __string newfile = (destine.string() + __concaturl + sources.name());
    if (!ios::Url::is_directory(destine))
        throw ios::exception(ios::exception::error::__notfolderdestine);
    if (ios::Url::is_exist(newfile.c_str()) && options_for_copy_and_move::overwrite != options)
    {
    repetnotblockask:
        switch (options)
        {
        case options_for_copy_and_move::duplicate:
        {
            ios::directory::__generate__fast__rename__(newfile, newfile.find_last_of(__dot));
            break;
        }
        case options_for_copy_and_move::update:
            throw ios::exception(ios::exception::error::__notfileupdater);
        case options_for_copy_and_move::overwrite:
        {
            ios::directory::remove_file(newfile.c_str());
            break;
        }
        default:
        {
            __standartcout << __string("El archivo \"") + sources.name() + __string("\" ya existe en el direcrorio \"") + destine.string() << std::endl;
            options = ask_options_for_copy_and_move_file();
            if (options != ios::directory::options_for_copy_and_move::asking_before)
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
void ios::directory::copy(const ios::Url &sources, const ios::Url &destine, ios::directory::options_for_copy_and_move options)
{
    if (!ios::Url::is_directory(destine))
        throw ios::exception(ios::exception::error::__notfolderdestine);
    if (ios::Url::is_directory(sources))
    {
        ios::Url newdestine;
        ios::directory::create_directory(destine, sources.name(), static_cast<options_for_create>(options), &newdestine);
        for (auto &&ifile : ios::directory::container(sources))
        {
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
            {
                __string newsources = sources.string() + __concaturl + ifile.cFileName;
                ios::directory::copy(newsources, newdestine, options);
            }
        }
    }
    else
        copy_file(sources, destine, options == options_for_copy_and_move::update ? options_for_copy_and_move::duplicate : options);
}

void ios::directory::move_file(const ios::Url &sources, const ios::Url &destine, directory::options_for_copy_and_move options)
{
    __string newfile = (destine.string() + __concaturl + sources.name());
    if (!ios::Url::is_directory(destine))
        throw ios::exception(ios::exception::error::__notfolderdestine);
    if (ios::Url::is_exist(newfile.c_str()) && options_for_copy_and_move::overwrite != options)
    {
    repetnotblockask:
        switch (options)
        {
        case options_for_copy_and_move::duplicate:
        {
            ios::directory::__generate__fast__rename__(newfile, newfile.find_last_of(__dot));
            break;
        }
        case options_for_copy_and_move::update:
            throw ios::exception(ios::exception::error::__notfileupdater);
        case options_for_copy_and_move::overwrite:
        {
            ios::directory::remove_file(newfile.c_str());
            break;
        }
        default:
        {
            __standartcout << __string("El archivo \"") + sources.name() + __string("\" ya existe en el direcrorio \"") + destine.string() << std::endl;
            options = ask_options_for_copy_and_move_file();
            if (options != ios::directory::options_for_copy_and_move::asking_before)
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
void ios::directory::move(const ios::Url &sources, const ios::Url &destine, ios::directory::options_for_copy_and_move options)
{
    if (!ios::Url::is_directory(destine))
        throw ios::exception(ios::exception::error::__notfolderdestine);
    if (ios::Url::is_directory(sources))
    {
        ios::Url newdestine;
        ios::directory::create_directory(destine, sources.name(), static_cast<options_for_create>(options), &newdestine);
        for (auto &&ifile : ios::directory::container(sources))
        {
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
            {
                __string newsources = sources.string() + __concaturl + ifile.cFileName;
                ios::directory::move(newsources, newdestine, options);
            }
        }
    }
    else
        move_file(sources, destine, options == options_for_copy_and_move::update ? options_for_copy_and_move::duplicate : options);
}

void ios::directory::back_folder(ios::Url &url)
{
    url = url.parent();
}
void ios::directory::open_folder(ios::Url &url, const __caracter *_str)
{
    url = ios::Url(url.string() + __concaturl + _str, true);
}
void ios::directory::open_folder(ios::Url &url, const __string &_str)
{
    url = ios::Url(url.string() + __concaturl + _str, true);
}

void ios::directory::view_root(const ios::Url &url, bool recursive)
{
    __standartcout << url.name() << std::endl;
    /////////////////////////////////////////////////////////////
    if (ios::Url::is_directory(url))
    {
        for (auto &&ifile : ios::directory::container(url))
        {
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
            {
                __string v = url.string() + __concaturl + ifile.cFileName;
                ios::directory::__intern__viewer__directory__(v, 2, recursive);
            }
        }
    }
}
bool ios::directory::__intern__viewer__directory__(const ios::Url &url, size_t n_profundidad, bool recursive)
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
    if (!ios::Url::is_directory(url))
        return true;
    /////////////////////////////////////////////////////////////
    for (auto &&ifile : ios::directory::container(url))
    {
        if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
            ios::directory::__intern__viewer__directory__(url.string() + __concaturl + ifile.cFileName, n_profundidad + 1, recursive);
    }
    return true;
}

void ios::directory::create_directory(const ios::Url &url, const __caracter *name, directory::options_for_create options, ios::Url *update)
{
    create_directory(url, __string(name), options, update);
}
void ios::directory::create_directory(const ios::Url &url, const __string &name, directory::options_for_create options, ios::Url *update)
{
    __string newpath = url.string() + __concaturl + name;
    if (ios::Url::is_exist(newpath.c_str()))
    {
    repetnotblockask:
        switch (options)
        {
        case directory::options_for_create::duplicate:
        {
            ios::directory::__generate__fast__rename__(newpath, newpath.size());
            break;
        }
        case directory::options_for_create::overwrite:
        {
            __standartcout << __string("Esta seguro de sobreescribir el directorio \"") + name + __string("\" se borraran todos los archivos: \nSi: 1\nNo: 0\n:");
            unsigned char c;
            __standartcin >> c;
            if (c == 1)
                ios::directory::remove(newpath);
        }
        case directory::options_for_create::overwrite_not_ask:
        {
            ios::directory::remove(newpath.c_str());
        }
        case directory::options_for_create::asking_before:
        {
            __standartcout << __string("El directorio \"") + name + __string("\" ya existe en el direcrorio \"") + url.string() << std::endl;
            options = ask_options_for_create();
            if (options != ios::directory::options_for_create::asking_before)
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
        throw ios::exception(ios::exception::error::__notexistingfolder);
    if (update != nullptr)
        *update = newpath;
outignore:
    return;
}
ios::iofstream ios::directory::open_file(const ios::Url &url, bool binary, bool syncroned_input_output_system)
{
    return ios::iofstream(url, binary, syncroned_input_output_system);
}

void ios::directory::remove(const ios::Url &sources)
{
    if (ios::Url::is_directory(sources))
    {
        for (auto &&ifile : ios::directory::container(sources))
            if (__compare(ifile.cFileName, __dot) != 0 && __compare(ifile.cFileName, __dot2) != 0)
                ios::directory::remove(sources.string() + __concaturl + ifile.cFileName);
        if (
#if defined(USINGWCARACTER)
            !RemoveDirectoryW(sources.c_str())
#else
            !RemoveDirectoryA(sources.c_str())
#endif
        )
            throw ios::exception(__string("Error: No se puede eliminar el directorio, \"") + sources.string() + "\" y el sistema lanzo el siguiente error: \n" + ios::directory::get_last_error());
    }
    else
        ios::directory::remove_file(sources);
}
void ios::directory::remove_file(const ios::Url &sources)
{
    if (ios::Url::is_directory(sources))
        throw ios::exception(ios::exception::error::__notfolderdestine);
    if (
#if defined(USINGWCARACTER)
        !DeleteFileW(sources.c_str())
#else
        !DeleteFileA(sources.c_str())
#endif
    )
        throw ios::exception(__string("Error: No se puede eliminar el directorio, \"") + sources.string() + "\" y el sistema lanzo el siguiente error: \n" + ios::directory::get_last_error());
}

void ios::directory::rename(const ios::Url &url, const __caracter *new_name, bool ignore_type)
{
    ios::Url newurl = url.parent() + new_name;
    ios::directory::move(url, newurl);
}

void ios::directory::__generate__fast__rename__(__string &str, size_t pos)
{
    size_t count = 0;
    while (ios::Url::is_exist(str.c_str()))
    {
        if (pos >= str.size())
            str.append("(" + __to_str(count + 1) + ")");
        else
            str.insert(pos, "(" + __to_str(count + 1) + ")");
        count++;
    }
}

ios::Url ios::directory::getPathRecycle()
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
        return ios::Url(__ruta);
    }
    throw ios::exception("No se pudo encontrar la ruta de la papelara de reciclaje.");
    return "";
}

void ios::directory::create_file(const Url &url, const __caracter *name, options_for_create options, Url *update)
{
    __string newpath = url.string() + __concaturl + name;
    ios::fstream ocl;
    if (ios::Url::is_exist(newpath.c_str()))
    {
    repetnotblockask:
        switch (options)
        {
        case directory::options_for_create::duplicate:
        {
            ios::directory::__generate__fast__rename__(newpath, newpath.size());
            break;
        }
        case directory::options_for_create::overwrite:
        {
            __standartcout << __string("Esta seguro de sobreescribir el directorio \"") + name + __string("\" se borraran todos los archivos: \nSi: 1\nNo: 0\n:");
            unsigned char c;
            __standartcin >> c;
            if (c != 1)
                goto outignore;
        }
        case directory::options_for_create::overwrite_not_ask:
        {
            goto ejecuteaction;
        }
        case directory::options_for_create::asking_before:
        {
            __standartcout << __string("El directorio \"") + name + __string("\" ya existe en el direcrorio \"") + url.string() << std::endl;
            options = ask_options_for_create();
            if (options != ios::directory::options_for_create::asking_before)
                goto repetnotblockask;
            break;
        }
        default:
            goto outignore;
            break;
        }
    }
ejecuteaction:
    ocl = ios::fstream(newpath.c_str(), ios::out);
    ios::fstream::close(ocl);
    if (update != nullptr)
        *update = newpath;
outignore:
    return;
}
void ios::directory::create_file(const Url &url, const __string &name, options_for_create options, Url *update)
{
    ios::directory::create_file(url, name, options, update);
}