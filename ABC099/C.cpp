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
  
  VI m;
  m.push_back(1);
  int s=6;
  while(s<=N){
    m.push_back(s);
    s*=6;
  }
  s=9;
  while(s<=N){
    m.push_back(s);
    s*=9;
  }
  sort(ALL(m));
  reverse(ALL(m));

  int ans=0;
  REP(i,m.size()){
    if(m[i] <= N){
      ans += N/m[i];
      N %= m[i];
      printf("%d %d %d\n", N, m[i], ans);
    }
    if(N==0)break;
  }
  cout << ans << endl;
}

