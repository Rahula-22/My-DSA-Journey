#include <bits/stdc++.h>
using namespace std;
//optimal O(2k)
class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int lsum=0, rsum=0, maxsum=0, rind=arr.size()-1;
        for(int i=0;i<k;i++){
            lsum+=arr[i];
            maxsum=lsum;
        }
        for(int i=k-1;i>=0;i--){
            lsum-=arr[i];
            rsum+=arr[rind];
            maxsum=max(maxsum,lsum+rsum);
            rind--;
        }
        return maxsum;
    }
};