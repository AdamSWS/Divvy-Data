#include <iostream>   // For Input and Output
#include <fstream>    // For file input and output
#include <cassert>    // For the assert statement
#include <vector>     // For vectors
#include <string>     // String operations
#include <algorithm>  // use of vector algorithms
#include <cmath>  //for square root function
#include <iomanip>  //for setw() function

using namespace std;

// Utility functions getting distant between two map points
// Attribution: https://www.geeksforgeeks.org/program-distance-two-points-earth/
// converting degrees to radians
long double toRadians(const long double degree)
{
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    long double one_deg = (3.14159265358979323846) / 180;
    return (one_deg * degree);
}

long double distance(long double lat1, long double long1,
                     long double lat2, long double long2)
{
    // Convert the latitudes
    // and longitudes
    // from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);

    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;

    long double ans = pow(sin(dlat / 2), 2) +
                      cos(lat1) * cos(lat2) *
                      pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 3956;

    // Calculate the result
    ans = ans * R;

    return ans;
}

class dataTypes {
public:
    vector <string> rideID, rideableType,startedAt,endedAt,startStationName,endStationName,startLat,startLng,endLat,endLng,memberCasual, cleanRideID, cleanRideableType, cleanStartedAt,cleanEndedAt,cleanStartStationName,cleanendStationName,cleanStartLat,cleanStartLng,cleanEndLat,cleanEndLng,cleanMemberCasual, lineVector, date;
    vector <int> time, time1, time4;
    vector <long double> stLatCon, stLngCon, endLatCon, endLngCon;
    //all vector declarations
    string line;
    //string line for file inputs to vectors
    void dataBuild(string fileName) {
        //dataBuild() builds above vectors based on the fileName parameter
        int j = 0;
        ifstream fin;
        fin.open(fileName);
        while(!fin.eof()){
            getline(fin, ride_id, ',');
            rideID.push_back(ride_id);
            getline(fin, rideable_type, ',');
            rideableType.push_back(rideable_type);
            getline(fin, started_at, ',');
            startedAt.push_back(started_at);
            getline(fin, ended_at, ',');
            endedAt.push_back(ended_at);
            getline(fin, start_station_name, ',');
            startStationName.push_back(start_station_name);
            getline(fin, end_station_name, ',');
            endStationName.push_back(end_station_name);
            getline(fin, start_lat, ',');
            startLat.push_back(start_lat);
            getline(fin, start_lng, ',');
            startLng.push_back(start_lng);
            getline(fin, end_lat, ',');
            endLat.push_back(end_lat);
            getline(fin, end_lng, ',');
            endLng.push_back(end_lng);
            getline(fin, member_casual, '\n');
            memberCasual.push_back(member_casual);
            j += 1;
        }
        fin.close();
        fin.open(fileName);
        while(!fin.eof()) {
            //building a vector line by line in each csv
            getline(fin, line, '\n');
            lineVector.push_back(line);
        }
    }

    void cleanBuild() {
        //cleanBuild pushes back strings store in vectors above to cleanData
        //strings must be empty
        for (int i = 1; i < lineVector.size() - 1; i++) {
            if (rideID.at(i).empty() || rideableType.at(i).empty() || startedAt.at(i).empty() || endedAt.at(i).empty() || startStationName.at(i).empty() || endStationName.at(i).empty() || startLat.at(i).empty() || startLng.at(i).empty()|| endLat.at(i).empty()|| endLng.at(i).empty() || memberCasual.at(i).empty()) {
            } else {
                cleanRideID.push_back(rideID[i]);
                cleanRideableType.push_back(rideableType[i]);
                cleanStartedAt.push_back(startedAt[i]);
                cleanEndedAt.push_back(endedAt[i]);
                cleanStartStationName.push_back(startStationName[i]);
                cleanendStationName.push_back(endStationName[i]);
                cleanStartLat.push_back(startLat[i]);
                cleanStartLng.push_back(startLng[i]);
                cleanEndLat.push_back(endLat[i]);
                cleanEndLng.push_back(endLng[i]);
                cleanMemberCasual.push_back(memberCasual[i]);
            }
        }
    }

