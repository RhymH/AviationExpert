#include "scheduledb.h"

ScheduleDB::ScheduleDB()
{

}

ScheduleDB::ScheduleDB(const string& filename){
    ifstream is(filename);
    if(!is){
        cout<< "File not found !!!";
        return;
    }

    Schedule entry;
    while(is >> entry){
        db.push_back(entry);
    }
}

ostream& operator<<(ostream& _os, const ScheduleDB& _obj){
    for(int i = 0; i < _obj.db.size(); i++){
        _os << _obj.db[i] << endl;
    }
    return _os;
}
