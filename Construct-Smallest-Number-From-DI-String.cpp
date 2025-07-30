class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> st;
        string result = "";

        for (int i = 0; i <= pattern.size(); ++i) {
            st.push(i + 1);

            // Flush stack on 'I' or end of string
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }

        return result;
    }
};