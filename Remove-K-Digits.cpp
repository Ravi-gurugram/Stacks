class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;

    for (char digit : num) {
        // While current digit is less than the top of stack and k > 0, pop
        while (!stack.empty() && k > 0 && stack.back() > digit) {
            stack.pop_back();
            k--;
        }
        stack.push_back(digit);
    }

    // If still have digits to remove, remove from end
    while (k > 0 && !stack.empty()) {
        stack.pop_back();
        k--;
    }

    // Remove leading zeros
    int idx = 0;
    while (idx < stack.size() && stack[idx] == '0') {
        idx++;
    }

    string result = stack.substr(idx);
    return result.empty() ? "0" : result;
    }
};