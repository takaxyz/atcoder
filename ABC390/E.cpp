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
  int n,x;
  cin >> n >> x;

  vector food(3, vector<P>());
  REP(_,n){
    int v,a,c;
    cin >> v >> a >> c;
    v--;
    food[v].pb({a,c});
  }
  vvi d(3);
  REP(v,3){
    int sz = food[v].size();
    vvi dp(sz+1,vi(x+1, -1));
    dp[0][0]=0;
    REP(i,sz){
      auto [a,c] = food[v][i];
      REP(j,x+1){
        if(dp[i][j]==-1)continue;
        chmax(dp[i+1][j],dp[i][j]);
        if(j+c<=x)chmax(dp[i+1][j+c],dp[i][j]+a);
      }
    }
//    printf("\n%d:\n",v);
    REP(i,x)chmax(dp[sz][i+1],dp[sz][i]);
  //   REP(i,x+1){
  //     //if(dp[sz][i]==-1)continue;
  //     printf("%d %d\n",i,dp[sz][i]);
  //   }
  // }
    d[v] = dp[sz];
  }

  auto f = [&](int s) -> bool {
    int cnt = 0;
    REP(v,3){
      if(d[v][x] < s)return false;
      int i = lower_bound(ALL(d[v]), s) - d[v].begin();
      cnt += i;
    }
    return cnt <= x;

  };

  int ok=0, ng=INF;

  while(abs(ok-ng)>1){
    int mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  cout << ok << endl;

}

