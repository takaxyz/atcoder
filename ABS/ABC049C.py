s = input()
s = s[::-1]

p = 0
while(p < len(s)):
  if p + 5 <= len(s) and s[p:p+5] == "maerd":
    p = p + 5
  elif p + 7 <= len(s) and s[p:p+7] == "remaerd":
    p = p + 7
  elif p + 5 <= len(s) and s[p:p+5] == "esare":
    p = p + 5
  elif p + 6 <= len(s) and s[p:p+6] == "resare":
    p = p + 6
  else:
    print("NO")
    exit()

print("YES")