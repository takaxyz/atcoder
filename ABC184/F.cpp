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

vector<ll> solve(vector<ll> &v){
  int n = v.size();
  vector<ll> w;
  REP(i, 1<<n){
    ll now=0;
    REP(j,n){
      if(i>>j & 1){
        now += v[j];
      }
    }
    w.emplace_back(now);
  }
  sort(ALL(w));
  return w;
} 


int main(){
  int n,t;
  cin >> n >> t;

  vector<ll> v1(n/2), v2((n+1)/2);
  REP(i,n/2){
    cin >> v1[i];
  }
  REP(i,(n+1)/2){
    cin >> v2[i];
  }
  vector<ll> w1 = solve(v1);
  vector<ll> w2 = solve(v2);

  // REP(i,w1.size()){
  //   cout << w1[i] << (i==w1.size()-1 ? "\n" : " ");
  // }
  // REP(i,w2.size()){
  //   cout << w2[i] << (i==w2.size()-1 ? "\n" : " ");
  // }

  ll ans = 0;
  for(auto x: w1){
    ll now = x;
    if(now>t)continue;
    auto iter = upper_bound(ALL(w2), t-now);
    iter--;

    chmax(ans, now+(*iter));
  }

  cout << ans << endl;
}

