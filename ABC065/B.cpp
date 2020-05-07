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

  vector<int> a(N+1);
  vector<bool> v(N+1,false);
  REP(i,N)cin>>a[i+1];

  int t=1;
  int ans=0;
  while(t!=2 && v[t] == false){
    v[t] = true;
    t=a[t];
    ans++;
  }

  if(t==2){
    cout << ans << endl;
  }else{
    cout << -1 << endl;
  }

}

