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

// using mint = modint1000000007;
using mint = modint998244353;

int main(){
  int n,m,k;
  cin >> n >> m >> k;
  vector<P> e(m);
  REP(i,m){
    int x,y;
    cin >> x >> y;
    x--; y--;
    e[i].first = x;
    e[i].second = y;
  }

  vector<mint> dp(n);
  dp[0]=1;

  REP(i,k){
    vector<pair<int,mint>> add;
    for(auto [x,y]: e){
      int xi = (x + n) - (i%n);
      int yi = (y + n) - ((i+1)%n);
      xi %= n;
      yi %= n;
      add.emplace_back(yi, dp[xi]);
    }
    for(auto [yi, val]: add){
      dp[yi] += val;
    }
  }
  mint ans = 0;
  for(auto x: dp)ans+=x;
  cout << ans.val() << endl;

}

