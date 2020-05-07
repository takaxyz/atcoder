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
  int N,Y;
  cin >> N >> Y;
  Y /= 1000;

  REP(i,N+1)FOR(j,0,N+1-i){
    int k = N-i-j;
    if(i*10 + j*5 + k == Y){
      printf("%d %d %d\n",i,j,k);
      exit(0);
    }
  }
  cout << "-1 -1 -1" << endl;
}

