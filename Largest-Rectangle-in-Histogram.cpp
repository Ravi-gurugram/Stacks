class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
    stack<int> s;
    vector<int> left(n), right(n);

    // Left limits
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear stack for reuse
    while (!s.empty()) s.pop();

    // Right limits
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Compute max area
    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
    }
};