// singly linklist different question practice 

// count nodes
int count_nodes(Node * ptr){
    if(ptr == NULL)
      return 0;

    return 1 + count_nodes(ptr->next);
}

// count sum
int count_sum(Node * head){
    if(head == NULL)
     return 0;

    return head->data + count_sum(head->next);
}


// count odd_sum
int odd_sum(Node * head){
    if(!head)
     return 0;
    if(head->next == NULL)
      return head->data;

    return head->data + odd_sum(head->next->next);
}


// count even_sum
int count_sum(Node * head){
    if(head == NULL || head->next == NULL)
     return 0;
    
    int sum = 0;
     Node * temp = head->next;

     while(temp != NULL && temp->next !=NULL){
       sum += temp->data;
      temp = temp->next->next;
     }

     return sum;
}

void swap_node(Node * left, Node * right , Node * prev){
    prev->next = right;
    left->next  = right->next;
    right->next = left;
}

void rotate_link_list(Node *& head){
   if(head == NULL || head->next == NULL)
     return ;
    
    Node * temp , *prev ;
    prev = NULL;
    temp = head;

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
     temp->next = head;
     prev->next = NULL;
     head = temp;

}