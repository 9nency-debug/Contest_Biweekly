#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // long long low = 1, high = 1e6;
        // int ans = high;
        int globalMax = 0;

        // while (low <= high) {
        //     long long mid = low + (high - low) / 2;
        //     long long ops = 0;
        //     long long limit = mid * mid;
        //     bool possible = true;

        //     for (int n : nums) {
        //         ops += (n + mid - 1) / mid;
        //         if (ops > limit) {
        //             possible = false;
        //             break;
        //         }
        //     }
        //     if (possible) {
        //         ans = mid;
        //         high = mid - 1;
        //     } else {
        //         low = mid + 1;
        //     }
        // }

        for (int b = 0; b < 31; ++b) {
            vector<int> candidates;
            for (int x : nums) {
                if ((x >> b) & 1) {
                    candidates.push_back(x);
                }
            }
            if (candidates.empty()) 
                continue;

            vector<int> tails;
            for (int x : candidates) {
                auto it = lower_bound(tails.begin(), tails.end(), x);
                if (it == tails.end()) {
                    tails.push_back(x);
                } else {
                    *it = x;
                }
                }
            globalMax = max(globalMax, (int)tails.size());
            }
        
        return globalMax;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    int result = sol.longestSubsequence(nums);
    cout << result << endl; // Output the length of the longest subsequence
    return 0;
}