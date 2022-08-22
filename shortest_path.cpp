#include<bits/stdc++.h>
#include "graph.cpp"
#include"connection.cpp"
using namespace std;
class Shortest_path{
private:
    vector<vector<int>> dp_table;
public:

    int get_shortest_path(int source,int destinstion,MetroGraph mg) {
        int no_of_station=mg.get_no_of_stations();
        vector<int> distance(no_of_station,INT_MAX);
        distance[source]=0;

        vector<int> parent(no_of_station,-1);

        set<pair<int,int>> s;  // keeps data in a sorted way and works like a priority queue
        // keep track of color change and with every color change we make a increment of c
        int color_id_initial,color_id_final;
        s.insert({0,source});
        while(!s.empty()) {
            set<pair<int,int>>::iterator itr;
            itr=s.begin();
            int top_node=itr->second;
            int top_dis=itr->first;
            vector<vector<Connection>> adj_list=mg.get_adjacency();
            for(auto i:adj_list[top_node]) {
                if(distance[i.get_second_station()] > i.get_distance()+top_dis) {
                    auto check=s.find({i.get_second_station(),distance[i.get_second_station()]});
                    if(check!=s.end()) {
                        s.erase(check);
                    }
                    parent[i.get_second_station()]=top_node;
                    s.insert(i.get_second_station(),top_dis+i.get_distance());
                    distance[i.get_second_station()]=top_dis+i.get_distance();
                }
            }
        }
    }
};