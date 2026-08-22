#include <iostream>
using namespace std;

class Node{
    int val;
    public:
    Node *left ; 
    Node *right;
    
    Node(){
        left = NULL;
        right = NULL;
    }

    int get_val(){
        return val;
    }
    void set_val(int v){
        val=v;
    }

};

struct SearchResult {
    bool found;
    int floor;
    int ceiling;
    int predecessor;
    int successor;
};

// Exact Recursive Search
bool Search(Node * root,int val){
if(root == NULL) return false;

if(root->get_val() == val) return true;    


if(val > root->get_val()){
   return Search(root->right, val);
}else{
    return Search(root->left , val);
}
}


bool Iter_Search(Node * root,int val){

while (root !=NULL)
{
if(root->get_val() == val) return true;

 if(val > root->get_val()){
    root = root->right;
 }else{
  root = root->left;  
 }
    
}

return false;
}


// Extreme Search
// First Technique
int Find_Min(Node *root){
if(root == NULL) return -1;

int n = Find_Min(root->left);
if(n ==-1) return root->get_val();

return n;
}

// Second Technique
int Find_min(Node* root) {
    if (root == NULL)
        return -1;

    if (root->left == NULL)
        return root->get_val();

    return Find_min(root->left);
}


int Find_Max(Node *root){
if(root == NULL) return -1;

int n = Find_Max(root->right);
if(n==-1) return root->get_val();

return n;
}

int Find_max(Node * root){
    if(root == NULL) return -1;

    if(root->left == NULL) return root->get_val();
    
    return Find_max(root->right);
}



int floor_Search(Node * root , int target , int ans ){

if(root == NULL) return ans;
int n;



if(root->get_val() <= target){
ans = root->get_val();
n = floor_Search(root->right , target , ans);
}else{
n = floor_Search(root->left , target , ans);
}

return n;

}

int Ceil_Search(Node * root , int target , int ans){
int n;
if(root == NULL) return ans;

if(root->get_val() >= target){
    ans = root->get_val();
 n = Ceil_Search(root->left , target , ans);   
}else{
n = Ceil_Search(root->right,target,ans);
}
return n;
}


// Predeccessor 

int Predeccessor(Node *root , int target , int ans){
int n;
if(root==NULL) return ans;

if(root->get_val() < target){
    ans = root->get_val();
   n= Predeccessor(root->right , target , ans);
}else{
   n= Predeccessor(root->left , target , ans);
}
return n;

} 
// Successor

int Successor(Node * root , int target , int ans){
int n;
if(root == NULL) return ans;

if(root->get_val() > target){
    ans = root->get_val();
 n = Successor(root->left , target , ans);   
}else{
n = Successor(root->right,target,ans);
}
return n;

}

pair<int,int> Both_Pre_and_Succ(Node * root, int target, pair<int,int> ans){
pair<int,int> n;
if(root == NULL) return ans;

if(root->get_val()== target){
int a = Find_Max(root->left);
int b= Find_Min(root->right);

n.first = a;
n.second = b;
} 

if(root->get_val() < target){ 
ans.first = root->get_val();
n = Both_Pre_and_Succ(root->right,target,ans);
}

if(root->get_val() > target){
ans.second = root->get_val();
n = Both_Pre_and_Succ(root->left,target,ans);   
}

return n;
}


SearchResult Both(Node * root , int target , int pre , int suc){
SearchResult R1;
if(root == NULL){
R1.found = false;
R1.predecessor = pre;
R1.successor = suc;
R1.floor = pre;
R1.ceiling = suc;
    return R1;
} 

if(root->get_val()== target){
int a = Find_Max(root->left);
int b= Find_Min(root->right);

R1.predecessor = a;
R1.successor = b;
R1.found = true;
R1.floor = target;
R1.ceiling = target;
return R1;
} 

if(root->get_val() < target){ 
R1.predecessor = root->get_val();
R1 = Both(root->right,target,R1.predecessor, suc);
}

if(root->get_val() > target){
R1.successor = root->get_val();
R1 = Both(root->left,target,pre, R1.successor);   
}

return R1;
}


 void range(Node * root , int First , int last , int arr[] ,int &ind){
  if(root == NULL) return ;

if(root->get_val() < First){
 range(root->right , First , last , arr, ind);
}else if(root->get_val() > last){
 range(root->left , First, last, arr , ind);
}else{

    range(root->left,First,last,arr,ind);

    arr[ind] = root->get_val(); 
    ind++;

    range(root->right,First,last,arr,ind);

}

}

