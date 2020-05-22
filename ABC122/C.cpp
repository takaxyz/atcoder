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

int main(){
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<int> csum(n+1,0);
  REP(i,n-1){
    if(s[i] == 'A' && s[i+1] == 'C')csum[i+1] = csum[i] + 1;
    else csum[i+1] = csum[i];
  }
  // REP(i,n+1){
  //   cout << i <<  " " << csum[i] << endl;
  // }
  REP(i,q){
    int l,r;
    cin >> l >> r;
    cout << csum[r-1] - csum[l-1] << endl;
  }

}

