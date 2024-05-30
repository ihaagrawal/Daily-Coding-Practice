// 135. Candy (HARD)
// https://leetcode.com/problems/candy/description/


//Time: O(3n)
//Space: O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        //if only one child id present, then min req candies is 1
        if(n==1) return 1;

        //assign each child with 1 candy
        vector<int> candies(n+1, 1);

        //traverse from left to right and adjust candies[i]
        //according to the rating of previous child compared to current
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }

        //traverse from right to left and adjust the candies[i]
        //according to the rating of (i+1)th index child compared to current
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }

        //add all the candies
        int total = 0;
        for(int i=0;i<n;i++) total += candies[i];
        return total;
    }
};

//initially, we assign all children with 1 candy as that is the minimum required
//next we traverse from left to right, if i-1 has less rating than i
//then we increase number of candies[i] by candies[i-1]+1
//then we traverse from right to left, if i+1 has less rating than i
//then we check the max(candies[i], candies[i+1]+1) and assign to candies[i]
//then simply add all the candies
