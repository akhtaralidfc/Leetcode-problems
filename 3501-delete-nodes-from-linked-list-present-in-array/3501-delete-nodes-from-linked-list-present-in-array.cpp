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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(auto it: nums) st.insert(it);
        ListNode* nhead=NULL;
        ListNode* prev=new ListNode();
        for(ListNode* start=head; start!=NULL; start=start->next){
            if(st.find(start->val)==st.end()){
                if(nhead==NULL){
                    nhead=new ListNode(start->val);
                    prev=nhead;
                }
                else{
                    ListNode* temp=new ListNode(start->val);
                    prev->next=temp;
                    prev=temp;
                }
            }
        }
        return nhead;
    }
};