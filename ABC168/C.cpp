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

int main(){
  double a,b,h,m;
  cin >> a >> b >> h >> m;

  double h_rad = M_PI * 2.0 * (h * 60 + m)  / 720;
  double m_rad = M_PI * 2.0 * m / 60;

  double ans = sqrt(a * a + b * b - 2.0 * a * b * cos(m_rad - h_rad));

  printf("%0.20f\n",ans);
}

