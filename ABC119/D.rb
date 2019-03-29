A,B,Q=gets.chomp.split.map(&:to_i)
s=[]
A.times do
  s << gets.to_i
end
t=[]
B.times do
  t << gets.to_i
end

s.sort!
t.sort!

def binary_search(arr, v)
  l = 0
  r = arr.size - 1

  while l <= r
    mid = (l + r) / 2

    if arr[mid] == v
      return [v]
    elsif arr[mid] < v
      l = mid + 1
    else
      r = mid - 1
    end

  end

  if r == -1
    return [arr[0]]
  elsif l == arr.size
    return [arr[-1]]
  else
    return [arr[r], arr[l]]
  end
end

Q.times do
  x = gets.to_i
  ss = binary_search(s, x)
  tt = binary_search(t, x)

  ans = Float::INFINITY
  ss.each do |i|
    tt.each do |j|
      if i < x && j < x || i > x && j > x
        tmp = [(x-i).abs, (x-j).abs].max
      else
        tmp = [2*(x-i).abs+(x-j).abs, (x-i).abs+2*(x-j).abs].min
      end
      ans = ans < tmp ? ans : tmp
    end
  end
  puts ans
end
  
