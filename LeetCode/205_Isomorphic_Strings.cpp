/*
205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, 
but a character may map to itself.
*/

//both t->s and s->t should be single matching
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //we need the two string to have a same pattern
        if (s.length() != t.length())
            return false;
        int n = s.size();
        map<char, char> s_t={{s[0], t[0]}};
        map<char, char> t_s={{t[0], s[0]}};
        for (int i=1; i<n; i++)
        {
            //prepair relationship found 
            if(s_t.find(s[i]) != s_t.end() && t_s.find(t[i])!= t_s.end())
            {
                //check whether the pair still exist
                if(s_t[s[i]] != t[i] || t_s[t[i] != s[i]])
                    return false;
            }
            else if (s_t.find(s[i]) == s_t.end() && t_s.find(t[i])== t_s.end())
            {
                s_t[s[i]] = t[i];
                t_s[t[i]] = s[i];
            }
            else
                return false;
        }
        return true;
    }
};