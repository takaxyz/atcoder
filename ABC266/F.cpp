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

  vvi edge(n);
  REP(_,n){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].pb(v);
    edge[v].pb(u);
  }

  vi seen(n),finished(n);
  vi stack;
  auto dfs = [&](auto dfs, int v, int p=-1) -> int {
    seen[v]=1;
    stack.pb(v);

    for(auto nv : edge[v]){
      if(nv == p)continue;

      if(finished[nv])continue;

      if(seen[nv] && !finished[nv]){
        //stack.pb(nv);
        return nv;
      }

      int p = dfs(dfs, nv,v);
      if(p != -1)return p;
    }
    finished[v]=1;
    stack.pop_back();
    return -1;
  };

  int p = dfs(dfs, 0);

  //REP(i,stack.size())cout << stack[i] << endl;

  vi cy(n);

  while(!stack.empty()){
    cy[stack.back()]=1;
    if(p == stack.back()){
      break;
    }
    stack.pop_back();
  }

  //REP(i,n)cout << cy[i] << endl;

  vi root(n);

  auto dfs2 = [&](auto dfs2, int rt, int v, int p = -1) -> void{
    root[v]=rt;
    for(auto nv: edge[v]){
      if(nv == p)continue;
      if(cy[nv])continue;
      dfs2(dfs2,rt,nv,v);
    }
  };

  REP(i,n){
    if(cy[i])dfs2(dfs2,i,i);
  }

  //for(auto x: root)cout << x << endl;

  int q;
  cin >> q;

  REP(_,q){
    int x,y;
    cin >> x >> y;
    x--; y--;

    cout << (root[x] == root[y] ? "Yes" : "No") << endl;
  }


}

