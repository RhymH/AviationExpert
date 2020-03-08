#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <iostream>
#include "time.h"

// This class stores a schedule of an aircraft.
// The data consists of the departure/arrival airport and the departure/arrival time, the aircraft and the duration.
class Schedule
{
private:
    std::string departureAirport;   // Unique 3 letter IATA code of the departure airport
    std::string arrivalAirport;     // Unique 3 letter IATA code of the arrival airport
    std::string aircraft;           // Unique 3 letter IATA code of the aircraft
    Time departure;                 // Departure time
    Time arrival;                   // Arrival time
    Time duration;                  // Duration of the flight

public:
    // Constructors
    Schedule();
    Schedule(const std::string& _departureAirport,
             const std::string& _arrivalAirport,
             const std::string& _aircraft,
             const Time& _departure,
             const Time& _arrival,
             const Time& _duration);

    // Setter and getter methods for all attributes
    const std::string& getDepartureAirport() const;
    const std::string& getArrivalAirport() const;
    const std::string& getAircraft() const;
    const Time& getDeparture() const;
    const Time& getArrival() const;
    const Time& getDuration() const;
    void setDepartureAirport(const std::string& _departureAirport);
    void setArrivalAirport(const std::string& _arrivalAirport);
    void setAircraft(const std::string& _aircraft);
    void setDeparture(const Time& _departure);
    void setArrival(const Time& _arrival);
    void setDuration(const Time& _duration);
};

// Used for file I/O.
// The format is "IATA of departure airport;IATA of arrival airport;IATA of aircraft;departure time;arrival time;duration of flight"
std::ostream& operator<<(std::ostream& _os, const Schedule& _obj);
std::istream& operator>>(std::istream& _is, Schedule& _obj);

#endif // SCHEDULE_H
