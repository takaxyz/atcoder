#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int a,b;
  cin >> a >> b;
  if(a+b>=10){
    cout << "error" << endl;
  }else{
    cout << a+b << endl;
  }
}

