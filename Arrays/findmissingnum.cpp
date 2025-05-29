#include <bits/stdc++.h>
using namespace std;
//Brute O(nlgn), O(1)... can also run two loops and iterate and using flag=0 and change it to 1 if missing

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int cnt=nums.size();
        int mis=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return cnt;
    }
};

//Better using hash array O(2n),O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> hash(n + 1, 0);
        for(int i=0;i<n;i++){
            hash[nums[i]]=1;
        }
        for(int i=0;i<n;i++){
            if(hash[i]==0){
                return i;
            }
        }
        return n;
    }
};

//optimised O(n), O(1) using sum(total_sum-curr_sum) but it will overflow for large data I will need to use long or XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;
        for (int i = 0; i < n; i++) {
            xor2 ^= nums[i];
            xor1 ^= i;
        }
        xor1 ^= n;
        return xor1 ^ xor2;
    }
};

