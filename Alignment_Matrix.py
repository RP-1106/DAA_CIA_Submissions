#-----main-------
print("Alignment Matrix Program\n")

num=0
a = input("Input sequence 1 : ")
b = input("Input sequence 2 : ")

arr = [0,0,0,0,0,0,0,0,0]*9
print(a[7])
for i in range(9):
    for j in range(9):
        if (i==0 or j==0):
            arr[i][j]=0
        elif i>=1:
            if (a[j]==b[i]):
                arr[i][j] = arr[i-1][j-1]+2
            else:
                num = max(arr[i-1][j-1], arr[i-1][j], arr[i][j-1])
                if (num<0):
                    arr[i][j]=0
                else:
                    arr[i][j]=num-1;
                    
for i in range(9):
    for j in range(9):
        print(arr[i][j],end= " ")
    print()
    