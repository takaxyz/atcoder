b=[]
c=[]
2.times { b << gets.chomp.split.map(&:to_i)}
3.times { c << gets.chomp.split.map(&:to_i)}
$board = []
$board[0] = [-1,-1,-1]
$board[1] = [-1,-1,-1]
$board[2] = [-1,-1,-1]


def solve(board, b, c, turn)
#  p $board
  ok = 0
  0.upto(2) do |i|
    0.upto(2) do |j|
      ok += 1 if $board[i][j] == -1
    end
  end

  ii,jj=0,0
  if(ok == 1)
#    p turn
    0.upto(2) do |i|
      0.upto(2) do |j|
        if $board[i][j] == -1
          $board[i][j] = 0
          ii = i
          jj = j
        end
      end
    end
    p $board
    
    s = 0
    0.upto(1) do |i|
      0.upto(2) do |j|
        if $board[i][j] == $board[i+1][j]
          s += b[i][j]
        end
      end
    end
    0.upto(2) do |i|
      0.upto(1) do |j|
        if $board[i][j] == $board[i][j+1]
          s += c[i][j]
        end
      end
    end
    printf("score=%d\n",s)
    $board[ii][jj] = -1
    return s
    
  else
    s = -1
    0.upto(2) do |i|
      0.upto(2) do |j|
        if $board[i][j] == -1
        
          $board[i][j] = turn
          tmp = solve(b,c,(turn+1)%2)
          $board[i][j] = -1
          if(turn==0)
            if(s == -1 || s <tmp)
              s = tmp
            end
          else
            if(s == -1 || s > tmp)
              s = tmp
            end
          end
        end
      end
    end

    return s
  end
end

#board = Array.new(3).map{Array.new(3,-1)}

#board[0] = [1,0,1]
#board[1] = [0,0,1]
#board[2] = [0,1,0]

ans = solve(b,c,0)
puts ans