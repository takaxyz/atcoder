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

int main(){
  int n,m;
  cin >> n >> m;
  vi a(n);
  REP(i,n)cin >> a[i];
  vi u(m),v(m);

  dsu uf(n);
  
  REP(i,m){
    cin >> u[i] >> v[i];
    u[i]--; v[i]--;
    if(a[u[i]] > a[v[i]])swap(u[i],v[i]);

    if(a[u[i]] == a[v[i]])uf.merge(u[i],v[i]);
  }

  vector<set<int>> edge(n);
  REP(i,m){
    if(a[u[i]] < a[v[i]]){
      edge[uf.leader(u[i])].insert(uf.leader(v[i]));
    }
  }

  vi vs;
  REP(i,n)if(uf.leader(i)==i)vs.pb(i);
  sort(ALL(vs), [&](int u,int v){
    return a[u] < a[v];
  });

  vi dp(n,-INF);
  int s = uf.leader(0);
  int g = uf.leader(n-1);

  dp[s]=1;
  for(auto v: vs){
    for(auto nv: edge[v]){
      chmax(dp[nv], dp[v]+1);
    }
  }

  if(dp[g]<0){
    cout << 0 << endl;
  }else{
    cout << dp[g] << endl;
  }


}

