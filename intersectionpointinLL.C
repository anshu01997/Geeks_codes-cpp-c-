int intersectPoint(Node* head1, Node* head2)
{
    Node* h1,*h2;
    int l1=0,l2=0,d;
    h1=head1,h2=head2;
    while(h1)
    {
        ++l1;
        h1=h1->next;
    }
    while(h2)
    {
        ++l2;
        h2=h2->next;
    }
    h1=head1,h2=head2;
    if(l1>l2)
    {
        d=l1-l2;
        while(d--)
        h1=h1->next;
    }
    else
    {
        d=l2-l1;
        while(d--)
        h2=h2->next;
    }
    while(h1!= h2 && h1 && h2)
    {
        h1=h1->next;
        h2=h2->next;
    }
    if(h1 == h2)
    return h1->data;
    else
    return -1;
    // Your Code Here
}#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
  int data;
  struct Node* next;
};
/* Function to get the counts of node in a linked list */
int getCount(struct Node* head);

/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has d more nodes than
   head2 */
int _getIntesectionNode(int d, struct Node* head1, struct Node* head2);

/* function to get the intersection point of two linked
   lists head1 and head2 */
int getIntesectionNode(struct Node* head1, struct Node* head2)
{
  int c1 = getCount(head1);
  int c2 = getCount(head2);
  int d;

  if(c1 > c2)
  {
    d = c1 - c2;
    return _getIntesectionNode(d, head1, head2);
  }
  else
  {
    d = c2 - c1;
    return _getIntesectionNode(d, head2, head1);
  }
}

/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has d more nodes than
   head2 */
int _getIntesectionNode(int d, struct Node* head1, struct Node* head2)
{
  int i;
  struct Node* current1 = head1;
  struct Node* current2 = head2;

  for(i = 0; i < d; i++)
  {
    if(current1 == NULL)
    {  return -1; }
    current1 = current1->next;
  }

  while(current1 !=  NULL && current2 != NULL)
  {
    if(current1 == current2)
      return current1->data;
    current1= current1->next;
    current2= current2->next;
  }

  return -1;
}

/* Takes head pointer of the linked list and
   returns the count of nodes in the list */
int getCount(struct Node* head)
{
  struct Node* current = head;
  int count = 0;

  while (current != NULL)
  {
    count++;
    current = current->next;
  }

  return count;
}

/* IGNORE THE BELOW LINES OF CODE. THESE LINES
   ARE JUST TO QUICKLY TEST THE ABOVE FUNCTION */
int main()
{
  /*
    Create two linked lists

    1st 3->6->9->15->30
    2nd 10->15->30

    15 is the intersection point
  */

  struct Node* newNode;
  struct Node* head1 =
            (struct Node*) malloc(sizeof(struct Node));
  head1->data  = 10;

  struct Node* head2 =
            (struct Node*) malloc(sizeof(struct Node));
  head2->data  = 3;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 6;
  head2->next = newNode;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 30;
  head1->next->next= newNode;

  head1->next->next->next = NULL;

  printf("\n The node of intersection is %d \n",
          getIntesectionNode(head1, head2));

  //getchar();
}
