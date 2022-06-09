#include <bits/stdc++.h>
using namespace std;

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
using P = pair<ll,int>;
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

struct Edge{
  int to, cost, id;
  Edge(int to, int cost, int id): to(to), cost(cost), id(id) {}
};


int main(){
  int n, m;
  cin >> n >> m;

  vector<vector<Edge>> g(n);

  REP(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(b, c, i+1);
    g[b].emplace_back(a, c, i+1);
  }

  priority_queue<P, vector<P>, greater<P>> q;

  vector<ll> dst(n, LINF);
  dst[0] = 0;
  q.emplace(0,0);
  vi from(n);
  while(!q.empty()){
    auto [d, v] = q.top(); q.pop();
    if(dst[v] < d)continue;

    for(auto [u, c, id] : g[v]){
      ll nd = dst[v] + c;
      if(dst[u] <= nd)continue;
      from[u] = id;
      dst[u] = nd;
      q.emplace(nd, u);
    }
  }
  FOR(i,1, n){
    cout << from[i] << endl;
  }

}

