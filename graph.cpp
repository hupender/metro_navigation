
#ifndef GRAPH_CPP
#define GRAPH_CPP

#include<bits/stdc++.h>
#include "connection.cpp"
#include "common.h"

using namespace std;

class MetroGraph{
private:

    // adjacency list
    vector< vector<Connection>> adj;

    // store all stations
    vector<Station> stations;

public :


    // get adjacency list
    vector<vector<Connection>> get_adjacency() {
        return adj;
    }

    // find distance between two stations
    float find_distance(float x1,float y1,float x2,float y2) {
        return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }

    float get_distance(int id1,int id2) {
        float _1x,_1y,_2x,_2y;
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
        float res =  find_distance(_1x,_1y,_2x,_2y);
        

        if(glob::dM) cout << "get_distance for id1 = " << id1 << " id2 = " << id2 << " returned res = " << res << "\n";
        
        return res;
    }

    // add station
    void add_station(Station s) {

        if(glob::dM){
            cout << "add_station called for station with these details : \n";
            s.print_data();
        }
        stations.push_back(s);
        adj.push_back({});
        // can use resize instead
    }
    
    // delete station
    // very inefficient
    // Todo : Make it efficient
    void delete_station(int station_id) {
        if(glob::dM){
            cout << "delete_station called for station_id = " << station_id << endl;
        }
        adj[station_id].clear();
        for(int i=0;i<adj.size();i++) {
            for(int j=0;j<adj[i].size();j++) {
                if(adj[i][j].get_first_station()==station_id || adj[i][j].get_second_station()==station_id) {
                    // adj[i] is the vector
                    // we need to delete its jth element
                    adj[i].erase(adj[i].begin()+j);
                }
            }
        }
        cout<<"STATION DELETED SUCCESSFULLY"<<endl;
    }

    // get count of stations
    int get_count_station() {
        return stations.size();
    }

    void add_connection(Connection c) {
        if(glob::dM){
            cout << "add_connection called for connection with these details : \n";
            c.print_data();
        }
        adj[c.get_first_station()].push_back(c);
        adj[c.get_second_station()].push_back(c);
        // cout<<"ADDDED SUCCESSFULLY"<<endl;
    }
    
    // delete connection
    void delete_connection(int id_1st_station,int id_2nd_station) {
        
        if(glob::dM){
            cout << "delete_connection called for these station ids : " << id_1st_station << ", " << id_2nd_station << endl;
        }


        vector<Connection>::iterator it;
        for(it=adj[id_1st_station].begin(); it!=adj[id_1st_station].end() ;it++) {
            if(it->get_second_station()==id_2nd_station || it->get_first_station()==id_2nd_station) {
                adj[id_1st_station].erase(it);
            }
        }
        for(it=adj[id_2nd_station].begin(); it!=adj[id_2nd_station].end() ;it++) {
            if(it->get_second_station()==id_1st_station || it->get_first_station()==id_1st_station) {
                adj[id_1st_station].erase(it);
            }
        }
    }
};


#endif