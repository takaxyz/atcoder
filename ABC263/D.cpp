#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

int main(){
  int n;
  ll l, r;
  cin >> n >> l >> r;
  vector<ll> a(n);
  ll sum=0;
  REP(i,n){
    cin >> a[i];
    sum += a[i];
  }

  vector<ll> L(n);
  REP(i,n){
    L[i] += l - a[i];
    if(i>0)L[i] += L[i-1];
  }
  // for(auto x: L){
  //   cout << x << endl;
  // }
  vector<ll> R(n);
  vector<ll> Rmin(n);
  ll mn = 0;
  for(int i = n-1; i >=0; i--){
    R[i] += r - a[i];
    if(i<n-1)R[i] += R[i+1];
    chmin(mn, R[i]);
    Rmin[i]=mn;
  }
  // for(auto x: R){
  //   cout << x << endl;
  // }
  // for(auto x: Rmin){
  //   cout << x << endl;
  // }

  ll x = Rmin[0];
  REP(i,n){
    if(i < n - 1)chmin(x, L[i] + Rmin[i+1]);
    else chmin(x, L[i]);
  }
  cout << min(sum + x,sum) << endl;
}

