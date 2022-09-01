#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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

using mint = modint998244353;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

int main(){
  int n,m;
  cin >> n >> m;

  vector<ll> xd(3), yd(3);
  REP(i,3)cin >> xd[i] >> yd[i];

  set<pair<ll,ll>> st;
  REP(i,m){
    ll x,y;
    cin >> x >> y;
    st.insert({x,y});
  }

  map<pair<ll,ll>, mint> dp;
  dp[{0,0}]=1;
  REP(i,n){
    map<pair<ll,ll>, mint> dp1;
    swap(dp1,dp);

    for(auto [k,v]: dp1){
      auto [x,y] = k;
      REP(i,3){
        ll nx = x + xd[i];
        ll ny = y + yd[i];
        //cout << nx << " " << ny << endl;
        if(st.count({nx,ny}))continue;
        dp[{nx,ny}] += v;
      }
    }
  }

  mint ans=0;
  for(auto [k,v]: dp){
    ans += v;
  }
  cout << ans.val() << endl;
}

