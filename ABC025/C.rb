b=[]
c=[]
2.times { b << gets.chomp.split.map(&:to_i)}
3.times { c << gets.chomp.split.map(&:to_i)}

sum = 0
b.each {|v| sum += v.inject(:+)}
c.each {|v| sum += v.inject(:+)}

def solve(board, b, c, turn)
  if(turn == 9)
    s = 0
    0.upto(1) do |i|
      0.upto(2) do |j|
        if board[i][j] == board[i+1][j]
          s += b[i][j]
        end
      end
    end
    0.upto(2) do |i|
      0.upto(1) do |j|
        if board[i][j] == board[i][j+1]
          s += c[i][j]
        end
      end
    end
    return s
    
  else
    s = nil
    0.upto(2) do |i|
      0.upto(2) do |j|
        if board[i][j] == -1
        
          board[i][j] = turn%2
          tmp = solve(board, b,c,turn+1)
          board[i][j] = -1
          if(turn%2==0)
            if(s == nil || s <tmp)
              s = tmp
            end
          else
            if(s == nil || s > tmp)
              s = tmp
            end
          end
        end
      end
    end

    return s
  end
end

board = Array.new(3).map{Array.new(3,-1)}


ans = solve(board, b,c,0)
puts ans
puts sum-ans