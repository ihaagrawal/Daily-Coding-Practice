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

//Space Complexity is better, time complexity is worse
//Better (Space: O(1), Time: O(n^3))
class Solution {
public:

    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(-1);
        dummy->next=nullptr;
        ListNode* temp=dummy;

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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==1) return lists[0];
        while(k > 1){
            lists[0] = merge(lists[0], lists[1]);
            lists.erase(lists.begin() + 1);
            k--;
        }
        return k == 0 ? nullptr : lists[0];
    }
};


//Optimal (Space: O(k) , Time: O(klogk) + O(n*k*logk))
class Solution {
public:

    struct compare{
        bool operator()(const pair<int, ListNode*>& a, const pair<int, ListNode*>& b){
            return a.first>b.first;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, compare> pq;
        int k=lists.size();
        for(int i=0;i<k;i++){
            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(it.second->next) pq.push({it.second->next->val, it.second->next});
            temp->next=it.second;
            temp=temp->next;
        }

        return dummy->next;
    }
};
