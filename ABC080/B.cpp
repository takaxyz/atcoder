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
  int X;
  cin >> X;
  int f=0;
  int x=X;
  while(x>0){
    f += x%10;
    x /= 10;
  }
  cout << (X%f==0 ? "Yes" : "No") << endl;
}

