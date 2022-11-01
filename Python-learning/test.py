# f = float (input('enter F='))
# c = ( f - 32 ) / 1.8
# print('%.1f华氏度 = %.1f摄氏度' % (f, c))
#

# r = float (input ('what is the radius? '))
# a = 3.14 * (r**2)
# w = 2 * r * 3.14
# print ('area is %.1f, and circumference is %.1f' % (a , w))

# calculus whether a year is leap or not
year = int (input ('enter a year: '))
is_leap = (year % 4 == 0 and year % 100 != 0) or year % 400 == 0
print (is_leap)
