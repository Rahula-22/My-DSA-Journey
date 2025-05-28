#include <bits/stdc++.h>
using namespace std;

// TC-O((m+n)log(m+n)), SC- O(m+n) using sets
/* class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> st;
        for(int val:a){
            st.insert(val);
        }
        for(int val:b){
            st.insert(val);
        }
        vector<int> vec;
        for(int it:st){
            vec.push_back(it);
        }
        return vec;
    }
};*/

//optimise use two pointers and track back the last element for check
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n=a.size();
        int m=b.size(), i=0, j=0;
        vector<int> unionA;
        while(i<n && j<m){
            if(a[i]<=b[j]){
                if(unionA.size()==0 || unionA.back()!=a[i]){
                    unionA.push_back(a[i]);
                }
                i++;
            }
            else{
                if(unionA.size()==0||unionA.back()!=b[j]){
                    unionA.push_back(b[j]);
                }
                j++;
            }
        }
        while(i<n){
            if(unionA.size()==0 || unionA.back()!=a[i]){
                    unionA.push_back(a[i]);
            }
            i++;
        }
        while(j<m){
            if(unionA.size()==0 || unionA.back()!=b[j]){
                    unionA.push_back(b[j]);
            }
            j++;
        }
        return unionA;
    }
};