#include <iostream>
#include vector
class Node{
    int data;
public:
Node(int val){
  data = val;
};
 
int Get_val(){
    return data;
}
};

// Disconnected Bidirectional Graph
class Graph{
    vector<Node> vertices;
    vector<vector<int>> adjacencyList;
  public:
  
  Graph(){};


  add_Node(Node a){
    vertices.push_back(a);
    adjacencyList.push_back({});
  }

  add_edge(int a , int b){
    adjacencyList[a].push_back(b);
    adjacencyList[b].push_back(a);
  }
  

  void BFS(int arr[] , int index , bool vis_arr[],int v){

queue<int> q;


q.push(v);
vis_arr[v]= true;
arr[index] = v;
index++;

 while (!q.empty())
 {
  int u = q.front();
  q.pop();  
  

 for(int n :adjacencyList[u]){
    if(!vis_arr[n]){
     vis_arr[n] = true;
     arr[index] = n;
     index++;
     q.push(n);
    }}
}
}

void DFS(int arr[] , int &index , bool vis_arr[] , int val){


vis_arr[val]= true;
arr[index] = val;
index++;


for(int u: adjacencyList[val]){
    if(!vis_arr[u]){
     DFS(arr, index , vis_arr , u);
    }
}
}


// Disconnected DFS

void Disconnected_DFS(int arr[], int &index , bool vis_arr[]){

    for(int i = 0;i<adjacencyList.size();i++){
    if(!vis_arr[i]){
     DFS(arr,index,vis_arr,i);
    }
}

    
}

// Disconnected BFS
void Disconnected_BFS(int arr[], int &index , bool vis_arr[]){
      for(int i=0;i<adjacencyList.size();i++){
    if(!vis_arr[i]){
     BFS(arr,index,vis_arr,i);
    }
}
}



};





















































class directional_Graph{
    vector<Node> vertices;
    vector<vector<int>> adjacencyList;
  public:

};


class Weighted_Graph{

};
