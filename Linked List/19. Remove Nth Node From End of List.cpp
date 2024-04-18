// 19. Remove Nth Node From End of List (MEDIUM)
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

//count->length of linked list
//Brute (Space: O(1), Time: O(2*count))
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* temp=head;
        int count=0;

        while(temp){
            count++;
            temp=temp->next;
        }
        temp=head;
        if(n==count) return head->next;
        n=n%count;
        int num=count-n-1;
        while(num){
            temp=temp->next;
            num--;
        }
        if(temp->next)
            temp->next=temp->next->next;
        else temp->next=nullptr;
        return head;
    }
};

//Better (Space: O(1), Time: O(count))
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(n){
            fast=fast->next;
            n--;
        }

        if(!fast) return head->next;

        while(fast && fast->next){
            fast=fast->next;
            slow=slow->next;
        }

        if(slow->next)
            slow->next=slow->next->next;
        else slow->next=nullptr;
        return head;
    }
};
