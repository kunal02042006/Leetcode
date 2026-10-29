class Solution {
public:
    bool isUgly(int n) {
        // '/' quotient deta hai, '%' remainder; divisible check karne ke liye n % divisor == 0 use karte hain.
        if(n==0 || n<0){
            return false;
        }
        while(n%2==0){
            n = n/2;
        }
        while(n%3==0){
            n = n/3;
        }
        while(n%5==0){
            n = n/5;
        }
        if(n==1){
            return true;
        }

        return false;
    }   
    
};