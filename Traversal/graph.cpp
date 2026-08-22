#include <iostream>
#include <list>
#include <stack>
# include <vector>
#include <queue>

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

void BFS(list<int> * L, int arr[] , int index , bool vis_arr[],int v){

queue<int> q;


q.push(0);
vis_arr[0]= true;
arr[index] = 0;
index++;

 while (!q.empty())
 {
  int u = q.front();
  q.pop();  
  

 for(int n :L[u]){
    if(!vis_arr[n]){
     vis_arr[n] = true;
     arr[index] = n;
     index++;
     q.push(n);
    }}
}
}

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


// Disconnected DFS

void Disconnected_DFS(list<int> * L , int V,int arr[], int &index , bool vis_arr[], int val){

    for(int i=val;i<V;i++){
    if(!vis_arr[i]){
     DFS(L,arr,index,vis_arr,i);
    }
}

    
}
// Disconnected BFS
void Disconnected_BFS(list<int> * L , int V,int arr[], int &index , bool vis_arr[], int val){
      for(int i=val;i<V;i++){
    if(!vis_arr[i]){
     BFS(L,arr,index,vis_arr,i);
    }
}
}

// Cycle Detection 
bool Cycle_DFS(list<int> * L, int arr[] , int &index , bool vis_arr[] , int val , int par){


vis_arr[val]= true;
arr[index] = val;
index++;


for(int u: L[val]){
    if(!vis_arr[u]){
     if(Cycle_DFS(L, arr, index , vis_arr , u , val)){
         return true;
     }
    }else{
    if(u != par){
        return true;
    }
    }
}

 return false;
}



// LEVEL BFS 
void LEVEL_BFS(list<int> * L,int** arr , int index , bool vis_arr[]){

queue<int> q;


q.push(0);
vis_arr[0]= true;
int level = 0;

 while (!q.empty())
 {

int levelSize = q.size();

   for (int i = 0; i < levelSize; i++)
    { 


  int u = q.front();
  q.pop();  
  arr[level][index] = u;  
  index++;


 for(int n :L[u]){
    if(!vis_arr[n]){
     vis_arr[n] = true;
     q.push(n);
    }}
   
    
}

index = 0;
level++;
}

}

// Connected Components
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


//  Multi Source BFS
int MultiSourceBFS(int arr[] , int index , bool ** vis_arr,int v , int ** grid , int a ,int b){
queue<pair<pair<int,int> ,int>>q;
int i;
int j;
int time;
    for(int i=0;i<a;i++){
        for(int j= 0;j<b;j++){
          if(grid[i][j] == 2){
      q.push({{i, j}, 0});
      vis_arr[i][j] = true;
    }
        }
    }

while (!q.empty())
 {
  auto p = q.front();
 i = p.first.first;
 j = p.first.second;
 time = p.second;
  q.pop();  
    if(j + 1 < b && grid[i][j+1] == 1 && !vis_arr[i][j+1]){
     vis_arr[i][j+1] = true;
     q.push({{i,j+1},time+1});
    }
    
    if(i + 1 < a && grid[i+1][j] == 1 &&!vis_arr[i+1][j]){
    vis_arr[i+1][j] = true;
     q.push({{i+1,j} ,time+1});
    }


    if(j - 1 >= 0 && grid[i][j-1] == 1 && !vis_arr[i][j-1])
{
    vis_arr[i][j-1] = true;
    q.push({{i,j-1}, time+1});
}


if(i - 1 >= 0 && grid[i-1][j] == 1 && !vis_arr[i-1][j])
{
    vis_arr[i-1][j] = true;
    q.push({{i-1,j}, time+1});
}
}




for(int i = 0; i < a; i++)
{
    for(int j = 0; j < b; j++)
    {
        if(grid[i][j] == 1 && !vis_arr[i][j])
            return -1;
    }
}

return time;
}


