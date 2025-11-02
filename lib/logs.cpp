#include <stda/system/logs/logs.hpp>

logssystem::logs::logs(const __caracter *_message, logssystem::logs::type _id) : message(_message), id(_id), time(timesystem::get_time_now()) {}
logssystem::logs::logs(const __string &_message, logssystem::logs::type _id) : message(_message.c_str(), _message.size()), id(_id), time(timesystem::get_time_now()) {}
logssystem::logs::logs(const __stringbuffer &_message, logssystem::logs::type _id) : message(_message), id(_id), time(timesystem::get_time_now()) {}
logssystem::logs::logs(const std::exception &_message, logssystem::logs::type _id) : message(_message.what()), id(_id), time(timesystem::get_time_now()) {}

const char *logssystem::manager::codecolor[4] =
    {
        "\x1b[32m",
        "\x1b[33m",
        "\x1b[31m",
        "\033[m"};
const char *logssystem::manager::codemensage[4]{
    "Message",
    "Warning",
    "Error",
    "None"};
std::vector<logssystem::logs> logssystem::manager::allocator = {};
const char *logssystem::manager::nameprogram = __argv[0];

void logssystem::manager::exportfile(const ios::Url &path)
{
    ios::ofstream os(path);
    for (auto &&log : allocator)
        os << log.time.to_string(timesystem::formatdate::shortlow, timesystem::formatclock::large24h) << "  " << nameprogram << "  " << codemensage[static_cast<u8>(log.id)] << "  " << log.message << '\n';
}
void logssystem::manager::view()
{
    for (auto &&log : allocator)
        std::cerr << codecolor[static_cast<u8>(log.id)] << log.time.to_string(timesystem::formatdate::shortlow, timesystem::formatclock::large24h) << "  " << nameprogram << "  " << codemensage[static_cast<u8>(log.id)] << "  " << log.message.c_str() << codecolor[3] << '\n';
}
void logssystem::manager::serialize(const logssystem::logs &log) {
    if(allocator.capacity() < 256) allocator.reserve(256);
    allocator.push_back(log);
}

