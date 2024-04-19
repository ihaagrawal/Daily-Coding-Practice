// 24. Swap Nodes in Pairs (MEDIUM)
// https://leetcode.com/problems/swap-nodes-in-pairs/description/

//Brute (Space: O(n), Time: O(n))
//n->number of nodes
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* itr1=head;
        ListNode* itr2=head->next;
        while(itr1 && itr2){
            ListNode* newnode1=new ListNode(itr2->val);
            temp->next=newnode1;
            temp=temp->next;
            ListNode* newnode2=new ListNode(itr1->val);
            temp->next=newnode2;
            temp=temp->next;
            itr1=itr2->next;
            if(itr1) itr2=itr1->next;
        }
        if (itr1) {
            temp->next = new ListNode(itr1->val);
            temp = temp->next;
        }
        return dummy->next;
    }
};

//Approach-2 (Space: O(n)->Recursive Stack, Time: O(n))
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* temp=head->next;
        head->next=swapPairs(head->next->next);
        temp->next=head;
        return temp;
    }
};
