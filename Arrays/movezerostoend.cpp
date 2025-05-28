#include <bits/stdc++.h>
using namespace std;
// brute remove non zero ele in a temp array and put back from beginning
// then fill remaining places with zeros
// TC-O(2n) SC-O(n)

// Optimise space have a pointer from begin then interate to get non zero 
// no. and fill in pointer then move pointer then from pointer to end fill with zeros
//// TC-O(n) SC-O(1)   I can swapping also with two pointer wihtout filling zeros
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lnz=0, n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[lnz]=nums[i];
                lnz++;
            }
        }
        for(int i=lnz;i<n;i++){
            nums[i]=0;
        }
    }
};