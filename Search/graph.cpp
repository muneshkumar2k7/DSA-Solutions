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



// dfs search /Reachibilty DFS / path exist or not
bool dfs(list <int> * L,int target , bool vis[] ,int val ){
vis[val]  = true;

if(val == target) return true;

for(int u : L[val]){
    if(!vis[u]){
        if(dfs( L,target ,vis ,u)) return true;
    }
}

return false;
}


//dfs search /Reachibilty BFS / Path exist or not 
  bool bfs_search(int arr[] , int index , bool vis_arr[],int v , int target){

queue<int> q;


q.push(v);
vis_arr[v]= true;
arr[index] = v;
index++;



 while (!q.empty())
 {
  int u = q.front();
  if(u == target) return true;
  q.pop();  
  

 for(int n :adjacencyList[u]){
    if(!vis_arr[n]){
     vis_arr[n] = true;
     arr[index] = n;
     index++;
     q.push(n);
    }}
}

return false;
}



// If it is reachable then what is the path between two nodes
// we check its reachable if its not then vector will be empty

// finding path
bool dfs(list <int> * L,int target , bool vis[] ,int val  , vector<int> & path){
vis[val]  = true;
path.push_back(val);

if(val == target) return true;

for(int u : L[val]){
    if(!vis[u]){
        if(dfs( L,target ,vis ,u, path)) return true;
        else path.pop_back();   
    }
}


return false;
}


//path reconstruction
 vector<int> bfs_search(bool vis_arr[],int v , int target){

queue<int> q;
int * par = new int[100];

q.push(v);
vis_arr[v]= true;
par[v]= -1;



 while (!q.empty())
 {
  int u = q.front();
  if(u == target) {
    return par;
    }

  q.pop();  
  

 for(int n :adjacencyList[u]){

    if(!vis_arr[n]){
     par[n] = u;
     vis_arr[n] = true;
     q.push(n);
    }}
      
   
}
return par; 
 }


// Finding all paths
void dfs(list <int> * L,int target , bool vis[] ,int val  , vector<int>& path , vector<vector<int>>&all_paths){
vis[val]  = true;
path.push_back(val);

if(val == target){ 
    all_paths.push_back(path); 
    vis[val] = false;
    path.pop_back();
     return;
    }

for(int u : L[val]){
    if(!vis[u]){
          dfs( L,target ,vis ,u, path , all_paths);
    }
}

vis[val] = false;
path.pop_back();
}



// Connected Components  it is almost similar to disconnected DFS 
void DFS_island(int i,int j,bool **vis,int** grid,int n,int m){
 if(i<0|| j<0|| i>=n || i >=m || grid[i][j]!=1 || vis[i][j]){
  return ;
 }   
vis[i][j] = true;

DFS_island(i+1,j,vis,grid,n,m);
DFS_island(i-1,j,vis,grid,n,m);
DFS_island(i,j+1,vis,grid,n,m);
DFS_island(i,j-1,vis,grid,n,m);
}


int Number_of_island(int **grid , int n, int m, bool ** visit){
    int count = 0;
    for (int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    if (grid[i][j] == 1 && !visit[i][j])
    {
        count++;              // new island discovered
        DFS_island(i, j , visit, grid,n,m);            // consume/trace this whole island
    }
}
}
return count;
}






int main(){

}