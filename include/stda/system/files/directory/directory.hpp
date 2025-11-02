#include <stda/system/files/fstream/fstream.hpp>
#include <shlobj.h>
#include <thread>

#ifndef DIRECTORY
#define DIRECTORY

#if defined(USINGWCARACTER)
using w32fdata = WIN32_FIND_DATAW;
#else
using w32fdata = WIN32_FIND_DATAA;
#endif

namespace ios
{
    class directory
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Opciones para la copia y movimiento de carpetas y archivos
        enum class options_for_copy_and_move : unsigned char
        {
            asking_before,           // Pregunta que operacion se desea hacer con cada archivo
            duplicate,               // Duplica los archivos y carpetas con un identificador adicional
            overwrite,               // Sobreescribe la carpeta o el archivo
            overwrite_not_ask,       // Sobreescribe la carpeta o el archivo sin preguntar al usuario si desea mantener el directorio o el archivo
            update,                  // Only folder: Actualiza la carpeta agragando los elemntos que no existan y ejecutando el resto de operaciones si es la continuacion
            _default = asking_before // Modo por defecto de las operaciones
        };
        /// @brief Opciones para la creacion carpetas y archivos
        enum class options_for_create : unsigned char
        {
            asking_before,           // Pregunta que operacion se desea hacer con cada archivo
            duplicate,               // Duplica los archivos y carpetas con un identificador adicional
            overwrite,               // Sobreescribe la carpeta o el archivo
            overwrite_not_ask,       // Sobreescribe la carpeta o el archivo sin preguntar al usuario si desea mantener el directorio o el archivo
            _default = asking_before // Modo por defecto de las operaciones
        };
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        class container
        {
        private:
            w32fdata __main__;
            HANDLE __hanlde__;

        public:
            class iterator
            {
            private:
                const w32fdata *__ptr__main__;
                const HANDLE &ref_handle;
                friend container;

            public:
                explicit iterator(const w32fdata *__receptor__, const HANDLE &__handle) : ref_handle(__handle), __ptr__main__(__receptor__) {}

                bool operator==(const iterator &otro) const { return this->__ptr__main__ == otro.__ptr__main__; }
                bool operator!=(const iterator &otro) const { return this->__ptr__main__ != otro.__ptr__main__; }

                w32fdata &operator*() { return *(const_cast<w32fdata *>(__ptr__main__)); }
                w32fdata *operator->() { return const_cast<w32fdata *>(__ptr__main__); }

                iterator &operator++()
                {
                    if (
#if defined(USINGWCARACTER)
                        FindNextFileW(ref_handle, const_cast<w32fdata *>(__ptr__main__)) == 0
#else
                        FindNextFileA(ref_handle, const_cast<w32fdata *>(__ptr__main__)) == 0
#endif
                    )
                        __ptr__main__ = nullptr;
                    return *this;
                }

                iterator operator++(int)
                {
                    iterator temp(*this);
                    ++(*this);
                    return temp;
                }
            };

            container() {}
            container(const Url &url)
            {
#if defined(USINGWCARACTER)
                __hanlde__ = FindFirstFileExW((url.string() + L"\\*").c_str(), FindExInfoStandard, &__main__, FindExSearchNameMatch, NULL, FIND_FIRST_EX_LARGE_FETCH);
#else
                __hanlde__ = FindFirstFileExA((url.string() + "\\*").c_str(), FindExInfoStandard, &__main__, FindExSearchNameMatch, NULL, FIND_FIRST_EX_LARGE_FETCH);
#endif
                if (__hanlde__ == INVALID_HANDLE_VALUE)
                    throw ios::exception(ios::exception::error::__notexistingfolder);
// Codigo para proximas versiones
//                 size_t v = 0;
//                 do
//                 {
//                     if ((__compare(__main__.cFileName, __dot) != 0 && __compare(__main__.cFileName, __dot2) != 0)) break;
//                 } while (
//                     #if defined(USINGWCARACTER)
//                         (v = FindNextFileW(__hanlde__, &__main__)) == 0
// #else
//                         (v = FindNextFileA(__hanlde__, &__main__)) == 0
// #endif
//                 );
//                 if(v == 0)                 
            }
            iterator begin() { return iterator(&__main__, __hanlde__); }
            iterator end() { return iterator(nullptr, __hanlde__); }
            ~container()
            {
                FindClose(__hanlde__);
            }
        };
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Obtiene el ultimo error lanzado por el sistema operativo
        /// @return Devuelve un __string con el mensaje de error del sistema
        static __string get_last_error();
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Copia un directorio o archivo de una ruta a otra
        /// @param sources Path(Ruta) de deseada
        /// @param destine Path(Ruta) de destino
        /// @param options Opciones para la copia
        static void copy(const Url &sources, const Url &destine, directory::options_for_copy_and_move options = directory::options_for_copy_and_move::asking_before);
        /// @brief Copia un archivo de una ruta a otra
        /// @param sources Path(Ruta) de deseada Aclaracion: Saltara un error si intentas mover un directorio
        /// @param destine Path(Ruta) de destino
        /// @param options Opciones para la copia
        static void copy_file(const Url &sources, const Url &destine, directory::options_for_copy_and_move options = directory::options_for_copy_and_move::asking_before);
        /// @brief Mueve un directorio o archivo de una ruta a otra
        /// @param sources Path(Ruta) de deseada
        /// @param destine Path(Ruta) de destino
        /// @param options Opciones para la copia
        static void move(const Url &sources, const Url &destine, directory::options_for_copy_and_move options = directory::options_for_copy_and_move::asking_before);
        /// @brief Mueve un archivo de una ruta a otra
        /// @param sources Path(Ruta) de deseada Aclaracion: Saltara un error si intentas mover un directorio
        /// @param destine Path(Ruta) de destino
        /// @param options Opciones para la copia
        static void move_file(const Url &sources, const Url &destine, directory::options_for_copy_and_move options = directory::options_for_copy_and_move::asking_before);
        /// @brief Transforma la ruta insertada como parametro al directorio anterior
        /// @param url Path(Ruta) de deseada
        static void back_folder(Url &url);
        /// @brief Abre una carpeta deseada si existe en el directorio, sino lanzara el error
        /// @param url Path(Ruta) donde estaria la carpeta
        /// @param _str Nombre de la carpeta
        static void open_folder(Url &url, const __caracter *_str);
        /// @brief Abre una carpeta deseada si existe en el directorio, sino lanzara el error
        /// @param url Path(Ruta) donde estaria la carpeta
        /// @param _str Nombre de la carpeta
        static void open_folder(Url &url, const __string &_str);
        /// @brief Da una vista desde la terminar de las carpetas y archivos que existen dentro del directorio
        /// @param url Path(Ruta) de deseada
        /// @param recursive Esto generara un arbol con todas las subcarpetas y archivos dentro de estas
        static void view_root(const Url &url, bool recursive = false);
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Crea una carpeta nueva en el directorio y si se realiza un cambio interno dentro de la ruta afectara la pasada
        /// @param url Ruta del archivo(Se modifica si existe algun cambio dentro)
        /// @param name Nommbre del archivo(Si ya existe los cambios dentro de esta solo afectaran la ruta)
        /// @param options Opciones para crear carpteas
        static void create_directory(const Url &url, const __caracter *name, options_for_create options, Url *update = nullptr);
        /// @brief Crea una carpeta nueva en el directorio y si se realiza un cambio interno dentro de la ruta afectara la pasada
        /// @param url Ruta del archivo(Se modifica si existe algun cambio dentro)
        /// @param name Nommbre del archivo(Si ya existe los cambios dentro de esta solo afectaran la ruta)
        /// @param options Opciones para crear carpteas
        static void create_directory(const Url &url, const __string &name, options_for_create options, Url *update = nullptr);
        /// @brief Obtiene el tamano de los archivos y de directorios
        /// @param url Ruta del archvio
        /// @return Devuelve el numero de Bytes del conjuto
        static size_t size(const Url &url);
        /// @brief Obtiene el tamano de los archivos
        /// @param url Ruta del archvio
        /// @return Devuelve el numero de Bytes del archivo
        static size_t size_file(const Url &url);
        /// @brief Abre un archivo existe y genera un objeto iofstream para manejar el archivo 
        /// @param url Ruta del archvio
        /// @param binary Si la lectura del archivo sera binaria o en texto
        /// @param syncroned_input_output_system Si el sistema de engtrada estara sincronizado con el de salida(que los punteros y buffers sean unicos para ambos modos)
        /// @return el objecto iofstream
        static ios::iofstream open_file(const Url &url, bool binary = false, bool syncroned_input_output_system = false);

