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
  int H,W;
  cin >> H >> W;
  
  char s[50][50];

  REP(i,H)REP(j,W)cin >> s[i][j];

  int dx[] = {1,1,1,0,0,-1,-1,-1};
  int dy[] = {0,1,-1,1,-1,0,-1,1};

  int c[50][50];
  REP(i,H)REP(j,W)c[i][j] = 0;

  REP(i,H)REP(j,W){
    if(s[i][j]=='#')continue;

    REP(k,8){
      int ii = i + dx[k];
      int jj = j + dy[k];

      if(ii < 0 || ii >= H)continue;
      if(jj < 0 || jj >= W)continue;

      if(s[ii][jj]=='#')c[i][j]++;
    }
  }

  REP(i,H){
    REP(j,W){
      if(s[i][j]=='#'){
        cout << '#';
      }else{
        cout << c[i][j];
      }
    }
    cout << endl;
  }

}

