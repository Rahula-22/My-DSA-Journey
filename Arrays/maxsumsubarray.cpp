#include <bits/stdc++.h>
using namespace std;

// brute force we can run 3 loops and get the sum and track maximum sum 
// better use sum before 2nd loop and add each ele on iterating in 2nd loop and track
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};

//optimal TC-O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxi = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]);
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};

