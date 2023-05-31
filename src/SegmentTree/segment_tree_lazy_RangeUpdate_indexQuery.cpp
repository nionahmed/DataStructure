
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;

ll a[N];
struct st{
    #define lc (n<<1)
    #define rc ((n<<1)+1)

    ll t[4*N], lazy[4*N];

    st(){
    memset(t, 0, sizeof t);
    memset(lazy, -1, sizeof lazy);
    }
    inline void push(ll n, ll b, ll e){ //change here
        if(lazy[n]==-1) return;
        t[n]=lazy[n];
        if(b!=e){
            lazy[lc]=lazy[n];
            lazy[rc]=lazy[n];
        }
        lazy[n]=-1;
    }

    inline ll combine(ll a, ll b){ // change here
        return a+b;
    }
    inline void pull(ll n){ // change here
        t[n]=t[lc]+t[rc];
    }
    void build(ll n, ll b, ll e){
        lazy[n]=0; // change here
        if(b==e){
            t[n]=a[b];
            return;
        }
        ll mid= (b+e)>>1;
        build(lc, b, mid);
        build(rc, mid+1, e);
        pull(n);
    }
    void update (ll n, ll b, ll e, ll i, ll j, ll v){
        push(n, b, e);
        if(j<b || i>e) return;
        if(i<=b and j>=e){
            lazy[n]=v; // set lazy
            push(n, b, e);
            return ;
        }
        ll mid=(b+e)>>1;
        update(lc, b, mid, i, j, v);
        update(rc, mid+1, e, i, j, v);
        pull(n);
    }

    ll query(ll n, ll b, ll e, ll i, ll j){

    push(n, b,e);
    if(i>e || j<b) return 0; // change gere
    if(i<=b and e<=j) return lazy[n]!= -1? lazy[n]: t[n];
    ll mid=(b+e)>>1;
    return combine(query(lc, b,mid, i,j), query(rc, mid+1, e, i, j));
    }

}t;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m; cin>>n>>m;

    t.build(1,1,n);
    while(m--){
        ll type; cin>>type;
        if(type==1){
            ll l,r,v;
            cin>>l>>r>>v;
            t.update(1,1,n,l+1,r,v);
        }
        else{
            ll i; cin>>i;
            ll ans =t.query(1,1,n,i+1,i+1);
            cout<<ans<<endl;
        }



    }



    return 0;
}



