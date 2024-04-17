// 206. Reverse Linked List (EASY)
// https://leetcode.com/problems/reverse-linked-list/description/

//Brute (Space: O(n), Time: O(n))
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int>st;
        ListNode* temp=head;
        if (!head || !head->next)
            return head;

        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(!st.empty()){
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
};

//Better (Space: O(1), Time: O(n))
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* nextnode;
        ListNode* current=head;
        ListNode* prev=nullptr;

        while(current){
            nextnode=current->next;
            current->next=prev;
            prev=current;
            current=nextnode;
        }
        head=prev;
        return head;
    }
};

//Better Approach 2 (Space: O(n)->recursive stack, Time: O(n))
class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
    }
};
