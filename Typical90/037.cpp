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
const int MOD = 1e9 + 7;

ll op(ll a, ll b) {
  return max(a, b);
}

ll e() {
  return -LINF;
}


int main(){
  int w,n;
  cin >> w >> n;

  vi L(n), R(n);
  vector<ll> V(n);
  REP(i,n)cin >> L[i] >> R[i] >> V[i];

  vector<ll> dp(w+1, -LINF);
  dp[0] = 0;

  segtree<ll, op, e> seg(w+1);
  seg.set(0,0);

  FOR(i,1,n+1){
    vector<ll> d(w+1, -LINF);
    swap(d,dp);

    REP(j,w+1){
      dp[j] = d[j];
      int li = max(0, j - R[i-1]);
      int ri = max(0, j - L[i-1]+1);
      // cout << j << " " << R[i-1] << " " << L[i-1] << endl;
      // cout << li << " " << ri << endl;
      if(li==ri)continue;
      if(seg.prod(li,ri) == -LINF)continue;
      chmax(dp[j], seg.prod(li,ri) + V[i-1]);
    }

    seg = segtree<ll, op, e>(w+1);
    REP(j,w+1)seg.set(j, dp[j]);
  }
  //REP(i,w+1)cout << i << " " << dp[i] << endl;
  cout << (dp[w] == -LINF ? -1 : dp[w]) << endl;
}

