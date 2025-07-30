class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> s;

        // Previous smaller: strictly less
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i])
                s.pop();
            prevSmaller[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Next smaller or equal
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            nextSmaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            ans = (ans + arr[i] * left * right) % MOD;
        }

        return ans;
    }
};