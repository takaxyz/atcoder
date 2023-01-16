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

vvi edge;
ll n,m;
vi visited;


int c[200001];


bool dfs(int v, int color, vector<ll>& cnt, int& e){
  c[v] = color;
  cnt[color]++;
  e += edge[v].size();

  for(auto nx: edge[v]){
    if(c[nx]==color)return false;


    if(c[nx]==-1 && !dfs(nx, color^1, cnt, e)){
      return false;
    }
  }
  return true;
}



int main(){
  ll n,m;


  cin >> n >> m;


  edge.resize(n);
  visited.resize(n);
  REP(i,n)visited[i]=0;
  REP(i,n)c[i]=-1;

  REP(i,m){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  ll ans = n * (n-1) /2;


  REP(i,n){
    if(c[i]!=-1)continue;

    vector<ll> cnt(2,0);
    int e=0;
    if(!dfs(i, 0, cnt, e)){
      cout << 0 << endl;
      return 0;
    }
    ans -= cnt[0] * (cnt[0]-1)/2;
    ans -= cnt[1] * (cnt[1]-1)/2;

  }
  ans -= m;

  cout << ans << endl;

}

