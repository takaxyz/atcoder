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
  double c;
  cin >> n >> c;

  vector<double> x(n),y(n);
  REP(i,n)cin >> x[i] >> y[i];


  double lb = -1000000;
  double ub = 1000000;

  auto f = [&](double v) {
    double res=0;
    REP(i,n){
      res += (v - x[i])*(v - x[i]) + (c - y[i])*(c - y[i]);
    }
    return res;

  };

  // ループの回数は探索範囲次第
  REP(i,200){
    double t1 = (2.0 * lb + ub) / 3.0;
    double t2 = (lb + 2 * ub) / 3.0;
    // 下に凸の場合
    if(f(t1) > f(t2))lb=t1;
    else ub=t2;
  }

  printf("%.9f\n",f(lb));

}

