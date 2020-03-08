#include "iata.h"

// Default constructor
IATA::IATA()
{
    /* nada */
}

// Constructor
IATA::IATA(const std::string &_iata, const std::string &_name, const std::string &_country)
{
    setIATA(_iata);
    setName(_name);
    setCountry(_country);
}

// Getter for the 3 letter IATA code
const std::string &IATA::getIATA() const
{
    return iata;
}

// Getter for the name
const std::string &IATA::getName() const
{
    return name;
}

// Getter for the country
const std::string &IATA::getCountry() const
{
    return country;
}

// Setter for the 3 letter IATA code
// Throws a range_error exception if the code isn't three letters long
void IATA::setIATA(const std::string &_iata)
{
    iata = _iata;

    if (iata.length() != 3)
        throw std::range_error("setIATA");
}

// Setter for the name
void IATA::setName(const std::string &_name)
{
    name = _name;
}

// Setter for the country
void IATA::setCountry(const std::string &_country)
{
    country = _country;
}

// Returns true if the lexical order of the first IATA code is less than the second one, false otherwise
bool IATA::operator<(const IATA &_other) const
{
    return iata < _other.iata;
}

// Global "<<" operator used by output streams
// The format is "IATA;Name of airport/aircraft;Country"
std::ostream& operator<<(std::ostream &_os, const IATA &_obj)
{
    return _os << _obj.getIATA() << ";" << _obj.getName() << ";" << _obj.getCountry();
}

// Global ">>" operator used by input streams
// The format is "IATA;Name of airport/aircraft;Country"
std::istream& operator>>(std::istream &_is, IATA &_obj)
{
    std::string str;

    if (std::getline(_is, str, ';'))
        _obj.setIATA(str);
    if (std::getline(_is, str, ';'))
        _obj.setName(str);
    if (std::getline(_is, str))
        _obj.setCountry(str);

    return _is;
}
