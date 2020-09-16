
#include <bits/stdc++.h>
using namespace std;

class Node
{
   public:
   int data;
   Node* next;
};

Node *reverse (Node *head, int k)
{
   Node* current = head;
   Node* next = NULL;
   Node* prev = NULL;
   int count = 0;

   while (current != NULL && count < k)
   {
       next = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
   }

   if (next != NULL)
   head->next = reverse(next, k);


   return prev;
}

void push(Node** head_ref, int new_data)
{

   Node* new_node = new Node();
   new_node->data = new_data;
   new_node->next = (*head_ref);
   (*head_ref) = new_node;
}


void printList(Node *node)
{
   while (node != NULL)
   {
       cout<<node->data<<" ";
       node = node->next;
   }
}

int main()
{
   Node* head = NULL;
   int n, num, i, k;

   cout<<"enter number of elements";
   cin>>n;

   for(i=0; i<n;i++)
   {
       cin>>num;
       push(&head, num);
   }

   cout<<"enter k";
   cin>>k;
   head = reverse(head, 3);

   cout<<"\nReversed Linked list \n";
   printList(head);

   return(0);
} 
