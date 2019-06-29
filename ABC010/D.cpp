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

int N,G,E;

bool visited[101][101];
bool edge[101][101];

int main(){
  REP(i,101)REP(j,101){
    visited[i][j] = false;
    edge[i][j] = false;
  }

  cin >> N >> G >> E;

  vector<int> p(G);

  REP(i,G){
    cin >> p[i];
  }
  REP(i,E){
    int a,b;
    cin >> a >> b;
    edge[a][b] = true;
    edge[b][a] = true;
  }

  // REP(i,N+1){
  //   REP(j,N+1){
  //     cout << edge[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  

}