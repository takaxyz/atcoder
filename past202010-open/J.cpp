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

int main(){
  int n,m;
  cin >> n >> m;
  int ab, bc, ca;
  cin >> ab >> ca >> bc;
  string S;
  cin >> S;

  vector<vector<pair<int, int>>> edge(n+6, vector<pair<int,int>>());
  REP(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    edge[a].emplace_back(b,c);
    edge[b].emplace_back(a,c);
  }
  const int a_in = n;
  const int a_out = n+1;
  const int b_in = n+2;
  const int b_out = n+3;
  const int c_in = n+4;
  const int c_out = n+5;
  REP(i,S.size()){
    int s,t;
    switch(S[i]){
      case 'A':
        s = a_in;
        t = a_out;
        break;
      case 'B':
        s = b_in;
        t = b_out;
        break;
      case 'C':
        s = c_in;
        t = c_out;
        break;
    }
    edge[i].emplace_back(s, 0);
    edge[t].emplace_back(i, 0);
  }
  edge[a_in].emplace_back(b_out, ab);
  edge[a_in].emplace_back(c_out, ca);
  edge[b_in].emplace_back(c_out, bc);
  edge[b_in].emplace_back(a_out, ab);
  edge[c_in].emplace_back(a_out, ca);
  edge[c_in].emplace_back(b_out, bc);


  vector<ll> cost(n+6, LINF);

  cost[0] = 0;

  priority_queue< pair<ll, int>, vector< pair< ll, int > >, greater< pair< ll, int > > > que;

  que.push({cost[0],0});

  while(!que.empty()){
    ll c;
    int i;
    tie(c, i) = que.top();
    que.pop();
    if(cost[i] < c)continue;

    for(auto &e: edge[i]){
      ll next_cost = c + e.second;
      if(cost[e.first] <= next_cost)continue;
      cost[e.first] = next_cost;
      que.emplace(cost[e.first], e.first);
    }
  }
  cout << cost[n-1] << endl;

}

