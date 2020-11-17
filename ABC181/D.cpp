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
  string s;
  cin >> s;
  vi cnt(10);

  REP(i,s.size()){
    cnt[s[i]-'0']++;
  }

  if(s.size()==1){
    if(s=="8"){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
    return 0;
  }
  if(s.size()==2){
    if(stoi(s) % 8 == 0){
      cout << "Yes" << endl;
      return 0;
    }
    swap(s[0], s[1]);
    if(stoi(s) % 8 == 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
    return 0;
  }


  FOR(i,1,125){    
    int n = i*8;

    vi cnt2(10);
    cnt2[(n%1000)/100]++;
    cnt2[(n%100)/10]++;
    cnt2[n%10]++;

    if(cnt2[0]>0)continue;

    bool ok=true;
    FOR(i,1,10){
      if(cnt[i] < cnt2[i])ok=false;
    }

    if(ok){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}

