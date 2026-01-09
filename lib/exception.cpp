#include <stda/system/exceptions/exceptions.hpp>

const char *System::Exception::what() const noexcept
{
    return __message__;
} 