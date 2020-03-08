#ifndef TIME_H
#define TIME_H

#include "iostream"
using namespace std;


#include <sstream>
#include "vector"

class Time
{
private:
    int hour ;
    int minute ;



public:
    Time();
    Time(int _hour, int _minute);
    int getHour() const;
    int getMinute() const;
    void setHour(int _hour);
    void setMinute(int _minute);
    bool operator<(const Time& _other) const;
    bool operator==(const Time& _other) const;



};

ostream& operator<<(ostream& _os, const Time& _obj);
istream& operator>>(istream& _is, Time& _obj);

template <class Container>
void split2(const std::string& str, Container& cont, char delim = ' ');

#endif // TIME_H