    void intToStrVector(string fileName, vector <string> &bounds) {
        //pushes back clean data(lat and long) into vector to be converted into mileage
        for (long i = 0; i < bounds.size(); i++) {
            stLatCon.push_back(stod(cleanStartLat[i]));
            stLngCon.push_back(stod(cleanStartLng[i]));
            endLatCon.push_back(stod(cleanEndLat[i]));
            endLngCon.push_back(stod(cleanEndLng[i]));
        }
    }

    void timeAndDate(string fileName) {
        for (int i = 0; i < cleanStartedAt.size(); i++) {
            //uses substring functions to create new vectors with date and time
            string line(cleanStartedAt[i]);
            date.push_back(line.substr(0, line.find(' ')));
            time.push_back(stoi(line.substr(8, line.find(':') - 8)));
        }
        for (int i = 0; i < time.size(); i++) {
            //time for the first day of the month
            if (date[i][2] == '1') {
                time1.push_back(time[i]);
            }
        }
        for (int j = 0; j < time.size(); j++) {
            //time for the forth day of the month
            if (date[j][2] == '4') {
                time4.push_back(time[j]);
            }
        }
    }

    //columnGenerator1 and columnGenerator2 uses the algorithm to display data relative to maxValue

    void columnGenerator1(int value1, int maxValue) {
        int value2 = (value1 * 50) / maxValue;
        for (int i = 0; i < value2; i++) {
            cout << "@";
        }
    }

    void columnGenerator2(int value1, int maxValue) {
        int value2 = (value1 * 50) / maxValue;
        for (int i = 0; i < value2; i++) {
            cout << "+";
        }
    }

private:
    //strings for the dataBuild function
    string ride_id, rideable_type,started_at,ended_at,start_station_name,end_station_name,start_lat,start_lng,end_lat,end_lng,member_casual;
};

void menuDisplay() {
    //menu
    cout << "Select a menu option:" << endl;
    cout << " 1. Select datafile, display rides totals and clean data" << endl;
    cout << " 2. Display overall trip information" << endl;
    cout << " 3. Display percentage of members vs. casual riders" << endl;
    cout << " 4. Display weekday vs weekend usage" << endl;
    cout << " 5. Extra Credit: find closest station" << endl;
    cout << " 6. Exit" << endl;
    cout << "Your choice --> ";
}

int counter = 0; //global variable to control if user doesn't input menu 1 before other choices
int subCounter = 0; //controls one-time display
int subChoice = 0; //userInput for nested menus
int subChoice1 = 0; //userInput for nested menus
string fileName; //var for csv files

