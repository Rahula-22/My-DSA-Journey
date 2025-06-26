#include <bits/stdc++.h>
using namespace std; 

// O(n), SC-O(256)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=0, maxl=0;
        vector<int> hash(256,-1);
        while(r<n){
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
            maxl=max(maxl,r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxl;
    }
};