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

ll unimodalFunc(int t, ll c, ll d){
  return c + d / (1+t) + t;
}
ll findMaximal(int from, int to, int t, ll c, ll d) {




  ll d2 = (ll)floor(sqrt(d));

  if(from < d2)return unimodalFunc(from, c, d);

  ll ret = LINF;
  REP(i,10){
    chmin(ret, unimodalFunc(d2+i, c, d));
    if(d2-i>=0 && from<=d2-i)chmin(ret, unimodalFunc(d2-i, c, d));
  }

	return ret;
}

struct edge{
  int to; ll c; ll d;
};

vector<vector<edge>> E;

int main(){
  int n,m;
  cin >> n >> m;
  E.resize(n);
  REP(i,m){
    int a,b;
    ll c, d;
    cin >> a >> b >> c >> d;
    a--;b--;
    E[a].push_back({b,c,d});
    E[b].push_back({a,c,d});
  }
  vector< ll > dist(n, LINF);
  using Pi = pair< ll, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[0] = 0;
  que.emplace(dist[0], 0);
  while(!que.empty()) {
    ll cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : E[idx]) {
      
      auto next_cost = cost + findMaximal(cost, INF, cost, e.c, e.d);

      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  if(dist[n-1]==LINF){
    cout << -1 << endl;
  }else{
    cout << dist[n-1] << endl;
  }

}

