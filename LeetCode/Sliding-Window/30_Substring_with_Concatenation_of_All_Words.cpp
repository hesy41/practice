/*30. Substring with Concatenation of All Words
  You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.
  You can return the answer in any order.*/


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> count;
        vector<int> ans;
        int len = words[0].length();
        int num = words.size();
        for (string word : words)
            count[word]++;
        for(int i=0; i< s.size() - num * len +1; i++)
        {
            unordered_map<string, int> seen;
            int j;
            for (j=0; j < num; j++)
            {
                string cur = s.substr(i + j*len, len);
                if(count.find(cur) != count.end()) // cur word is in words list
                {
                    seen[cur]++;
                    if(seen[cur] > count[cur]) // have more words than the list
                        break;
                }
                else //cur word is in words list
                    break;
            }
            if (j== num)
                ans.push_back(i);
        }
        return ans;
    }
};