# # 英制单位英寸和公制单位厘米互换
# value = float (input ('enter the length '))
# unit = input ('enter the unit: ')
# if unit == 'in':
#     print ('%.1f inch = %.1f cm' % (value, value * 2.54))
# elif unit == 'cm':
#     print ('%f cm = %f in' % (value, value/2.54))
# else:
#     print ('please enter a vaild unit')
#
#


# #百分制成绩转换为等级制成绩
# score = int (input ('enter your score: '))
# if score >= 90:
#     print ('your grade is A')
# elif score >=80 and score < 90:
#     print ('your grade is B')
# elif score >=70 and score < 80:
#     print ('your grade is C')
# elif score >= 60 and score < 70:
#     print ('your grade is D')
# elif score < 60:
#     print ('your grade is F'

#输入三条边长，如果能构成三角形就计算周长和面积。
a = float (input ('a= '))
b = float (input ('b= '))
c = float (input ('c= '))
if a+c > b and a+b > c and c+b > a:
    print ('yes')
else:
    print ('no')