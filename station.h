#include<iostream>
using namespace std;
class station {
    private:
        int id;
        string name;
        int x_coordinate;
        int y_coordinate;
        int platform;
    public:
        station(int a,string s,int x,int y,int count) {
            id=a;
            name=s;
            x_coordinate=x;
            y_coordinate=y;
            platform=count;
        }
        int get_id() {
            return id;
        }
        string get_name() {
            return name;
        }
        int get_x_coord() {
            return x_coordinate;
        }
        int get_y_coordinate() {
            return y_coordinate;
        }
        int get_count_plat() {
            return platform;
        }

};