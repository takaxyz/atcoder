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
  string S;
  cin >> S;

  //000 - 111
  REP(i,8){
    int t=S[0]-'0';
    string ans = S.substr(0,1);
    REP(j,3){
      if(i & (1<<j)){
        t += S[j+1] - '0';
        ans += "+";
      }else{
        t -= S[j+1] - '0';
        ans += "-";
      }
      ans += S.substr(j+1,1);
    }
    if(t==7){
      cout << ans << "=7" << endl;
      exit(0);
    }else{
//      cout << t << " " << s << endl;
    }
  }


}

