// 860. Lemonade Change (EASY)
// https://leetcode.com/problems/lemonade-change/description/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fives = 0, tens=0, twenties=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                fives+=1;
                continue;
            }

            if(bills[i]==10){
                if(fives==0) return false;
                tens += 1;
                fives -= 1;
                continue;
            }

            if(bills[i]==20){
                if(fives && tens){
                    fives -= 1;
                    tens -= 1;
                    twenties += 1;
                }else if(fives>=3){
                    fives -= 3;
                    twenties += 1;
                }else return false;
            }
        }
        return true;
    }
};
