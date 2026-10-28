class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        // Right se left jaayenge, kyunki addition last digit se start hota hai
        for (int i = n - 1; i >= 0; i--) {

            // Agar digit 9 se chhota hai, toh simply 1 add kar do
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // Agar digit 9 hai, toh 0 banega aur carry aage jayega
            digits[i] = 0;
        }

        // Agar saare digits 9 the, toh starting mein 1 add karna padega
        digits.insert(digits.begin(), 1);

        return digits;
    }
};