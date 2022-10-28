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
    struct comp
    {
        bool operator()(ListNode* a,ListNode* b)
        {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& A) 
    {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        priority_queue<ListNode*,vector<ListNode*>,comp>minh;
        for(int i=0;i<A.size();i++)
        {
            if(A[i])
                minh.push(A[i]);
        }
        while(!minh.empty())
        {
            ListNode* curr = minh.top();
            minh.pop();
            temp->next = curr;
            temp = temp->next;
            if(curr->next)
                minh.push(curr->next);
        }
        return head->next;
    }
};