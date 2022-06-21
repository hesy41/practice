/*28. Implement strStr()
  Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

*/

 class Solution {
public:
    int strStr(string big, string target) {
        int first=0, flag=-1;
        while(first<big.length())
        {
            if(big[first] == target[0])
            {
                flag=first;
                for (int i=1; i<target.length(); i++)
                {
                    if(big[first+i] != target[i])
                    {
                        flag=-1;
                        i=target.length();
                    }
                }
                if(flag != -1)
                    return flag;
            }
            first++;
        }
        return flag;
    }
};