class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = n, right = 0;
        stack<int> s;

        // Find left boundary (violates ascending order)
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                left = min(left, s.top());
                s.pop();
            }
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Find right boundary (violates descending order from end)
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                right = max(right, s.top());
                s.pop();
            }
            s.push(i);
        }

        return (right > left) ? (right - left + 1) : 0;
    }
};