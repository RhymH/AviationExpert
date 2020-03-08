#include <sstream>
#include "schedule.h"

// Default constructor
Schedule::Schedule()
{

}

// Constructor
Schedule::Schedule(const std::string &_departureAirport,
                   const std::string &_arrivalAirport,
                   const std::string &_aircraft,
                   const Time &_departure,
                   const Time &_arrival,
                   const Time &_duration)
{
    setDepartureAirport(_departureAirport);
    setArrivalAirport(_arrivalAirport);
    setAircraft(_aircraft);
    setDeparture(_departure);
    setArrival(_arrival);
    setDuration(_duration);
}

// Getter for the 3 letter IATA code of the departure airport
const std::string &Schedule::getDepartureAirport() const
{
    return departureAirport;
}

// Getter for the 3 letter IATA code of the arrival airport
const std::string &Schedule::getArrivalAirport() const
{
    return arrivalAirport;
}

// Getter for the 3 letter IATA code of aircraft
const std::string &Schedule::getAircraft() const
{
    return aircraft;
}

// Getter for the departure time
const Time &Schedule::getDeparture() const
{
    return departure;
}

// Getter for the arrival time
const Time &Schedule::getArrival() const
{
    return arrival;
}

// Getter for the flight duration
const Time &Schedule::getDuration() const
{
    return duration;
}

// Setter for the 3 letter IATA code of the departure airport
void Schedule::setDepartureAirport(const std::string &_departureAirport)
{
    departureAirport = _departureAirport;

    if (departureAirport.length() != 3)
        throw std::range_error("setDepartureAirport");
}

// Setter for the 3 letter IATA code of the arrival airport
void Schedule::setArrivalAirport(const std::string &_arrivalAirport)
{
    arrivalAirport = _arrivalAirport;

    if (arrivalAirport.length() != 3)
        throw std::range_error("setArrivalAirport");
}

// Setter for the 3 letter IATA code of aircraft
void Schedule::setAircraft(const std::string &_aircraft)
{
    aircraft = _aircraft;

    if (aircraft.length() != 3)
        throw std::range_error("setAircraft");
}

// Setter for the departure time
void Schedule::setDeparture(const Time &_departure)
{
    departure = _departure;
}

// Setter for the arrival time
void Schedule::setArrival(const Time &_arrival)
{
    arrival = _arrival;
}

// Setter for the flight duration
void Schedule::setDuration(const Time &_duration)
{
    duration = _duration;
}

// Global "<<" operator used by output streams
// The format is "IATA of departure airport;IATA of arrival airport;IATA of aircraft;departure time;arrival time;duration of flight"
std::ostream &operator<<(std::ostream &_os, const Schedule &_obj)
{
    return _os << _obj.getDepartureAirport() << ";"
               << _obj.getArrivalAirport() << ";"
               << _obj.getAircraft() << ";"
               << _obj.getDeparture() << ";"
               << _obj.getArrival() << ";"
               << _obj.getDuration();
}

// Global ">>" operator used by input streams
// The format is "IATA of departure airport;IATA of arrival airport;IATA of aircraft;departure time;arrival time;duration of flight"
std::istream &operator>>(std::istream &_is, Schedule &_obj)
{
    std::string str;
    Time time;

    if (std::getline(_is, str, ';'))
        _obj.setDepartureAirport(str);
    if (std::getline(_is, str, ';'))
        _obj.setArrivalAirport(str);
    if (std::getline(_is, str, ';'))
        _obj.setAircraft(str);
    if (std::getline(_is, str, ';'))
    {
        std::istringstream iss(str);
        iss >> time;
        _obj.setDeparture(time);
    }
    if (std::getline(_is, str, ';'))
    {
        std::istringstream iss(str);
        iss >> time;
        _obj.setArrival(time);
    }
    if (std::getline(_is, str))
    {
        std::istringstream iss(str);
        iss >> time;
        _obj.setDuration(time);
    }

    return _is;
}
