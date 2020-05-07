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

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> s(H,vector<char>(W));

  REP(i,H)REP(j,W)cin >> s[i][j];

  REP(i,H){
    REP(j,W){
      if(s[i][j]=='.')continue;
      bool ok=false;
      REP(k,4){
        int ii = i + dx[k];
        int jj = j + dy[k];
        if(ii < 0 || ii >= H || jj < 0 || jj >= W)continue;
        if(s[ii][jj]=='#')ok=true;
      }
      if(!ok){
        cout << "No" << endl;
        exit(0);
      }
    }
  }
  cout << "Yes" << endl;

}

