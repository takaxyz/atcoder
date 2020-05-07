#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F;

  A*=100;
  B*=100;
  double tmp=-1;
  double lim=(double)E / (100+E);
  int ans_w=0;
  int ans_s=0;
  REP(a,F/A+1)REP(b,(F-a*A)/A+1)REP(c, (F-a*A-b*B)/C+1)REP(d, (F-a*A-b*B-c*C)/D+1){
    if(a+b==0 || a*A+b*B+C*c+D*d > F)continue;

    double s;
    s = (double)(c*C) + (double)(d*D);
    s /= (A*a + B*b + C*c + D*d);

    if(lim<s)continue;
    if(tmp<s){
      ans_w = A*a + B*b;
      ans_s = C*c + D*d;
      tmp=s;
    }

  }
  cout << ans_w + ans_s << " " << ans_s << endl;
}


