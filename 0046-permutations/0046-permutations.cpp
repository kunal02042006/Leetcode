class Solution {
public:

    void solve(vector<int>& nums, int index, vector<vector<int>>& ans) {

        // Base case: jab index last position ke aage chala jaye,
        // ek complete permutation ready ho gayi hai
        if(index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Current position par har possible element ko try karenge
        for(int j = index; j < nums.size(); j++) {

            swap(nums[index], nums[j]);

            // Ab baaki positions ko recursion handle karega
            solve(nums, index + 1, ans);

            // Original array mein changes kiye hain,
            // isliye swap back karke original state maintain karni hai
            // This step is called Backtracking
            swap(nums[index], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        int index = 0;

        solve(nums, index, ans);

        return ans;
    }
};