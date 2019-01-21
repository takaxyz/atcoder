H,W=gets.chomp.split.map(&:to_i)
s = []
s << ["+"] * (W+2)
H.times { s << ["+"] + gets.chomp.split("") + ["+"]}
s << ["+"] * (W+2)

v = Array.new(H+2).map{Array.new(W+2, 0)  }

def solve_b(s,i,j,v,cnt)
  return if v[i][j] > 0
  v[i][j] = cnt
  solve_w(s,i-1,j,v,cnt) if s[i-1][j] == '.'
  solve_w(s,i+1,j,v,cnt) if s[i+1][j] == '.'
  solve_w(s,i,j-1,v,cnt) if s[i][j-1] == '.'
  solve_w(s,i,j+1,v,cnt) if s[i][j+1] == '.'
end

def solve_w(s,i,j,v,cnt)
  return if v[i][j] > 0
  v[i][j] = cnt
  solve_b(s,i-1,j,v,cnt) if s[i-1][j] == '#'
  solve_b(s,i+1,j,v,cnt) if s[i+1][j] == '#'
  solve_b(s,i,j-1,v,cnt) if s[i][j-1] == '#'
  solve_b(s,i,j+1,v,cnt) if s[i][j+1] == '#'
end

cnt = 1
1.upto(H) do |i|
  1.upto(W) do |j|
    if s[i][j] == '#' && v[i][j] == 0
      solve_b(s,i,j,v,cnt)
      cnt += 1
    elsif s[i][j] == '.' && v[i][j] == 0
      solve_w(s,i,j,v,cnt)
      cnt += 1
    end
  end
end

h = {}
1.upto(H) do |i|
  1.upto(W) do |j|
    if v[i][j] > 0
      if h.has_key?(v[i][j])
      
      else
        h[v[i][j]] = Hash.new(0)
      end
      h[v[i][j]][s[i][j]] += 1
    end
  end
end

ans = 0
h.each do |k,vv| 
  ans += vv['#'] * vv['.']
end
puts ans

