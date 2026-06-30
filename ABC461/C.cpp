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
  int n,k,m;
  cin >> n >> k >> m;

  vvi j(n);
  REP(_,n){
    int c,v;
    cin >> c >> v;
    c--;
    j[c].pb(v);
  }
  REP(i,n)sort(ALL(j[i]));

  vector<P> vs;
  REP(i,n){
    if(j[i].size()==0)continue;
    vs.pb({j[i].back(), i});
  }
  sort(RALL(vs));

  ll ans=0;
  REP(i,m){
    ans += vs[i].first;
    j[vs[i].second].pop_back();
  }

  vi j2;
  REP(i,n){
    for(auto x: j[i])j2.pb(x);
  }
  sort(RALL(j2));

  REP(i,k-m){
    ans += j2[i];
  }
  cout << ans << endl;

}

