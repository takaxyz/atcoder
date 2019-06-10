#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<iomanip>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int main(){

  int N,K;
  cin >> N >> K;

  double ans = 0;

  FOR(i,1,N+1){
    int t = i;
    double s = 1.0/N;
    while(t < K){
      s *= 0.5;
      t = t << 1;
    }
    ans += s;
  }

  cout << setprecision(12) << ans << endl;
}
