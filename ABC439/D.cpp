#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;

using mint = modint1000000007;
// using mint = modint998244353;

int main(){
  int n;
  cin >> n;
  vi a(n);
  REP(i,n)cin >> a[i];
  map<int,vi> mp;
  REP(i,n){
    mp[a[i]].pb(i);
  }
  for(auto [k, v]: mp)sort(ALL(mp[k]));

  ll ans = 0;
  REP(i,n){
    if(a[i]%5 != 0)continue;

    int x7 = a[i] / 5 * 7;
    int x3 = a[i] / 5 * 3;

    if(mp.count(x7) == 0 || mp.count(x3)==0)continue;

    ans += (ll)(mp[x7].end() - upper_bound(ALL(mp[x7]), i)) * (mp[x3].end() - upper_bound(ALL(mp[x3]), i)); 
    ans += (ll)(lower_bound(ALL(mp[x7]), i) - mp[x7].begin()) * (lower_bound(ALL(mp[x3]), i) - mp[x3].begin()); 
  }
  cout << ans << endl;
}

