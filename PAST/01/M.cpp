#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()

#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);

int N,M;

bool check(vector<int> a,vector<int> b,vector<int> c,vector<int> d, double t){
  vector<double> s, ss;

  REP(i,N){
    s.push_back(b[i]-t*a[i]);
  }
  REP(i,M){
    ss.push_back(d[i]-t*c[i]);
  }
  sort(ALL(ss),std::greater<double>());
  s.push_back(ss[0]);
  sort(ALL(s), std::greater<double>());

  double tmp = 0;
  REP(i,5){
    tmp += s[i];
  }


  return tmp >= 0;
}


int main(){
  cin >> N >> M;
  vector<int> A(N),B(N),C(M),D(M);

  REP(i,N)cin >> A[i] >> B[i];
  REP(i,M)cin >> C[i] >> D[i];

  double l = 0;
  double r = 1e9;

  REP(i,100){
    double m = (l+r)/2;
    if(check(A,B,C,D,m)){
      l=m;
    }else{
      r=m;
    }
  }
  cout << fixed << setprecision(10) << l << endl;

}

