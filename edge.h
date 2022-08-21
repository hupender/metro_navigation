#include<iostream>
using namespace std;

class edges {
    private:
        int first_station;
        int second_station;
        int color_id;    //don't forget to mention what color has what id 
        int distance;
    public:
        edges(int a,int b,int c,int d) {
            first_station=a;
            second_station=b;
            color_id=c;
            distance=d;
        }
        int get_first_stat() {
            return first_station;
        }
        int get_sec_stat() {
            return second_station;
        }
        int get_color_id() {
            return color_id;
        }
        int get_distance() {
            return distance;
        }
};