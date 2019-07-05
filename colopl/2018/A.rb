N=gets.to_i
S=gets.chomp
t=0
cnt_a=[]
S.chars.each do |c|
  if c == 'A'
    t+=1
  elsif t!=0
    cnt_a << t
    t=0
  end
end
if t!=0
  cnt_a << t
end

p cnt_a
if cnt_a.size==1
  puts (N*S.size)*(N*S.size+1)/2
  exit
end

ans=0
if S[0] == 'A' && S[-1] == 'A'
  ans+=cnt_a[0]*(cnt_a[0]+1)/2
  ans+=cnt_a[-1]*(cnt_a[-1]+1)/2
  1.upto(cnt_a.size-2) do |i|
    ans+=(cnt_a[i]*(cnt_a[i]+1)/2)*N
  end
  ans+= ((cnt_a[0]+cnt_a[-1]) * (cnt_a[0]+cnt_a[-1] + 1) / 2) *(N-1)
else
  cnt_a.each do |i|
    ans += i*(i+1)/2*N
  end
end
puts ans