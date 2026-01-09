#include <stda/system/Time/Time.hpp>


const char *System::Time::weekstext[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
const char *System::Time::monthstext[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

u16 System::Time::Point::clockregulate12h(u16 horsformat24h, bool& pm)
{
    if (horsformat24h == 0)
    {
        pm = false;
        return 12;
    }
    else if (horsformat24h > 12)
    {
        pm = true;
        return horsformat24h - 12;
    }
    else
    {
        pm = false;
        return horsformat24h;
    }
}

std::string System::Time::Point::clocklarge12(const Point &__tallocator)
{
    bool pm = false;
    u16 hours = clockregulate12h(__tallocator.hours, pm);
    return (hours < 10 ? "0" : "") + std::to_string(hours) + ":" + (__tallocator.mins < 10 ? "0" : "") + std::to_string(__tallocator.mins) + ":" + (__tallocator.seconds < 10 ? "0" : "") + std::to_string(__tallocator.seconds) + ((pm)?" pm":" am");
}
std::string System::Time::Point::clocklarge24(const Point &__tallocator)
{
    return (__tallocator.hours < 10 ? "0" : "") + std::to_string(__tallocator.hours) + ":" + (__tallocator.mins < 10 ? "0" : "") + std::to_string(__tallocator.mins) + ":" + (__tallocator.seconds < 10 ? "0" : "") + std::to_string(__tallocator.seconds);
}
std::string System::Time::Point::clockshort12(const Point &__tallocator)
{
    bool pm = false;
    u16 hours = clockregulate12h(__tallocator.hours, pm);
    return (hours < 10 ? "0" : "") + std::to_string(hours) + ":" + (__tallocator.mins < 10 ? "0" : "") + std::to_string(__tallocator.mins) + ((pm)?" pm":" am");
}
std::string System::Time::Point::clockshort24(const Point &__tallocator)
{
    return (__tallocator.hours < 10 ? "0" : "") + std::to_string(__tallocator.hours) + ":" + (__tallocator.mins < 10 ? "0" : "") + std::to_string(__tallocator.mins);
}
std::string System::Time::Point::dateshort(const Point &__tallocator)
{
    return std::to_string(__tallocator.days_of_month) + "/" + std::to_string(__tallocator.month + 1) + "/" + std::to_string(__tallocator.years + 1900);
}
std::string System::Time::Point::datelarge(const Point &__tallocator)
{
    return std::to_string(__tallocator.days_of_month) + "." + System::Time::monthstext[__tallocator.month] + "." + std::to_string(__tallocator.years + 1900);
}
std::string System::Time::Point::datelargewithweekday(const Point &__tallocator)
{
    return System::Time::weekstext[__tallocator.days_of_weeks] + std::string(" ") + std::to_string(__tallocator.days_of_month) + "." + System::Time::monthstext[__tallocator.month] + "." + std::to_string(__tallocator.years + 1900);
}

System::Time::Point::TimerFormat System::Time::Point::to_stringformatdate[4] =
    {
        dateshort,
        datelarge,
        datelargewithweekday};
System::Time::Point::TimerFormat System::Time::Point::to_stringformatclock[4] =
    {
        clockshort12,
        clockshort24,
        clocklarge12,
        clocklarge24};

std::vector<System::Chrono::Point> clockcontainer = {};
