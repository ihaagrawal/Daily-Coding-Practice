// 11. Container With Most Water (MEDIUM)
// https://leetcode.com/problems/container-with-most-water/description/

//Brute (Space: O(1), Time: O(n^2))
//TIME LIMIT EXCEEDED
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int area=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int new_area=min(height[i], height[j])*(j-i);
                area=max(new_area, area);
            }
        }
        return area;
    }
};


//Better (Space: O(1), Time: O(n))
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0, j=n-1, area=INT_MIN;
        while(i<j){
            int new_area=min(height[i], height[j])*(j-i);
            area=max(area, new_area);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return area;
    }
};
