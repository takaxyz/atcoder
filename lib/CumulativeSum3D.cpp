// 0-indexed
// query は半開区間なのでgx,gyは含まない
struct CumulativeSum3D {
  vector<vector<vector<int>>> data;

  CumulativeSum3D(int x, int y, int z) : data(x+1, vector<vector<int>>(y+1, vector<int>(z+1, 0))) {}

  void add(int x, int y, int z, int val){
    ++x; ++y; z++; 
    if(x >= data.size() || y >= data[0].size() || z >= data[0][0].size()) return;
    data[x][y][z] += val;
  }

  void build() {
    for(int i = 1; i < data.size(); i++){
      for(int j = 1; j < data[i].size(); j++){
        for(int k = 1; k < data[0][0].size(); k++){
          data[i][j][k] += data[i][j-1][k] + data[i-1][j][k] + data[i][j][k-1] - data[i][j-1][k-1] - data[i-1][j][k-1] - data[i-1][j-1][k] + data[i-1][j-1][k-1];
        }
      }
    }
  }

  // 半開区間なのでgx,gyは含まない
  int query(int sx, int sy, int sz, int gx, int gy, int gz){
    return data[gx][gy][gz] - data[sx][gy][gz] - data[gx][sy][gz] - data[gx][gy][sz] + data[gx][sy][sz] + data[sx][gy][sz]+ data[sx][sy][gz] - data[sx][sy][sz];
  }
};
