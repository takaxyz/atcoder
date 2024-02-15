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
  vector<ll> dp(n,LINF);
  dp[0]=0;

  vector<ll> a(n-1),b(n-1);
  vi x(n-1);
  REP(i,n-1){
    cin >> a[i] >> b[i] >> x[i];
    x[i]--;
  }

  priority_queue< pair<ll,int>, vector< pair<ll,int> >, greater< pair<ll,int> > > que;

  vector<ll> dist(n,LINF);

  dist[0]=0;

  que.emplace(0, 0);
  while(!que.empty()) {
    auto [cost, idx] = que.top();
    que.pop();
    if(idx == n-1)continue;
    if(dist[idx] < cost) continue;

    // idx + 1
    int nx = idx+1;
    ll next_cost = cost + a[idx];
    if(dist[nx] > next_cost){
      dist[nx] = next_cost;
      que.emplace(dist[nx], nx);
    }

    nx = x[idx];
    next_cost = cost + b[idx];
    if(dist[nx] > next_cost){
      dist[nx] = next_cost;
      que.emplace(dist[nx], nx);
    }
  }

  cout << dist[n-1] << endl;
}

