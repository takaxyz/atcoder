#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);
//const int INF=(1<<29);

int main(){
  int x,y;
  cin >> x >> y;

  int N;
  cin >> N;
  VI X(N), Y(N);

  REP(i,N){
    cin >> X[i] >> Y[i];
  }
  X.emplace_back(X[0]);
  Y.emplace_back(Y[0]);

  double ans = 100000000;
  REP(i,N){
    complex<double> c1(X[i],Y[i]);
    complex<double> c2(X[i+1],Y[i+1]);
    complex<double> c3(x,y);

    c2 -= c1;
    c3 -= c1;

    c3 = c3 / (c2 / abs(c2));
    chmin(ans, c3.imag());
  }
  cout << setprecision(8) << ans << endl;
}

