/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(!head)
        {
            return NULL;
        }
        
        node* current = head;
        node* prev = NULL;
        node* next = NULL;
        int cnt=0;
        
        while(current!=NULL && cnt<k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            cnt++;
        }
        
        if(next!=NULL)
        {
            head->next = reverse(next, k);
        }
        
        return prev;
    }
};
