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
//using P = pair<int,int>;
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

struct P {
  double x, y;
};

int n;
vector<P> p;

double dist(P s, P t){
  return sqrt((s.x - t.x) * (s.x - t.x) + (s.y - t.y) * (s.y - t.y));
}

double g(double x, double y){
  double ret = 0;
  REP(i,n){
    chmax(ret, dist({x,y}, p[i]));
  }
  return ret;
}

double f(double x){
  double lb = 0;
  double ub = 1000;

  REP(i,200){
    double t1 = (2.0 * lb + ub) / 3.0;
    double t2 = (lb + 2 * ub) / 3.0;
    if(g(x,t1) > g(x,t2))lb=t1;
    else ub=t2;
  }
  return g(x, lb);
}

int main(){
  cin >> n;
  p.resize(n);
  REP(i,n){
    cin >> p[i].x >> p[i].y;
  }

  double lb = 0;
  double ub = 1000;

  REP(i,200){
    double t1 = (2.0 * lb + ub) / 3.0;
    double t2 = (lb + 2 * ub) / 3.0;
    if(f(t1) > f(t2))lb=t1;
    else ub=t2;
  }

  printf("%.8f\n", f(lb));
}

