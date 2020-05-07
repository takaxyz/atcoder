#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int n, m;
  cin >> n >> m;

  vector<int> a(n,-1);

  REP(i,m){
    int s,c;
    cin >> s >> c;
    s--;
    if(a[s]==-1){
      a[s]=c;
    }else if(a[s] != c){
      cout << -1 << endl;
      exit(0);
    }
  }

  if(n !=1 && a[0]==0){
    cout << -1 << endl;
    exit(0);
  }else if(n !=1 && a[0]==-1){
    a[0]=1;
  }

  int ans = 0;
  REP(i,n){
    ans *= 10;
    if(a[i]==-1){      
    }else{
      ans += a[i];
    }
  }

  cout << ans << endl;


}

