#include <bits/stdc++.h>
using namespace std; 
// brute force  use set ds and store 2 unique elements
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n=arr.size();
        int maxl=0;
        for(int i=0;i<n;i++){
            set<int> st;
            for(int j=i;j<n;j++){
                st.insert(arr[j]);
                if(st.size()<3){
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

//better  O(2n), O(3)
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n=arr.size();
        int maxl=0,l=0,r=0;
        unordered_map<int,int> mpp;
        while(r<n){
            mpp[arr[r]]++;
            if(mpp.size()>2){
                while(mpp.size()>2){
                    mpp[arr[l]]--;
                    if(mpp[arr[l]]==0) mpp.erase(arr[l]);
                    l++;
                }
            }
            if(mpp.size()<=2){
                maxl=max(maxl,r-l+1);
            }
            r++;
        }
        return maxl;
    }
};

//optimal replace while with if O(n)