#include<iostream>
#include<stdio.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* doubleIt(ListNode* head) 
    {
        ListNode* t;
        head->val++;
        if(head->next!=NULL)
            return head;
        t=doubleIt(head->next);
        t->val=t->val*2;
        if(t->val>=10 && t->val<20)
            t->val-=11;
        else if(t->val>=20)
            t->val-=12;
        else
            t->val--;
        return head;
    }
};