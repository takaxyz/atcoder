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
  string s[2];
  cin >> s[0] >> s[1];
  int n[2];
  REP(i,2){
    if(s[i][0]=='B'){
      n[i] = 1 - (s[i][1]-'0');
    }else{
      n[i] = s[i][0]-'0';
    }
  }


  cout << abs(n[0]-n[1]) << endl;
}

