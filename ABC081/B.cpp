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

  int ans = (1<<10);
  REP(i,N){
    int a;
    cin >> a;
    int cnt = 0;
    while(a%2==0){
      a/=2;
      cnt++;
    }
    ans=min(ans,cnt);
  }
  cout << ans << endl;
}

