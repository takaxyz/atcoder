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
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  if((B < C) || (D < A)){
    cout << 0 << endl;
  }else{
    cout << min(B,D) - max(A,C) << endl;
  }


}

