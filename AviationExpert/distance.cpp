#include <stdexcept>
#include <sstream>
#include "distance.h"

// Default constructor
Distance::Distance()
    : distance(0.0)
{
    /* nada */
}

// Constructor
Distance::Distance(const std::string &_airport1, const std::string &_airport2, double _distance)
{
    setAirport1(_airport1);
    setAirport2(_airport2);
    setDistance(_distance);
}

// Getter for the first airport IATA code
const std::string &Distance::getAirport1() const
{
    return airport1;
}

// Getter for the second airport IATA code
const std::string &Distance::getAirport2() const
{
    return airport2;
}

// Getter for the distance between both airports in kilometers
double Distance::getDistance() const
{
    return distance;
}

// Setter for the first airport IATA code
void Distance::setAirport1(const std::string &_name)
{
    airport1 = _name;
}

// Setter for the second airport IATA code
void Distance::setAirport2(const std::string &_name)
{
    airport2 = _name;
}

// Setter for the distance between both airports in kilometers.
// Throws a range_error exception if the distance is less than zero
void Distance::setDistance(double _distance)
{
    distance = _distance;
    if (distance < 0.0)
        throw std::range_error("setDistance");
}

// Returns true if the distance is less than another distance, false otherwise
bool Distance::operator<(const Distance &_other) const
{
    return distance < _other.distance;
}

// Global "<<" operator used by output streams
// The format is "IATA of airport 1;IATA of airport 2;distance"
std::ostream &operator<<(std::ostream &_os, const Distance &_obj)
{
    return _os << _obj.getAirport1() << ";" << _obj.getAirport2() << ";" << _obj.getDistance();
}

// Global ">>" operator used by input streams
// The format is "IATA of airport 1;IATA of airport 2;distance"
std::istream &operator>>(std::istream &_is, Distance &_obj)
{
    std::string str;
    double val;

    if (std::getline(_is, str, ';'))
        _obj.setAirport1(str);
    if (std::getline(_is, str, ';'))
        _obj.setAirport2(str);
    if (std::getline(_is, str))
    {
        std::istringstream iss(str);
        iss >> val;
        _obj.setDistance(val);
    }

    return _is;
}
