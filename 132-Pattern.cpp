class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
    stack<int> st;
    int third = INT_MIN; // this will hold potential '2' (nums[k])

    for (int i = n - 1; i >= 0; --i) {
        // If we find a number smaller than 'third', we found 132 pattern
        if (nums[i] < third)
            return true;

        // While current number > stack.top(), pop and set third
        while (!st.empty() && nums[i] > st.top()) {
            third = st.top();
            st.pop();
        }

        st.push(nums[i]); // now this could be a future nums[j]
    }

    return false;
    }
};