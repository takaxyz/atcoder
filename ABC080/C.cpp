#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int N;
  cin >> N;
  int F[100][10];
  REP(i,N)REP(j,10)cin >> F[i][j];

  int P[100][11];
  REP(i,N)REP(j,11)cin >> P[i][j];

  int ans = -(1<<30);
  FOR(i,1,1024){
    int t = i;
    int tmp = 0;
    // j: お店
    REP(j,N){
      int cnt=0;
      // k: 時間帯
      REP(k,10)
      if((i>>k) & 1){
        if(F[j][k])cnt++;
      }
      tmp += P[j][cnt]; 
    }
    ans = max(ans,tmp);
  }

  cout << ans << endl;
}