bool Bidirectional_BFS(list <int> * start ,list <int> * target,bool vis_start[] , bool vis_target[],int tar_value,int start_val){
queue <int> q1;
queue <int> q2;

q1.push(start_val);
vis_start[start_val] = true;
q2.push(tar_value);
vis_target[tar_value] = true;

 while (!q1.empty() && !q2.empty())
 {

    int a=q1.front();
    int b = q2.front();

    q1.pop();
    q2.pop();
    

    for(int u : start[a]){
        if(!vis_start[u]){
        if(vis_target[u])
        {
           return true;
        }
          q1.push(u);
          vis_start[u]= true;
        }
    }

    for(int v : target[b]){
        if(!vis_target[v]){
        if(vis_start[v])
        {
           return true;
        }
          q2.push(v);
          vis_target[v]= true;
        }else{

        }
    }
   

 }
 return false;
    
}


// DFS Entry Exit time 
void DFS_Entry_Exit(list<int> * L  , int EntryTime[] ,int val, int ExitTime[], bool vis[] ,int &time){
    time++;
    EntryTime[val]= time; 
    vis[val] = true; 

    for(int u : L[val]){
        if(!vis[u]){
         DFS_Entry_Exit(L , EntryTime, u,ExitTime, vis ,time);
        }
    }
    time++;
    ExitTime[val] = time;
}

// Detect Cycle in Directed Graph 
bool Cycle_DFS(list<int> * L, bool vis_arr[] , bool recPath[], int val ){


vis_arr[val]= true;
recPath[val]=true;


for(int u: L[val]){
    if(!vis_arr[u] ){
     if(Cycle_DFS(L, vis_arr, recPath , u ))
       return true;

    }else{
    if(recPath[u])
     return true;
    }
}

recPath[val] = false;
return false;
}

bool Bipartite_BFS(list<int> * L , bool vis_arr[], int val ,int color[] ){
    queue<int> q; 

    q.push(val);
    vis_arr[val] = true;
    color[val] =1;


    while (!q.empty())
    {
       int v =  q.front();
       q.pop();

       for(int u : L[v]){
        if(!vis_arr[u]){
        
            if(color[v]==1){
             vis_arr[u]= true;
             color[u]=2;
             q.push(u);
            }else{
             vis_arr[u] = true;
             color[u] = 1;
             q.push(u);
            }
        }else{
            if(color[u]==color[v])
              return false;
        }

       }
    }
    
return true;
}

// Bipartite DFS
bool Bipartite_DFS(list<int> * L , bool vis_arr[],int color[], int val , int n){

    vis_arr[val] = true;
    color[val] =n;
    
    for(int u : L[val]){
       
        if(!vis_arr[u]){
            if(color[val]==1){

            if(!Bipartite_DFS(L,vis_arr,color,u,2)){
                return false;
            }

            }else{

            if(!Bipartite_DFS(L,vis_arr,color,u,1)){
                return false;
            }   
            }
           
        }else{
            if(color[u]==color[val])
              return false;
        }

    }


    
return true;  


}



//  Topological Sorting  DFS
void DFS_Topological_sort(list<int> * L ,bool vis_arr[] ,int val, stack <int> &s){
vis_arr[val]= true;


  for(int u : L[val]){
  if(!vis_arr[u]){
     DFS_Topological_sort(L,vis_arr,u,s);
    } 
  }
  
    
s.push(val);    
}


void Disconnected_DFS_TS(list <int> * L,int V ,bool vis[], stack<int> &s){
for(int i=0;i<V;i++){
    if(!vis[i])
      DFS_Topological_sort(L , vis , i,s);
}
}

// Kahn's Algorithm BFS Topological Sorting 

void BFS_TS(list <int> * L , int V , int indegree[], int ans[] ,int &index){

 queue<int> q;

 for(int i=0; i<V; i++){
   for(int u : L[i]){
    indegree[u]++;
   }  
 }

 for(int i = 0; i < V; i++){
    if(indegree[i]== 0){
        q.push(i);
    }
}

    while(!q.empty()){
     int u = q.front();
    ans[index] = u;
     index++;
     q.pop();

  for(int v : L[u]) {
        indegree[v]--;

        if(indegree[v] == 0)
            q.push(v);
    }
 
}
}


