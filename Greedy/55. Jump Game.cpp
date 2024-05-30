// 55. Jump Game (MEDIUM)
// https://leetcode.com/problems/jump-game/description/

//APPROACH
//We go right to left in the array, we try to find if we can reach the start from the end
//we stand at goal = n-1 index, we check if we can reach n-1 from n-2
//if we can then we shift goal to n-2
//similarily we do this through the whole array
//at the end if we reach 0th index that means we do have a path from start to end
//else we dont

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        //assign the last index to the goal
        int goal = n-1;

        //traverse from right to left
        for(int i=n-2;i>=0;i--){

            //check if we can reach current index from the previous index
            //if the jump length of previous index is enough to reach current index
            //then move the goal to the previous index
            if(nums[i] + i >= goal){
                goal = i;
            }
        }

        //if we reach 0th index return true
        //else return false
        if(goal == 0) return true;
        return false;
    }
};

