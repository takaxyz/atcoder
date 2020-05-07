#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);

const int p = 8000;

//x=-8000 flist={8000}
bool dp(vector<int> flist, int x){
  if(flist.size()==0)return x == 0;

  vector<vector<int>> dp(flist.size(), vector<int>(p*2+2,0));

  dp[0][flist[0]+p]=1;
  FOR(i,1,flist.size()){
    REP(j,dp[i].size()){
      if(dp[i-1][j]){
        dp[i][j+flist[i]]=1;
        dp[i][j-flist[i]]=1;
      }
    }
  }

  return dp[flist.size()-1][p+x] == 1;
}

int main(){
  string s;
  cin >> s;
  int x,y;
  cin >> x >> y;

  vector<int> a,b;
  int flag=1;
  int cnt=0;
  s+='T';
  if(s[0]=='T'){
    a.push_back(0);
  }
  b.push_back(0);
  REP(i,s.size()){
    if(s[i]=='T'){
      if(flag){
        if(cnt)a.push_back(cnt);
      }else{
        if(cnt)b.push_back(cnt);
      }
      flag ^= 1;
      cnt=0;
    }else{
      cnt++;
    }
  }

  // REP(i,a.size()){
  //   cout << a[i] << " ";
  // }
  // cout << endl;
  // REP(i,b.size()){
  //   cout << b[i] << " ";
  // }
  // cout << endl;

  cout << (dp(a,x) && dp(b,y) ? "Yes" : "No") << endl;
}

