// 127. Word Ladder (HARD)
// https://leetcode.com/problems/word-ladder/description/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word(wordList.begin(), wordList.end());
        if(word.find(endWord)==word.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int level=1;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string current=q.front();
                q.pop();
                for(int j=0;j<current.length();j++){
                    char curr=current[j];
                    for(char c='a';c<='z';c++){
                        current[j]=c;
                        if(current==endWord) return level+1;
                        if(word.find(current)!=word.end()){
                            q.push(current);
                            word.erase(current);
                        }
                        current[j]=curr;
                    }
                }
            }
            level++;
        }
        return 0;
    }
};
