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
  int n,m;
  cin >> n >> m;
  vi x(m);
  REP(i,m){
    cin >> x[i];
    x[i]--;
  }

  // 時計回り
  auto dist1 = [&](int x, int y){
    return abs(x-y);
  };

  // 反時計回り
  auto dist2 = [&](int x, int y){
    return n - abs(x-y);
  };

  ll ans=0;
  REP(i,m-1){
    ans += dist1(x[i+1], x[i]);
  }

  vector<ll> v(n+1);
  REP(i,m-1){
    ll s = dist2(x[i+1], x[i]) - dist1(x[i+1], x[i]);
    int mi = min(x[i+1], x[i]);
    int mx = max(x[i+1], x[i]);
    v[mi] += s;
    v[mx] -= s;
  }

  ll tmp=ans;
  REP(i,n){
    tmp += v[i];
    chmin(ans, tmp);
    //cout << ans << endl;
  }


  cout << ans << endl;
}

