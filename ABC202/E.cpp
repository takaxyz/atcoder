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


int n;
vvi edge;
vector<vector<P>> Q;
vi D;
vi ans;

void dfs(int v, int d){
  // printf("in: %d\n",v);
  // REP(i,n){
  //   printf("%d ", D[i]);
  // }
  // printf("\n");

  if(Q[v].size()>0){
    for(auto x: Q[v]){
      int dx = x.first;
      int ix = x.second;
      ans[ix] -= D[dx];
    }
  }
  D[d]++;


  for(auto c: edge[v]){
    dfs(c, d+1);
  }
  // printf("out: %d\n",v);
  // REP(i,n){
  //   printf("%d ", D[i]);
  // }
  // printf("\n");

  if(Q[v].size()>0){
    for(auto x: Q[v]){
      int dx = x.first;
      int ix = x.second;
      ans[ix] += D[dx];
    }
  }
}

int main(){
  cin >> n;
  edge.reserve(n);
  Q.resize(n);
  D.resize(n,0);

  REP(i,n-1){
    int p;
    cin >> p;
    edge[p-1].push_back(i+1);
  }
  int q;
  cin >> q;
  ans.resize(q);
  REP(i,q){
    int u,d;
    cin >> u >> d;
    u--;
    Q[u].emplace_back(d,i);
  }

  dfs(0,0);

  REP(i,q){
    cout << ans[i] << endl;
  }
}

