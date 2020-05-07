#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int d,g;
  cin >> d >> g;

  VI p(d),c(d);

  REP(i,d){
    cin >> p[i] >> c[i];
  }

  int ans = 10000000;

  REP(i,(1<<d)){
    int ii=i;

    int score=0;
    int cnt=0;
    int ma = -1;
    REP(j,d){
      if( (ii>>j) &1){
        score += 100*(j+1)*p[j]+c[j];
        cnt += p[j];
      }else{
        ma = j;
      }
    }

    if(score<g){
      if(((g-score)+(100*(ma+1))-1)/(100*(ma+1)) < p[ma]){
        cnt += ((g-score)+(100*(ma+1))-1)/(100*(ma+1));
        ans = min(ans,cnt);
      }
    }else{
      ans = min(ans,cnt);
    }
  }
  cout << ans << endl;
}


