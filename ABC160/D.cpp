#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int N,X,Y;
  cin >> N >> X >> Y;

  VI ans(N,0);
  FOR(i,1,N){
    ans[i] = N-i; 
  }

  FOR(i,1,N+1){
    FOR(j,i+1,N+1){
      if(abs(X-i) + abs(Y-j)+1 < j-i){
        ans[j-i]-=1;
        ans[abs(X-i) + abs(Y-j)+1]+=1;
      }
    }
  }
  FOR(i,1,N){
    cout << ans[i] << endl;
  }

}