int main() {
    int choice = 0; //user Input
    if (subCounter == 0) {
        cout << "Analyze Divvy bike ride information using September trip data." << endl;
        cout << "First select option 1 to read and clean the data." << endl << endl;
        subCounter++; //controls menu for one time display
    } //starter message
    menuDisplay(); //display Menu
    cin >> choice; //userInput
    if (counter == 0 && choice != 1) { //controls user input
        cout << "First read in data by selecting menu option 1" << endl << endl;
        main();
    } //must pull data before options 2-5
    if (choice == 1) {
        counter++;
        cout << " Select datafile:" << endl;
        cout << "   1. Small subset of data with 14 rides to help create your program" << endl;
        cout << "   2. Week day vs weekend rides" << endl;
        cout << "   3. All September 2021 data" << endl;
        cout << " Your selection--> ";
        cin >> subChoice;
        switch(subChoice) {
            case 1: {
                dataTypes case1sub1; //case1 object
                string fileName = "divvyridesampledata.csv";
                case1sub1.dataBuild(fileName); //builds vectors based on fileName
                cout << "Total # of trips found in datafile: " << case1sub1.lineVector.size() - 2 << endl;
                case1sub1.cleanBuild(); //creates clean vectors
                cout << "Total # of trips in clean data: " << case1sub1.cleanRideID.size() << endl << endl;
            }
                break;
            case 2: {
                dataTypes case1sub2; //case1 object
                string fileName = "weekdayweekend.csv";
                case1sub2.dataBuild(fileName); //builds vectors based on fileName
                cout << "Total # of trips found in datafile: " << (case1sub2.lineVector.size() - 2) << endl;
                case1sub2.cleanBuild(); //creates clean vectors
                cout << "Total # of trips in clean data: " << case1sub2.cleanRideID.size()<< endl << endl;
            }
                break;
        }
        main();
    }
    if (choice == 2) {
        dataTypes case2; //case2 object
        double sum = 0; //some of mileage
        double maxDistance; //max mileage
        int maxIndex; //index of max mileage
        string maxDistanceTripID; //ID of max trip
        if (subChoice == 1) {
            fileName = "divvyridesampledata.csv";
            case2.dataBuild(fileName); //vector creation
            case2.cleanBuild(); //clean vector creation
            case2.intToStrVector(fileName, case2.cleanRideID); //creates vectors for miles
            for (int i = 0; i < case2.stLatCon.size(); i++) {
                sum = distance(case2.stLatCon[i], case2.stLngCon[i], case2.endLatCon[i], case2.endLngCon[i]) + sum;
                if (distance(case2.stLatCon[i], case2.stLngCon[i], case2.endLatCon[i], case2.endLngCon[i]) > maxDistance) {
                    maxDistance = distance(case2.stLatCon[i], case2.stLngCon[i], case2.endLatCon[i], case2.endLngCon[i]);
                    maxIndex = i;
                }
            }
            double y = case2.stLatCon.size();
            double avg = (sum / (y)); //creates average
            cout << " Total # of miles traveled: " << round(sum) << endl;
            cout << " Average length of trips in miles: " << setprecision(2) << avg << endl << endl;
            cout << " Longest trip information below: " << endl;
            cout << " -------------------------------" << endl;
            cout << " Trip ID: " << case2.cleanRideID[maxIndex] << endl;
            cout << " Trip start location: " << case2.cleanStartStationName[maxIndex] << endl;
            cout << " Trip end location:  " << case2.cleanendStationName[maxIndex] << endl;
            cout << " Trip distance in miles: " << setprecision(2) << maxDistance << endl << endl;
        } else if(subChoice == 2) {
            fileName = "weekdayweekend.csv";
            case2.dataBuild(fileName); //vector creation
            case2.cleanBuild(); //clean vector creation
            case2.intToStrVector(fileName, case2.cleanRideID);
            for (int i = 0; i < case2.stLatCon.size(); i++) {
                sum = distance(case2.stLatCon[i], case2.stLngCon[i], case2.endLatCon[i], case2.endLngCon[i]) + sum;
                if (distance(case2.stLatCon[i], case2.stLngCon[i], case2.endLatCon[i], case2.endLngCon[i]) > maxDistance) {
                    maxDistance = distance(case2.stLatCon[i], case2.stLngCon[i], case2.endLatCon[i], case2.endLngCon[i]);
                    maxIndex = i;
                }
            }
            double y = case2.stLatCon.size();
            double avg = (sum / (y - 3)); //creates average
            cout << " Total # of miles traveled: " << round(sum) << endl;
            cout << " Average length of trips in miles: " << setprecision(2) << avg << endl << endl;
            cout << " Longest trip information below: " << endl;
            cout << " -------------------------------" << endl;
            cout << " Trip ID: " << case2.cleanRideID[maxIndex] << endl;
            cout << " Trip start location: " << case2.cleanStartStationName[maxIndex] << endl;
            cout << " Trip end location:  " << case2.cleanendStationName[maxIndex] << endl;
            cout << " Trip distance in miles: " << setprecision(3) << maxDistance << endl << endl;
        }
        main();
    } else if(choice == 3) {
        dataTypes case3; //case3 object
        double tracker1 = 0; //var
        double tracker2 = 0; //var
        string option = "member";
        string option2 = "casual";
        if (subChoice == 1) {
            fileName = "divvyridesampledata.csv";
            case3.dataBuild(fileName);
            case3.cleanBuild();
            for (int i = 0; i < case3.cleanMemberCasual.size(); i++) {
                if (case3.cleanMemberCasual[i][0] == 'm') {
                    tracker1++; //var to track how many members
                } else if (case3.cleanMemberCasual[i][0] == 'c') {
                    tracker2++; //var to track how many casuals
                }
            }
        } else {
            fileName = "weekdayweekend.csv";
            case3.dataBuild(fileName); //creates vectors
            case3.cleanBuild(); //creates clean vectors
            for (int i = 0; i < case3.cleanMemberCasual.size(); i++) {
                if (case3.cleanMemberCasual[i][0] == 'm') {
                    tracker1++; //var to track how many members
                } else if (case3.cleanMemberCasual[i][0] == 'c') {
                    tracker2++; //var to track how many casuals
                }
            }
        }
        double percentCasual = (tracker2 / case3.cleanMemberCasual.size() * 100.0);
        double memberCasual = (tracker1 / case3.cleanMemberCasual.size() * 100.0);
        cout << " Casual Rider Percentage: " << setprecision(1) << fixed << percentCasual << "%" << endl;
        cout << " Member Rider Percentage: " << setprecision(1) << fixed << memberCasual << "%" << endl << endl;
        main();
    } else if(choice == 4) {
        cout << " Select type of display: " << endl;
        cout << "   1. Counts of rides per hour in the day" << endl;
        cout << "   2. Proportional 50 column graph with @ for weekday and + for weekend" << endl;
        cout << "Your selection--> " << endl;
        cin >> subChoice1;
        switch(subChoice1) {
            case 1: {
                int value;
                dataTypes case4;
                if (subChoice == 1) {
                    fileName = "divvyridesampledata.csv";
                    value = 3; //maxVal
                } else if (subChoice == 2) {
                    fileName = "weekdayweekend.csv";
                    value = 1317; //max Val
                }
                case4.dataBuild(fileName); //creates vectors
                case4.cleanBuild(); //creates clean vectors
                case4.timeAndDate(fileName); //creates time and date vectors
                cout << "LargestNumberOfRides is: " << value << endl;
                cout << "Rides per hour for weekday and weekend:" << endl;
                for (int i = 0; i < 24; i++) {
                    int x = 0;
                    int y = 0;
                    for (int k = 0; k < case4.time4.size(); k++) {
                        if (i == case4.time4[k]) {
                            y++;
                        }
                    }
                    for (int k = 0; k < case4.time1.size(); k++) {
                        if (i == case4.time1[k]) {
                            x++;
                        }
                    }
                    cout << i << ":" << setw(5) << " " << x << setw(5) << " " << y << endl;
                }
                cout << endl;
                break;
            }
            case 2: {
                int value;
                dataTypes case4sub2;
                if (subChoice == 1) {
                    fileName = "divvyridesampledata.csv";
                    value = 3;
                } else if (subChoice == 2) {
                    fileName = "weekdayweekend.csv";
                    value = 1317;
                }
                case4sub2.dataBuild(fileName); //creates vectors
                case4sub2.cleanBuild(); //creates clean vectors
                case4sub2.timeAndDate(fileName); //creates time and date vectors
                for (int i = 0; i < 24; i++) {
                    int x = 0;
                    int y = 0;
                    for (int k = 0; k < case4sub2.time4.size(); k++) {
                        if (i == case4sub2.time4[k]) {
                            y++;
                        }
                    }
                    for (int k = 0; k < case4sub2.time1.size(); k++) {
                        if (i == case4sub2.time1[k]) {
                            x++;
                        }
                    }
                    cout << i << ": ";
                    case4sub2.columnGenerator1(x, value);
                    cout << endl << setw(4) << " ";
                    case4sub2.columnGenerator2(y, value);
                    cout << endl;
                }
                cout << endl;
            }
            break;
        }
        main();
    } else if(choice == 5) {
        int userInputLat;
        int userInputLong;
        cout << "   Input latitude and longitude of the home: " << endl;
        cin >> userInputLat;
        cin >> userInputLong;
        cout << "You entered " << userInputLat << " for latitude and " << userInputLong << " for longitude" << endl;
        cout << "   Closest Divvy station is: " << endl;
        main();
    } else if(choice == 6) {
        exit(EXIT_FAILURE); //exit function
    }
    return 0;
}