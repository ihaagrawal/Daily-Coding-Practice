// 45. Jump Game II (MEDIUM)
// https://leetcode.com/problems/jump-game-ii/description/

//we basically use a form of BFS traversal
//we start at index 0 and assign left=right=0
//we assign left = right + 1
//we take the max index we can jump to using the elements of our window
//then we assign the said max index to right
//each window is an addition to count i.e. number of jumps
//we do this till right index is less than the last element

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int left = 0, right = 0;

        while(right < n-1){

            //take a variable to check the farthest jump
            int far = 0;

            //run a loop to find the farthest index we can jump to
            for(int i=left;i<=right;i++){
                far = max(far, nums[i]+i);
            }

            //asign values to left, right and count
            left = right + 1;
            right = far;
            count++;
        }
        return count;
    }
};
