#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n=arr.size();
        int l=INT_MIN, sl=INT_MIN;
        if(n<2) return -1;
        for(int i=0;i<n;i++){
            if(arr[i]>l){
                sl=l;
                l=arr[i];
            }
            else if(arr[i]>sl && arr[i]!=l){
                    sl=arr[i];
            }
        }
        return (sl == INT_MIN) ? -1 : sl;
    }
};