// Shortest Path unweighted
void Shortest_Path_BFS(list <int> * L , int val , int tar , int parent[], bool vis[] ){
queue <int> q;

vis[val]= true;
parent[val] = -1;
q.push(val);

while (!q.empty())
{
    int a = q.front();
    q.pop();

    for(int u: L[a]){
        if(!vis[u]){
            vis[u] = true;
            parent[u] = a; 
            q.push(u);
        }
    }
}
int ind = 0;
int n = tar;

int arr[V];
arr[ind] = tar;
ind++;

while(parent[n] != -1){
   int u = parent[n];
   arr[ind]= u;
   ind++;
   n = u;
}
}


// Dijikstra Algorithm weighted Undirected Graphs
void Short_path(list <pair<int,int>> L[],  int src, int dest , int dist[]){
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;

pq.push({0,src});


while(!pq.empty()){
    int a = pq.top().first; // weight
    int b = pq.top().second; // neigh
    pq.pop();

    for( auto u : L[b]){
       int d =  a + u.second;  // weight
       if(d < dist[u.first]){ 
        dist[u.first]= d;
        pq.push({d,u.first});
       }

       }
      }
    } 



// Bellmen Ford Algorithm 
void Short_Path_DP(list <pair<int,int>> L[], int dist[],int V){


for(int i=0;i<V-1;i++){
    for(int u = 0;u<V;u++){
           for( auto b : L[u]){
       int d =  dist[u] + b.second;  // weight
       if(d < dist[b.first]){ 
        dist[b.first]= d;
       }

       }

    }
}
  
      }


// Floyd Warshall (Shortest Path in Every pair)
void Short_path_FW(int V,int ** dist){

   for(int k=0;k<V;k++){
    for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
       int d = dist[i][k]+ dist[k][j];
       if(dist[i][j] > d){
          dist[i][j]=d;
       }
        }
        }
    }

}

    


// Bridge 
void Dfs_Bridge(list<int> L[],int u, bool vis[], int v, int &time ,int dt[],int low[] , vector <pair<int,int>> &brige){

    vis[u] = true;
    time++;
    dt[u] = time;
    low[u]  =time;

    for(int a : L[u]){
        if(!vis[a]){
            Dfs_Bridge(L ,a,vis,u ,time, dt, low  ,brige);
            // Case -1 
           if(low[u] > low[a]){
            low[u] = low[a];
           }
           // Case -2
           if(low[a]> dt[u]){
             brige.push_back({a,u});
           }

        }else{
            //Case - 3
            if(a != v){
              if(low[u] > dt[a]){
                low[u] = dt[a];
              }  
            }
        }
          
    }
}

// Articulation Point

void Dfs_Bridge_Art(list<int> L[],int u, bool vis[], int v, int &time ,int dt[],int low[], vector<int> & art, bool isArt[]){
int children = 0;
    vis[u] = true;
    time++;
    dt[u] = time;
    low[u]  =time;

    for(int a : L[u]){
        if(!vis[a]){
            children++;
            Dfs_Bridge_Art(L ,a,vis,u ,time, dt, low , art, isArt);
            // Case -1 
           if(low[u] > low[a]){
            low[u] = low[a];
           }
           // Case -2
           if(low[a]>= dt[u]  && v != -1){
         isArt[u]= true;
           }

        }else{
            //Case - 3
            if(a != v){
              if(low[u] > dt[a]){
                low[u] = dt[a];
              }  
            }
        }
          
    }

    if(v == -1 && children > 1){
   isArt[u] = true;
}
};

void Articulation_Points(list<int> L[],int V, vector<int>& art){
    bool vis[V] = {false};
    bool isArt[V] = {false};

    int dt[V];
    int low[V];

    int time = 0;

    for(int i = 0; i < V; i++){

        if(!vis[i]){
      Dfs_Bridge_Art( L,i,vis,-1,time,dt,low,art,isArt );
        }
    }


    // Collect articulation points
    for(int i = 0; i < V; i++){

        if(isArt[i]){
            art.push_back(i);
        }
    }
}



// Kosaraju's algorithm 

void Transpose_Graph(list<int> L[], int V, list<int> T[]){
   
    for(int i=0; i<V;i++){
        for(auto u :L[i]){
          T[u].push_back(i);
        }
    }
}


