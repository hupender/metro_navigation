#ifndef SHORTEST_PATH_FINDER_CPP
#define SHORTEST_PATH_FINDER_CPP


#include<bits/stdc++.h>
#include "graph.cpp"
#include "common.h"

using namespace std;
class Shortest_path_finder{
public:

    vector<pair<int,int>> get_shortest_path(int source,MetroGraph mg) {
        if(glob::dM){
            cout << "get_shortest_path called. source = " << source << endl;
            cout << "graph details : num_stations = ";
            cout << mg.get_count_station() << endl;
        }
        bool internal_debug = true && glob::dM;

        int no_of_station=mg.get_count_station();
        //store shortest distance from the given source
        vector<int> distance(no_of_station,INT_MAX);
        distance[source]=0;

        //store parent station of all stations
        vector<pair<int,int>> parent(no_of_station, {-1, 0});
        // parent[i].first is the source from which i has shortest path
        // parent[i].second is the color of edge from  i <--> parent[i].first
        // parent[i].first is -1 only for source.
        // parent[i].first is -1 also when i is not reachable

        parent[source]={-1,0};

        // keep track of color change and with every color change we make a increment of c
        vector<int> color(no_of_station);
        color[source]=-1;

        // keeps data in a sorted way and works like a priority queue
        set<pair<int,int>> s;

        s.insert({0,source});
        while(!s.empty()) {

            // iterator to set of pairs
            set<pair<int,int>>::iterator itr;

            // pop element with smallest distance
            itr=s.begin();
            int top_node=itr->second;
            int top_dis=itr->first;

            if(internal_debug){
                cout << "[DEBUG] top_node " << top_node << " top_dis = " << top_dis << endl;
            }

            s.erase(s.begin());

            //get adjacency list
            vector<vector<Connection>> adj_list=mg.get_adjacency();

            for(auto i:adj_list[top_node]) {
                
                // get the color of edge between curr station and child nodes
                color[i.get_second_station()]=i.get_color_id();

                int line_change_factor=10;

                if(color[i.get_second_station()]==color[top_node]) {
                    line_change_factor=0;
                }

                // check if distance to reach a station is short from any path
                if(distance[i.get_second_station()] > i.get_distance()+top_dis+line_change_factor) {
                    auto check=s.find({distance[i.get_second_station()],i.get_second_station()});
                    
                    // erase any earlier presence of the station if any present in the set
                    if(check!=s.end()) {
                        s.erase(check);
                    }

                    // update parent
                    parent[i.get_second_station()]={top_node,i.get_color_id()};

                    // insert with the short path
                    s.insert({top_dis+i.get_distance()+line_change_factor, i.get_second_station()});

                    //update the distance vector
                    distance[i.get_second_station()]=top_dis+i.get_distance()+line_change_factor;
                }
            }
        }

        if(glob::dM){
            cout << "shortest_path calculated for source = " << source << " :\n";
            cout << "distance array : " ;
            for(int i : distance){
                cout << i << " ";
            }
            cout << endl;

            cout << "parent array : ";
            for(pair<int, int> i : parent){
                cout << "{" << i.first << ", " << i.second << "} ";
            }
            cout << endl;

            cout << "color array : ";
            for(int i : color){
                cout << i << " ";
            }
            cout << endl;
        }

        return parent;
    }
};


#endif