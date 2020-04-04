
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if(head == NULL)
        {
            std::cout<<"Should not come here"<<std::endl;
            return head;
        }
        if(head->next == NULL)
        {
            std::cout<<"Should not come here"<<std::endl;
            return head;
        }

        ListNode* l1;
        ListNode* l2;
        ListNode* l3;
        l1 = head;
        l2 = head->next;
        l3 = l2->next;
        /*First sort L1 and L2*/
        if(l1->val > l2->val)
        {
            ListNode* temp = l1;
            l1 = l2;
            l2 = temp;
            l1->next = l2;
            
        }
        l2->next = NULL;
        ListNode* curr;
        ListNode* prev = NULL;
        curr = l1;
        while(l3 != NULL)
        {
            curr = l1;
            prev = NULL;
           /*First check if l3 can be placed first*/
            if(l3->val <= curr->val)
            {
                ListNode* nextL3 = l3->next;
                l3->next = l1;
                l1 = l3;
                l3 = nextL3;
                curr = l1;
            }
           /*Second check l3 can be placed at the end*/
            else if(l2->val <= l3->val)
            {
                l2->next = l3;
                l2 = l3;
                l3 = l3->next;
                l2->next = NULL;
            }
           /*Insert l3 in between l1 and l2*/ 
           else
           {
               while(curr->val < l3->val)
               {
                   prev = curr;
                   curr = curr->next;
               }
               ListNode* nextL3 = l3->next;
               prev->next = l3;
               l3->next = curr;
               l3 = nextL3;
           }
           
        }

        return l1;
    }
};

