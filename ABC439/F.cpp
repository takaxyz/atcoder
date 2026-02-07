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
  int n;
  cin >> n;

  vi p(n);
  REP(i,n){
    cin >> p[i];
    p[i]--;
  }

  fenwick_tree<int> fw(n);

  vi a(n), b(n);
  for(int i = 0; i < n; i++){
    a[i] = fw.sum(0,p[i]);
    fw.add(p[i],1);
  }

  fw = fenwick_tree<int>(n);
  for(int i = n-1; i >= 0; i--){
    b[i] = fw.sum(0,p[i]);
    fw.add(p[i],1);
  }
//  REP(i,n)cout << a[i] << (i==n-1 ? "\n" : " ");
//  REP(i,n)cout << b[i] << (i==n-1 ? "\n" : " ");

  mint ans = 0;

  REP(i,n){
    ans += mint(a[i]) * b[i];
  }

  mint s = 0;
  REP(i,n){
    ans += s * b[i];
    s = s*2 + a[i];
  }
  cout << ans.val() << endl;

}

