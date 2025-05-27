#include <bits/stdc++.h>
using namespace std;

/*Brute Force
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(int val:nums){
            st.insert(val);
        }
        int idx=0;
        for(auto it:st){
            nums[idx]=it;
            idx++;
        }
        return idx;
    }
};
*/

//Optimal Solution using two pointer 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};