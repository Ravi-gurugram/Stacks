class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        stack<vector<int>> st;
        bool inserted = false;

        for (auto& curr : intervals) {
            if (curr[1] < newInterval[0]) {
                st.push(curr);  // Completely before
            }
            else if (curr[0] > newInterval[1]) {
                if (!inserted) {
                    st.push(newInterval);
                    inserted = true;
                }
                st.push(curr);  // Completely after
            }
            else {
                // Overlapping: merge
                newInterval[0] = min(newInterval[0], curr[0]);
                newInterval[1] = max(newInterval[1], curr[1]);
            }
        }

        if (!inserted) st.push(newInterval);

        // Transfer from stack to result (in reverse order)
        vector<vector<int>> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;



    }
};