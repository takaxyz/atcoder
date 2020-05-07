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
  int a,b;
  cin >> a >> b;
  int n=b;
  
  if(b>=100)n+=a*1000;
  else if(b>=10)n+=a*100;
  else n += a*10;

  for(int i = 1; i*i<=n; i++){
    if(i*i==n){
      cout << "Yes" << endl;
      exit(0);
    }
  }
  cout << "No" << endl;
}

