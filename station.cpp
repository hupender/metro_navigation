

#ifndef STATION_CPP
#define STATION_CPP

#include<bits/stdc++.h>
#include "common.h"

using namespace std;
class Station {

private:
    
    int      station_id;
    string   station_name;
    float      station_x_coordinate;
    float      station_y_coordinate;

public:
    // constructor
    Station(
        int      station_id,
        string   station_name,
        float      station_x_coordinate,
        float      station_y_coordinate
    ) {
        this->station_id             = station_id;
        this->station_name           = station_name;
        this->station_x_coordinate   = station_x_coordinate;
        this->station_y_coordinate   = station_y_coordinate;
    }

    // get id of station
    int get_id() {
        return station_id;
    }
    // name of station
    string get_name() {
        return station_name;
    }
    // x coordinate of station
    float get_x_coordinate() {
        return station_x_coordinate;
    }
    // y coordinate of station
    float get_y_coordinate() {
        return station_y_coordinate;
    }

};

#endif