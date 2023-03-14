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
  int n;
  cin >> n;
  vi a(n);
  REP(i,n)cin >> a[i];

  vi dp1(n,INF);
  vi p(n);
  REP(i,n){
    auto it = lower_bound(ALL(dp1), a[i]);
    *it = a[i];
    p[i] =  it - dp1.begin() + 1;
  }

  vi dp2(n,INF);
  vi q(n);
  REP(i,n){
    auto it = lower_bound(ALL(dp2), a[n-i-1]);
    *it = a[n-i-1];
    q[n-i-1] =  it - dp2.begin() + 1;
  }

  int ans=0;
  REP(i,n){
    chmax(ans, p[i]+q[i]-1);
  }
  cout << ans << endl;




}

