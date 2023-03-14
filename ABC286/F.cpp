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
  vector<ll> m = {4,5,7,9,11,13,17,19,23};
  const int M=108;

  cout << M << endl;
  int s = 0;
  REP(i,9){
    REP(j, m[i]){
      cout << (j + 1) % m[i] + 1 + s << " ";
    }
    s += m[i];
  }
  cout << endl;
  fflush(stdout);

  vi b(M);
  REP(i,M)cin >> b[i];

  vector<ll> c(9);
  s = 0;
  for(int i = 0, j = 0; i < m.size(); j += m[i++]){
    c[i] = b[j] - 1 - s;
    s += m[i];
  }
  auto [y,z] = crt(c, m);
  cout << y << endl;
  fflush(stdout);
}

