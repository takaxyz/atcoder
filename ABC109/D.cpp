#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define VVI        vector<vector<int>>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);
int cnt=0;
VVI ans;

void f(VVI &a, int i, int j, int ni, int nj){
  if(a[i][j]%2==1){
    a[i][j]-=1;
    a[ni][nj]+=1;
    cnt++;
    VI tmp = {i,j,ni,nj};
    ans.emplace_back(tmp);
  }
}

int main(){
  int h,w;
  cin >> h >> w;

  if(h==1 && w==1){cout << 0 << endl; return 0;}
  
  VVI a(h, VI(w,0));

  REP(i,h)REP(j,w)cin >> a[i][j];

  int i=0;
  int j=0;

  do{
    if(i%2==0){
      if(j==w-1){
        f(a, i,j,i+1,j);
        i++;
      }else{
        f(a, i,j,i,j+1);
        j++;
      }
    }else{
      if(j==0){
        f(a, i,j,i+1,j);
        i++;
      }else{
        f(a, i,j,i,j-1);
        j--;
      }
    }
  }while(!(i==h-1 && (i%2==0 && j==w-1 || i%2==1 && j==0)));

  cout << cnt << endl;
  for(auto v : ans){
    REP(i,4){
      cout << v[i]+1 << (i==3 ? "\n" : " ");
    }
  }
}
