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
  string s;
  cin >> s;

  int cnt=0;
  REP(i,s.size()/2){
    if(s[i]==s[s.size()-1-i])cnt++;
  }

  // aがもともと回文の場合
  if(cnt == s.size()/2){
    cout << s.size()/2*2*25 << endl;
  // 1文字違いで回文の場合
  }else if(cnt == s.size()/2-1){
    if(s.size()%2==1){
      cout << (s.size()/2*2-2)*25 + 24*2 + 25 << endl;
    }else{
      cout << (s.size()/2*2-2)*25 + 24*2 << endl;
    }
  }else{
    cout << s.size() * 25 << endl; 
  }
}

