#include <bits/stdc++.h>
using namespace std;

//brute force TC-O(n^2)


class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n=arr.size();
        vector<int> vec;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>=arr[j]){
                    if(j==(n-1)){
                       vec.push_back(arr[i]); 
                    }
                    continue;
                }
                else{
                    break;
                }
            }
        }
        vec.push_back(arr[n-1]);
        return vec;
    }
};

//Optimal TC-O(n), SC-O(n)
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n=arr.size();
        vector<int> vec;
        int maxi=arr[n-1];
        vec.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=maxi){
                vec.push_back(arr[i]);
                maxi=arr[i];
            }
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};
