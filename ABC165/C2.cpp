#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007
 
typedef long long int ll;
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
const ll INF=(ll)1e19;
//const int INF=(1<<30);
 
int n,m,q;
 
int a[50],b[50], c[50],d[50];
 
vector<int> A(50);
 
set<vector<int>> st;
 
int dfs(int s, int length){
//  cout << s << " " << length << endl;
  int ret=0;
 
  if(length < n){
    A[length] = s;
    FOR(i,s,m+1){
      chmax(ret, dfs(i,length+1));
    }
  }else{
    int tmp = 0;
    REP(i,q){
      if(A[b[i]]-A[a[i]]==c[i])tmp += d[i];
    }
    chmax(ret,tmp);
  }
  return ret;
}
 
 
int main(){
  cin >> n >> m >> q;
 
  REP(i,q){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--; b[i]--;
  }
 
 
  int ans = 0;
  FOR(i,1,11)chmax(ans,dfs(i, 0));
  cout << ans << endl;
}
 
