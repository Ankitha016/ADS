
#include <bits/stdc++.h> 
using namespace std; 
  
class Node  
{  
    public: 
    int data;  
    Node* nextxprev; 
};  
  
Node* XOR (Node *a, Node *b)  
{  
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));  
}  
  
/* Insert a node at the beginning of the  
XORed linked list */
void insert_begin(Node **head, int data)  
{   
    Node *new_node = new Node();  
    new_node->data = data;  

    new_node->nextxprev = *head;  
  
    if (*head != NULL)  
    {   
        (*head)->nextxprev = XOR(new_node, (*head)->nextxprev);  
    }  
  
    *head = new_node;  
} 

/*insert at end of lined list*/
void insert_end(Node **head,int data)
{
    Node *new_node = new Node(); 
    new_node->data=data;
    Node *curr = *head;  
    Node *prev = NULL;  
    Node *next;
     while (curr != NULL)  
    {     
        next = XOR (prev, curr->nextxprev);  
        prev = curr;  
        curr = next;  
    } 
    prev->nextxprev=XOR(new_node,prev->nextxprev);
    new_node->nextxprev=prev;
}
    
    
 
void printList (Node *head)  
{  
    Node *curr = head;  
    Node *prev = NULL;  
    Node *next;  
 
  
    while (curr != NULL)  
    {  
         
        cout<<curr->data<<" ";  
        next = XOR (prev, curr->nextxprev);   
        prev = curr;  
        curr = next;  
    }  
}  
 
int main ()  
{  
    
    Node *head = NULL;  
    insert_begin(&head, 1);   
    insert_begin(&head, 3); 
    cout<<"INITIAL LIST\n";
    printList (head);
    cout<<"\nAfter inserting 4 from begining\n";
    insert_begin(&head, 4);
    printList (head);   
    cout<<"\nAfter inserting 2 from ending\n";
    insert_end(&head, 2);
    printList (head);
    cout<<"\n"; 
    printList (head);
  
    return (0);  
}  
