cases = int(input())
for i in range(cases):
  s = input()
  f1, f0 = False, False
  for j in s:
    if j == '0':
      f0 = True
    else:
      f1 = True

  if f0 and f1:
    print(2)
  else:
    print(1)
