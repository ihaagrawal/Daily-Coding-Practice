// 21. Merge Two Sorted Lists (EASY)
// https://leetcode.com/problems/merge-two-sorted-lists/description/

//m->length of list1, n->length of list2
//Brute (Space: O(m+n), Time: O(m+n))
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;
        ListNode* newList = new ListNode();
        newList->next=nullptr;
        ListNode *temp=newList;
        while(list1 && list2){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }

        while(list1){
            temp->next=list1;
            list1=list1->next;
            temp=temp->next;
        }

        while(list2){
            temp->next=list2;
            list2=list2->next;
            temp=temp->next;
        }

        return newList->next;
    }
};


//Better (Space: O(1), Time: O(m+n))
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(list1 && list2){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }

        while(list1){
            temp->next=list1;
            list1=list1->next;
            temp=temp->next;
        }

        while(list2){
            temp->next=list2;
            list2=list2->next;
            temp=temp->next;
        }

        return dummy->next;
    }
};
