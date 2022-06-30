/*202. Happy Number
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.*/

class Solution {
public:
    bool isHappy(int n) {
        //finding the loop
        int fast = n, slow = n;
        do
        {
            slow = find(slow);
            fast = find(fast);
            fast = find(fast);
        }while(slow != fast);
        
        return slow==1 ? 1:0;
    }
    
    int find(int n)
    {
        int sum=0, temp;
        while(n)
        {
            temp = n %10;
            sum += temp * temp;
            n /= 10;
        }
        return sum;
    }
};