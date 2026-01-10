#include <stda/system/logs/logs.hpp>

System::Log::Log(const __caracter *_message, System::Log::Id _id) : message(_message), id(_id), time(System::Time::now()) {}
System::Log::Log(const __string &_message, System::Log::Id _id) : message(_message.c_str(), _message.size()), id(_id), time(System::Time::now()) {}
System::Log::Log(const __stringbuffer &_message, System::Log::Id _id) : message(_message), id(_id), time(System::Time::now()) {}
System::Log::Log(const std::exception &_message, Id _id) : message(_message.what()), id(_id), time(System::Time::now()) {}
System::Log::Log(const Exception &_message) : message(_message.what()), time(System::Time::now())
{
    unsigned char u = static_cast<unsigned char>(_message.signal()) + 1;
    id = static_cast<System::Log::Id>(u);
}
System::Log::Log(const Windows_Exceptions &_message) : message(_message.what()), time(System::Time::now())
{
    unsigned char u = static_cast<unsigned char>(_message.signal()) + 1;
    id = static_cast<System::Log::Id>(u);
}

const char *System::Log_Manager::codecolor[4] =
    {
        "\x1b[32m",
        "\x1b[33m",
        "\x1b[31m",
        "\033[m"};
const char *System::Log_Manager::codemensage[4]{
    "Message",
    "Warning",
    "Error",
    "None"};
std::vector<System::Log> System::Log_Manager::allocator = {};
const char *System::Log_Manager::nameprogram = __argv[0];

void System::Log_Manager::exportfile(const System::Url &path)
{
    System::Ios::ofstream os(path);
    for (auto &&log : allocator)
        os << log.time.to_string(System::Time::formatdate::shortlow, System::Time::formatclock::large24h) << "  " << nameprogram << "  " << codemensage[static_cast<u8>(log.id)] << "  " << log.message << '\n';
}
void System::Log_Manager::view()
{
    for (auto &&log : allocator)
        std::cerr << codecolor[static_cast<u8>(log.id)] << log.time.to_string(System::Time::formatdate::shortlow, System::Time::formatclock::large24h) << "  " << nameprogram << "  " << codemensage[static_cast<u8>(log.id)] << "  " << log.message.c_str() << codecolor[3] << '\n';
}
void System::Log_Manager::serialize(const System::Log &log)
{
    if (allocator.capacity() < 256)
        allocator.reserve(256);
    allocator.push_back(log);
}
