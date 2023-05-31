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
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  o_set<int> se;
  se.insert(2);
  se.insert(3);
  se.insert(4);
  se.insert(5);
  se.insert(2);
  se.insert(2);


  // sorted set se = [2, 4, 5]
  se.erase(4);
  for (auto i: se)cout<<i<<" ";
  cout<<endl;
  //cout << se.order_of_key(5) << '\n'; // number of elements < 5
  //cout << se.order_of_key(6) << '\n'; // number of elements < 6

  return 0;
}
