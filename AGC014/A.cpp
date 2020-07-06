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
  int a,b,c;
  cin >> a >> b >> c;

  if(a==b && b == c){
    cout << (a%2==0 ? -1 : 0) << endl;
    return 0;
  }

  int ans=0;
  while(a%2==0 && b%2==0 && c%2==0){
    ans++;
    int aa,bb,cc;
    aa = (b+c)/2;
    bb = (a+c)/2;
    cc = (b+a)/2;
    a = aa; b = bb; c = cc;
  }
  cout << ans << endl;
}

