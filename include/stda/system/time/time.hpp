#include <stda/standart/numbers.hpp>
#include <time.h>
#include <ctime>
#include <chrono>
#include <vector>
#include <stdexcept>
#include <thread>

#ifndef TIMES
#define TIMES

class timesystem
{
private:
    static time_t __now;
    static tm *__sytime;
    static const char *weekstext[7];
    static const char *monthstext[12];

public:
    enum class formatdate : u8
    {
        shortlow,
        large,
        largewithweekday
    };
    enum class formatclock : u8
    {
        short12h,
        short24h,
        large12h,
        large24h
    };

    class time_point
    {
    protected:
        typedef std::string (*TimerFormat)(const time_point &__tallocator);

    private:
        u16 years;
        u16 month;
        u16 weeks;
        ///////////
        u16 days_of_years;
        u16 days_of_month;
        u16 days_of_weeks;
        ///////////
        u16 hours;
        u16 mins;
        u16 seconds;
        static TimerFormat to_stringformatdate[4];
        static TimerFormat to_stringformatclock[4];

        static u16 clockregulate12h(u16 horsformat24h);
        static std::string clocklarge12(const time_point &__tallocator);
        static std::string clocklarge24(const time_point &__tallocator);
        static std::string clockshort12(const time_point &__tallocator);
        static std::string clockshort24(const time_point &__tallocator);
        static std::string dateshort(const time_point &__tallocator);
        static std::string datelarge(const time_point &__tallocator);
        static std::string datelargewithweekday(const time_point &__tallocator);

    public:
        time_point() {}
        time_point(u16 __years, u16 __month, u16 __weeks, u16 __days_of_years, u16 __days_of_month, u16 __days_of_weeks, u16 __hours, u16 __mins, u16 __seconds) : years(__years), month(__month), weeks(__weeks), days_of_years(__days_of_years), days_of_month(__days_of_month), days_of_weeks(__days_of_weeks), hours(__hours), mins(__mins), seconds(__seconds) {}
        std::string to_string(formatdate fdate = formatdate::shortlow, formatclock fclock = formatclock::short12h)
        {
            return (to_stringformatdate[static_cast<u8>(fdate)])(*this) + "   " + (to_stringformatclock[static_cast<u8>(fclock)])(*this);
        }
        ~time_point() {}
    };
    static time_point get_time_now()
    {
        return time_point(__sytime->tm_year, __sytime->tm_mon, __sytime->tm_isdst, __sytime->tm_yday, __sytime->tm_mday, __sytime->tm_wday, __sytime->tm_hour, __sytime->tm_min, __sytime->tm_sec);
    }
    static u16 get_day_of_years(u16 year) { return ((year % 4 == 0 && year % 400 != 0) ? 366 : 365); }
    static time_t get_seed_time_now() { return time(nullptr); }
};

class chrono
{
public:
    typedef std::chrono::high_resolution_clock::time_point time_point;
    using seconds = std::chrono::seconds;
    using milliseconds = std::chrono::milliseconds;
    using nanoseconds = std::chrono::nanoseconds;

private:
    static std::vector<time_point> clockcontainer;

public:

    static time_point &get(size_t idclock) { return clockcontainer[idclock]; }
    static size_t push(const time_point &_clock)
    {
        clockcontainer.push_back(_clock);
        return clockcontainer.size() - 1;
    }
    static const time_point now() { return std::chrono::high_resolution_clock::now(); }

    template <typename _Notation>
    static const _Notation getSeconds(const time_point &_clock) {
        return std::chrono::duration_cast<std::chrono::seconds>(_clock - time_point()).count();
    }
    template <typename _Notation>
    static const _Notation getMiliseconds(const time_point &_clock) {
        return std::chrono::duration_cast<std::chrono::milliseconds>(_clock - time_point()).count();
    }
    template <typename _Notation>
    static const _Notation getNanoseconds(const time_point &_clock) {
        return (_clock - time_point()).count();
    }
    template <typename _Fromat = std::chrono::milliseconds>
    static const size_t count(const std::chrono::duration<int64_t, std::nano> &__duration)
    {
        return std::chrono::duration_cast<_Fromat>(__duration).count();
    }
    template <typename _Notation, typename _Fromat = std::chrono::milliseconds>
    static _Notation max() { return std::chrono::duration<_Notation, _Fromat>::max(); }
    template <typename _Notation, typename _Fromat = std::chrono::milliseconds>
    static _Notation min() { return std::chrono::duration<_Notation, _Fromat>::min(); }
    template <typename _Fromat = std::chrono::milliseconds>
    static void sleep(int64_t time, const char *message = nullptr)
    {
        if (message != nullptr)
            std::cout << ">> " << message << std::endl;
        std::this_thread::sleep_for(_Fromat(time));
    }
    static void wait_for_signal(bool& _v) {
        while (_v);
    }
    static void wait_for_input(bool& _v) {
        char k;
        std::cin >> k;
        std::cin.clear();
    }
};
#endif