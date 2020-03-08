#include "distancedb.h"

DistanceDB::DistanceDB(){

}
DistanceDB::DistanceDB(const string& filename){
    ifstream is(filename);
    if(!is){
        cout<< "File not found !!!";
        return;
    }

    Distance entry;
    while(is >> entry){
        db.push_back(entry);
    }
}


ostream& operator<<(ostream& _os, const DistanceDB& _obj){
    for(int i = 0; i < _obj.db.size(); i++){
        _os << _obj.db[i] << endl;
    }
    return _os;
}
