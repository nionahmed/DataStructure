
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const ll N=1e5+9;
ll a[N];
ll t[4*N];
void build (ll n, ll shuru, ll ses){

    if(shuru==ses){
        t[n]=a[shuru];
        return;
    }

    ll x=2*n; ll y=(2*n)+1;

    ll mid= (shuru+ses)/2;
    build(x, shuru, mid);
    build(y, mid+1, ses);
    t[n]=min(t[x], t[y]);
    //cout<<1<<endl;

}
ll query(ll n, ll shuru, ll ses, ll i, ll j){

    if(shuru>j or ses<i) return 1e18;
    if(shuru>=i and ses<=j){
        return t[n];
    }

    ll mid=(shuru+ses)/2;
    ll x=2*n; ll y=2*n+1;
     // cout<<1<<endl;

    return min(query(x,shuru, mid, i,j), query(y,mid+1,ses, i,j) );

}

void update(ll n, ll shuru, ll ses, ll i, ll val){
    if(i<shuru or i> ses) return;
    if(shuru==ses and shuru==i){
        t[n]=val;
        return;
    }

    ll mid=(shuru+ses)/2;
    ll x=2*n; ll y=(2*n)+1;
    update(x,shuru, mid, i,val);
    update(y,mid+1,ses, i,val);
    t[n]=min(t[x], t[y]);
      //cout<<1<<endl;

}


    int main(){
       ll n,q;cin>>n>>q;

    for(ll i=1; i<=n; i++){
        ll x; cin>>x;
        a[i]=x;
    }
    //cout<<1<<endl;
    build(1,1,n);
   //cout<<t[1]<<endl;
    while(q--){
        ll x; cin>>x;
        if(x==1){
            ll idx, value; cin>>idx>>value;
            update(1,1,n, idx+1, value );
        }
        else{
            ll k1,k2; cin>>k1>>k2;
            ll ans=query(1,1, n, k1+1,k2);
            cout<<ans<<endl;
        }
    }
    return 0;


    }




