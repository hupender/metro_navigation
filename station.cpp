#include<bits/stdc++.h>
using namespace std;
class Station {

private:
    
    int id;
    string name;
    int x_coordinate;
    int y_coordinate;
    int platform;

public:
    // constructor
    Station(int a,string s,int x,int y,int count) {
        id=a;
        name=s;
        x_coordinate=x;
        y_coordinate=y;
        platform=count;
    }

    // get id of station
    int get_id() {
        return id;
    }
    // name of station
    string get_name() {
        return name;
    }
    // x coordinate of station
    int get_x_coordinate() {
        return x_coordinate;
    }
    // y coordinate of station
    int get_y_coordinate() {
        return y_coordinate;
    }
    // number of platform on a particular
    int get_count_plat() {
        return platform;
    }
};