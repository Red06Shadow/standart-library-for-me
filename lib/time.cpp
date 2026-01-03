#include <stda/system/time/time.hpp>


const char *systems::time::weekstext[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
const char *systems::time::monthstext[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

u16 systems::time::time_point::clockregulate12h(u16 horsformat24h, bool& pm)
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

std::string systems::time::time_point::clocklarge12(const time_point &__tallocator)
{
    bool pm = false;
    u16 hours = clockregulate12h(__tallocator.hours, pm);
    return (hours < 10 ? "0" : "") + std::to_string(hours) + ":" + (__tallocator.mins < 10 ? "0" : "") + std::to_string(__tallocator.mins) + ":" + (__tallocator.seconds < 10 ? "0" : "") + std::to_string(__tallocator.seconds) + ((pm)?" pm":" am");
}
std::string systems::time::time_point::clocklarge24(const time_point &__tallocator)
{
    return (__tallocator.hours < 10 ? "0" : "") + std::to_string(__tallocator.hours) + ":" + (__tallocator.mins < 10 ? "0" : "") + std::to_string(__tallocator.mins) + ":" + (__tallocator.seconds < 10 ? "0" : "") + std::to_string(__tallocator.seconds);
}
std::string systems::time::time_point::clockshort12(const time_point &__tallocator)
{
    bool pm = false;
    u16 hours = clockregulate12h(__tallocator.hours, pm);
    return (hours < 10 ? "0" : "") + std::to_string(hours) + ":" + (__tallocator.mins < 10 ? "0" : "") + std::to_string(__tallocator.mins) + ((pm)?" pm":" am");
}
std::string systems::time::time_point::clockshort24(const time_point &__tallocator)
{
    return (__tallocator.hours < 10 ? "0" : "") + std::to_string(__tallocator.hours) + ":" + (__tallocator.mins < 10 ? "0" : "") + std::to_string(__tallocator.mins);
}
std::string systems::time::time_point::dateshort(const time_point &__tallocator)
{
    return std::to_string(__tallocator.days_of_month) + "/" + std::to_string(__tallocator.month + 1) + "/" + std::to_string(__tallocator.years + 1900);
}
std::string systems::time::time_point::datelarge(const time_point &__tallocator)
{
    return std::to_string(__tallocator.days_of_month) + "." + systems::time::monthstext[__tallocator.month] + "." + std::to_string(__tallocator.years + 1900);
}
std::string systems::time::time_point::datelargewithweekday(const time_point &__tallocator)
{
    return systems::time::weekstext[__tallocator.days_of_weeks] + std::string(" ") + std::to_string(__tallocator.days_of_month) + "." + systems::time::monthstext[__tallocator.month] + "." + std::to_string(__tallocator.years + 1900);
}

systems::time::time_point::TimerFormat systems::time::time_point::to_stringformatdate[4] =
    {
        dateshort,
        datelarge,
        datelargewithweekday};
systems::time::time_point::TimerFormat systems::time::time_point::to_stringformatclock[4] =
    {
        clockshort12,
        clockshort24,
        clocklarge12,
        clocklarge24};

std::vector<systems::chrono::time_point> clockcontainer = {};
