/*
Bismillahir Rahmanir Rahim
Author: Md Nurul Amin
Information and Communication Engineering, NSTU
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void merging(ll a[], ll l, ll mid, ll r){

    ll n1=mid-l+1;
    ll n2=r-mid;

    ll x[n1], y[n2];

    for(ll i=0; i<n1; i++){
        x[i]=a[l+i];
    }
    for(ll i=0; i<n2; i++){
        y[i]=a[mid+i+1];
    }
    ll i=0, j=0, k=l;
    while(i<n1 and j<n2){
        if(x[i]<=y[j]){
            a[k]=x[i];
            i++; k++;
        }
        else{
            a[k]=y[j];
            j++; k++;
        }
    }
    while(i<n1){
         a[k]=x[i];
        i++; k++;
    }
    while(j<n2){
         a[k]=y[j];
         j++; k++;
    }

}

void merge_sort(ll a[], ll l, ll r){

    if(l<r){
    ll mid=(l+r)/2;
    merge_sort(a, l, mid);
    merge_sort(a, mid+1, r);

    merging(a, l, mid, r);
    }

}



int main(){
    ll n; cin>>n;
    ll a[n+1];
    for(ll i=1; i<=n; i++){
        cin>>a[i];
    }
    merge_sort(a, 1, n);

    for(ll i=1; i<=n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
