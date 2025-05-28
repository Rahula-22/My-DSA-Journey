#include <bits/stdc++.h>
using namespace std;
//brute TC-O(n^2) SC-O(n)
vector<int> find(vector<int> &a, vector<int> &b,int m){
    vector<int> ans;
    int vis[m]={0};
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(a[i]==b[j] && vis[j]==0){
                ans.push_back(a[i]);
                vis[j]=1;
                break;
            }
            if(b[j]>a[i]) break;
        }
    }

}

//use two pointer approach TC-O(n+m), SC-O(1)
vector<int> find(vector<int> &a, vector<int> &b){
    int i=0,j=0;
    vector<int> ans;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++,j++;
        }
    }
    return ans;
}
