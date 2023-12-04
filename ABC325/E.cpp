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
const int MOD = 1e9 + 7;

int main(){
  int n;
  ll a,b,c;
  cin >> n >> a >> b >> c;
  vector<vector<ll>> d(n,vector<ll>(n));
  REP(i,n)REP(j,n)cin >> d[i][j];

  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;

  vector<ll> dist(2*n,LINF);
  q.push({0,0});
  dist[0]=0;

  while(!q.empty()){
    auto [dst,v] = q.top();
    q.pop();
    if(dist[v] < dst)continue;

    if(v < n){
      REP(nv,n){
        if(nv == v)continue;
        ll cost = d[v][nv] * a;
        if(dist[nv] > dist[v] + cost){
          dist[nv] = dist[v] + cost;
          q.push({dist[v]+ cost, nv});
        }
      }
      REP(nv,n){
        if(nv == v)continue;
        ll cost = d[v][nv] * b + c;
        int nv2 = nv + n;
        if(dist[nv2] > dist[v] + cost){
          dist[nv2] = dist[v] + cost;
          q.push({dist[v]+ cost, nv2});
        }
      }
    }else{
      int v2 = v - n;
      REP(nv,n){
        if(nv == v2)continue;
        ll cost = d[v2][nv] * b + c;
        int nv2 = nv + n;
        if(dist[nv2] > dist[v] + cost){
          dist[nv2] = dist[v] + cost;
          q.push({dist[v]+ cost, nv2});
        }
      }
    }
  }

  cout << min(dist[n-1],dist[2*n-1]) << endl;
}

