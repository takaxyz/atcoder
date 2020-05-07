#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int c[3][3];
int a[3];
int b[3];

int main(){
  REP(i,3)REP(j,3)cin >> c[i][j];

  a[0]=0;

  REP(i,3)b[i]=c[0][i]-a[0];
  FOR(i,1,3)a[i]=c[i][0]-b[0];

  bool ok=true;
  FOR(i,1,3)FOR(j,1,3){
    if(c[i][j] != a[i]+b[j]){
      ok=false;
      break;
    }
  }

  if(ok){
    cout << "Yes" << endl;
    exit(0);
  }

  cout << "No" << endl;

}

