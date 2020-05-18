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

int main(){
  string s,t;
  cin >> s >> t;

  vector<int> a(26,-1);
  vector<int> b(26,-1);
  REP(i,s.size()){
    int si = s[i]-'a';
    int ti = t[i]-'a';

    if(a[si] != -1 || b[ti] != -1){
      if(a[si] != ti || b[ti] != si){
        cout << "No" << endl;
        return 0;
      }
    }else{
      a[si] = ti;
      b[ti] = si;
    }
  }
  cout << "Yes" << endl;
}

