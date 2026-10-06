#include <vector>

// Diameter

// Binary Trees
int Dm_trees(Node * root , int &res){

    if(root == NULL)
      return 0;

    int l = Dm_trees(root->left , res);
    int r = Dm_trees(root->right, res);
    
    int temp = 1+ max(l,r);
    int ans = max(temp , 1+l+r);
    res = max(res, ans);
    
    return temp;
}



// Maximum sum from any node to node
int Max_sum(Node * root , int & res){

    if(root == NULL)
      return 0;

    int l = Max_sum(root->left , res);
    int r = Max_sum(root->right, res);

    int temp = max(root->data + max(l,r) , root->data);
    int ans = max(temp , root->data+l+r);
    res = max(res, ans);
    
    return temp;

}

// Maximum Sum from leaf to leaf
int Max_sum_leaf(Node * root , int & res){

    if(root == NULL)
      return 0;
    
    if(root ->left == NULL && root->right == NULL){
        return root->data;
    }

    int l = Max_sum_leaf(root->left , res);
    int r = Max_sum_leaf(root->right, res);
     
    if(root->left !=NULL && root->right != NULL){
     int ans = root->data+l+r;
     res = max(res, ans);
    }
    
    
    return root->data + max(l,r);

}

