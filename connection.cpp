

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

    Connection(
        int     first_station   ,
        int     second_station  ,
        int     color_id        ,
        float   distance  
    )
    {
        this->first_station  = first_station  ;   
        this->second_station = second_station ;   
        this->color_id       = color_id       ;   
        this->distance       = distance       ;   
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

    // // distance between two  station
    int get_distance() {
        return distance;
    }
};