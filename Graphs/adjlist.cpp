#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;

void addedge(int src,int dest,bool bidir=true){
    graph[src].push_back(dest);
    if(bidir){
        graph[dest].push_back(src);
    }
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto el:graph[i]){
            cout<<el<<" , ";
        }
        
        cout<<endl;
    }
}

int main(){
    cout<<"Enter number of vertices: ";
    cin>>v;
    graph.resize(v,list<int>());
    
    int e;
    cout<<"Enter number of edges: ";
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        addedge(s,d);
    }
    cout<<"Adjacency List Representation of Graph: "<<endl;
    display();
    return 0;
}