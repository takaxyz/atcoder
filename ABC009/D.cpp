#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
#include<iomanip>
#include <queue>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
#define MAXS(x,y) (x = max(x,y))
#define MINS(x,y) (x = min(x,y))

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int K, M;

void mul(uint a[100][100], uint b[100][100], uint ret[100][100]){
  uint tmp[100][100];
  REP(i,K)REP(j,K)tmp[i][j]=0;

  REP(i,K)REP(j,K)REP(k,K){
    tmp[i][j] ^= a[i][k] & b[k][j];
  }
  REP(i,K)REP(j,K){
    ret[i][j] = tmp[i][j];
  }

}

void power(uint a[100][100],int n, uint ret[100][100]){
  if(n==0){
    REP(i,K)REP(j,K){
      if(i==j)ret[i][j]=-1;
      else ret[i][j]=0;
    }
  }else{

    if(n%2==0){
      power(a,n/2,ret);
      mul(ret,ret,ret);
    }else{
      power(a,n-1,ret);
      mul(a,ret,ret);
    }
  }
}


int main(){
  cin >> K >> M;

  uint a[100];
  uint c[100][100];
  uint d[100][100];

  REP(i,K) cin >> a[i];
  REP(i,K) cin >> c[0][i];
  REP(i,K-1) c[i+1][i] = -1;

  if(M<=K){
    cout << a[M-1] << endl;
    return 0;
  }

  power(c,M-K,d);


  uint ans = 0;
  REP(i,K) ans ^= d[0][i] & a[K-1-i];
  // REP(i,K){
  //   REP(j,K){
  //     cout << d[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << ans << endl;

}