import random
import os

from sys import argv

if(len(argv)!=3):
    print("Usage- python %s <number of points> <filename>"%(argv[0]))
    exit(0)
number_of_points = int(argv[1])
points = open(argv[2], "w")
points.write(str(number_of_points)+"\n")

for i in range(0,number_of_points):
    x1 = random.randint(-100, 100)
    y1 = random.randint(-100, 100)
    z1 = random.randint(-100, 100)
    points.write(str(x1)+","+str(y1)+","+str(z1)+"\n")
points.close()

os.system("sed -i '4 s/[0-9][0-9]*/"+str(number_of_points)+"/' partitions_serial_brute_force.c")
os.system("gcc partitions_serial_brute_force.c -o partitions_serial_brute_force")
