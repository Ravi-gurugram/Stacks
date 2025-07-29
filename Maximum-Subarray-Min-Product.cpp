class Solution {
public:
    typedef long long ll;
int maxSumMinProduct(vector<int>& nums) {
    int n = nums.size();
    vector<ll> prefix(n + 1, 0);

    // Step 1: Compute prefix sum
    for (int i = 0; i < n; ++i)
        prefix[i + 1] = prefix[i] + nums[i];

    // Step 2: Monotonic stack for previous & next smaller
    vector<int> left(n, -1), right(n, n);
    stack<int> s;

    // Find previous smaller
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
        if (!s.empty()) left[i] = s.top();
        s.push(i);
    }

    // Clear and reuse stack
    while (!s.empty()) s.pop();

    // Find next smaller
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
        if (!s.empty()) right[i] = s.top();
        s.push(i);
    }

    // Step 3: Calculate max min-product
    ll res = 0, mod = 1e9 + 7;
    for (int i = 0; i < n; ++i) {
        ll total = prefix[right[i]] - prefix[left[i] + 1];
        res = max(res, total * nums[i]);
    }

    return res % mod; 
    }
};