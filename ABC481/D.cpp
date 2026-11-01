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
  int n,m,s,t;
  cin >> n >> m >> s >> t;
  s--; t--;
  vector edge(n,vector<P>());

  REP(_,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].pb({b,0});
  }
  REP(i,n){
    sort(ALL(edge[i]));
    FOR(j,1,edge[i].size())edge[i][j].second = 1;
  }

  vi dist(n,INF);
  priority_queue<P, vector<P>, greater<P>> q;
  dist[s]=0;
  q.emplace(0, s);
  while(!q.empty()){
    auto [cost, v] = q.top();
    q.pop();
    if(dist[v] < cost)continue;
    
    for(auto [nv, c]: edge[v]){
      int nc = cost + c;
      if(dist[nv] <= nc)continue;
      dist[nv] = nc;
      q.emplace(nc, nv);
    }
  }
  cout << (dist[t] == INF ? -1 : dist[t]) << endl;
}

