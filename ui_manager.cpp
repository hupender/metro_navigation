
#ifndef UI_MANAGER_CPP
#define UI_MANAGER_CPP

#include<bits/stdc++.h>
#include "graph.cpp"
#include "shortest_path.cpp"
#include "common.h"

using namespace std;

class Ui_manager {
public:
    

    // 1 : add station
    // 2 : add edge/connection
    // 3 : remove station
    // 4 : remove edge
    // 5 : find sortest path
    void operation(MetroGraph metrograph) {
        int choice;
        cout<<"Enter what operation you want to do"<<endl;
        cin>>choice;

        if(glob::dM) cout << "user entered choice = " << choice << endl;

        switch(choice) {

            // add station
            case 1:
            {
                // how many stations we want to add
                int n;
                cout<<"Enter how many station you want to add"<<endl;
                cin>>n;
                cout<<"Enter station details"<<endl;
                for(int i=0;i<n;i++) {
                    int id;
                    float x,y;
                    string s;
                    cin>>id>>s>>x>>y;
                    Station st(id,s,x,y);
                    metrograph.add_station(st);
                }
                break;
            }
            // add edge
            case 2:
            {
                int p;
                // how many edges we want to add
                cout<<"Enter count of edges you want to add "<<endl;
                cin>>p;
                cout<<"Enter the edges you want to add"<<endl;
                for(int i=0;i<p;i++) {
                    int id1,id2,color;
                    float d=metrograph.get_distance(id1,id2);
                    Connection c(id1,id2,color,d);
                    metrograph.add_connection(c);
                }
                break;
            }
            // remove station
            case 3:
            {
                int id;
                cout<<"Enter id of station you want to delete"<<endl;
                cin>>id;
                metrograph.delete_station(id);
                break;
            }
            // remove a edge/connection
            case 4:
            {
                int id1,id2;
                cout<<"Enter id of the station you want to delete the edge"<<endl;
                cin>>id1>>id2;
                metrograph.delete_connection(id1,id2);
                break;
            }
            case 5:
            {
                Shortest_path_finder sortest_path;
                cout<<"Enter source_id and destination_id of stations"<<endl;
                int source,destination;
                cin>>source>>destination;
                vector<pair<int,int>> parent=sortest_path.get_shortest_path(source,metrograph);
                reverse(parent.begin(),parent.end());
                vector<pair<int,int>> res;
                int i;
                for(i=0;i<parent.size();i++) {
                    if(parent[i].first==destination) {
                        break;
                    }
                }
                while(i!=source) {
                    res.push_back(parent[i]);
                    i=parent[i].first;
                }
                reverse(res.begin(),res.end());
                cout<<res[0].first<<endl;;
                for(int j=1;j<res.size();j++) {
                    if(res[j].second==res[j-1].second) {
                        cout<<res[j].first<<endl;
                    }
                    else {
                        cout<<"Change line from "<<res[j-1].second<<" to "<<res[j].second<<endl;
                    }
                }
                break;
            }
            default :
                cout << "Invalid option\n";

        }
    }
    
};



#endif