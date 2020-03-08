#include <iostream>
#include <fstream>
// You have to implement those headers and their source files
#include "iatadb.h"
#include "distancedb.h"
#include "scheduledb.h"


#include "algorithm"

using namespace std;

void findIATA(string s, const IATADB& aircrafts, const IATADB& airports);

void cleanSchedules(ScheduleDB& schedules, const IATADB& aircrafts, const IATADB& airports);
bool hasInvalidSchedule(const Schedule& schedule, const IATADB& aircrafts, const IATADB& airports);
bool findAircraftIATA(const IATADB& aircrafts ,string s);
bool findAirportIATA(const IATADB& airports ,string s);

int main()
{
    string choice;
    IATADB aircrafts;
    IATADB airports;
    DistanceDB distances;
    ScheduleDB schedules;

    try
    {
        while (true)
        {
            cout << "1:  Read data from files" << endl;
            cout << "2:  Backup all data" << endl;
            cout << "3:  Search IATA" << endl;
            cout << "4:  Clean Schedule data" << endl;
            cout << "5:  Delete Aircraft" << endl;
            cout << "6:  Delete Airport" << endl;
            cout << "7:  Delete Country" << endl;
            cout << "8:  Query aircraft of flight route" << endl;
            cout << "9:  Query all departures of an airport" << endl;
            cout << "10: Query all arrivals of an airport" << endl;
            cout << "11: Query all domestic flights of a given country" << endl;
            cout << "0:  Quit" << endl;
            cout << "Your choice: ";

            if (!(cin >> choice))
            {
                cin.clear();
                cin.sync();
                continue;
            }

            if (choice == "1")
            {
                /* DONT CHANGE THIS CODE -> */
                aircrafts = IATADB("../data/aircrafts.csv");
                airports = IATADB("../data/airports.csv");
                distances = DistanceDB("../data/distances.csv");
                schedules = ScheduleDB("../data/schedules.csv");
                /* <- DONT CHANGE THIS CODE */
            }
            else if (choice == "2")
            {
                /* DONT CHANGE THIS CODE -> */
                ofstream ofs;

                ofs = ofstream("../data/~aircrafts.csv");
                ofs << aircrafts;
                ofs = ofstream("../data/~airports.csv");
                ofs << airports;
                ofs = ofstream("../data/~distances.csv");
                ofs << distances;
                ofs = ofstream("../data/~schedules.csv");
                ofs << schedules;
                /* <- DONT CHANGE THIS CODE */
            }
            else if (choice == "3")
            {
                cout << "IATA : ";
                string s;
                cin >> s;

                findIATA(s, aircrafts, airports);

            }
            else if (choice == "4")
            {
                 cleanSchedules(schedules, aircrafts, airports);

            }
            else if (choice == "5")
            {
                cout << "IATA : ";
                string s;
                cin >> s;

                aircrafts.db.erase (s);

                cleanSchedules(schedules, aircrafts, airports);

            }
            else if (choice == "6")
            {
                cout << "IATA : ";
                string s;
                cin >> s;

                airports.db.erase (s);

                distances.db.erase(
                    remove_if(distances.db.begin(), distances.db.end(),
                              [s](const Distance &o) { return (o.getAirport1() == s || o.getAirport2() == s); })
                              , distances.db.end());

                cleanSchedules(schedules, aircrafts, airports);

            }
            else if (choice == "7")
            {
                //delete country

                cout << "Country : ";
                string country;
                cin >> country;

                for(map<string, IATA>::const_iterator it = aircrafts.db.begin(); it != aircrafts.db.end(); ) {
                     if (it->second.getCountry() == country) {
                         //remove the aircrafts
                          it = aircrafts.db.erase(it);
                     } else {
                          ++it;
                     }
                }

                for(map<string, IATA>::const_iterator it = airports.db.begin(); it != airports.db.end(); ) {
                     if (it->second.getCountry() == country) {
                         //remove distances for airports in this country
                         distances.db.erase(
                             remove_if(distances.db.begin(), distances.db.end(),
                                       [it](const Distance &o) { return (o.getAirport1() == it->first || o.getAirport2() == it->first); })
                                       , distances.db.end());
                         //remove the airports
                         it = airports.db.erase(it);
                     } else {
                         ++it;
                     }
                }

                cleanSchedules(schedules, aircrafts, airports);

            }
            else if (choice == "8")
            {
                cout << "Route \"IATA1 IATA2\" : ";
                string start, end;
                cin >> start >> end;

                //with "ALC LGW" as input returns 319 aircraft

                for(int i = 0; i < schedules.db.size(); i++){
                    if(schedules.db[i].getDepartureAirport() == start && schedules.db[i].getArrivalAirport() == end){
                        string s = schedules.db[i].getAircraft();
                        findIATA(s, aircrafts, airports);
                    }
                }

            }
            else if (choice == "9")
            {
                cout << "Airport : ";
                string airport;
                cin >> airport;

                for(int i = 0; i < schedules.db.size(); i++){
                    if(schedules.db[i].getDepartureAirport() == airport){
                        cout << schedules.db[i] << endl;
                    }
                }

            }
            else if (choice == "10")
            {
                cout << "Airport : ";
                string airport;
                cin >> airport;

                for(int i = 0; i < schedules.db.size(); i++){
                    if(schedules.db[i].getArrivalAirport() == airport){
                        cout << schedules.db[i] << endl;
                    }
                }

            }
            else if (choice == "11")
            {
                cout << "Country : ";
                string country;
                cin >> country;

                for(int i = 0; i < schedules.db.size(); i++){
                    string start = schedules.db[i].getDepartureAirport();
                    string end = schedules.db[i].getArrivalAirport();

                    if(airports.db[start].getCountry() == country && airports.db[end].getCountry() == country){
                        cout << schedules.db[i] << endl;
                    }

                }

            }
            else if (choice == "0")
                break;

            cout << "...done" << endl;
        }
    }
    catch (std::exception& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}

void cleanSchedules(ScheduleDB& schedules, const IATADB& aircrafts, const IATADB& airports){
    schedules.db.erase(
        remove_if(schedules.db.begin(), schedules.db.end(),
                  [aircrafts,airports](const Schedule &o) { return hasInvalidSchedule(o, aircrafts, airports); })
                  , schedules.db.end());
}

void findIATA(string s, const IATADB& aircrafts, const IATADB& airports){
    bool found = false;
    for (map<string, IATA>::const_iterator it = aircrafts.db.begin(); it != aircrafts.db.end(); ++it)
    {
        if(it->first == s){
            cout << it->second << endl;
            found = true;
        }
    }
    for (map<string, IATA>::const_iterator it = airports.db.begin(); it != airports.db.end(); ++it)
    {
        if(it->first == s){
            cout << it->second << endl;
            found = true;
        }
    }

    if(!found)
        cout << "IATA not found !" << endl;
}

bool hasInvalidSchedule(const Schedule& schedule, const IATADB& aircrafts, const IATADB& airports){

        if(!findAircraftIATA(aircrafts, schedule.getAircraft())){
            return true;
        }
        if(!findAirportIATA(airports, schedule.getArrivalAirport())){
            return true;
        }
        if(!findAirportIATA(airports, schedule.getDepartureAirport())){
            return true;
        }

    return false;
}


bool findAircraftIATA(const IATADB& aircrafts ,string s){
    for (map<string, IATA>::const_iterator it = aircrafts.db.begin(); it != aircrafts.db.end(); ++it)
    {
        if(it->first == s){
            return true;
        }
    }
    return false;
}

bool findAirportIATA(const IATADB& airports ,string s){
    for (map<string, IATA>::const_iterator it = airports.db.begin(); it != airports.db.end(); ++it)
    {
        if(it->first == s){
            return true;
        }
    }
    return false;
}
















