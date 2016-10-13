# Number of clusters = 5

from random import randint
from sys import argv

cluster_size = 20

def gen_points(fp, start, end, size):
	for i in range(0, size):
		x = randint(start, end)
		y = randint(start, end)
		z = randint(start, end)
		fp.write(str(x)+","+str(y)+","+str(z)+"\n")

if(len(argv)!=3):
    print("Usage: python %s <number of points> <filename>"%(argv[0]))
    exit(-1)

n = int(argv[1])
fp = open(argv[2], 'w')
fp.write(argv[1] + '\n')

for i in xrange(0, 10, 2):
	gen_points(fp, i*cluster_size, (i+1)*cluster_size, n/5)

fp.close()