#include <stda/standart/numbers.hpp>
#if _WIN32
#include <windows.h>
#include <Psapi.h>
#include <iostream>
#else
#include <sys/resources.h>
#endif

#ifndef STDXMEMORY
#define STDXMEMORY

namespace memory
{
    class process_memory_counters : private _PROCESS_MEMORY_COUNTERS
    {
    public:
        process_memory_counters()
        {
            if (!GetProcessMemoryInfo(GetCurrentProcess(), (_PROCESS_MEMORY_COUNTERS*)this, sizeof(_PROCESS_MEMORY_COUNTERS)))
                throw std::runtime_error("Error al acceder a la memoria del sistema.");
        }
        size_t get_peak_memory_working();
        size_t get_page_fault_count();
        size_t get_page_file_usage();
        size_t get_page_file_peak_usage();
        size_t get_quota_non_paged_pool_usage();
        size_t get_quota_paged_pool_usage();
        size_t get_quota_peak_non_paged_pool_usage();
        size_t get_quota_peak_paged_pool_usage();
        size_t get_working_set_size();
        int get_cb() {return this->cb;}
        process_memory_counters operator+(const process_memory_counters& __other)
        {
            process_memory_counters resut;
            resut.PageFaultCount = this->PageFaultCount + __other.PageFaultCount;
            resut.PagefileUsage = this->PagefileUsage + __other.PagefileUsage;
            resut.PeakPagefileUsage = this->PeakPagefileUsage + __other.PeakPagefileUsage;
            resut.PeakWorkingSetSize = this->PeakWorkingSetSize + __other.PeakWorkingSetSize;
            resut.QuotaNonPagedPoolUsage = this->QuotaNonPagedPoolUsage + __other.QuotaNonPagedPoolUsage;
            resut.QuotaPagedPoolUsage = this->QuotaPagedPoolUsage + __other.QuotaPagedPoolUsage;
            resut.QuotaPeakNonPagedPoolUsage = this->QuotaPeakNonPagedPoolUsage + __other.QuotaPeakNonPagedPoolUsage;
            resut.QuotaPeakPagedPoolUsage = this->QuotaPeakPagedPoolUsage + __other.QuotaPeakPagedPoolUsage;
            resut.WorkingSetSize = this->WorkingSetSize + __other.WorkingSetSize;
            resut.cb = this->cb + __other.cb;
            return resut;
        }
        process_memory_counters operator-(const process_memory_counters& __other)
        {
            process_memory_counters resut;
            resut.PageFaultCount = this->PageFaultCount - __other.PageFaultCount;
            resut.PagefileUsage = this->PagefileUsage - __other.PagefileUsage;
            resut.PeakPagefileUsage = this->PeakPagefileUsage - __other.PeakPagefileUsage;
            resut.PeakWorkingSetSize = this->PeakWorkingSetSize - __other.PeakWorkingSetSize;
            resut.QuotaNonPagedPoolUsage = this->QuotaNonPagedPoolUsage - __other.QuotaNonPagedPoolUsage;
            resut.QuotaPagedPoolUsage = this->QuotaPagedPoolUsage - __other.QuotaPagedPoolUsage;
            resut.QuotaPeakNonPagedPoolUsage = this->QuotaPeakNonPagedPoolUsage - __other.QuotaPeakNonPagedPoolUsage;
            resut.QuotaPeakPagedPoolUsage = this->QuotaPeakPagedPoolUsage - __other.QuotaPeakPagedPoolUsage;
            resut.WorkingSetSize = this->WorkingSetSize - __other.WorkingSetSize;
            resut.cb = this->cb - __other.cb;
            return resut;
        }
    };
    void vmemory(const void *ptr, size_t size);
}

#endif