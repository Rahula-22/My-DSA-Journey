#include <bits/stdc++.h>
using namespace std;

// Run three loops and calculate sum and check the condition if ture cnt++
// run two loops and then add each ele at traversal and check consdion in second loop itself
// optimal O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int presum = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            if (mpp.find(presum - k) != mpp.end()) {
                cnt += mpp[presum - k];
            }
            mpp[presum]++;
        }
        return cnt;
    }
};
