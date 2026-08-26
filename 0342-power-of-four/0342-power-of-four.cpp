class Solution {
public:
    bool isPowerOfFour(int n) {
          for ( int i = 0; i <= 15;  i++){
            int answ = pow(4,i);
            
            if ( answ == n){
                return true;
            }
          } 
                return false;
    }
};