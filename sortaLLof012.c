#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node *next;
};
void sortlist(struct Node *head)
{
  struct Node *temp= head;
  int c0=0,c1=0,c2=0;
  while(temp != NULL)
  {
    if(temp->data == 0)
      {
        c0++;
      }
      else if(temp->data == 1)
           {
               c1++;
           }
           else
           {
               c2+=1;
           }
        temp=temp->next;
      }
 temp = head;
  while(c0)
 {
  temp->data = 0;
    c0--;
    temp=temp->next;
 }
 while(c1)
 {
  temp->data = 1;
  c1--;
  temp=temp->next;
 }
 while(c2)
 {
  temp->data = 2;
  c2--;
  temp=temp->next;
 }
}
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("n");
}
int main()
{
  struct Node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);

    printf("Linked List Before Sorting\n");
    printList(head);
    sortList(&head);
    printf("Linked List After Sortingn\n");
    printList(head);
    return 0;
}
