#include <iostream>
class Time
{
    private:

    int m_hours;
    int m_minutes;
    int m_seconds;

    public:

    Time(int Hours = 0, int Minutes = 0, int Seconds = 0) : m_hours(Hours), m_minutes(Minutes), m_seconds(Seconds){}

    void SetHours(int Hours)
    {
        if(Hours < 0 || Hours > 23)
            std::cout << "Вы ввели недопустимое значение часов" << std::endl;
        else
            m_hours = Hours;
    }

    void SetMinutes(int Minutes)
    {
        if(Minutes < 0 || Minutes > 59)
            std::cout << "Вы ввели недопустимое значение минут" << std::endl;
        else
            m_minutes = Minutes;
    }

    void SetSeconds(int Seconds)
    {
        if(Seconds < 0 || Seconds > 59)
            std::cout << "Вы ввели недопустимое значение секунд" << std::endl;
        else
            m_seconds = Seconds;
    }

    void SetTime(int Hours, int Minutes, int Seconds)
    {
        SetHours(Hours);
        SetMinutes(Minutes);
        SetSeconds(Seconds);
    }

    void AddHours(int Hours)
    {
        m_hours = (m_hours + Hours)%24;
    }

    void AddMinutes(int Minutes)
    {
        m_hours = (m_hours + (m_minutes + Minutes)/60)%24;
        m_minutes = (m_minutes + Minutes)%60;
    }

    void AddSeconds(int Seconds)
    {
        //m_hours = (m_hours + (m_minutes + (m_seconds + Seconds)/60)%60)%24;
        if((m_minutes + (m_seconds + Seconds)/60) >= 60)
        {
            m_hours = (m_hours + (m_minutes + (m_seconds + Seconds)/60)/60)%24;
        }
        m_minutes = (m_minutes + (m_seconds + Seconds)/60)%60;
        m_seconds = (m_seconds + Seconds)%60;
    }

    void ShowTime()
    {
        std::cout << "Время: " << m_hours << ":" << m_minutes << ":" << m_seconds << std::endl;
    }
};



int main()
{
    Time Current_Time;
    Current_Time.ShowTime();
    Current_Time.SetTime(27, 15, 30);
    Current_Time.ShowTime();
    Current_Time.AddSeconds(6000);
    Current_Time.ShowTime();
}