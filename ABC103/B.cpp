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
  string s,t;
  cin >> s >> t;

  bool ans=false;
  REP(i,s.size()){
    if(s==t){
      ans=true;
      break;
    }
    s = s.back() + s.substr(0,s.size()-1);
  }

  cout << (ans ?  "Yes" : "No" ) << endl;


}

