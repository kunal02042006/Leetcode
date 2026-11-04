class Solution {
private:

    vector<int> nextSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--) {
            int curr = arr[i];

            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int curr = arr[i];

            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = 0;

        for(int i = 0; i < n; i++) {
            int l = heights[i];

            if(next[i] == -1) {
                next[i] = n;
            }

            int b = next[i] - prev[i] - 1;
            int newArea = l * b;

            area = max(area, newArea);
        }

        return area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);

        // Step 1: First row se histogram calculate karo
        for(int j = 0; j < m; j++) {
            if(matrix[0][j] == '1') {
                heights[j] = 1;
            }
        }

        int area = largestRectangleArea(heights);

        // Step 2: Remaining rows update karo
        for(int i = 1; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == '1') {
                    heights[j] = heights[j] + 1;
                }
                else {
                    heights[j] = 0;
                }
            }

            area = max(area, largestRectangleArea(heights));
        }

        return area;
    }
};