// Kth smallest  I can do It with three techniques lets see how do I do it;

// first is in Kth smallest I use range and count and stop on kth element
int Kth_1(int sorted_arr[],int len ,int k){

if (k <= 0 || k > len)
        return -1;

return sorted_arr[k-1];
}


int Order=0;
int Kth_Smallest(Node *root,int k){
if(root == NULL) return -1;

int n = Kth_Smallest(root->left,k);

if(n != -1) return n;

Order++;
if(Order == k) return root->get_val();

n = Kth_Smallest(root->right,k);


return n;
}

int Large_order =0;
int Kth_largest(Node * root , int k){
if(root == NULL ) return -1;

int n= Kth_largest(root->right, k);
if(n!=-1) return n;

Large_order++;
if(Large_order == k) return root->get_val();

n = Kth_largest(root->left , k);

return n;
}

int Rank =0;

// Rank Search
int Rank_search(Node *root, int element){
if(root == NULL ) return -1;

int n= Rank_search(root->left, element);
if(n!=-1) return n;

Rank++;
if(root->get_val() == element) return Rank;

n = Rank_search(root->right , element);


return n;
};


int Occurence_Rank= 0;

int First_occurence(Node *root, int element){
if(root == NULL) return -1;

int n= First_occurence(root->left, element);
if(n!=-1) return n;

Occurence_Rank++;
if(root->get_val() == element) return Occurence_Rank;

n = First_occurence(root->right , element);


return n;

}



// Last Occurence 
int Last_occurence(Node *root, int element , int &Last_rank,int & store){


if(root == NULL) return -1;

int n= Last_occurence(root->left, element,Last_rank,store);

Last_rank++;
if(root->get_val() == element){
store = Last_rank;
} 

n = Last_occurence(root->right , element,Last_rank,store);

if(n==-1) return store;
else return n;

}

// Last Occurence 
int Freq_occurence(Node *root, int element , int &Last_rank,int & freq){


if(root == NULL) return -1;

int n= Freq_occurence(root->left, element,Last_rank,freq);

Last_rank++;
if(root->get_val() == element){
freq++;
} 

n = Freq_occurence(root->right , element,Last_rank,freq);

if(n==-1) return freq;
else return n;

}

// similar to Kth smallest 
int Duplicate_Kth_Smallest(Node *root,int k, int &count){
if(root == NULL) return -1;

int n = Duplicate_Kth_Smallest(root->left,k,count);

if(n != -1) return n;

count++;
if(count == k) return root->get_val();

n = Duplicate_Kth_Smallest(root->right,k,count);


return n;
}

// Lowest Common Ancestor
int LCA(Node *root , Node * p , Node * q){
if(root == NULL) return -1;

 if(root->get_val() > p->get_val() && root->get_val() > q->get_val()){
    return LCA(root->left,p,q);
 }else if(root->get_val() < p->get_val() && root->get_val() < q->get_val()){
    return LCA(root->right,p,q);
 }else{
    return root->get_val();
 }
}

void Ancestors(Node *root , Node * p , Node * q, int arr[], int &ind){
if(root == NULL) return ;

 if(root->get_val() > p->get_val() && root->get_val() > q->get_val()){
    arr[ind]= root->get_val();
    ind++;
    Ancestors(root->left,p,q,arr,ind);
 }else if(root->get_val() < p->get_val() && root->get_val() < q->get_val()){
    arr[ind]= root->get_val();
    ind++;
Ancestors(root->right,p,q,arr,ind);
 }else{
    arr[ind] = root->get_val();
        ind++;
 }
}

void Search_Path(Node * root, int arr[], int &ind, int target){
if(root == NULL) return;

arr[ind] = root->get_val();
ind++;

if(root->get_val() < target){
 Search_Path(root->right,arr,ind,target);
}


if(root->get_val() > target){
Search_Path(root->left,arr,ind,target);
}

};



int main(){

}