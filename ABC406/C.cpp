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
  vi p(n);
  REP(i,n)cin >> p[i];

  vector<P> vs;
  FOR(i,1,n-1){
    if(p[i-1] < p[i] && p[i] > p[i+1]){
      vs.emplace_back(0,i);
    }else if(p[i-1] > p[i] && p[i] < p[i+1]){
      vs.emplace_back(1,i);
    }
  }
  if(vs.size() < 2){
    cout << 0 << endl;
    return 0;
  }
//  for(auto [x,i]: vs)cout << x << " " << i << endl;
  ll ans = 0;
  REP(i,vs.size()-1){
    if(vs[i].first == 0 && vs[i+1].first == 1){
      ll l, r;
      if(i == 0)l = vs[i].second;
      else l = vs[i].second - vs[i-1].second;
    
      if(i+1 == vs.size()-1)r = n - 1 - vs[i+1].second;
      else r = vs[i+2].second - vs[i+1].second;

      ans += r*l;
      // cout << i << endl;
    }
  }
  cout << ans << endl;
}

