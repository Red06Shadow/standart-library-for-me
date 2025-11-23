#include <stda/system/exception/exception.hpp>

char const *const systems::exception::errors[__SIZE__] =
{
    "Fallo la operacion de entrada o salida en las operaciones",
    "No se puede otra entidad que no sea una carpeta para poder definirla como destino",
    "No se puede obtener el tamano del archivo",
    "No se ejecutar la opcion actualizar(update) en archivos",
    "Error: Invalid operation for move and copy options",
    "No existe ese directorio",
};

const char *systems::exception::what() const noexcept
{
    if(__error__ != error::__other)
        return static_cast<unsigned int>(__error__) > 0 ? errors[static_cast<unsigned int>(__error__) - 1] : "";
    return __other__;
}