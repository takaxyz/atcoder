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
  int N,H;
  cin >> N >> H;

  vector<int> a(N),b(N);
  REP(i,N)cin >> a[i] >> b[i];

  sort(ALL(a));
  sort(ALL(b));

  int a_max=a[N-1];

  int ans=0;
  for(int i = N-1; i>=0; i--){
    if(b[i] >= a_max){
      H -= b[i];
      ans++;
      if(H<=0)break;
    }
  }

  if(H>0)ans += (H+a_max-1)/a_max;

  cout << ans << endl;
}

