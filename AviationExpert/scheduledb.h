#ifndef SCHEDULEDB_H
#define SCHEDULEDB_H

#include "iostream"
using namespace std;

#include "fstream"
#include "vector"
#include "schedule.h"

class ScheduleDB
{
public:
    vector<Schedule> db;
    ScheduleDB();
    ScheduleDB(const string& filename);
    //… there’s more to come (additional tasks)

};

ostream& operator<<(ostream& _os, const ScheduleDB& _obj);

#endif // SCHEDULEDB_H
