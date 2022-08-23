#ifndef FILE_MANAGER_CPP
#define FILE_MANAGER_CPP
#include<bits/stdc++.h>
#include "graph.cpp"
using namespace std;
class file_manager{
public:
    MetroGraph get_input_from_file() {
        MetroGraph metro_graph;
        vector<Station> stations;
        ifstream input("data.txt");
        ofstream output("data.txt");


        int num_station;
        input>>num_station;

        int station_id,x_coordinate,y_coordinate;
        string station_name;

        for(int i=0;i<num_station;i++) {
            input>>station_id>>station_name>>x_coordinate>>y_coordinate;
            output<<station_id<<station_name<<x_coordinate<<y_coordinate;
            Station st(station_id,station_name,x_coordinate,y_coordinate);
            stations.push_back(st);

        }
        int num_connection;
        input>>num_connection;

        int station1_id,station2_id,color;
        float distance;
        for(int i=0;i<num_connection;i++) {
            input >>station1_id>>station2_id>>color;
            output<<station1_id<<station2_id<<color;
            distance=metro_graph.get_distance(station1_id,station1_id);
            Connection c(station1_id,station2_id,color,distance);
            metro_graph.add_connection(c);
        }
        return metro_graph;
        
    }
    
};


#endif