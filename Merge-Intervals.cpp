class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        stack<vector<int>> st;
        st.push(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            auto top = st.top();
            auto curr = intervals[i];

            // If overlapping
            if (curr[0] <= top[1]) {
                st.pop();
                top[1] = max(top[1], curr[1]);
                st.push(top);
            } else {
                st.push(curr);
            }
        }

        // Extract merged intervals from stack
        vector<vector<int>> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        // Since stack gives reversed order
        reverse(result.begin(), result.end());
        return result;
    }
};