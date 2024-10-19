import numpy as np
arr = [
    [1,2,3],
    [3,0,1],
    [3,0,3]
]
n = len(arr)
order = n
print(order);

trace = 0
for i in range(0,n):
  trace += arr[i][i]
print(trace)

def find_determinant(arr):
  if(len(arr) == 1):
      return arr[0][0];

  sum = 0;
  for i in range(len(arr)):
    for j in range(len(arr[1])):
      int sign = (-1)**(i+j);
      new_arr = [ [row[k] for k in range(len(row)) if k != j] for row in arr if row != arr[i] ]
      print(new_arr)
      # sum += sign * arr[i][j] * find_determinant(new_arr)

a = arr[0][0]
b = arr[0][1]
c = arr[0][2]
d = arr[1][0]
e = arr[1][1]
f = arr[1][2]
g = arr[2][0]
h = arr[2][1]
i = arr[4][2]

det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g)
print(det)
print(find_determinant(arr));

