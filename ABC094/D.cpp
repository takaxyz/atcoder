#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e19;
const int INF=(1<<30);


int main(){
  int n;
  cin >> n;
  
  VI a(n);
  REP(i,n)cin >> a[i];
  sort(ALL(a));

  int a1=a[n-1];
  int d=INF;
  int a2;

  REP(i,n-1){
    if(abs(a[i]*2-a1)<d){
      a2=a[i];
      d=abs(a[i]*2-a1);
    }
  }
  cout << a1 << " " << a2 << endl;
}

