#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e18;
const int INF=(1<<30);




int main(){
  int N;
  cin >> N;
  vector<double> t(N+3);
  vector<double> v(N+2);

  t[0]=0; t[1]=0;
  v[0]=0;

  int t_max = 0;
  REP(i,N){
    cin >> t[i+2];
    t[i+2] += t[i+1];
  }
  REP(i,N){
    cin >> v[i+1];
  }

  t[N+2]=t[N+1];
  v[N+1]=0;


  vector<double> v_list;
  for(double i = 0; i <= t[N+2]; i+=0.5){
    double tmp=1000000;

    REP(j,N+2){
      if(i < t[j]){
        tmp = min(tmp,v[j]+(t[j]-i));
      }else if(i >= t[j] && i <= t[j+1]){
        tmp = min(tmp,v[j]);
      }else{
        tmp = min(tmp,v[j] + (i-t[j+1]));
      }
    }
    v_list.push_back(tmp);
  }

  double ans = 0;
  REP(i,v_list.size()-1){
    ans += (v_list[i]+v_list[i+1])*0.25;
  }
  printf("%f\n",ans);
}

