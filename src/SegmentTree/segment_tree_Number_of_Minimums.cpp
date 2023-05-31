#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree< ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ott;
/// find_by_order(k) return kth iterator and *it= value,
/// order_of_key(x)  x er choto koyta ache set e


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
    t[n] = min(t[l], t[r]); // change this
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
    t[n] = min(t[l], t[r]); // change this
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return INT_MAX; // return appropriate value
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    return min(query(l, b, mid, i, j), query(r, mid + 1, e, i, j)); // change this
  }
}t;


int main(){
       ll n,q;cin>>n>>q;
    map<int, ott>mp;
    for(ll i=1; i<=n; i++){
        ll x; cin>>x;
        a[i]=x;
        mp[x].insert(i);
    }
    //cout<<1<<endl;
    t.build(1,1,n);
   //cout<<t[1]<<endl;
    while(q--){
        ll x; cin>>x;
        if(x==1){
            ll idx, value; cin>>idx>>value;
            t.upd(1,1,n, idx+1, value );
            mp[a[idx+1]].erase(idx+1);
            a[idx+1]=value;
            mp[a[idx+1]].insert(idx+1);
        }
        else{
            ll k1,k2; cin>>k1>>k2;
            ll ans=t.query(1,1, n, k1+1,k2);
            ll rpos=mp[ans].order_of_key(k2+1);
            ll lpos=mp[ans].order_of_key(k1+1);
            cout<<ans<<" "<<abs(rpos-lpos)<<endl;
        }
    }
    return 0;


    }




