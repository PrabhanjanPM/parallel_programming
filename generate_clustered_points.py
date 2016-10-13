from sys import argv

import math
import os

if(len(argv)!=3):
    print("Usage: python "+argv[0]+" <number of points> <filenam>")
    exit(0)

max_range = int(argv[1])
points = open(argv[2], "w")
#x=1
#y=1
#z=1
points.write(str(pow(max_range-1,3))+"\n")
for z in range(1,max_range):
    for y in range(1,max_range):
        for x in range(1,max_range):
            points.write(str(x)+" "+str(y)+" "+str(z)+"\n")
points.close()

