#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
//  Definition for singly-linked list.
using namespace std;
 struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        vector<int> v1;
        while(list1!=NULL)
        {
            ListNode* t;
            v1.push_back(list1->val);
            t=list1;
            list1=list1->next;
            delete t;
        }
        while(list2!=NULL)
        {
            ListNode* t;
            v1.push_back(list2->val);
            t=list2;
            list2=list2->next;
            delete t;
        }
        sort(v1.begin(),v1.end());
    }
};
