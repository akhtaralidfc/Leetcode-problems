/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *beforegrp=dummy,*aftergrp=head;
        while(1){
            ListNode *cursor=aftergrp;
            for(int i=0;i<k;i++){
                if(cursor==NULL) return dummy->next;
                cursor=cursor->next;
            }
            ListNode *cur=aftergrp,*prev=beforegrp,*Next=NULL;
            // cur=aftergrp;
            // prev=beforegrp;
            for(int i=0;i<k;i++){
                Next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=Next;
            }
            aftergrp->next=cur;
            beforegrp->next=prev;
            beforegrp=aftergrp;
            aftergrp=cur;
        }
    }
};