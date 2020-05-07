#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);

vector<string> s(3);
bool d[3][3][2005];

int main(){
  REP(i,3)cin >> s[i];
  
  sort(ALL(s));

  do {
    cout << s[0] << " " << s[1] << " " << s[2] << endl;

    REP(i,3)REP(j,3)REP(k,s[i].size()){
      if(i>=j)continue;
      bool ok = true;      

      FOR(ni,k,s[i].size()){
        int nj = ni - k;
        if(nj >= s[j].size())break;
        if(s[i][ni] == '?' || s[j][nj] == '?')continue;
        if(s[i][ni] != s[j][nj])ok=false;
      }

      d[i][j][k] = ok;
      printf("%d %d %d %d\n", i,j,k,d[i][j][k]);
    }

    


  }while(next_permutation(ALL(s)));

}

