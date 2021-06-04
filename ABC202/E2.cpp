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

vvi edge;
vi in, out, depth;
vvi dl;

int k=0;

void dfs(int v, int d){
  depth[v]=d;
  in[v]=k;
  k++;

  for(auto c: edge[v]){
    dfs(c, d+1);
  }
  out[v]=k;
}

int main(){
  int n;
  cin >> n;
  edge.resize(n);
  in.resize(n);
  out.resize(n);
  depth.resize(n);
  dl.resize(n);
  REP(i,n-1){
    int p;
    cin >> p;
    edge[p-1].push_back(i+1);
  }

  dfs(0,0);

  REP(i,n)dl[depth[i]].push_back(in[i]);
  REP(i,n)sort(ALL(dl[i]));

  // REP(i,n){
  //   cout << in[i] << (i==n-1 ? "\n" : " ");
  // }
  // REP(i,n){
  //   cout << out[i] << (i==n-1 ? "\n" : " ");
  // }
  // REP(i,n){
  //   cout << depth[i] << (i==n-1 ? "\n" : " ");
  // }
  // REP(i,n){
  //   REP(j,dl[i].size()){
  //     cout << dl[i][j] << (j==dl[i].size()-1 ? "\n" : " ");
  //   }
  // }

  int q;
  cin >> q;
  REP(i,q){
    int u, d;
    cin >> u >> d;
    u--;
    int x = lower_bound(ALL(dl[d]), out[u]) - dl[d].begin();
    int y = lower_bound(ALL(dl[d]), in[u]) - dl[d].begin();
    cout << x - y << endl;
  }
}

