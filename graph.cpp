#include<iostream>
#include <vector>
#include "station.cpp"
#include "connection.cpp"
using namespace std;

class MetroGraph{
private:
    int num_stations;
    vector< vector<Connection>> adj;

public :
    MetroGraph(){
        num_stations=0;
        adj.resize(num_stations);
    }

    void add_station(int n) {
        num_stations+=n;
    }

    int get_no_of_stations() {
        return num_stations;
    }

    vector<vector<Connection>> get_adjacency() {
        return adj;
    }
    
    void add_connection(Connection c) {
        adj[c.get_first_station()].push_back(c);
        adj[c.get_second_station()].push_back(c);
    }

};