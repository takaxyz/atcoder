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
  int n,m;
  cin >> n >> m;
  vector edge(n,vector<tuple<int,int,int>>());
  REP(_,m){
    int u,v,b,c;
    cin >> u >> v >> b >> c;
    u--;v--;
    edge[v].pb({u,b,c});
  }

  auto f = [&](double x) -> bool{
    vector<double> dp(n,-1e18);
    dp[0]=0;

    FOR(i,1,n){
      for(auto [v, b, c]: edge[i]){
        if(dp[v] < -1e17)continue;
        chmax(dp[i], dp[v] + b - x * c);
      }
    }

    return dp[n-1] >= 0;
  };

  double ok=0, ng=10000000000;

  REP(_,100){
    double mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }  
  printf("%.9f\n",ok);

}

