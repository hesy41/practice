/*
392. Is Subsequence
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. 
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool ans = false;
        int n_t = t.length(), n_s = s.length();
        if (n_t == 0 && n_s == 0)
            return true;
        int index_s = 0;
        for (int i = 0; i < n_t; ++i)
        {
            if (s[index_s] == t[i])
                index_s++;
            if (index_s == n_s)
            {
                ans = true;
                break;
            }
        }
        return ans;
    }
};