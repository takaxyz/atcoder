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

int n,m;
vvi edge;
vi visited;

int dfs(int v, set<int> st, int p = -1){
  int ret=0;
  cout << " " << v << endl;
  for(auto x: edge[v]){
    if(x==p)continue;
    if(visited[x] || st.count(x)){
      ret = 1;
    }else{
      st.insert(x);
      int tmp = dfs(x, st, v);
      if(tmp)ret=1;
      st.erase(st.find(x));
    }
  }
  if(ret)visited[v]=1;
  return ret;
}

int main(){
  cin >> n >> m;
  edge.resize(n);
  REP(_,m){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].push_back(v);
  }

  visited.resize(n);
  REP(i,n)visited[i]=0;

  REP(i,n){
    set<int> st;
    st.insert(i);
    if(visited[i]==0)dfs(i, st);
  }

  REP(i,n){
    cout << visited[i] << endl;
  }
}

