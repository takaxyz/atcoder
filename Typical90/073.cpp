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
  vector<char> c(n);
  REP(i,n)cin >> c[i];
  vvi edge(n);
  REP(_,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].pb(b);
    edge[b].pb(a);
  }

  vector dp(n,vector<mint>(3));

  auto dfs = [&](int v, int p, auto dfs) -> void{
    mint val1 = 1, val2 = 1;
    for(auto nv: edge[v]){
      if(nv == p)continue;

      dfs(nv, v, dfs);

      if(c[v] == 'a'){
        val1 *= (dp[nv][0] + dp[nv][2]);
        val2 *= (dp[nv][0] + dp[nv][1] + dp[nv][2]*2);
      }else{
        val1 *= (dp[nv][1] + dp[nv][2]);
        val2 *= (dp[nv][0] + dp[nv][1] + dp[nv][2]*2);
      }
    }

    if(c[v]=='a'){
      dp[v][0]=val1;
      dp[v][2]=val2-val1;
    }else{
      dp[v][1]=val1;
      dp[v][2]=val2-val1;
    }
  };

  dfs(0,-1,dfs);

  cout << dp[0][2].val() << endl;
}

