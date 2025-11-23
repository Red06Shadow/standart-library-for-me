#include <stda/system/logs/logs.hpp>

systems::logs::logs(const __caracter *_message, systems::logs::type _id) : message(_message), id(_id), time(systems::time::now()) {}
systems::logs::logs(const __string &_message, systems::logs::type _id) : message(_message.c_str(), _message.size()), id(_id), time(systems::time::now()) {}
systems::logs::logs(const __stringbuffer &_message, systems::logs::type _id) : message(_message), id(_id), time(systems::time::now()) {}
systems::logs::logs(const std::exception &_message, systems::logs::type _id) : message(_message.what()), id(_id), time(systems::time::now()) {}

const char *systems::log_manager::codecolor[4] =
    {
        "\x1b[32m",
        "\x1b[33m",
        "\x1b[31m",
        "\033[m"};
const char *systems::log_manager::codemensage[4]{
    "Message",
    "Warning",
    "Error",
    "None"};
std::vector<systems::logs> systems::log_manager::allocator = {};
const char *systems::log_manager::nameprogram = __argv[0];

void systems::log_manager::exportfile(const systems::Url &path)
{
    systems::ios::ofstream os(path);
    for (auto &&log : allocator)
        os << log.time.to_string(systems::time::formatdate::shortlow, systems::time::formatclock::large24h) << "  " << nameprogram << "  " << codemensage[static_cast<u8>(log.id)] << "  " << log.message << '\n';
}
void systems::log_manager::view()
{
    for (auto &&log : allocator)
        std::cerr << codecolor[static_cast<u8>(log.id)] << log.time.to_string(systems::time::formatdate::shortlow, systems::time::formatclock::large24h) << "  " << nameprogram << "  " << codemensage[static_cast<u8>(log.id)] << "  " << log.message.c_str() << codecolor[3] << '\n';
}
void systems::log_manager::serialize(const systems::logs &log) {
    if(allocator.capacity() < 256) allocator.reserve(256);
    allocator.push_back(log);
}

