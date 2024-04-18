// 2. Add Two Numbers (MEDIUM)
// https://leetcode.com/problems/add-two-numbers/description/

//n->length of longer linked list
//Brute (Space: O(n), Time: O(n))
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        dummy->next=nullptr;
        ListNode* temp=dummy;
        int carry=0, sum;

        while(l1 || l2 || carry){
            sum = carry;
            if (l1) sum = l1->val + sum;
            if (l2) sum = l2->val + sum;
            ListNode* newnode = new ListNode(sum%10);
            carry=sum/10;
            temp->next=newnode;
            temp=temp->next;

            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }

        return dummy->next;
    }
};

//n->length of longer linked list
//Better (Space: O(1), Time: O(n))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* prev = nullptr;
        int carry = 0, sum;

        while (l1 || l2 || carry) {
            sum = carry;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;

            if (l1) {
                l1->val = sum % 10;
                prev = l1;
                l1 = l1->next;
            } else {
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
            }

            carry = sum / 10;

            if (l2) l2 = l2->next;
        }

        return list1;
    }
};


