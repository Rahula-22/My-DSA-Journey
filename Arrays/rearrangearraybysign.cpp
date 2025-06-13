#include <bits/stdc++.h>
using namespace std;
// brute force is just make two arrays pos and neg and put back at even arr[2i]=pos and odd arr[2i+1]= neg TC O(n + n/2)
// We can't reduce space we will need to store
// make a new array and check pos and neg update pos and place 
// if the pos=neg optimal done O(n) otherwise brute will only works with adding equal ele based on which has greater length and add remianing ele at last
// TC- O(2n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,0);
        int pos=0,neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                v[pos]=nums[i];
                pos+=2;
            }
            else{
                v[neg]=nums[i];
                neg+=2;
            }
        }
        return v;
    }
};