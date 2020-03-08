#ifndef IATADB_H
#define IATADB_H


#include "iostream"
using namespace std;

#include <map>
#include "fstream"
#include "iata.h"

class IATADB
{

public :
    map<string, IATA> db;

    IATADB();
    IATADB(const string& filename);


    //… there’s more to come (additional tasks);

};

ostream& operator<<(ostream& _os, const IATADB& _obj);

#endif // IATADB_H
