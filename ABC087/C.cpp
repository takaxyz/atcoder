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

  vector<int> a1(N+1,0);
  vector<int> a2(N+1,0);


  REP(i,N){
    int t;
    cin >> t;
    a1[i+1] = a1[i] + t;
  }
  REP(i,N){
    int t;
    cin >> t;
    a2[i+1] = a2[i] + t;
  }

  int ans=0;
  REP(i,N){
    ans=max(ans, a1[i+1] + a2[N]-a2[i]);
  }
  cout << ans << endl;


}


