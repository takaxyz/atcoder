// 0-indexed
// query は半開区間なのでgx,gyは含まない
struct CumulativeSum2D {
  vector<vector<int>> data;

  CumulativeSum2D(int w, int h) : data(w+1, vector<int>(h+1, 0)) {}

  void add(int x, int y, int z){
    ++x; ++y; 
    if(x >= data.size() || y >= data[0].size()) return;
    data[x][y] += z;
  }

  void build() {
    for(int i = 1; i < data.size(); i++){
      for(int j = 1; j < data[i].size(); j++){
        data[i][j] += data[i][j-1] + data[i-1][j] - data[i-1][j-1];
      }
    }
  }

  // 半開区間なのでgx,gyは含まない
  int query(int sx, int sy, int gx, int gy){
    return data[gx][gy] - data[sx][gy] - data[gx][sy]  + data[sx][sy];
  }
}
