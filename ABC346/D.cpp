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
  string s;
  cin >> s;
  vector<ll> c(n);
  REP(i,n)cin >> c[i];

  ll now01 = 0,now10 = 0;
  vector<ll> f01(n+1),f10(n+1);
  REP(i,n){
    if(i%2==0){
      if(s[i]=='1')now01 += c[i];
      f01[i+1] = now01;
      if(s[i]=='0')now10 += c[i];
      f10[i+1] = now10;
    }else{
      if(s[i]=='1')now10 += c[i];
      f10[i+1] = now10;
      if(s[i]=='0')now01 += c[i];
      f01[i+1] = now01;
    }
  }
  // REP(i,n+1){
  //   cout << f01[i] << (i==n ? "\n" : " ");
  // }
  // REP(i,n+1){
  //   cout << f10[i] << (i==n ? "\n" : " ");
  // }

  vector<ll> g01(n+1),g10(n+1);
  now01 = 0; now10=0;
  for(int i = n-1; i>=0; i--){
    if(i%2==0){
      if(s[i]=='1')now01 += c[i];
      g01[i] = now01;
      if(s[i]=='0')now10 += c[i];
      g10[i] = now10;
    }else{
      if(s[i]=='1')now10 += c[i];
      g10[i] = now10;
      if(s[i]=='0')now01 += c[i];
      g01[i] = now01;
    }
  }


  // REP(i,n+1){
  //   cout << g01[i] << (i==n ? "\n" : " ");
  // }
  // REP(i,n+1){
  //   cout << g10[i] << (i==n ? "\n" : " ");
  // }

  ll ans=LINF;
  FOR(i,1,n)chmin(ans, f01[i]+g10[i]);
  FOR(i,1,n)chmin(ans, f10[i]+g01[i]);

  cout << ans << endl;

}

