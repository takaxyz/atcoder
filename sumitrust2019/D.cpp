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
  int n;
  cin >> n;
  string s;
  cin >> s;

  int pin[3];
  int ans=0;
  REP(i,1000){
    int p = i;
    REP(j,3){
      pin[j] = p%10;
      p /= 10;
    }

    int j=0;
    REP(k,s.size()){
      if(pin[j] == s[k] - '0')j++;
      if(j==3)break;
    }
    if(j==3)ans++;
  }
  cout << ans << endl;

}

