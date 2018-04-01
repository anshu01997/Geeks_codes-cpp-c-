/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    int size = 0;
    struct Node *temp;
    temp = head;
    while(temp!=NULL)
    {
        size++;
        temp = temp->next;
    }
    int first = 1;
    int last = size;
    int fdata;
    int ldata;
    while(first<last)
    {
        temp = head;
        int it = first;
        while(it--)
        {
            fdata = temp->data;
            temp = temp->next;
        }
        temp = head;
        it = last;
        while(it--)
        {
            ldata = temp->data;
            temp = temp->next;
        }
        if(fdata==ldata)
        {
            first++;
            last--;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
