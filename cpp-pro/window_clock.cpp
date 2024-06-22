

// Window Version 1. Simple Count //
DWORD start = GetTickCount();
DoBigTask();
DWORD end = GetTickCount();
std::cout << end - start << std::endl;

// Window Version 2. Loop Count //
DWORD start = GetTickCount();
for (unsigned int i = 0; i < n; ++i)
{
    Foo();
};
DWORD end = GetTickCount();
std::cout << end - start << std::endl;

// GetTickCount()'s Tick //
unsigned nz_count = 0, nz_sum = 0;
ULONG last, next;

for(last = GetTickCount(); nz_count < 100 ; last = next)
{
    next = GetTickCount();
    if (next != last)
    {
        nz_count +=1;
        nz_sun += (next- last);
    }
};

std::cout << "GetTickCount() mean resolution " << (double)nz_sum /nz_count << "tick" << std::endl;

// Latency //
ULONG start = GetTickCount();
LARGE_INTEGER count;
for(counter i = 0; i < nCalls; ++i)
{
    QueryPerformanceCounter(&couner);
}
ULONG stop = GetTickCount();
std::cout << stop - start << "ms for 100m Query PerformanceCounter() calls " << std::endl;

// Priority //
SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS);
SertThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);
SertThreadPriority(GetCurrentThread(), THREAD_PRIORITY_NORMAL);
