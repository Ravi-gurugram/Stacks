class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string part;

        while (getline(ss, part, '/')) {
            if (part == "" || part == ".") {
                continue;
            } else if (part == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(part);
            }
        }

        // Build the final path
        string result;
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};