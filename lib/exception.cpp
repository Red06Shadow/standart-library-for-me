#include <stda/system/exceptions/exceptions.hpp>

const char *systems::exception::what() const noexcept
{
    return __message__;
} 