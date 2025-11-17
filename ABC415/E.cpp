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
  int h,w;
  cin >> h >> w;
  vector a(h,vector<ll>(w));
  REP(i,h)REP(j,w)cin >> a[i][j];

  vector<ll> p(h+w-1);
  REP(i,h+w-1)cin >> p[i];

  auto f = [&](ll x){
    vector dp(h,vector<ll>(w,-1));
    dp[0][0] = x + a[0][0]; 
    REP(i,h)REP(j,w){
      dp[i][j] -= p[i+j];
      if(dp[i][j] < 0)continue;

      if(i < h-1)chmax(dp[i+1][j], dp[i][j] + a[i+1][j]); 
      if(j < w-1)chmax(dp[i][j+1], dp[i][j] + a[i][j+1]); 
    }

    //REP(i,h)REP(j,h)printf("%d %d: %lld\n",i,j,dp[i][j]);
    return dp[h-1][w-1] >= 0;
  };


  ll ok=LINF, ng=-1;

  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  cout << ok << endl;


}

