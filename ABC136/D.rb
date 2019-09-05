s=gets.chomp
ans=Array.new(s.size,0)
r_cnt=0
l_cnt=0
0.upto(s.size-2) do |i|
  if s[i] == 'R' && s[i+1] == 'R'
    ans[i] = 0
    r_cnt += 1
  elsif s[i] == 'R' && s[i+1] == 'L'
    r_cnt+=1
    l_cnt=1
    (i+2).upto(s.size-1) do |j|
      if s[j] == 'L'
        l_cnt += 1
      else
        break
      end
    end

    if r_cnt.odd?
      ans[i] += r_cnt/2+1
      ans[i+1] += r_cnt/2
    else
      ans[i] += r_cnt/2
      ans[i+1] += r_cnt/2
    end

    if l_cnt.odd?
      ans[i] += l_cnt/2
      ans[i+1] += l_cnt/2+1
    else
      ans[i] += l_cnt/2
      ans[i+1] += l_cnt/2
    end
    r_cnt=0
    l_cnt=0
  elsif s[i] == 'L' && s[i+1] == 'L'
    ans[i+1] = 0
  elsif s[i] == 'L' && s[i+1] == 'R'
  end
end
puts ans.join(" ")