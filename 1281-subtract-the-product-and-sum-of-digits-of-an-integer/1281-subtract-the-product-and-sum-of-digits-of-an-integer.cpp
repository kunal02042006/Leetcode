class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0 , product = 1 , Ans;
        while (n!=0){
        int digit = n%10;
        sum = sum + digit;
        product = product * digit;
         
         n = n/10;
        
    }
    Ans = product - sum;
    return Ans ;}
};
