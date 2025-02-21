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

map<int, int > prime_factor(int n) {
  map<int, int > ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main(){
  int n,K;
  cin >> n >> K;

  vi a(n);
  REP(i,n)cin >> a[i];

  map<int,vi> mp;
  vector<map<int,int>> pfs(n);
  REP(i,n){
    pfs[i] = prime_factor(a[i]);
    for(auto [k,v]: pfs[i]){
      mp[k].pb(v);
    }

  }
  // for(auto [k,v]: mp){
  //   cout << k  << ":" << endl;
  //   for(auto x: v){
  //     cout << x << " ";
  //   }
  //   cout << endl;

  // }

  for(auto [k,v]: mp){
    sort(ALL(mp[k]));
    reverse(ALL(mp[k]));
  }

  REP(i,n){
    int ans=1;
    for(auto [k,v] : pfs[i]){
      if(mp[k].size() < K)continue;

      REP(_,min(v,mp[k][K-1]))ans *= k;
    }
    cout << ans << endl;


  }

}

