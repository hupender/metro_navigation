#include<bits/stdc++.h>
#include "station.cpp"
using namespace std;

class Connection {
private:

    int first_station;  // id of 1st station
    int second_station; // id of 2nd station
    int color_id;   
    // 0 for red
    // 1 for green
    // 2 for yellow
    // 3 for pink
    // 4 for red 

    float distance;
    
public:
    // store all stations
    vector<Station> stations;

    // find distance between two stations
    float find_distance(int x1,int y1,int x2,int y2) {
        return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }

    // constructor
    Connection(int a,int b,int c) {
        first_station=a;
        second_station=b;
        color_id=c;
        int _1x,_1y,_2x,_2y;
        for(int i=0;i<stations.size();i++) {
            if(stations[i].get_id()==a) {
                _1x=stations[i].get_x_coordinate();
                _1y=stations[i].get_y_coordinate();
            }
            else if(stations[i].get_id()==b) {
                _2x=stations[i].get_x_coordinate();
                _2y=stations[i].get_y_coordinate();
            }
        }
        distance=find_distance(_1x,_1y,_2x,_2y);
    }

    // station 1 id
    int get_first_station() {
        return first_station;
    }

    // station 2 id 
    int get_second_station() {
        return second_station;
    }

    // color of line
    int get_color_id() {
        return color_id;
    }

    // distance between two  station
    int get_distance() {
        return distance;
    }
};