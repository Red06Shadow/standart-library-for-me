#include <stda/system/memory/memory.hpp>

void memory::vmemory(const void *ptr, size_t size)
{
    if (!ptr)
        throw std::runtime_error("Error: vmemory no puede recibir un puntero nulo");
    std::cout << "                    00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F    Texto Decodificado" << std::endl;
    bool control = true;
    char array[16];
    u64 line = 0;
    while (control)
    {
        std::cout << (Number::hex << Number::qword((u64)(16 * line))) << ": ";
        u64 columna = 0;
        u8 sallocator = 0;
        while (columna < 16 && control)
        {
            if ((line * 16 + columna) < size)
            {
                sallocator++;
                u8 value = ((u8 *)(ptr))[line * 16 + columna];
                array[columna] = value;
                std::cout << (Number::hex << Number::byte(value)) << " ";
            }
            else
                control = false;
            columna++;
        }
        while (columna < 16 && control)
        {
            std::cout << "      ";
            array[columna] = ' ';
            columna++;
        }
        std::cout << ' ';
        for (u8 columnac = 0; columnac < sallocator && control; columnac++)
        {
            char v = array[columnac];
            std::cout << ((v > 32 && v < 127) ? v : '.') << ' ';
        }
        line++;
        std::cout << std::endl;
    }
}
size_t memory::process_memory_counters::get_peak_memory_working()
{
    return this->PeakWorkingSetSize;
}
size_t memory::process_memory_counters::get_page_fault_count()
{
    return this->PageFaultCount;
}
size_t memory::process_memory_counters::get_page_file_usage()
{
    return this->PagefileUsage;
}
size_t memory::process_memory_counters::get_page_file_peak_usage()
{
    return this->PeakPagefileUsage;
}
size_t memory::process_memory_counters::get_quota_non_paged_pool_usage()
{
    return this->QuotaNonPagedPoolUsage;
}
size_t memory::process_memory_counters::get_quota_paged_pool_usage()
{
    return this->QuotaPagedPoolUsage;
}
size_t memory::process_memory_counters::get_quota_peak_non_paged_pool_usage()
{
    return this->QuotaPeakNonPagedPoolUsage;
}
size_t memory::process_memory_counters::get_quota_peak_paged_pool_usage()
{
    return this->QuotaPeakPagedPoolUsage;
}
size_t memory::process_memory_counters::get_working_set_size()
{
    return this->WorkingSetSize;
}