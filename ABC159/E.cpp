#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e19;
const int INF=(1<<30);


int main(){
  int H,W,K;
  cin >> H >> W >> K;

  vector<vector<int>> S(H, vector<int>(W,0));
  REP(i,H)REP(j,W){
    char c;
    cin >> c;
    S[i][j] = (c == '1' ? 1 : 0 );
  }

  int ans = INF;
  REP(i, 1<<(H-1)){
    vector<vector<int> > t(H, vector<int>(W,0));
    int h=0;
    int b=i;
    REP(j,H){
      REP(k,W){
        t[h][k] += S[j][k]; 
      }
      if(b & 1){
        h++;
      }
      b = b >> 1;
    }

    h++;
    // cout << h << endl;
    // REP(j,H){
    //   REP(k,W){
    //     cout << t[j][k] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    vector<int> sum(h,0);

    int l=0;
    int tmp=h-1;
    REP(j,W){
      bool ok = true;
      REP(k,h){
        sum[k] += t[k][j];
      }

      REP(k,h){
        if(sum[k] > K)ok = false;
      }

      if(!ok){
        tmp++;
        sum = vector<int>(h,0);
        REP(k,h){
          sum[k] += t[k][j];
        }

        REP(k,h){
          if(sum[k] > K){
            tmp = INF;
            break;
          }
        }
      }

    }
    ans = min(ans,tmp);

  }

  cout << ans << endl;
}

