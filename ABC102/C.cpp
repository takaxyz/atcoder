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
  int N;
  cin >> N;
  VI a(N);
  REP(i,N){
    cin >>a[i];
    a[i] -= i+1;
  }
  sort(ALL(a));

  ll mid = 0;
  if(N%2!=0){
    mid = a[N/2];
  }else{
    mid = round((a[N/2] + a[N/2-1])/2.0);
  }

  ll ans=0;
  REP(i,N){
    ans += abs(a[i]-mid);
  }
  cout << ans << endl;
}

