/*567. Permutation in String
  Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
  In other words, return true if one of s1's permutations is the substring of s2*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_freq, s2_window;
        if (s1.size()>s2.size())
            return false; 
        
        for (int a=0; a<s1.size(); a++)
        {
            s1_freq[s1[a]]++;
            s2_window[s2[a]]++;
            //ini the window to be the same size as s1
        }
        if(s1_freq == s2_window)
                return true;
        int i=0;
        int j=s1.size();
        while (j<s2.size())
        {
            s2_window[s2[i]]--;
            s2_window[s2[j]]++;
            
            if (s2_window[s2[i]] == 0)
                s2_window.erase(s2[i]);
            i++;
            j++;
            
            if(s1_freq == s2_window)
                return true;
        }
        return false;
    }
};

//shorter version
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_freq, s2_window;
        if (s1.size()>s2.size())
            return false; 
        
        for (int a=0; a<s1.size(); a++)
        {
            s1_freq[s1[a]]++;
            s2_window[s2[a]]++;
            //ini the window to be the same size as s1
        }
        if(s1_freq == s2_window)
                return true;
        int i=0;
        int j=s1.size();
        while (j<s2.size())
        {
            if (s2_window[s2[i]] == 1)
                s2_window.erase(s2[i++]);
            else
                s2_window[s2[i++]]-=1;
            
            s2_window[s2[j++]]+=1;
            
            if(s1_freq == s2_window)
                return true;
        }
        return false;
    }
};

//solution 2 with vector and no coping the window at first
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1v (26, 0);
        vector<int> s2v (26, 0);
        for (auto c : s1)
            s1v[c - 'a']++;
        
        int l = 0, r = 0;
        
        while (r < s2.size()) {
            s2v[s2[r]-'a']++;
            if (r - l + 1 == s1.size() && s1v == s2v)
                return true;
            
            if (r - l + 1 < s1.size()) 
                r++;
            else 
            {
                s2v[s2[l]-'a']--;
                l++;
                r++;
            }
        }
        return false;
    }
};