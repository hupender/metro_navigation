#include<bits/stdc++.h>
#include"connection.cpp"
#include"station.cpp"
#include"graph.cpp"
#include "shortest_path.cpp"
using namespace std;

class Ui_manager {
public:
    
    MetroGraph metrograph;

    // 1 : add station
    // 2 : add edge/connection
    // 3 : remove station
    // 4 : remove edge
    // 5 : find sortest path
    void operation() {
        int choice;
        cout<<"Enter what operation you want to do"<<endl;
        cin>>choice;
        switch(choice) {

            // add station
            case 1:
                // how many stations we want to add
                int n;
                cout<<"Enter how many station you want to add"<<endl;
                cin>>n;
                cout<<"Enter station details"<<endl;
                for(int i=0;i<n;i++) {
                    int id,x,y;
                    string s;
                    cin>>id>>s>>x>>y;
                    Station st(id,s,x,y);
                    metrograph.add_station(st);
                }
                break;

            // add edge
            case 2:
                int n;
                // how many edges we want to add
                cout<<"Enter count of edges you want to add "<<endl;
                cin>>n;
                cout<<"Enter the edges you want to add"<<endl;
                for(int i=0;i<n;i++) {
                    int id1,id2,color;
                    float d=metrograph.get_distance(id1,id2);
                    Connection c(id1,id2,color,d);
                    metrograph.add_connection(c);
                }
                break;
                
            // remove station
            case 3:
                int id;
                cout<<"Enter id of station you want to delete"<<endl;
                cin>>id;
                metrograph.delete_station(id);
                break;
            
            // remove a edge/connection
            case 4:
                int id1,id2;
                cout<<"Enter id of the station you want to delete the edge"<<endl;
                cin>>id1>>id2;
                metrograph.delete_connection(id1,id2);
                break;

            default:
                Shortest_path sortest_path;
                int source,destination;
                cin>>source>>destination;
                vector<pair<int,int>> path=sortest_path.get_shortest_path(source,metrograph);
                reverse(path.begin(),path.end());
                break;

        }
    }
    
};