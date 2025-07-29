class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);
    for (int i = 0; i < s.size(); ++i) {
        lastIndex[s[i] - 'a'] = i;
    }

    vector<bool> seen(26, false);
    stack<char> st;

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];

        if (seen[c - 'a']) continue;

        // Remove characters that are greater than current character
        // and will appear later again
        while (!st.empty() && c < st.top() && lastIndex[st.top() - 'a'] > i) {
            seen[st.top() - 'a'] = false;
            st.pop();
        }

        st.push(c);
        seen[c - 'a'] = true;
    }

    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
    }
};