#include<bits/stdc++.h>
#include "station.cpp"
#include "connection.cpp"
using namespace std;

class MetroGraph{
private:
    vector< vector<Connection>> adj;
    // store all stations
    vector<Station> stations;

public :
    MetroGraph(){
        adj.resize(stations.size());
    }

    // add station
    void add_station(Station s) {
        stations.push_back(s);
    }

    // get count of stations
    int get_count() {
        return stations.size();
    }

    void add_connection(Connection c) {
        adj[c.get_first_station()].push_back(c);
        adj[c.get_second_station()].push_back(c);
        cout<<"ADDDED SUCCESSFULLY"<<endl;
    }
    void delete_connection(int id1,int id2) {
        for(int i=0;i<stations.size();i++) {
            if(i==id1) {
                for(auto it:adj[i]) {
                    if(it.get_first_station()==id2 || it.get_second_station()==id2) {
                        
                    }
                }
            }
            if(i==id2) {
                for(auto it:adj[i]) {
                    if(it.get_first_station()==id1 || it.get_second_station()==id1) {
                        
                    }
                }
            }
        }
     }


    vector<vector<Connection>> get_adjacency() {
        return adj;
    }

};