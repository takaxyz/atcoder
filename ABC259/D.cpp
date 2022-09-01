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

bool visited[3001];
vvi edge;

void dfs(int v, int p){
  visited[v]=true;
  for(auto vv: edge[v]){
    if(vv==p)continue;
    if(visited[vv])continue;
    dfs(vv, v);
  }
}

int main(){
  int n;
  cin >> n;
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  vector<ll> x(n),y(n),r(n);
  REP(i,n)cin >> x[i] >> y[i] >> r[i];

  int s,t;
  REP(i,n){
    if((sx-x[i])*(sx-x[i]) + (sy-y[i])*(sy-y[i]) == r[i]*r[i]){
      s = i;
      break;
    }
  }
  REP(i,n){
    if((tx-x[i])*(tx-x[i]) + (ty-y[i])*(ty-y[i]) == r[i]*r[i]){
      t = i;
      break;
    }
  }

  edge.resize(n);
  REP(i,n)FOR(j,i+1,n){
    if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= (r[i]+r[j])*(r[i]+r[j]) &&
      ((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) >= (r[i]-r[j])*(r[i]-r[j]))
    ){
      edge[i].emplace_back(j);
      edge[j].emplace_back(i);
    }
  }

  // REP(i,n){
  //   for(auto v: edge[i]){
  //     cout << i << " " << v << endl;
  //   }
  // }

  dfs(s,-1);

  cout << (visited[t] ? "Yes" : "No") << endl;

}

