#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
  int R,C,K;

  cin >> R >> C >> K;

  int c[500][500];
  char s[500][500];

  REP(i,500)REP(j,500)c[i][j]=0;
  
  REP(i,R){
    REP(j,C){
      char tmp;
      cin >> tmp;
      s[i][j] = tmp;
    }
  }

  REP(j,C)REP(i,R){
    if(s[i][j] == 'o'){
      if(i > 0){
        c[i][j] = c[i-1][j] + 1;
      }else{
        c[i][j] = 1;
      }
    }else{
      if(i > 0){
        c[i][j] = c[i-1][j];
      }
    }
  }

  int ans = 0;
  FOR(i,K-1,R-K+1){
    FOR(j,K-1,C-K+1){
      bool flag = true;
      FOR(l,-K+1,K){
        int m = K-abs(l);
        if(i - m < 0){
          if(c[i+m-1][j-l] < m*2-1){
            flag = false;
            break;
          }
        }else{
          if(c[i+m-1][j-l] - c[i-m][j-l] < m*2-1){
            flag = false;
            break;
          }
        }
      }
      if(flag)ans+=1;
    }
  }
  cout << ans << endl;
}
