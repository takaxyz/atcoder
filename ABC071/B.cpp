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
  string s;
  int cnt[26] = {0};
  cin >> s;
  REP(i,s.size()){
    cnt[s[i] - 'a']++;
  }
  REP(i,26){
    if(cnt[i]==0){
      cout << char('a'+i) << endl;
      exit(0);
    }
  }
  cout << "None" << endl;

}


