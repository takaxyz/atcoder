#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);
//const int INF=(1<<29);

int main(){
  string S;
  cin >> S;
  reverse(ALL(S));

  int p=0;
  while(p<S.size()){
    if(p+5<= S.size() && S.substr(p,5)=="maerd"){
      p+=5;
    }else if(p+7<= S.size() && S.substr(p,7)=="remaerd"){
      p+=7;
    }else if(p+5<= S.size() && S.substr(p,5)=="esare"){
      p+=5;
    }else if(p+6<= S.size() && S.substr(p,6)=="resare"){
      p+=6;
    }else{
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}

