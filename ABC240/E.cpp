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
int n;
int ans=0;
vector<P> t;

P dfs(int v, int p=-1){
  int cnt=0;

  int mx = -1;
  int mi = INF;
  for(auto nv: edge[v]){
    if(nv==p)continue;
    cnt++;
    P ret = dfs(nv, v);
    chmin(mi, ret.first);
    chmax(mx, ret.second);
  }
  if(cnt==0){
    ans++;
    t[v]=make_pair(ans,ans);
  }else{
    t[v]=make_pair(mi,mx);
  }
  return t[v];
}

int main(){
  cin >> n;
  edge.resize(n);
  t.resize(n);
  REP(i,n-1){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  dfs(0);
  REP(i,n){
    cout << t[i].first << " " << t[i].second << endl;
  }


}

