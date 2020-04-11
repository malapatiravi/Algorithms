/*
*Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
* To represent a cycle in the given linked list, we use an integer pos which represents the 
* position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
* Note: Do not modify the linked list.
*/
/**
 * Example 1:
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the second node
 * 
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the first node
 * /
 * 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == NULL)
          return NULL;
        slow = head->next;
        if(slow != NULL && slow->next != NULL)
            fast = head->next->next;
        else
            return NULL;
        
        while(slow != fast && slow != NULL && fast != NULL)
        {
            slow = slow->next;
            if(fast->next)
                fast = fast->next->next;
            else
                return NULL;
        }
        if(slow == fast)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
        else
        {
             return NULL;
        }
           
    }
};