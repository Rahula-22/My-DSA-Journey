#include <bits/stdc++.h>
using namespace std;

//brute force: run two loops and a cnt if(cnt==1) return that number
//better using hash first will need to fing length O(3n), O(max) but for lage numbers we can't use hash 
// it doesn’t meet the strict space requirement. map<key, int> ds
//TC of ordered map-(NlogM)+ O(N/2+1) sc-O(N/2+1), M is size of map and N is size of array, unordered O(n), worst O(n^2) 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto &it:mpp){
            if(it.second==1){
                return it.first;
            }
        }
        return -1;
    }
};
//best
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xr=0;
        for(int i=0;i<n;i++){
            xr=xr^nums[i];
        }
        return xr;
    }
};

