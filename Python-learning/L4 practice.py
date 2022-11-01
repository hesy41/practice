# #输入一个正整数判断它是不是素数
# from math import sqrt
# num = int(input('请输入一个正整数: '))
# end = int(sqrt(num))
# is_prime = True
# for x in range (2, end +1):
#     if num % x == 0 and num != 1:
#         is_prime = False
#         print ('is not prime')
#         break
# if is_prime == True:
#         print ('is prime!')
#
#

# #输入两个正整数，计算它们的最大公约数和最小公倍数。
# from math import sqrt
# a = int (input ('a= '))
# b = int (input ('b= '))
#
# for factor in range(b, 0, -1):
#     if a % factor == 0 and b % factor == 0:
#         print ('%d is the greatest common divisor' % (factor))
#         print ('%d is the lease common multiple' % (a*b // factor))

#打印三角形图案
row = int(input('请输入行数: '))
for i in range(row):
    for f in range(i + 1):
        print('*', end='')
    print()

for i in range(row):
    for j in range (row):
        if j < row-i-1:
            print (' ', end = '')
        else:
            print ('*', end = '')
    print ()

for i in range (row):
        for k in range (row-i-1):
            print (' ', end= '')
        for k in range (2*i+1):
            print ('*', end= '')
        print ()
