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
  vector<ll> a(n),b(n),c(n),d(n),e(n);
  REP(i,n)cin >> a[i];
  REP(i,n)cin >> b[i];
  REP(i,n)cin >> c[i];
  REP(i,n)cin >> d[i];
  REP(i,n)cin >> e[i];

  map<ll,vector<ll>> mp1,mp2;
  REP(i,n){
    mp1[d[i]].pb(b[i]);
    mp2[b[i]-d[i]].pb(b[i]);
  }

  for(auto &[_,v]: mp1)sort(ALL(v));
  for(auto &[_,v]: mp2)sort(ALL(v));


  REP(i,n){
    int ans=0;

    ll x = a[i]-e[i];
    ans += lower_bound(mp1[x].begin(), mp1[x].end(), a[i]+c[i]) - mp1[x].begin();
    x = c[i]+e[i];
    ans += mp2[x].end() - lower_bound(mp2[x].begin(), mp2[x].end(), a[i]+c[i]);
    cout << ans << endl;
  }
}

