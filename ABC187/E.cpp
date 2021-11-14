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

vi depth;
vvi edge;
vector<ll> cost;
vector<ll> ans;

void dfs(int v, int p=-1, int d=0){
  depth[v]=d;
  for(auto x: edge[v]){
    if(x==p)continue;
    dfs(x,v,d+1);
  }
}

void dfs2(int v, int p=-1, ll c=0){
  c += cost[v];
  ans[v] = c;
  for(auto x: edge[v]){
    if(x==p)continue;
    dfs2(x,v,c);
  }
}

int main(){
  int n;
  cin >> n;
  edge.resize(n);

  vector<P> es;
  REP(i,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
    es.emplace_back(a,b);
  }

  depth.resize(n);
  dfs(0);

  cost.resize(n);

  int q;
  cin >> q;
  REP(i,q){
    int t,e;
    ll x;
    cin >> t >> e >> x;
    e--;
    int a,b;
    a = es[e].first;
    b = es[e].second;
    if(t==2)swap(a,b);

    if(depth[a] < depth[b]){
      cost[0]+=x;
      cost[b]-=x;
    }else{
      cost[a]+=x;
    }
  }


  ans.resize(n);
  dfs2(0);

  REP(i,n){
    cout << ans[i] << endl;
  }
}

