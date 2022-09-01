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

template< typename T >
vector<T> get_divisor(T n){
  vector<T> ret;

  for(T i = 1; i*i <= n; i++){
    if(n%i==0){
      ret.push_back(i);
      if(i*i != n) ret.push_back(n/i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}


int main(){
  int n,k;
  cin >> n >> k;
  vi a(n);
  REP(i,n)cin >> a[i];

  int sum = 0;
  REP(i,n)sum += a[i];

  auto ds = get_divisor(sum);
  reverse(ALL(ds));
  for(auto d : ds){

    vi ls(n+1), rs(n+1);

    vi m(n);
    REP(i,n)m[i] = a[i] % d;

    sort(ALL(m));

    REP(i,n){
      ls[i+1] = ls[i] + m[i];
    }

    REP(i,n){
      rs[n-i-1] = rs[n-i] + (d - m[n-1-i]);
    }

    FOR(i,1,n+1){
      if(ls[i]==rs[i] && ls[i] <= k){
        cout << d << endl;
        return 0;
      }
    }

  }
}

