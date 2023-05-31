/*
Bismillahir Rahmanir Rahim
Author: Md Nurul Amin
Information and Communication Engineering, NSTU
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>v;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        v.push_back(x);
    }
    int x; cin>>x;
    sort(v.begin(), v.end());
    int idx=lower_bound(v.begin(), v.end(), x)-v.begin()+1;
    int idx2=upper_bound(v.begin(), v.end(), x)-v.begin()+1;

    cout<<idx<<endl;
    cout<<idx2<<endl;
}
