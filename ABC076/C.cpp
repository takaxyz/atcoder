#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e18;
const int INF=(1<<30);


int main(){
  string S,T;
  
  cin >> S >> T;

  for(int i = S.size() - T.size(); i >= 0; i--){
    bool flag = true;
    REP(j,T.size()){
      if(S[i+j] != '?' && S[i+j]!=T[j]){
        flag = false;
        break;
      }
    }
    if(flag){
      REP(j,i){
        cout << (S[j]=='?' ? 'a' : S[j] );
      }
      cout << T;
      FOR(j,i+T.size(),S.size()){
        cout << (S[j]=='?' ? 'a' : S[j] );
      }
      cout << endl;
      exit(0);
    }

  }
  cout << "UNRESTORABLE" << endl;

}

