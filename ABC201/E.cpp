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
vector<vector<pair<int, ll>>> edge;

int dfs(int p, int u){
  int ret=1;  
  for(auto v: edge[u]){
    if(v==p)continue;
    ret+=dfs(u, v);
  }
  printf("%d %d: %d\n", p,u, ret);
  return ret;
}

int main(){
  cin >> n;
  edge.resize(n+1);
  REP(i,n-1){
    int u,v; ll w;
    cin >> u >> v >> w;
    edge[u].emplace_back(v,w);
    edge[v].emplace_back(u,w);
  }

  int ans=0;

  for(auto m: edge[1]){
    int v = m.first;
    ll w = m.second;
    int x = dfs(1, v);
    if(x * (n-x) % 2 == 0){
      ans += 
    }else{

    }
  }
}

