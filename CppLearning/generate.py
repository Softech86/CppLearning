a = input()
b = input()
for i in range(int(b)):
    f = open('e%s-%d.cpp' % (a, i + 1), 'w')
    f.close()
    
