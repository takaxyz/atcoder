#include<iostream>
#include<array>
#include<algorithm>
#include<string>


using namespace std;
#define len(val) static_cast<long long>(val.size())
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;
typedef pair<int, int> P;

typedef array<array<int, 3>, 3> Board;
int B[2][3], C[3][2];
int cnt = 0;

P getScore(Board b, int turn){
    int ok = 0;
    rep(i, 3) rep(j, 3) if(b[i][j] == -1) ok++;
    if(ok == 1){
        rep(i, 3) rep(j, 3) if(b[i][j] == -1) b[i][j] = turn;
        int s1 = 0, s2 = 0;
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                if(b[i][j] == b[i+1][j]){
                    s1 += B[i][j];
                }else{
                    s2 += B[i][j];
                }
            }
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<2; j++){
                if(b[i][j] == b[i][j+1]){
                    s1 += C[i][j];
                }else{
                    s2 += C[i][j];
                }
            }
        }
        return P(s1, s2);
    }
    P maxP = P(-1, -1);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(b[i][j] == -1){
                b[i][j] = turn;
                P ms = getScore(b, (turn+1)%2);
                b[i][j] = -1;
                if(turn == 0){
                    if(maxP.first == -1 || ms.first > maxP.first){
                        maxP = ms;
                    }
                }else{
                    if(maxP.second == -1 || ms.second > maxP.second){
                        maxP = ms;
                    }
                }
            }
        }
    }
    return maxP;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cin >> B[i][j];
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            cin >> C[i][j];
        }
    }
    Board b;
    rep(i, 3) rep(j, 3) b[i][j] = -1;
    P p = getScore(b, 0);
    cout << p.first << endl;
    cout << p.second << endl;
}