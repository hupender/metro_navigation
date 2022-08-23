#include<bits/stdc++.h>
#include"connection.cpp"
#include"station.cpp"
#include"graph.cpp"
using namespace std;

class Ui_manager {
private:
    int l;
public:
    
    MetroGraph m;

    // 1 : add station
    // 2 : add edge/connection
    // 3 : remove station
    // 4 : remove edge
    // 5 : find sortest path
    void operation(int choice) {
        switch(choice) {

            // add station
            case 1:
                // how many stations we want to add
                int n;
                cin>>n;
                for(int i=0;i<n;i++) {
                    int id,x,y,count_platform;
                    string s;
                    cin>>id>>s>>x>>y>>count_platform;
                    Station st(id,s,x,y,count_platform);
                    m.add_station(st);
                }
            // add edge

            case 2:
                int n;
                // how many edges we want to add
                cin>>n;
                for(int i=0;i<n;i++) {
                    int id1,id2,color;
                    Connection c(id1,id2,color);
                    m.add_connection(c);
                }
                
            // remove station
            case 3:
                int id;
                cin>>id;
            
            // remove a edge
            case 4:
                int id1,id2;

        }
    }
    
};