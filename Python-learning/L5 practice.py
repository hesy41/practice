# #寻找水仙花数。
# for x in range (100, 1000):
#     a = x // 100 #hundreds
#     b = x // 10 % 10 #tens
#     c = x % 10 #ones
#     if x == a**3 + b**3 + c**3:
#         print ('get the numerbr %d' % (x) )

# #百钱百鸡问题。
# for male in range (21):
#     for female in range (34):
#         child = 100 - male - female
#         if 100 == male*5 + female*3 + child/3:
#             print ('male %d, female %d, child %d' % (male, female, child))

# #CRAPS赌博游戏。
# from random import randint
# first = randint (1,6) + randint (1,6)
# while True:
#     if first == 7 or first == 11:
#         print ('player wins')
#         break
#     if first == 2 or first == 3 or first == 12:
#         print ('banker wins')
#         break
#     toast = randint (1,6) + randint (1,6)
#     if toast == 7:
#         print ('banker wins')
#         break
#     if toast == first:
#         print ('player wins')
#         break

# #斐波那契数列
# #input
# nitems = int (input ('how many items do you want in Fibonacci sequence? '))
# #number qualify
# if nitems < 0:
#     print ('invaild number of iterms')
# elif nitems == 1:
#     print ('Fibonacci sequence')
#     print ('1')
# else:
#     n1 = 1
#     n2 = 1
#     counter = 2
#     print (n1, ",", n2, end= " , ")
#     while counter < nitems:
#         new = n1 + n2
#         print (new, end= " , ")
#         counter += 1
#         #update
#         n1 = n2
#         n2 = new

# #完美数
# for x in range (10001):
#     totalF = 0
#     for factor in range (1,x):
#         if x % factor == 0:
#             totalF = totalF + factor
#     if totalF == x:
#         print (x, "is a Perfect number!")

#输出100以内所有的素数
isPrime_list = []
for x in range (2, 100):
    for factor in range (2, x//2+1):
        if x % factor == 0:
            break
    else:
        isPrime_list.append(x)
print (isPrime_list)






