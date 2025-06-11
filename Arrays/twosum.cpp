#include <bits/stdc++.h>
using namespace std;

//brute is simple two loop O(n)
// better soln unordered_map in best and avg case O(n), ordered map (nlogn) worst O(n^2), SC-O(n) 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int x=target-nums[i];
            if(mpp.count(x)){
                return {mpp[x],i};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};

//No uss of map, 2 poiner approach by sorting then us left right pointer TC- O(n log n), SC - O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int left=nums[0];
        int right=nums[n-1];
        sort(nums.begin(),nums.end());
        while(left<right){
            int sum = nums[left]+nums[right];
            if(sum==target){
                return {left,right};
            }
            else if(sum<target) left++;
            else right++;
        }
        return {};
    }
};