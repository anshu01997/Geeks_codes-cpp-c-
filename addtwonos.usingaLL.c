#include<stdio.h>
#include<stdlib.h>

/* Linked list node */
struct Node
{
    int data;
    struct Node* next;
};

struct Node *newNode(int data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
  //struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));

    /* allocate node */
    struct Node* new_node = newNode(new_data);
  //  new_node->data=new_data;
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Adds contents of two linked lists and return the head node of resultant list */
struct Node* addTwoLists (struct Node* first, struct Node* second)
{
    struct Node* res = NULL; // res is head node of the resultant list
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) //while both lists exist
    {
        sum = carry + (first? first->data: 0) + (second? second->data: 0);

        // update carry for next calulation
        carry = (sum >= 10)? 1 : 0;

        // update sum if it is greater than 10
        sum = sum % 10;

        // Create a new node with sum as data
        temp = newNode(sum);
/*temp->next= NULL;
temp->data=sum;*/
        // if this is the first node then set it as head of the resultant list
        if(res == NULL)
            res = temp;
        else // If this is not the first node then connect it to the rest.
        //see this as if in the given example:7+8 isn't the only sum,then move to the prev no. of 7,i.e.,5 and add 4 to 5 (store the sum in next ptr to 5).
            prev->next = temp;

        // Set prev for next insertion
        prev  = temp;

        // Move first and second pointers to next nodes
        if (first) first = first->next;
        if (second) second = second->next;
    }

    if (carry > 0)

      temp->next = newNode(carry);
    /*temp1->next=NULL;
     temp1->data=carry;*/

    // return head of the resultant list
    return res;
}

// A utility function to print a linked list
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Driver program to test above function */
int main(void)
{
    struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;

    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);

    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    printList(second);

    // Add the two lists and see result
    res = addTwoLists(first, second);
    printf("Resultant list is ");
    printList(res);

   return 0;
}


struct Node *addtwolists(struct Node *first,struct Node *second)
{
  struct Node *temp,*prev = NULL;
  struct Node *res = NULL;
  int carry = 0,sum;

  while(first != NULL && second != NULL)
  {
    sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
    carry = (sum >= 10 ? 1 :0);
    sum = sum % 10;
    temp =  newNode(sum);
    if(res == NULL)
      res = temp;
      else
        prev->next = temp;
        prev =  temp;

        if(first)
        first=first->next;
        if(second)
        second=second->next;
      }
        if(carry > 0)

          temp->next = newNode(carry);
        return res;
 
}
/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list
Node* create(int c)
{
    Node *temp1=(Node*)malloc(sizeof(Node));
    temp1->data=c;
    temp1->next=NULL;
    return temp1;
}
Node*  addTwoLists(Node* first, Node* second)
{
    Node *temp,*res=NULL;
    int sum,carry=0;
    
    while(first!=NULL && second!=NULL)
    {
        sum=(first->data)+(second->data)+carry;
        carry=sum/10;
        sum=sum%10;
        
        if(res==NULL)
        {
        res=create(sum);
        temp=res;
        }
        else
        {
        res->next=create(sum);
        res=res->next;
        }
        first=first->next;
        second=second->next;
    }
    
    if(first!=NULL)
    {
        while(first!=NULL)
        {
            sum=first->data+carry;
            carry=sum/10;
            sum=sum%10;
            res->next=create(sum);
            res=res->next;
            first=first->next;
        }
    }
    else if(second!=NULL)
    {
        while(second!=NULL)
        {
            sum=second->data+carry;
            carry=sum/10;
            sum=sum%10;
            res->next=create(sum);
            res=res->next;
            second=second->next;
        }
    }
    if(carry!=0)
    {
        res->next=create(carry);
    }
    return temp;
}