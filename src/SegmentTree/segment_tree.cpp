
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const ll N=1e6+9;
int a[N];
struct ST {
  int t[4 * N];
  static const int inf = 1e9;
  ST() {
    memset(t, 0, sizeof t);
  }
  void build(int n, int b, int e) {
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = max(t[l], t[r]); // change this
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[n] = x; // update
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    t[n] = max(t[l], t[r]); // change this
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return -inf; // return appropriate value
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j)); // change this
  }
}t;

int main()
{
    ll n,q;cin>>n>>q;

    for(ll i=1; i<=n; i++){
        ll x; cin>>x;
        a[i]=x;
    }
    t.build(1,1,n);
   // cout<<t[1]<<endl;
    while(q--){
        ll x; cin>>x;
        if(x==1){
            ll idx, value; cin>>idx>>value;
            t.upd(1,1,n, idx+1, value );
        }
        else{
            ll k1,k2; cin>>k1>>k2;
            ll ans=t.query(1,1, n, k1+1,k2);
            cout<<ans<<endl;
        }
    }








    return 0;
}




