#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std::chrono;

class TimerBase
{
private:
    system_clock::time_point m_start;
    
public:
    TimerBase() : m_start(system_clock::time_point::min()) {}
    
    void Clear()
    {
        m_start = system_clock::time_point::min();
    }
    
    bool IsStarted() const
    {
        return (m_start.time_since_epoch() != system_clock::duration(0));
    }
    
    void Start()
    {
        m_start = system_clock::now();
    }
    
    unsigned long GetMs()
    {
        if(IsStarted())
        {
            system_clock::duration diff;
            diff = system_clock::now() - m_start;
            return (unsigned)(duration_cast<milliseconds>(diff).count());
        }
        return 0;
    }
};

class TimerBaseClock
{
private:
    clock_t m_start;
public:
    TimerBaseClock()
    {
        m_start = -1;
    }
    
    void Clear();
    
    bool IsStarted() const
    {
        return (m_start != -1);
    }
    
    void Start()
    {
        m_start = clock();
    }
    
    unsigned long GetMs()
    {
        clock_t now;
        if(IsStarted())
        {
            now = clock();
            clock_t dt = (now-m_start);
            return (unsigned long)(dt*1000/ CLOCKS_PER_SEC);
        }
        return 0;
    }
};

class TimerBaseChrono
{
private:
    std::chrono::system_clock::time_point m_start;
    
public:
    TimerBaseChrono() : m_start(system_clock::time_point::min())
    {
    }
    
    void Clear()
    {
        m_start = system_clock::time_point::min();
    }
    
    bool IsStarted() const
    {
        return (m_start != system_clock::time_point::min());
    }
    
    void Start()
    {
        m_start = std::chrono::system_clock::now();
    }
    
    unsigned long GetMs()
    {
        if(IsStarted())
        {
            system_clock::duration diff;
            diff = system_clock::now() - m_start;
            return (unsigned)(duration_cast<illiseconds>(diff).count());
        }
        return 0;
    }
};

template <typename T> class basic_stopwatch : T
{
    typedef typename T BaseTimer;
public:
    explicit basic_stopwatch(bool start);
    explicit basic_stopwatch(char const* activity = "stopwatch", bool start = true);
    basic_stopwatch(std::ostream& log, char const* activitiy = "stopwatch", bool start = true);
    
    ~basic_stopwatch();
    
    unsigned LapGet() const;
    
    bool IsStarted() const;
    
    unsigned Show(char const* event = "show");
    
    unsigned Start(char const* event_name = "start");
    
    unsigned Stop(char const* event_name = "stop");
    
private:
    char const* m_activity;
    unsigned m_lap;
    std::ostream& m_log;
};


