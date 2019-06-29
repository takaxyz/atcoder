N,K=gets.chomp.split.map(&:to_i)
if (N-1)*(N-2)/2 < K
  puts -1
else
  puts (N-1) + ((N-1)*(N-2)/2 - K)
  2.upto(N) do |i|
    printf("1 %d\n",i)
  end

  cnt = (N-1)*(N-2)/2 - K
  2.upto(N) do |i|
    (i+1).upto(N) do |j|
      if cnt == 0
        exit
      end
      printf("%d %d\n",i, j)
      cnt -= 1
    end
  end

end