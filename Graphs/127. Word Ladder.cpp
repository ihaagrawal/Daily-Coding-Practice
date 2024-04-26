// 127. Word Ladder (HARD)
// https://leetcode.com/problems/word-ladder/description/

//O(n^4)
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

//O(n^3)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        
        if(word.find(endWord)==word.end()) return 0;

        q.push({beginWord, 1});
        word.erase(beginWord);

        while(!q.empty()){
            string current=q.front().first;
            int steps=q.front().second;
            q.pop();

            if(current==endWord) return steps;

            for(int i=0;i<current.length();i++){
                int curr=current[i];
                for(char c='a';c<='z';c++){
                    current[i]=c;
                    if(word.find(current)!=word.end()){
                        q.push({current, steps+1});
                        word.erase(current);
                    }
                }
                current[i]=curr;
            }
        }
        return 0;
    }
};
