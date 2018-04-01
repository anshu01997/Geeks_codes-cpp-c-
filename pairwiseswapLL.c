#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node *next;
};
void swap(int *a,int *b)
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}
void swap_pairwise(struct Node *head)
{
  struct Node *temp=head;
  while(temp != NULL && temp->next != NULL)
  {
    swap(&temp->data,&temp->next->data);
    temp=temp->next->next;
  }
}
void push(struct Node **head_ref,int new_data)
{
  struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
  new_node->data=new_data;
  new_node->next=*head_ref;
  *head_ref=new_node;
}
void printlist(struct Node *node)
{
  while(node != NULL)
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
  swap_pairwise(head);
  printlist(head);
  return 0;
  }
  /* Recursive function to pairwise swap elements of a linked list */
void pairWiseSwap(struct node *head)
{
  /* There must be at-least two nodes in the list */
  if (head != NULL && head->next != NULL)
  {
      /* Swap the node's data with data of next node */
      swap(&head->data, &head->next->data);
    
      /* Call pairWiseSwap() for rest of the list */
      pairWiseSwap(head->next->next);
  }  
}