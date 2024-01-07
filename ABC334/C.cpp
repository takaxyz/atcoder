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
  int n,k;
  cin >> n >> k;
  vi a(k);
  REP(i,k)cin >> a[i];

  if(k==1){
    cout << 0 << endl;
    return 0;
  }

  if(k%2==0){
    ll ans=0;
    REP(i,k/2)ans += a[2*i+1] - a[2*i];
    cout << ans << endl;
  }else{
    vector<ll> b(k-1);
    REP(i,k-1)b[i] = a[i+1]-a[i];

    // REP(i,k-1)cout << i << " -  " << b[i] << endl;

    vector<ll> x(k/2+1), y(k/2+1);
    REP(i,k/2)x[i+1] = x[i]+b[i*2];
    REP(i,k/2)y[i+1] = y[i]+b[k-i*2-2];
    // REP(i,k/2+1)cout << i << " : " << x[i] << endl;
    // REP(i,k/2+1)cout << i << " :: " << y[i] << endl;

    ll ans=LINF;
    REP(i,k/2+1)chmin(ans, x[i]+y[k/2-i]);
    cout << ans << endl;
  }
}

