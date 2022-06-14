/*1234. Replace the Substring for Balanced String
  You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.

A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.
*/

class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> map;
        int res=INT_MAX, i=0, n=s.length();
        int mean=n/4; 
        //coping all data
        for (int j=0; j<n; j++)
            map[s[j]]++;
        
        for (int j=0; j<n; j++)
        {
            map[s[j]]--;
            while(i<n && map['Q'] <=mean && map['W']<=mean && map['E']<=mean && map['R']<=mean){
                res=min(res, j-i+1);
                map[s[i++]]+=1;
            }
        }
        
        return res;
            
    }
};