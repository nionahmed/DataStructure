/*
Bismillahir Rahmanir Rahim
Author: Md Nurul Amin
Information and Communication Engineering, NSTU
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll n; cin>>n;
    ll a[n+1];
    for(ll i=1; i<=n; i++){
        cin>>a[i];
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n-i; j++){
            if(a[j]>a[j+1]){
                a[j]=a[j]+a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]=a[j]-a[j+1];
            }
        }
    }
    for(ll i=1; i<=n; i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;
}
