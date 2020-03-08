#include "iatadb.h"

#include <iostream>
using namespace std;

IATADB::IATADB(){

}
IATADB::IATADB(const string& filename){
    ifstream is(filename);
    if(!is){
        cout<< "File not found !!!";
        return;
    }

    IATA entry;
    while(is >> entry){
        db.insert(make_pair(entry.getIATA(), entry));
    }
}



ostream& operator<<(ostream& _os, const IATADB& _obj){

    for (map<string, IATA>::const_iterator it = _obj.db.begin(); it != _obj.db.end(); ++it)
    {
        _os << it->second << endl;
    }

    return _os;
}
