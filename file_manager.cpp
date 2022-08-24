#ifndef FILE_MANAGER_CPP
#define FILE_MANAGER_CPP
#include<bits/stdc++.h>
#include "graph.cpp"
#include "common.h"

using namespace std;
class File_manager{
public:
    MetroGraph get_input_from_file() {
        MetroGraph metro_graph;
        ifstream input("data.txt");

        if(glob::dM) cout << "Started Reading data from file\n";


        int num_station;
        input>>num_station;

        int station_id;
        float x_coordinate,y_coordinate;
        string station_name;

        for(int i=0;i<num_station;i++) {
            input>>station_id;
            getline(input, station_name); // dummy read for "\n??"
            getline(input, station_name);
            input>>x_coordinate>>y_coordinate;



            Station st(station_id,station_name,x_coordinate,y_coordinate);
            metro_graph.add_station(st);

        }

        if(glob::dM) cout << "Finished Reading station data\n";
        int num_connection;
        input>>num_connection;

        int station1_id,station2_id,color;
        float distance;
        for(int i=0;i<num_connection;i++) {
            input >>station1_id>>station2_id>>color;
            distance=metro_graph.get_distance(station1_id,station1_id);
            Connection c(station1_id,station2_id,color,distance);
            metro_graph.add_connection(c);
        }


        if(glob::dM) cout << "Finished reading connection data\n";

        return metro_graph;
        
    }
    
};


#endif