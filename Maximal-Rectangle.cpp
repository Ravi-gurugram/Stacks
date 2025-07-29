class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    int maxArea = 0;
    vector<int> left(n), right(n);

    // Find nearest smaller to left
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i])
            s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear stack
    while (!s.empty()) s.pop();

    // Find nearest smaller to right
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i])
            s.pop();
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Compute area
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int n = matrix[0].size();
    vector<int> heights(n, 0);
    int maxArea = 0;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < n; j++) {
            // Update histogram
            if (matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }
        // Use 84's logic
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
    }
};