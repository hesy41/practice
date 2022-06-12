/*438. Find All Anagrams in a String
  Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
  An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size())
            return ans;
        vector<int> s1(26, 0);
        vector<int> s2(26, 0);
        for (auto a : p)
        {
            s1[a - 'a']++;
        }
        
        int i=0, j=0;
        
        while(j<s.size())
        {
            s2[s[j] - 'a']++;
            if (j-i+1 == p.size() && s1==s2)
                ans.push_back(i);
            
            
            if(j-i+1 < p.size())
                j++;
            else
            {
                s2[s[i] - 'a']--;
                i++;
                j++;
            }
        }
        return ans;
    }
};