class Solution {
public:
    vector<int> nextSmaller(vector<int> &heights) {
        int n = heights.size();
        vector<int> next(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (!st.empty())
                next[i] = st.top();

            st.push(i);
        }
        return next;
    }

    vector<int> prevSmaller(vector<int> &heights) {
        int n = heights.size();
        vector<int> prev(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (!st.empty())
                prev[i] = st.top();

            st.push(i);
        }
        return prev;
    }

    int maxArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> prev = prevSmaller(heights);
        vector<int> next = nextSmaller(heights);

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int width = next[i] - prev[i] - 1;
            maxi = max(maxi, width * heights[i]);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            ans = max(ans, maxArea(heights));
        }
        return ans;
    }
};
