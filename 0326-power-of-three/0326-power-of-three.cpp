class Solution {
public:
    bool isPowerOfThree(int n) {
          for ( int i = 0; i <= 19;  i++){
            int answ = pow(3,i);
            
            if ( answ == n){
                return true;
            }
          }

          return false;
    
    }
};