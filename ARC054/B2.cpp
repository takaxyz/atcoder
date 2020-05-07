#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

double f(double p, double t){
  return t+p/pow(2.0, 2.0/3.0*t);
}

int main(){
  double p;
  cin >> p;

  double lb = 0;
  double ub = p;
  REP(i,200){
    double t1 = (2.0 * lb + ub) / 3.0;
    double t2 = (lb + 2 * ub) / 3.0;

    if(f(p,t1) > f(p,t2))lb=t1;
    else ub=t2;
  }

  printf("%0.8f\n", f(p,lb));

}

