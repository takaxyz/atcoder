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
  
  vector<ll> vs;
  vector<ll> x(n),r(n);
  REP(i,n){
    cin >> x[i] >> r[i];
    vs.pb(x[i]+r[i]);
    vs.pb(x[i]-r[i]);
  }
  sort(ALL(vs));
  vs.erase(unique(ALL(vs)),vs.end());

  int sz = vs.size();
  vvi edge(sz);

  REP(i,n){
    int a = lower_bound(ALL(vs), x[i]+r[i]) - vs.begin();
    int b = lower_bound(ALL(vs), x[i]-r[i]) - vs.begin();
    edge[a].pb(b);
    edge[b].pb(a);
  }

  vi visited(sz);

  int ans=0;
  REP(i,sz)if(!visited[i]){
    int cnt_v=0;
    int cnt_e=0;
    auto dfs = [&](int v, auto dfs) -> void{
      visited[v]=1;
      cnt_v++;
      cnt_e += edge[v].size();
      for(auto nv : edge[v]){
        if(visited[nv])continue;
        dfs(nv,dfs);
      }
    };

    dfs(i,dfs);

    cnt_e /= 2;

    if(cnt_e == cnt_v - 1){
      ans+= cnt_v - 1;
    }else{
      ans+= cnt_v;
    }

  }

  cout << ans << endl;



}

