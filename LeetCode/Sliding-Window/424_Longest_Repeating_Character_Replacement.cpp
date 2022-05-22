/*424. Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(), start=0, end=0, maxCount=0, res=0;
        vector count(26,0);
        
        for(end=0; end<n; end++)
        {
            count[s[end]-'A']++;
            maxCount = max(count[s[end]-'A'], maxCount);
            
            while(end-start-maxCount+1 > k)//need more than k move
            {
                count[s[start]-'A']--;
                start++; //slide the window
                for (int i=0; i<26; i++)
                {
                    if(count[i]>maxCount)
                        maxCount=count[i];
                }
            }
            res=max(res, end-start+1);
        }
        return res;
    }
};