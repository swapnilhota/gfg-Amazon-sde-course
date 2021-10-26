/*
Given a linked list of N nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at position X. If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present.  
*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node* curr = head;
        
        if(head==NULL)
        {
            return;
        }
        
        while(curr)
        {
            if(curr->next==NULL)
            {
                return;
            }
            if(curr->next->data < 0)
            {
                curr->next=NULL;
                return;
            }
            curr->data *= -1;
            curr=curr->next;
        }
    }
};
