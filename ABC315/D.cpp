#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> c(h);
  REP(i,h)cin >> c[i];

  vvi rcnt(h, vi(26,0));
  vvi ccnt(w, vi(26,0));
  REP(i,h)REP(j,w){
    int a = (char)c[i][j]-'a'; 
    rcnt[i][a]++;
  }
  REP(i,w)REP(j,h){
    int a = (char)c[j][i]-'a'; 
    ccnt[i][a]++;
  }

 int ans=h*w;
  while(true){
    vvi rcnt2(h, vi(26,0));
    vvi ccnt2(w, vi(26,0));

    REP(i,h)REP(j,26)rcnt2[i][j]=rcnt[i][j];
    REP(i,w)REP(j,26)ccnt2[i][j]=ccnt[i][j];

    int hh = 0;
    int ww = 0;
    REP(i,h){
      REP(j,26){
        if(rcnt[i][j]==w && rcnt[i][j]>=2){
          rcnt2[i][j]=0;
          REP(k,w)ccnt2[k][j]--;
          hh++;
        }
      }
    }
    REP(i,w){
      REP(j,26){
        if(ccnt[i][j]==h && ccnt[i][j]>=2){
          ccnt2[i][j]=0;
          REP(k,h)rcnt2[k][j]--;
          ww++;
        }
      }
    }
    //cout << hh << " " << ww << endl;
    ans -= hh * w;
    ans -= ww * h;
    ans += ww*hh;

    h -= hh;
    w -= ww;
    //cout << "ans: " << ans << " " << h << " " << w << endl;
    swap(rcnt,rcnt2); swap(ccnt,ccnt2);
    if(hh+ww==0)break;
  }
  cout << ans << endl;


}

