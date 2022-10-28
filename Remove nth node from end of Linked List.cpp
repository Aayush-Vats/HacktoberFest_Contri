#include<bits/stdc++.h>
//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int count = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while(count<n)
        {
            fast = fast->next;
            count++;
        }
        if(fast==NULL) //the first node is to be deleted
        {
            return head->next;
        }
        while(fast->next!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};