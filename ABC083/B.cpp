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
  int N,A,B;

  cin >> N >> A >> B;
  int ans=0;
  FOR(i,1,N+1){
    int n=i;
    int t=0;
    while(n>0){
      t += n%10;
      n /= 10;
    }
    if(A <= t && t <= B){
      ans+=i;
    }
  }
  cout << ans << endl;
}

