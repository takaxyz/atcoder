#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;
int H,W;

int main(){
  cin >> H >> W;
  vector<vector<int> > s1(H);
  vector<vector<int> > s2(W);

  REP(i,W)s2[i].push_back(0);

  REP(i,H){
    string str;
    cin >> str;
    s1[i].push_back(0);
    REP(j,str.size()){
      if(str[j] == '#'){
        s1[i].push_back(j+1);
        s2[j].push_back(i+1);
      }
    }
    s1[i].push_back(W+1);
  }

  REP(i,W)s2[i].push_back(H+1);


  vector<vector<int> > t;
  t = vector<vector<int> >(H, vector<int>(W, 0));

  FOR(i,1,H+1){
    int k=0;
    FOR(j,1,W+1){
      if(s1[i-1][k+1]==j){
        k+=1;
        continue;
      }else{
        t[i-1][j-1] = (s1[i-1][k+1] - j) + (j - s1[i-1][k]) - 1;
      }
    
    }
  }

  FOR(i,1,W+1){
    int k=0;
    FOR(j,1,H+1){
      if(s2[i-1][k+1]==j){
        k+=1;
        continue;
      }else{
        
        t[j-1][i-1] += (s2[i-1][k+1] - j) + (j - s2[i-1][k]) - 1;
      }
      
    }
  }

  int ans=0;
  REP(i,H){
    REP(j,W){
      ans = max(ans,t[i][j]);
    }
  }

  cout << ans - 1 << endl;

}