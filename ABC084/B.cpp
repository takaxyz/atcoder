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
  int A,B;
  cin >> A >> B;
  string S;
  cin >> S;

  REP(i,A){
    if('0'  > S[i] || S[i] > '9' ){
      cout << "No" << endl;
      exit(0);
    }
  }
  if(S[A] != '-'){
    cout << "No" << endl;
    exit(0);
  }

  FOR(i,A+1,A+B+1){
    if('0'  > S[i] || S[i] > '9' ){
      cout << "No" << endl;
      exit(0);
    }
  }
  cout <<"Yes" << endl;
}

