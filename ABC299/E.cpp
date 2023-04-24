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
  vvi edge(n);
  REP(i,m){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].pb(v);
    edge[v].pb(u);
  }

  int k;
  cin >> k;
  vi p(k),d(k);
  REP(i,k){
    cin >> p[i] >> d[i];
    p[i]--;
  }


  vvi dist(n,vi(n,INF));

  auto bfs = [&](int x) -> void {
    dist[x][x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
      int v = q.front();
      q.pop();

      for(auto nv : edge[v]){
        if(dist[x][nv]!=INF)continue;
        dist[x][nv] = dist[x][v] + 1;
        q.push(nv);
      }
    }

  };

  REP(i, n){
    bfs(i);
  }

  vi c(n,1);

  REP(i,k){
    REP(j,n){
      if(dist[p[i]][j] < d[i])c[j]=0;
    }
  }

  REP(i,k){
    bool ok = false;
    REP(j,n){
      if(dist[p[i]][j] == d[i] && c[j]==1)ok=true;
    }
    if(!ok){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  REP(i, n)cout << c[i];
  cout << endl;
}

