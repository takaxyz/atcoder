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
  int n,m,q;
  cin >> n >> m >> q;
  vector<vector<pair<int,int>>> edge(n, vector<P>());
  REP(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    edge[a].pb({b,c});
    edge[b].pb({a,c});
  }
  vi x(q);
  REP(i,q)cin >> x[i];

  priority_queue<P,vector<P>,greater<P>> que;

  for(auto [to,c]: edge[0])que.push({c,to});

  vi visited(n);
  visited[0]=1;
  int ans=1;
  REP(i,q){
    vector<P> q2;
    while(!que.empty()){
      if(x[i] >= que.top().first){
        int v = que.top().second;
        que.pop();
        if(visited[v])continue;
        visited[v]=1;
        ans++;
        for(auto [to,c]: edge[v]){
          if(visited[to])continue;
          q2.push_back({c,to});
        }
      }else break;
    }
    cout << ans << endl;

    for(auto [c,to]: q2)que.push({c,to});
  }
}

