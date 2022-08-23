#include<bits/stdc++.h>
#include "station.cpp"
#include "connection.cpp"
using namespace std;

class MetroGraph{
private:

    // adjacency list
    vector< vector<Connection>> adj;

    // store all stations
    vector<Station> stations;

public :

    MetroGraph(){
        adj.resize(stations.size());
    }

    // get adjacency list
    vector<vector<Connection>> get_adjacency() {
        return adj;
    }

    // find distance between two stations
    float find_distance(int x1,int y1,int x2,int y2) {
        return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }

    float get_distance(int id1,int id2) {
        int _1x,_1y,_2x,_2y;
        for(int i=0;i<stations.size();i++) {
            if(stations[i].get_id()==id1) {
                _1x=stations[i].get_x_coordinate();
                _1y=stations[i].get_y_coordinate();
            }
            else if(stations[i].get_id()==id2) {
                _2x=stations[i].get_x_coordinate();
                _2y=stations[i].get_y_coordinate();
            }
        }
        return find_distance(_1x,_1y,_2x,_2y);
    }

    // add station
    void add_station(Station s) {
        stations.push_back(s);
    }

    // get count of stations
    int get_count_station() {
        return stations.size();
    }

    void add_connection(Connection c) {
        adj[c.get_first_station()].push_back(c);
        adj[c.get_second_station()].push_back(c);
        cout<<"ADDDED SUCCESSFULLY"<<endl;
    }
    
    // delete connection
    void delete_connection(int id_1st_station,int id_2nd_station) {
        vector<Connection>::iterator it;
        for(it=adj[id_1st_station].begin(); it!=adj[id_1st_station].end() ;it++) {
            if(it->get_second_station()==id_2nd_station) {
                adj[id_1st_station].erase(it);
            }
        }
        for(it=adj[id_2nd_station].begin(); it!=adj[id_2nd_station].end() ;it++) {
            if(it->get_second_station()==id_1st_station) {
                adj[id_1st_station].erase(it);
            }
        }
    }
};