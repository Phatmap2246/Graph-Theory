#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int v,e; 
int a[1005][1005]; // Adjacency Matrix
vector<int> adj[1005]; // Adjacency List
vector<pair<int,int>> edges; // Edge List

// UNDIECTED GRAPH

// 1. Change Edge list to Adjacency List
void EdgeListToAdjList(){
    cout<<"Please enter graph vertex:  ";cin>>v;cout<<endl;
    cout<<"Please enter graph edge: ";cin>>e;cout<<endl;
    int h,t; // head and tail
    for (int i = 0;i<e;i++){
        cin>> h>>t;
        adj[h].push_back(t);
        adj[t].push_back(h);
    }

    for(int i = 1; i<=v;i++){
        cout<<i<<" : ";
        for(int x : adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

// 2. Change Edge list to Matrix
void EdgeListToMatrix(){
    cout<<"Please enter graph vertex:  ";cin>>v;cout<<endl;
    cout<<"Please enter graph edge: ";cin>>e;cout<<endl;
    int h,t; // head and tail
    for (int i = 1; i <= e; i++)
    {
        cin>>h>>t;
        a[h][t] = a[t][h]= 1;
    }

    for(int i = 1;i<=v;i++){
        for(int j = 1; j<=v ; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

// 3. Change Matrix to Adj List
void MatrixToAdjList(){
    cout<<"Please enter graph vertex: ";cin>>v;cout<<endl;
    for(int i = 1;i<=v;i++){
        for(int j = 1;j<=v;j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1;i<=v;i++){
        for(int j = 1;j<=v;j++){
            if (a[i][j]==1 && i<=j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    cout<<"Result: "<<endl;
    for (int i = 1; i<=v;i++){
        cout<<i<<" : ";
        for(int x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

// 4. Change Adj list to Edge list
void InputAdjList(){
    cout<<"Please enter graph vertex: ";cin>>v;
    cin.ignore();
    string line = "";
    int x = 0;
    for(int i =1 ; i<=v;i++ ){
        cout<<i<<" : ";
        line = "";
        getline(cin,line);
        stringstream ss(line);
        while (ss >>x)
        {
            adj[i].push_back(x);
        }
        
    }
}
void AdjListToEdgeList(){
    for(int i = 1;i<=v;i++){
        for(int x: adj[i]){
            if(i<=x){
                edges.push_back({i,x});
            }
        }
    }
    for(auto edge : edges){
        cout<<edge.first<<" "<<edge.second<<endl;
    }
}

// DIRECTED GRAPH

// 1. Change edge list to adj list directed graph
void EdgeListToAdjList_Directed(){
    cout<<"Please enter graph vertex: ";cin>>v;
    cout<<"Please enter graph edge: ";cin>>e;

    int h,t = 0;
    for(int i = 1; i<= e; i++){
        cin>>h>>t;
        adj[h].push_back(t);
    }

    cout<<"Adj List: "<<endl;
    for(int i =1 ;i<=v;i++){
        cout<<i<<" : ";
        for(int x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
} 

// 2. Change Adj list to Edge list Directed graph
int main(){
    EdgeListToAdjList_Directed();
    return 0;
}