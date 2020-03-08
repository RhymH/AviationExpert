#ifndef DISTANCEDB_H
#define DISTANCEDB_H

#include "iostream"
using namespace std;

#include "fstream"
#include "vector"
#include "distance.h"


class DistanceDB
{
public:
    vector<Distance> db;
    DistanceDB();
    DistanceDB(const string& filename);
    //… there’s more to come (additional tasks)

};

ostream& operator<<(ostream& _os, const DistanceDB& _obj);

#endif // DISTANCEDB_H
