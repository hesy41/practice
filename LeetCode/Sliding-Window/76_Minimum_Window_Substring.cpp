/*76. Minimum Window Substring
  Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.*/

//using unordered_map
class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        if (s.length() < t.length())
            return ans;
        if(s==t)
            return s;
        
        unordered_map<char, int> rec;
        for (auto h : t)
            rec[h]++;
        
        int i=0, j=0, counter = t.size(), minStart=0, minLen=INT_MAX;
        
        while(j< s.size())
        {
            rec[s[j]]--;
            
            if (rec[s[j]] >= 0) // s[j] is in t
                counter--;
            
            while(counter ==0) //substring is found
            {
                if(j-i+1 < minLen)
                {
                    minStart = i;
                    minLen= j-i+1;
                }
                
                //move i to see whether there is a storter substring
                rec[s[i]]++;
                if(rec[s[i]] > 0)
                    counter++;
                i++; 
            }
            j++;
        }
        
        return minLen == INT_MAX ? "": s.substr(minStart, minLen);
    }
};


//using vector -- a litter faster
class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        if (s.length() < t.length())
            return ans;
        if(s==t)
            return s;
        
        vector<int> rec(128,0);
        for (auto h : t)
            rec[h-'A']++;
        
        int i=0, j=0, counter = t.size(), minStart=0, minLen=INT_MAX;
        
        while(j< s.size())
        {
            rec[s[j]-'A']--;
            
            if (rec[s[j]-'A'] >= 0) // s[j] is in t
                counter--;
            
            while(counter ==0) //substring is found
            {
                if(j-i+1 < minLen)
                {
                    minStart = i;
                    minLen= j-i+1;
                }
                
                //move i to see whether there is a storter substring
                rec[s[i]-'A']++;
                if(rec[s[i]-'A'] > 0)
                    counter++;
                i++; 
            }
            j++;
        }
        
        return minLen == INT_MAX ? "": s.substr(minStart, minLen);
    }
};