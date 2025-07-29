class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> first, second;
    vector<int> buffer;  // temporary holding area

    for (int i = 0; i < n; ++i) {
        // Resolve second greater
        vector<int> temp;
        while (!second.empty() && nums[i] > nums[second.top()]) {
            ans[second.top()] = nums[i];
            second.pop();
        }

        // Move from first to second if nums[i] > nums[first.top()]
        while (!first.empty() && nums[i] > nums[first.top()]) {
            buffer.push_back(first.top());
            first.pop();
        }

        // Reverse the buffer to maintain correct order in stack
        for (int j = buffer.size() - 1; j >= 0; --j) {
            second.push(buffer[j]);
        }
        buffer.clear();

        // Always push current index to first
        first.push(i);
    }

    return ans;
    }
};