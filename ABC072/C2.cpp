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
  vector<int> c(100001,0);

  REP(i,N){
    int a;
    cin >> a;
    c[a]++;
  }

  int ans = c[0]+c[1]+c[2];
  int tmp = ans;
  FOR(i,1,100001-3){
    tmp-=c[i-1];
    tmp+=c[i+2];
    ans=max(ans,tmp);
  }
  cout << ans << endl;

}

