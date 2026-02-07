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

void solve(){
  int n;
  cin >> n;
  vi r(n);
  REP(i,n)cin >> r[i];
  vi org = r;


  priority_queue<P,vector<P>,greater<P>> q;
  REP(i,n)q.push({r[i],i});

  vi visited(n);
  while(q.size()){
    auto [x,v] = q.top();
    q.pop();

    if(visited[v])continue;
    visited[v] = 1;

    for(int i = -1; i < 2; i+=2){
      int nv = v + i;
      if(nv < 0 || nv >= n)continue;
      if(visited[nv])continue;

      if(r[v] == r[nv]){
        q.push({r[nv], nv});
      }else if(r[v] < r[nv]){
        r[nv] = r[v]+1;
        q.push({r[nv],nv});
      }
    }
  }
//  REP(i,n)cout << r[i] << (i==n-1 ? "\n" : " ");
  ll ans=0;
  REP(i,n)ans += (ll)abs(r[i]-org[i]);
  cout << ans << endl;
//  cout << endl;
}


int main(){
  int t;
  cin >> t;
  REP(_,t)solve();
}

