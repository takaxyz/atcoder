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
  string s;
  cin >> n >> s;

  vvi sum(3,vi(n+1));

  REP(i,n){
    REP(j,3)sum[j][i+1]=sum[j][i] + ((s[i]-'A') == j);
  }
  
  vector mp(3, map<int,int>());

  REP(i,3)REP(j,n+1){
    mp[i][sum[i][j] - sum[(i+1)%3][j]]++;
  }

  ll ans = (ll)n*(n+1)/2;

  REP(i,3){
    for(auto [k,v]: mp[i]){
      ans -= (ll)v * (v-1) / 2;
    }
  }

  map<pair<int,int>, int> mp2;
  REP(i,n+1){
    mp2[{sum[0][i] - sum[1][i], sum[1][i] - sum[2][i]}]++;
  }


  for(auto [k,v]: mp2){
    ans += (ll)v * (v-1);
  }

  cout << ans << endl;

}

