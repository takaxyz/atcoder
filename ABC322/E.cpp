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
  int n,k,p;
  cin >> n >> k >> p;
  vi c(n);
  vvi a(n,vi(k));
  REP(i,n){
    cin >> c[i];
    REP(j,k){
      cin >> a[i][j];
    }
  }

  map<vi,ll> dp;
  dp[vi(k)] = 0;

  REP(i,n){
    map<vi,ll> old;
    swap(old,dp);

    for(auto [d, v]: old){
      vi dd(k);
      REP(j,k)dd[j] = min(d[j] + a[i][j],p);
      if(dp.count(dd)){
        chmin(dp[dd], v + c[i]);
      }else{
        dp[dd] = v + c[i];        
      }
      if(dp.count(d)){
        chmin(dp[d], v);
      }else{
        dp[d]=v;
      }
    }
  }

  ll ans=LINF;
  for(auto [d,v]: dp){
    bool ok=true;
    for(auto kk: d){
      if(kk < p)ok=false;
    }
    if(ok)chmin(ans,v);

  }
  cout << (ans == LINF ? -1 : ans) << endl;

}

