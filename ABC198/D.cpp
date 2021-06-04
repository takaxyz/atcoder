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

bool check(vector<string> &s, vi &cnv){
  
  REP(i,3)if(cnv[s[i][0]-'0'] == 0)return false;

  ll s1=0;
  ll s2=0;
  ll s3=0;
  for(auto c: s[0]){
    s1 *= 10;
    s1 += cnv[c-'0'];
  }
  for(auto c: s[1]){
    s2 *= 10;
    s2 += cnv[c-'0'];
  }
  for(auto c: s[2]){
    s3 *= 10;
    s3 += cnv[c-'0'];
  }

  if(s1+s2==s3){
    cout << s1 << " " << s2 << " " << s3 << endl;
    return true;
  }

  return false;
}


int main(){
  vector<string> s(3);
  REP(i,3)cin >> s[i];


  map<char,int> mp;
  REP(i,3){
    for(auto c: s[i])mp[c]++;
  }

  if(mp.size() > 10){
    cout << "UNSOLVABLE" << endl;
    return 0;
  }

  vi p(10);
  REP(i,10)p[i]=i;

  do{
    int i=0;
    vi cnv(26);
    for(auto v: mp){
      cnv[v.first-'0'] = p[i++];
    }
    if(check(s,cnv))return 0;

  }while(next_permutation(ALL(p)));

  cout << "UNSOLVABLE" << endl;
}

