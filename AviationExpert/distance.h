#ifndef DISTANCE_H
#define DISTANCE_H

#include <string>
#include <iostream>

// This class stores two airports by their unique 3 letter IATA code and the distance both
class Distance
{
private:
    std::string airport1;   // 3 letter IATA code of the first airport
    std::string airport2;   // 3 letter IATA code of the second airport
    double distance;        // Distance in kilometers between both airports

public:
    // Constructors
    Distance();
    Distance(const std::string& _airport1, const std::string& _airport2, double _distance);

    // Setter and getter methods for all attributes
    const std::string& getAirport1() const;
    const std::string& getAirport2() const;
    double getDistance() const;
    void setAirport1(const std::string& _name);
    void setAirport2(const std::string& _name);
    void setDistance(double _distance);

    // The "less than" operator is used for sorting
    bool operator<(const Distance& _other) const;
};

// Used for file I/O. The format is "IATA of airport 1;IATA of airport 2;distance"
std::ostream& operator<<(std::ostream& _os, const Distance& _obj);
std::istream& operator>>(std::istream& _is, Distance& _obj);

#endif // DISTANCE_H
