#include <stda/system/time/time.hpp>

time_t timesystem::__now = time(nullptr);
tm *timesystem::__sytime = localtime(&timesystem::__now);

const char *timesystem::weekstext[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
const char *timesystem::monthstext[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

u16 timesystem::time_point::clockregulate12h(u16 horsformat24h)
{
    if (horsformat24h == 0)
        return 12;
    else if (horsformat24h > 12)
        return horsformat24h - 12;
    else
        return horsformat24h;
}

std::string timesystem::time_point::clocklarge12(const time_point &__tallocator)
{
    return (clockregulate12h(__tallocator.hours) < 10 ? "0" : "") + std::to_string(__tallocator.hours) + ":" + (__tallocator.mins < 10 ? "0" : "") + std::to_string(__tallocator.mins) + ":" + (__tallocator.seconds < 10 ? "0" : "") + std::to_string(__tallocator.seconds);
}
std::string timesystem::time_point::clocklarge24(const time_point &__tallocator)
{
    return (__tallocator.hours < 10 ? "0" : "") + std::to_string(__tallocator.hours) + ":" + (__tallocator.mins < 10 ? "0" : "") + std::to_string(__tallocator.mins) + ":" + (__tallocator.seconds < 10 ? "0" : "") + std::to_string(__tallocator.seconds);
}
std::string timesystem::time_point::clockshort12(const time_point &__tallocator)
{
    return (clockregulate12h(__tallocator.hours) < 10 ? "0" : "") + std::to_string(__tallocator.hours) + ":" + (__tallocator.mins < 10 ? "0" : "") + std::to_string(__tallocator.mins);
}
std::string timesystem::time_point::clockshort24(const time_point &__tallocator)
{
    return (__tallocator.hours < 10 ? "0" : "") + std::to_string(__tallocator.hours) + ":" + (__tallocator.mins < 10 ? "0" : "") + std::to_string(__tallocator.mins);
}
std::string timesystem::time_point::dateshort(const time_point &__tallocator)
{
    return std::to_string(__tallocator.days_of_month) + "/" + std::to_string(__tallocator.month + 1) + "/" + std::to_string(__tallocator.years + 1900);
}
std::string timesystem::time_point::datelarge(const time_point &__tallocator)
{
    return std::to_string(__tallocator.days_of_month) + "." + timesystem::monthstext[__tallocator.month] + "." + std::to_string(__tallocator.years + 1900);
}
std::string timesystem::time_point::datelargewithweekday(const time_point &__tallocator)
{
    return timesystem::weekstext[__tallocator.days_of_weeks] + std::string(" ") + std::to_string(__tallocator.days_of_month) + "." + timesystem::monthstext[__tallocator.month] + "." + std::to_string(__tallocator.years + 1900);
}

timesystem::time_point::TimerFormat timesystem::time_point::to_stringformatdate[4] =
    {
        dateshort,
        datelarge,
        datelargewithweekday};
timesystem::time_point::TimerFormat timesystem::time_point::to_stringformatclock[4] =
    {
        clockshort12,
        clockshort24,
        clocklarge12,
        clocklarge24};

std::vector<chrono::time_point> clockcontainer = {};
