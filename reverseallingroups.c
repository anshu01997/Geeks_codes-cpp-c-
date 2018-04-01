#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node *next;
};
struct Node *reverse(struct Node *head,int k)
{
  struct Node *current = head;
  struct Node *prev=NULL;
  struct Node *next=NULL;
  int count=0;
  while(current != NULL && count<k)
  {
     next= current->next;
     current->next= prev;
     prev=current;
     current=next;
     count++;
  }
  if(next != NULL)
     head->next =reverse(next,k);
     return prev;
}
void push(struct Node **head_ref,int new_data/* arguments */) {
  /* code */
  struct Node *new_node =  (struct Node*)malloc(sizeof(struct Node));
  new_node->data=new_data;
  new_node->next=(*head_ref);
  (*head_ref)=new_node;
}
void printlist(struct Node* node)
{
  while(node!=NULL)
  {
    printf("%d",node->data);
    node=node->next;
  }
}
  int main()
  {
    struct Node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
   printf("original ll:");
   printlist(head);
   reverse(head,4);
    printf("after reversing:");
    printlist(head);
    return (0);
  }
