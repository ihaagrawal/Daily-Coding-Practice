// 876. Middle of the Linked List (EASY)
// https://leetcode.com/problems/middle-of-the-linked-list/description/

//Brute (Space: O(1), Time: O(2n))
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        temp=head;
        int num=count/2;
        while(num && temp->next){
            temp=temp->next;
            num--;
        }
        return temp;
    } 
};

//Better (Space: O(1), Time: O(n))
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};
