#include <bits/stdc++.h>
using namespace std;

// brute force two loops and update profit maxi TC-O(n^2) 
// Optimal I will linearly travel the array and maintain a minimum from 
// the start of the array and compare it with every element of the array, if it is greater than the
// minimum then take the difference and maintain it in max, otherwise update the minimum.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0], maxp=0;
        for(int i=0;i<n;i++){
            mini=min(mini,prices[i]);
            maxp=max(maxp, prices[i]-mini);
        }
        return maxp;
    }
};