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

//using mint = modint1000000007;
using mint = modint998244353;

int main(){
  int n,m;
  cin >> n >> m;

  vector<mint> a(n+1),b(m+1);
  REP(i,n){
    int x;
    cin >> x;
    a[i+1] = x; 
  }
  REP(i,m){
    int x;
    cin >> x;
    b[i+1] = x; 
  }
  
  mint ans=0;

  mint aa=0;
  FOR(i,1,n+1)aa += a[i] * i;
  FOR(i,1,m+1)ans += aa * b[i];

  vector<mint> sa(n+2);
  REP(i,n+1)sa[i+1] = sa[i]+ a[i];
  FOR(i,1,m+1){
    int l = 0;
    while(l <= n){
      ans -= (sa[min(n+1,l+i)]-sa[l])*l*b[i];
      l += i;
    }
  }

  cout << ans.val() << endl;
}