        static void create_file(const Url &url, const __caracter* name, options_for_create options, Url *update = nullptr);
        static void create_file(const Url &url, const __string& name, options_for_create options, Url *update = nullptr);

        static void remove(const Url &sources);
        static void remove_file(const Url &sources);
        static void rename(const Url& url, const __caracter *new_name, bool ignore_type = true);
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////

    private:
        // static Url recylePath;
        inline static bool __interfaces_avilite__ = false;
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////
        static void __stdcall copy_and_move_progress_interface(LARGE_INTEGER __totalFileSize,
                                                               LARGE_INTEGER __totalBytesTransferrend,
                                                               LARGE_INTEGER __streamSize,
                                                               LARGE_INTEGER __StreamBytesTransferrend,
                                                               DWORD __dwStreamNumber,
                                                               DWORD __callBackReason,
                                                               HANDLE __hSorcesFile,
                                                               HANDLE __hDestinationFile,
                                                               LPVOID lpData);
        static bool __intern__viewer__directory__(const Url &url, size_t n_profundidad, bool recursive = false);
        static directory::options_for_copy_and_move ask_options_for_copy_and_move_file();
        static directory::options_for_create ask_options_for_create();
        static void __generate__fast__rename__(__string &str, size_t pos);
        template <typename T, typename Q>
        static T cases_optimizate(Q input, Q invalid_values_of_greath_equals);
        static Url getPathRecycle();
    };
}

// static bool recyle(const Url url);

// static size_t allocate_url(const Url url, Fstream *fstream_only_file = nullptr);
// static Directory::Token get(size_t id);

#endif