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

  if(n!=m){
    cout << "No" << endl;
    return 0;
  }
  vvi edge(m);

  REP(_,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].pb(b);
    edge[b].pb(a);
    if(edge[a].size() > 2){
      cout << "No" << endl;
      return 0;
    }
    if(edge[b].size() > 2){
      cout << "No" << endl;
      return 0;
    }
  }
  vi visited(n,0);

  auto dfs = [&](int v, int p, auto dfs) -> void {
    //cout << v << " " << p << endl;
    visited[v]=1;
    for(auto x: edge[v]){
      if(x == p)continue;
      if(visited[x])continue;
      dfs(x,v,dfs);
    }
  };
  dfs(0,-1,dfs);

  REP(i,n){
    if(visited[i]==0){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}

