#ifndef IATA_H
#define IATA_H

#include <string>
#include <iostream>

// This class stores the unique 3 letter IATA code, the name and the country of an airport/aircraft.
class IATA
{
private:
    std::string iata;       // Unique 3 letter IATA code
    std::string name;       // Name of airport or aircraft
    std::string country;    // Country

public:
    // Constructors
    IATA();
    IATA(const std::string& _iata, const std::string& _name, const std::string& _country);

    // Setter and getter methods for all attributes
    const std::string& getIATA() const;
    const std::string& getName() const;
    const std::string& getCountry() const;
    void setIATA(const std::string& _iata);
    void setName(const std::string& _name);
    void setCountry(const std::string& _country);

    // The "less than" operator is used for sorting
    bool operator<(const IATA& _other) const;
};

// Used for file I/O. The format is "IATA;Name of airport/aircraft;Country"
std::ostream& operator<<(std::ostream& _os, const IATA& _obj);
std::istream& operator>>(std::istream& _is, IATA& _obj);

#endif // IATA_H
