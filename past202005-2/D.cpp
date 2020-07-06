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


int solve(string x[5]){
  string y[10][5] = {
    {
    "###",
    "#.#",
    "#.#",
    "#.#",
    "###"},
    {
    ".#.",
    "##.",
    ".#.",
    ".#.",
    "###"},
    {
    "###",
    "..#",
    "###",
    "#..",
    "###"},
    {
    "###",
    "..#",
    "###",
    "..#",
    "###"},
    {
    "#.#",
    "#.#",
    "###",
    "..#",
    "..#"},
    {
    "###",
    "#..",
    "###",
    "..#",
    "###"},
    {
    "###",
    "#..",
    "###",
    "#.#",
    "###"},
    {
    "###",
    "..#",
    "..#",
    "..#",
    "..#"},
    {
    "###",
    "#.#",
    "###",
    "#.#",
    "###"},
    {
    "###",
    "#.#",
    "###",
    "..#",
    "###"},
  };

  int ret=0;
  REP(i,10){
    bool ng=true;
    REP(j,5){
      if(y[i][j]!=x[j])ng=false;
    }
    if(ng)return i;
  }
  return(999);
}

int main(){
  int N;
  cin >> N;

  string s[5];
  REP(i,5){
    cin >> s[i];
  }

  REP(i,N){
    string x[5];
    x[0] = s[0].substr(i*4+1,3);
    x[1] = s[1].substr(i*4+1,3);
    x[2] = s[2].substr(i*4+1,3);
    x[3] = s[3].substr(i*4+1,3);
    x[4] = s[4].substr(i*4+1,3);
    cout << solve(x);
  }
  cout << endl;
}

