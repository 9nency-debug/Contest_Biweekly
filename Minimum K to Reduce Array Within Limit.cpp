#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumK(vector<int>& nums) {
     long long low = 1;
        long long high = 2000000000;
        int ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid == 0) {
                low = 1;
                continue;
            }
            long long total_ops = 0;
            long long k_square = mid * mid;
            bool possible = true;
            for (int x: nums) {
                total_ops += (x + mid - 1) / mid;

                if (total_ops > k_square) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                ans = (int)mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
    return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int result = sol.minimumK(nums);
    cout << result << endl; // Output the minimum K
    return 0;
}