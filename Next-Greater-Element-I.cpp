class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;  // next greater element map
    stack<int> st;

    for (int num : nums2) {
        while (!st.empty() && num > st.top()) {
            nge[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    // Fill -1 for elements that have no NGE
    while (!st.empty()) {
        nge[st.top()] = -1;
        st.pop();
    }

    vector<int> result;
    for (int num : nums1) {
        result.push_back(nge[num]);
    }

    return result;
    }
};