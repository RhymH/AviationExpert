#include "time.h"

Time::Time(){

}
Time::Time(int _hour, int _minute){
    hour = _hour;
    minute = _minute;
}
int Time::getHour() const{
    return hour;
}
int Time::getMinute() const{
    return minute;
}
void Time::setHour(int _hour){
    hour = _hour;
}
void Time::setMinute(int _minute){
    minute = _minute;
}
bool Time::operator<(const Time& _other) const{
    if(hour == _other.hour){
        return (minute < _other.minute);
    }else{
        return (hour < _other.hour);
    }
}
bool Time::operator==(const Time& _other) const{
    return(minute == _other.minute && hour == _other.hour);
}


ostream& operator<<(ostream& _os, const Time& _obj){

    _os << _obj.getHour();
    _os << ":";
    _os << _obj.getMinute();

    return _os;

}


//found yesterday on the internet but I don't remember where.
template <class Container>
void split(const std::string& str, Container& cont, char delim = ' ')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

istream& operator>>(istream& _is, Time& _obj){
    string s;
    _is >> s;
    std::vector<std::string> words;
    split(s, words, ':');

    int hour, minutes;

    std::istringstream(words[0]) >> hour;
    std::istringstream(words[1]) >> minutes;

    _obj.setHour(hour);
    _obj.setMinute(minutes);

    return _is;

}





















