#include <bits/stdc++.h>
using namespace std;

// Brute force using two loops tracking cnt and check if cnt>n/2 TC-O(n^2)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    cnt++;
                }
            }
            if(cnt>nums.size()/2){
                    return nums[i];
            }
        }
        return -1;
    }
};

//Alternate TC-O(nlogn)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

//better soln is TC-O(n), SC-O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > n / 2) return num;
        }
        return -1;
    }
};

//better O(n) time, O(1) space

