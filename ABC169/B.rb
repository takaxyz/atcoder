n=gets.to_i
a=gets.chomp.split.map(&:to_i).sort

mx=10**18
ans=1
a.each do |v|
  ans*=v
  if(ans > mx) then
    puts -1
    exit
  end
end
puts ans