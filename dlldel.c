#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};
void push(struct Node**head_ref,int new_data)
{
  struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
  new_node->data=new_data;
  new_node->prev=NULL;
  new_node->next=(*head_ref);
  if(*head_ref!=NULL)
   (*head_ref)->prev=new_node;
   (*head_ref)=new_node;
}
void printlist(struct Node *node)
{
  while(node!=NULL)
  {
    printf("%d\n",node->data);
    node=node->next;
  }
}
void deleteNode(struct Node **head_ref,struct Node *del)
{
  //base case:if ll is either empty or the node to be deleted isn't present
  if(*head_ref ==NULL || del == NULL)
  return;
  //if node to be deleted is a head node
  if(*head_ref == del)
   (*head_ref) = del->next;
   //if node to be deleted is not the last node
   if(del->next != NULL)
    del->next->prev = del->prev;
    //if node to be deleted is not the first node
    if(del->prev != NULL)
     del->prev->next = del->next;
  free(del);
  return;
}
int main()
{
  struct Node *head=NULL;
  push(&head,5);
  push(&head,4);
  push(&head,6);
  push(&head,9);
  printf("original linked list is:");
  printlist(head);
  deleteNode(&head,head);
  deleteNode(&head,head->next->next);
  deleteNode(&head,head);
  printf("modified linked list:");
  printlist(head);
  getchar();
  return 0;
}
