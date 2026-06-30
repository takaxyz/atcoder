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
  vvi a(n,vi(n));

  vector<tuple<int,int,int>> e;
  REP(i,n)FOR(j,i+1,n){
    cin >> a[i][j];
    e.pb({a[i][j],i,j});
  }

  sort(ALL(e));

  dsu uf(n);

  vector edge(n, vector<P>());
  for(auto [c, u, v]: e){
    if(uf.same(u,v))continue;

    uf.merge(u,v);

    edge[u].pb({v,c});
    edge[v].pb({u,c});
  }

  vvi dist(n,vi(n));

  REP(s,n){
    queue<int> q;
    vi visited(n);
    visited[s]=1;
    dist[s][s] = 0;
    q.push(s);
    while(q.size()){
      int v = q.front();
      q.pop();

      for(auto [nv,c]: edge[v]){
        if(visited[nv])continue;
        visited[nv]=1;
        dist[s][nv] = dist[s][v] + c;
        q.push(nv);
      }
    }
  }

  REP(i,n)FOR(j,i+1,n){
    if(dist[i][j] != a[i][j]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

}

