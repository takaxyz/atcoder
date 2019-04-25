#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
#include<iomanip>
#include <queue>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
#define MAXS(x,y) (x = max(x,y))
#define MINS(x,y) (x = min(x,y))

using namespace std;

typedef long long int ll;
typedef pair<int,int> PI;
typedef pair<ll,ll>   PL;
typedef vector<PI>    VIP; 
typedef vector<int>   VI;
typedef vector<VI>    VVI;


const ll INF=(ll)1e18;

int N,M;
ll T;

struct edge{
    int to;
    int cost;
};


vector<ll> solve(vector<vector<edge> > g){
  priority_queue< PL, vector<PL>, greater<PL> > que;
  vector<ll> dist(g.size(),INF);

  dist[0] = 0;
  que.push(PL(0,0));
  while(!que.empty()){
    PL p = que.top();
    que.pop();

    int v = p.second;
    ll cost = p.first;
    if(dist[v] < cost) continue;
    REP(i,g[v].size()){
      edge e = g[v][i];
      if(dist[e.to] > dist[v] + e.cost){
        dist[e.to] = dist[v] + e.cost;
        que.push(PL(dist[e.to], e.to));
      }
    }

  }
  return dist;
}

int main(){
  cin >> N >> M >> T;

  VI a(N);
  
  vector<vector<edge> > g1(N,vector<edge>());
  vector<vector<edge> > g2(N,vector<edge>());

  REP(i,N) cin >> a[i];

  REP(i,M){
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    edge e1 = {b,c};
    edge e2 = {a,c};
    g1[a].push_back(e1);
    g2[b].push_back(e2);
  }

  vector<ll> d1 = solve(g1);
  vector<ll> d2 = solve(g2);


  // REP(i,d1.size())cout << d1[i] << " ";
  // cout << endl;
  // REP(i,d2.size())cout << d2[i] << " ";
  // cout << endl;

  ll ans = 0;
  REP(i,N){
    if(d1[i]==INF)continue;
    if(T<=d1[i]+d2[i])continue;

    ans = max(ans, (T-d1[i]-d2[i])*a[i]);

  }
  cout << ans  << endl;
}