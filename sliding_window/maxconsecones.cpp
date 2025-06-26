#include <bits/stdc++.h>
using namespace std; 
// longest subarray with atmost k zeroes
// better O(2n)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int r=0,l=0, zeroes=0,maxl=0;
        while(r<n){
            if(nums[r]==0){
                zeroes++;
            }
            while(zeroes>k){
                if(nums[l]==0) zeroes--;
                l++;
            }
            if(zeroes<=k){
                maxl=max(maxl,r-l+1);
            }
            r++;
        }
        return maxl;
    }
};

//optimal soln O(n) just replace while(zeroes>k) with if(zeroes>k)