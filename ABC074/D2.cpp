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
  int N;
  cin >> N;

  vector<vector<int>> A(N,vector<int>(N));

  REP(i,N)REP(j,N){
    cin >> A[i][j];
  }

  vector<vector<bool>> e(N,vector<bool>(N,true));

  ll ans=0;
  REP(k,N)REP(i,N)REP(j,N){
    if(A[i][j] > A[i][k] + A[k][j]){
      cout << -1 << endl;
      exit(0);
    }

    if(A[i][j] == A[i][k] + A[k][j] && i != k && j != k){
      e[i][j] = false;
    }
  }

  REP(i,N)REP(j,N){
//    cout << i << " " << j << " " << e[i][j] << endl;
    if(i==j)continue;
    if(e[i][j])ans+=A[i][j];
  }


  cout << ans/2 << endl;
}


