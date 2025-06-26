#include <bits/stdc++.h>
using namespace std; 
//same as Longest Substring With At Most K Distinct Characters
//brute force it is just pseudo code 
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        map<int,int> mpp;
        int maxl=0;
        for(int i=0;i<n;i++){
            mpp.clear();
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                if(mpp.size()<=k){
                    maxl=max(maxl,j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return maxl;
    }
};

//better 
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int> freq(26,0);
        int maxf=0;
        int maxl=0, r=0,l=0;
        while(r<n){
            int idx=s[r]-'A';
            freq[idx]++;
            maxf=max(maxf,freq[idx]);
            while((r-l+1)-maxf>k){
                freq[s[l]-'A']--;
                l++;
            }
            maxl=max(maxl,r-l+1);
            r++;
        }
        return maxl;
    }
};
//optimal- replace while to if
