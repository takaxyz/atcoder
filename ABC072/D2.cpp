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
  vector<int> p(N+1);

  REP(i,N)cin >> p[i+1];

  int i = 1;
  int ans = 0;
  while(i<N+1){
    if(p[i]==i){
      ans++;
      i += 2;
    }else{
      i++;
    }
  }
  cout << ans << endl;
}

