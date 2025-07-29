class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1]; // ascending defense
        return a[0] > b[0]; // descending attack
    });

    int maxDefense = 0;
    int weakCount = 0;

    // Step 2: Traverse and count weaker characters
    for (auto& p : properties) {
        if (p[1] < maxDefense) {
            weakCount++;
        } else {
            maxDefense = p[1];
        }
    }

    return weakCount;
    
    }
};