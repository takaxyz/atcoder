#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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
  int n,m,k;
  cin >> n >> m >> k;

  vector<vector<P>> edge(2*n);
  REP(i,m){
    int v,u,a;
    cin >> v >> u >> a;
    v--; u--;
    if(a==1){
      edge[v].emplace_back(u,1);
      edge[u].emplace_back(v,1);
    }else{
      edge[v+n].emplace_back(u+n,1);
      edge[u+n].emplace_back(v+n,1);
    }
  }

  REP(i,k){
    int s;
    cin >> s;
    s--;
    edge[s].emplace_back(s+n,0);
    edge[s+n].emplace_back(s,0);
  }

  vi dist(2*n,INF);
  dist[0]=0;

  priority_queue< P, vector<P>, greater<P> > q;
  q.push({0,0});

  while(q.size()){
    int d = q.top().first;
    int x = q.top().second;
    //printf("%d %d\n",d,x);
    q.pop();
    if(dist[x] < d)continue;

    for(auto [v, c] : edge[x]){
      if(dist[v] <= d+c)continue;

      dist[v] = d+c;
      q.push({dist[v], v});
    }
  }

  if(dist[n-1] == INF && dist[2*n-1]==INF){
    cout << -1 << endl;
  }else{
    cout << min(dist[n-1], dist[2*n-1]) << endl;
  }
}

