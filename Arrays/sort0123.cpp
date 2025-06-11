#include <bits/stdc++.h>
using namespace std;


// Best solution through counting 0,1,2 and filling TC- O(n), SC-O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) cnt0++;
            else if (nums[i] == 1) cnt1++;
            else cnt2++;
        }
        int i = 0;
        while (cnt0--) nums[i++] = 0;
        while (cnt1--) nums[i++] = 1;
        while (cnt2--) nums[i++] = 2;
    }
};

//Dutch National Flag algorithm  same efficiency
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,h=nums.size()-1;
        while(mid<=h){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[h]);
                h--;
            }
        }
    }
};
