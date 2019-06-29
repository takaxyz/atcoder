w,h,x,y=gets.chomp.split.map(&:to_i)
if 2*x==w && 2*y==h
  printf("%f 1\n",w*h/2.0)
else
  printf("%f 0\n",w*h/2.0)
end