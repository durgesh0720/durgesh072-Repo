#include<iostream>
#include<stdio.h>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* t1=NULL,*t2=head,*t3;
        if(head==NULL)
            return head;
        t3=head->next;
        while(t3)
        {
            t2->next=t1;
            t1=t2;
            t2=t3;
            t3=t3->next;
        }
        t2->next=t1;
        head=t2;
        return head;
    }
};