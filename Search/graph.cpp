#include <iostream>
using namespace std;

class Graph{
int V; 
list<int> * L;

public:

Graph(int V){
 this->V = V;
 L = new list<int>[V];
}
void AddEdge(int u , int v){
L[u].push_back(v);
L[v].push_back(u);
}

void PrintList(){
for(int i=0;i<V;i++){
    for(int n : L[i]){
        cout<< n <<" ";
    }
    cout << endl;
}
}

};


void DFS(list<int> * L, int arr[] , int &index , bool vis_arr[] , int val){


vis_arr[val]= true;
arr[index] = val;
index++;


for(int u: L[val]){
    if(!vis_arr[u]){
     DFS(L, arr, index , vis_arr , u);
    }
}
}

// dfs search
bool dfs(list <int> * L,int target , bool vis[] ,int val){
vis[val]  = true;

if(val == target) return true;

for(int u : L[val]){
    if(!vis[u]){
        if(dfs( L,target ,vis ,u)) return true;
    }
}

return false;
}


bool iter_dfs(list <int> * L,int target , bool vis[] ,int val){
    
}

int main(){

}