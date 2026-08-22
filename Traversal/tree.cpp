#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;





class Node{
    public:
   Node *right;
   Node * left;
   int value;  

    Node(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

class Tree{
    public:
    Node* arr[100];
   Node* stack[100];
   int stack_ind= 0;

   void push(Node * value){
    stack[stack_ind] = value;
    stack_ind++;
   }

   Node * top(){
    return stack[stack_ind];
   }
    
   bool is_empty(){
    return stack_ind ==0;
   };
   void pop(){
    if(is_empty())
      stack_ind--;
   }


    int front = 0;
    int rear = 0;
    
      Tree() {
      
    }

    bool is_empty(){
        return front>=rear;
    }
    void enqueue(Node * r){
        if(is_empty()){
           front = 0;
           rear = 0;
        }
    arr[rear] = r;
    rear++;
    }
    
    void dequeue(){
    if(is_empty()){
           front = 0;
           rear = 0;
    }else{
     front++;      
    }

    }

    Node * Front(){
        return arr[front];
    }


    void add_node(Node *root , Node * r){

        if(root == NULL){
         root = r;
         return;
        }else{
          enqueue(root);
        }

        if(root->left == NULL){
         root->left = r;
         return;
        }else{
          enqueue(root->left);
        }

        if(root->right == NULL){
         root->right = r;
         return;
        }else{
          enqueue(root->right);
        }
       
        dequeue();
        Node * a = Front();
       
        add_node(a,r);

    } 

// PreorderTraversal
    int preorder_traverse(Node * root , int arr[] ,int index){
       
       if (root == NULL){
        return -1;
       }
       arr[index] = root->value;
       index++;
       int b= preorder_traverse(root->left , arr, index);
       int c = preorder_traverse(root->right ,arr , b);
       return c;
    
      
    };

    // Inorder Traversal
      int inorder_traverse(Node * root , int arr[] ,int index){
       if (root == NULL) return index;
       
       
       int a = inorder_traverse(root->left, arr , index);
       arr[a] = root->value;
       a++;
       int c = inorder_traverse(root->right ,arr , a);
       return c;
    
      
    };
    

    // Post Order Traversal
       int post_order_traverse(Node * root , int arr[] ,int index){
       if (root == NULL) return index;
       
       
       int a = post_order_traverse(root->left, arr , index);
       
       int c = post_order_traverse(root->right ,arr , a);
       arr[c] = root->value;
       c++;
       return c;
    
      
    };

    // Level Order Traversal 

  void  Level_order(Node * root,int arr[] , int &index){

    if(root == NULL){
        return;
        }else{
          arr[index] = root->value;
          index++;
        }

        if(root->left != NULL){
          enqueue(root->left);
        }

       if(root->right != NULL){  
        enqueue(root->right);
        } 
        
       
       
        Node * a = Front();
        dequeue();
       Level_order(a,arr,index);
        
  }
    


// Reverse Order Traversal Right to Left

  void  rtl_Level_order(Node * root,int arr[] , int &index){

    if(root == NULL){
        return;
        }else{
          arr[index] = root->value;
          index++;

        }


        if(root->right != NULL){  
        enqueue(root->right);
        } 


        if(root->left != NULL){
          enqueue(root->left);
        }

       
        Node * a = Front();
        dequeue();
        rtl_Level_order(a,arr,index);
        
  }
    
// Reverse Order traverse right to left just reverse the upcoming array 


  void  rev_Level_order(Node * root,int arr[] , int &index){

    if(root == NULL){
        return;
        }else{
          arr[index] = root->value;
          index++;

        }


        if(root->right != NULL){  
        enqueue(root->right);
        } 


        if(root->left != NULL){
          enqueue(root->left);
        }

       
        Node * a = Front();
        dequeue();
        rev_Level_order(a,arr,index);
        
  }



  // Zig Zag order Traversal

void zig_zag(int arr[], int &index, bool left_to_right)
{
    if (rear == front)
        return;



    int level_size =  rear - front;

    int temp[100];
    int temp_index = 0;

    for (int i = 0; i < level_size; i++)
    {
        Node *current = Front();
        dequeue();

        temp[temp_index] = current->value;
        temp_index++;

        if (current->left != NULL)
            enqueue(current->left);

        if (current->right != NULL)
            enqueue(current->right);
    }

    if (left_to_right)
    {
        for (int i = 0; i < temp_index; i++)
        {
            arr[index] = temp[i];
            index++;
        }
    }
    else
    {
        for (int i = temp_index - 1; i >= 0; i--)
        {
            arr[index] = temp[i];
            index++;
        }
    }

    zig_zag(arr, index, !left_to_right);
}


// Iterative DFS

void it_DFS(Node *root , int arr[] , int index){

  if (root == NULL)
    return;


 push(root);

 while (!is_empty())
 {
 
Node* current = top();
pop();


if(current->right != NULL){
 push(current->right);
}

if(current->left !=NULL){
push(current->left);
}
 
 }

}



void left_traversal(Node * root , int arr[] , int &index){
  if (root == NULL)
    return;

  if(root->left == NULL && root->right == NULL)
    return;

  arr[index] = root->value;
  index++;

  if (root->left != NULL)
  left_traversal(root->left,arr,index);
  else if (root->right != NULL)
  left_traversal(root->right,arr,index);

}

void leaf_nodes_traversal(Node *root , int arr[] , int & index){
  if (root == NULL)
  return ;

  if(root->left ==NULL && root->right == NULL){
    arr[index] = root->value;
    index++;
    return;
  }

  if(root->left != NULL)
  leaf_nodes_traversal(root->left,arr,index);
  if(root->right != NULL)
  leaf_nodes_traversal(root->right,arr,index);


}


void right_nodes_traversal(Node * root , int arr[], int & index){
  if(root == NULL)
   return;
  
   if(root->left == NULL && root->right == NULL)
    return;



   if (root->right != NULL)
  right_nodes_traversal(root->right,arr,index);
  else if (root->left != NULL)
  right_nodes_traversal(root->left,arr,index);

  arr[index] = root->value;
  index++;

}

void Boundary_traversal(Node *root, int arr[], int &index)
{
    if (root == NULL)
        return;

    // Print root
    arr[index++] = root->value;

    // Left boundary (excluding root)
    left_traversal(root->left, arr, index);

    // All leaf nodes
    leaf_nodes_traversal(root->left, arr, index);
    leaf_nodes_traversal(root->right, arr, index);

    // Right boundary (excluding root)
    right_nodes_traversal(root->right, arr, index);
}



// Vertical Order Traversal
void Vertical_order(Node * root ,int column,map<int , vector<int>> &vertical_levels){
if (root == NULL)
  return;

vertical_levels[column].push_back(root->value);

if(root->left != NULL){
 Vertical_order(root->left,column-1,vertical_levels);
}
if(root->right != NULL){
 Vertical_order(root->right,column+1,vertical_levels);
}
}

// Vertical order traversal is completed, now we can fill the array with the values from the map
void Boundary_or_Vertical_Result(int arr[],int& index,map<int, vector<int>>& vertical_levels){
    for (auto& level : vertical_levels) {
        for (int value : level.second) {
            arr[index++] = value;
        }
    }
}


// Left view 
  void  Left_view(Node * root,int arr[] , int &index , int level = 0, int &max_level ){

    if(root == NULL){
        return;
        }else{
          if(level == 0){
            arr[index] = root->value;
            index++;
          }
          
          if(level > max_level){
            arr[index] = root->value;
            index++;
            max_level = level;
          }
          
        }
         
       
       
        
      Left_view(root->left,arr,index , level+1, max_level);
      Left_view(root->right,arr,index , level+1, max_level);
  
  }
    



  

// right view 
  void  Right_view(Node * root,int arr[] , int &index , int level = 0, int &max_level ){

    if(root == NULL){
        return;
        }else{
          if(level == 0){
            arr[index] = root->value;
            index++;
          }
          
          if(level > max_level){
            arr[index] = root->value;
            index++;
            max_level = level;
          }
          
        }
         
       
       
        
      Right_view(root->right,arr,index , level+1, max_level);
      Right_view(root->left,arr,index , level+1, max_level);
  
  }

  // top view (DFS)
  void Top_view(Node * root ,int column,map<int , int> &vertical_levels){
if (root == NULL)
  return;

if(vertical_levels.find(column) == vertical_levels.end()){
vertical_levels[column] = root->value;
}

if(root->left != NULL){
 Top_view(root->left,column-1,vertical_levels);
}
if(root->right != NULL){
 Top_view(root->right,column+1,vertical_levels);
}
}


  // bottom view
  void bottom_view(Node * root ,int column,map<int , int> &vertical_levels){
if (root == NULL)
  return;

vertical_levels[column] = root->value;

if(root->left != NULL){
 bottom_view(root->left,column-1,vertical_levels);
}
if(root->right != NULL){
 bottom_view(root->right,column+1,vertical_levels);
}
}


  void  Level_order(Node * root,int arr[] , int &index){

    if(root == NULL){
        return;
        }else{
          arr[index] = root->value;
          index++;
        }

        

        
       
       
        Node * a = Front();
        dequeue();
       Level_order(a,arr,index);
        
  }


  // Top view (BFS)
    void Top_view(Node * root ){
    if(root == NULL)
        return;

    queue<pair<Node*, int>> q;

    map<int,int> top;

    q.push({root,0});

    while(!q.empty())
    {
        Node* a = q.front().first;
        int column = q.front().second;

        q.pop();


        // first node at this column
        if(top.find(column) == top.end())
        {
            top[column] = a->value;
        }


        if(a->left != NULL)
        {
            q.push({a->left,column-1});
        }

        if(a->right != NULL)
        {
            q.push({a->right,column+1});
        }
    }

}

// Diagonal Traversal
void Diagonal_traversal(Node * root , int left, int right , int ** arr){
if(root == NULL)
  return;

arr[left][right] = root->value;

if(root->left != NULL){
 Diagonal_traversal(root->left,left+1,right,arr);
}
if(root->right != NULL){
 Diagonal_traversal(root->right,left,right+1,arr);
}
}

void Diagonal_traversal_result(int ** arr , int rows , int cols , int * result , int &index){
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if(arr[i][j] != -1){
        result[index] = arr[i][j];
        index++;
      }
    }
  }
}







// Morris Inorder Traversal
void morris_inorder(Node * root , int arr[] , int &index){
  if (root == NULL)
    return;


Node * nex_curr = root;
  while (nex_curr  != NULL)
  {
     Node * curr = nex_curr->left;
      if (nex_curr->left == NULL){
        
    arr[index++] = nex_curr->value;
    nex_curr = nex_curr->right;

      }else{
        // find predecessor
         while (curr->right && curr->right !=nex_curr)
  {     
   curr = curr->right; 
  }

  // create/remove thread
  if(curr->right == nex_curr){
      arr[index] = nex_curr->value;
      index++;
      curr->right = NULL;
      
       nex_curr = nex_curr->right;
  }else{
      curr->right = nex_curr;
      nex_curr = nex_curr->left;
  }


      }

  
  }


  

 }


};





int main(){
    Node * root= NULL;
  Node n1(4);
  Node n2(5);
  Node n3(6);

    Tree t1;
    t1.add_node(root,&n1);
    t1.add_node(root,&n2);
    t1.add_node(root,&n3);


    return 0;
   }
