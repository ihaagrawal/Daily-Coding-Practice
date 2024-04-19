// 23. Merge k Sorted Lists (HARD)
// https://leetcode.com/problems/merge-k-sorted-lists/description/

//Brute (Space: O(total number of nodes), Time: O(k*n) + O(mlogm) + o(m))
//k->number of rows, m->n*k
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=nullptr){
                arr.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(arr.begin(), arr.end());
        ListNode* dummy=new ListNode(-1);
        ListNode* itr=dummy;
        for(int i=0;i<arr.size();i++){
            ListNode* newnode = new ListNode(arr[i]);
            itr->next=newnode;
            itr=itr->next;
        }
        return dummy->next;
    }
};
