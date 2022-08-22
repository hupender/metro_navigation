#include<iostream>
using namespace std;

class Connection {
private:
    int first_station; // id
    int second_station; // id
    int color_id;    
    //don't forget to mention what color has what id 
    // 0 for red
    // 1 for green
    // 2 fro yellow
    // 3 for pink
    // 4 for red 

    int distance;
public:
    Connection(int a,int b,int c,int d) {
        first_station=a;
        second_station=b;
        color_id=c;
        distance=d;
    }
    int get_first_station() {
        return first_station;
    }
    int get_second_station() {
        return second_station;
    }
    int get_color_id() {
        return color_id;
    }
    int get_distance() {
        return distance;
    }
};