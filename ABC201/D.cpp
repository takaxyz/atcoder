#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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

vvi memo;
vvi a;
int h,w;

int f(int i, int j){
  if(memo[i][j]!=INF)return memo[i][j];
  if(i==h-1 && j==w-1)return memo[i][j] = 0;

  
  if((i+j)%2==0){
  // Takahashi
    int res=-INF;
    if(i+1 < h)chmax(res, f(i+1,j)+a[i+1][j]);
    if(j+1 < w)chmax(res, f(i,j+1)+a[i][j+1]);
    return memo[i][j] = res;
  }else{
  // Aoki
    int res=INF;
    if(i+1 < h)chmin(res, f(i+1,j)-a[i+1][j]);
    if(j+1 < w)chmin(res, f(i,j+1)-a[i][j+1]);
    return memo[i][j] = res;
  }
}

int main(){

  cin >> h >> w;
  a.resize(h, vi(w));

  REP(i,h)REP(j,w){
    char c;
    cin >> c;

    if(c=='+')a[i][j]=1;
    else a[i][j]=-1;
  }

  memo.aaaize(h, vi(w, INF));

  int res = f(0,0);
  if(res>0){
    cout << "Takahashi" << endl;
  }else if(res <0){
    cout << "Aoki" << endl;
  }else{
    cout << "Draw" << endl;
  }
  // REP(i,h)REP(j,w){
  //   cout << memo[i][j] << (j==w-1 ? "\n": " ");
  // }
}

