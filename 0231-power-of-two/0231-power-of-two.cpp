class Solution {
public:
    bool isPowerOfTwo(int n) {
        for ( int i = 0; i <= 30;  i++){
            int answ = pow(2,i);
            
            if ( answ == n){
                return true;
            }

        }
        return false;
        
    }
};
