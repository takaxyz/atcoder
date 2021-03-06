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
vi nodes;
vi used;
vi col;
void dfs(int v){
  used[v]=1;
  nodes.push_back(v);
  for(auto w: edge[v]){
    if(used[w]==1)continue;
    dfs(w);
  }
}
ll now;
void dfs2(int i){
  if(i==nodes.size()){now++; return;}

  REP(c,3){
    bool ok=true;
    col[nodes[i]]=c;
    for(auto v: edge[nodes[i]]){
      if(col[v]==c)ok=false;
    }
    if(ok){
      dfs2(i+1);
    }
  }
  col[nodes[i]]=-1;
}

int main(){
  int n,m;
  cin >> n >> m;
  edge = vvi(n, vi());
  used = vi(n,0);
  REP(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  ll ans=1;
  REP(i,n){
    if(used[i]==1)continue;
    ans *= 3;
    nodes = vi();
    dfs(i);
    now=0;
    col = vi(n,-1);
    col[nodes[0]]=0;
    dfs2(1);
    ans *= now;
  }
  cout << ans << endl;
}

