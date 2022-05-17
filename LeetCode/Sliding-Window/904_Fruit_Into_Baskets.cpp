/*904. Fruit Into Baskets
 You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

*/

class Solution {
public:
    
    //Find out the longest length of subarrays with at most 2 different numbers
    int totalFruit(vector<int>& fruits) {
        int a=0, b=0, cur=0, res=0, count_b=0; //the last same number list;
        
        for(int c : fruits)
        {
            if(c==a || c==b) //see whether the next one can naturally place in the basket
                cur +=1;
            else
                cur=count_b+1;
            if(c==b) // wehther c can merge into the the last same number list
                count_b ++;
            else{
                count_b=1;//11223: 3 is the new 'b'
                a=b;
                b=c; //admitted two updates
            }
            res = max(res,cur);
        }
        return res;
    }
};