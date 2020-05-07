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
  int X,A,B;
  cin >> X >> A >> B;

  if(A >= B){
    cout << "delicious" << endl;
  }else if(A+X>=B){
    cout << "safe" << endl;
  }else{
    cout << "dangerous" << endl;
  }

}

