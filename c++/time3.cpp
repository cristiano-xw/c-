 
#include <iostream>

class Time
{
private:
    int hours;
    int minutes;

public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    friend Time operator+(const Time &a, const Time &b); //'+'运算符的友元函数原型;
    friend Time operator-(const Time &a, const Time &b); //'-'运算符的友元函数原型;
    Time operator*(double n) const;
    friend Time operator*(double m, const Time &t) { return t * m; } //内联友元函数;
    friend std::ostream &operator<<(std::ostream &os, const Time &t);
};

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
    return;
}

void Time::AddHr(int h)
{
    hours += h;
    return;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
    return;
}

Time operator+(const Time &a, const Time &b) //友元函数实现的'+'运算符重载;
{
    Time sum;
    sum.minutes = a.minutes + b.minutes;
    sum.hours = a.hours + b.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time operator-(const Time &a, const Time &b) //友元函数实现的'-'运算符重载;
{
    Time diff;
    int tot1, tot2;
    tot1 = a.minutes + 60 * a.hours;
    tot2 = b.minutes + 60 * b.hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double mult) const
{
    Time result;
    long totalminutes = hours * mult * 60 + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

std::ostream &operator<<(std::ostream &os, const Time &t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}


