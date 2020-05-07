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
  int N,Z,W;
  cin >> N >> Z >> W;
  vector<int> a(N);
  REP(i,N)cin >> a[i];

  if(N==1){
    cout << abs(a[N-1]-W) << endl;
  }else{
    cout << max(abs(a[N-1]-W), abs(a[N-2]-a[N-1])) << endl;
  }
}

