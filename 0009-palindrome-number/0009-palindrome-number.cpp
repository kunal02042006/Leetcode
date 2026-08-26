class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0)
        return false;

    int temp = x;
    long ans = 0;

    while (temp != 0) {
        ans = (ans * 10) + temp % 10;
        temp = temp / 10;
    }

    return ans == x;
}
};