//  Topological Sorting  DFS
// void DFS_Topological_sort(list<int> * L ,bool vis_arr[] ,int val, stack <int> &s){
// vis_arr[val]= true;


//   for(int u : L[val]){
//   if(!vis_arr[u]){
//      DFS_Topological_sort(L,vis_arr,u,s);
//     } 
//   }
  
    
// s.push(val);    
// }


// void Disconnected_DFS_TS(list <int> * L,int V ,bool vis[], stack<int> &s){
// for(int i=0;i<V;i++){
//     if(!vis[i])
//       DFS_Topological_sort(L , vis , i,s);
// }
// }

void Kosaraju_algo(int V){
    // step 1 topological Order
list<int> L[V];
list <int> T[V];

stack <int> s;
bool vis[V] = {false};

for(int i=0;i<V;i++){
    if(!vis[i])
     DFS_Topological_sort(L,vis,i,s);
}

// Step 2 Transpose Graph

Transpose_Graph(L,V,T);

// step 3 now stack 
int i =0;

bool vis_arr[V] = {false};
int comp_arr[V][V];
while(!s.empty()){
    int u = s.top();
    s.pop();
    
    if(!vis_arr[u]){
        int j= 0;
      DFS(T, comp_arr[i] ,j,  vis_arr, u);
       i++;
    }
}

}





void SSC_tarjan(list<int> L[],int u, bool vis[], int &time ,int dt[],int low[] , stack<int> &s , bool instack[], int** Scc_Comp,int &i){

    vis[u] = true;
    time++;
    dt[u] = time;
    low[u]  =time;
    s.push(u);
    instack[u] = true;

    for(int a : L[u]){
        if(!vis[a]){
   
            SSC_tarjan(L ,a,vis ,time, dt, low, s,instack, Scc_Comp,i);
            
            // Case -1 
           if(low[u] > low[a]){
            low[u] = low[a];
           }

        }else{
            //Case - 3
           if(instack[a]){
    if(low[u] > dt[a]){
        low[u] = dt[a];
    }
}
        }
          
    }


    if(low[u] == dt[u]){
           while(true){

        int x = s.top();
        s.pop();

        instack[x] = false;

       Scc_Comp[i][x]= x;
      

        if(x == u)
            break;
    }
     i++;
    }

}



// Euler Path and Circuit

void Euler_DFS(list <int> L[] , int u , int edges[] , bool vis[]){

    vis[u]= true;
 int n=0;


  for(int j : L[u]){
    if(!vis[j]){
     Euler_DFS(L,j,edges,vis);
    }
      n++;
  }


  edges[u]=n;

}

int Euler_path_or_Circuit(list <int> L[] , int V , int edges[] , bool vis[]){

    
      int num = 0;
     
        Euler_DFS(L,0,edges,vis);
      
        for(int i=0;i<V;i++){
            if(!vis[i] && edges[i]){ // connectivity check
                return 0;
            }
              
            if(edges[i]%2 != 0){  // path
                num++;
            }
        }

        if(num == 2){  // path
            return 1;
        }else if(num ==0){ // circuit
            return 2;
        }
    
}



// hamiltonian path
int Hamiltonian(list <int> L[] ,int start ,int u , int V ,bool vis[]){
vis[u] = true;
bool isNeigh= false;
bool full_traversed = true;


for(int i=0;i<V;i++){
    if(!vis[i]){
      full_traversed = false;
    }
    
}

if(full_traversed){
for(int i : L[u]){
    if(vis[i]){
     if(i == start) isNeigh = true;
    }
}
if(full_traversed && isNeigh ){ return 2;}else{
   return 1;
}

}



    for(int i:L[u]){

    if(!vis[i]){
        int val  = Hamiltonian(L,start,i,V,vis);
       if(val){
        return val;
       }
       vis[i] = false;
        }
}



   return 0;

}


int hamitonian_path_or_Circuit(list <int> L[] ,int u, int V , bool vis[]){

int n = u;    
     int check_path;
     check_path =  Hamiltonian(L,n,u,V,vis);
       
      
        for(int i=0;i<V;i++){
            if(!vis[i]) check_path = 0;
        } 

        return check_path;
}
};






int main(){
    return 0;
}