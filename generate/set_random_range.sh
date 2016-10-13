#!/bin/bash

random_range=$1

sed -i "14s/.*/    x1 = random.randint(-$random_range, $random_range)/" create_points.py 
sed -i "15s/.*/    y1 = random.randint(-$random_range, $random_range)/" create_points.py 
sed -i "16s/.*/    z1 = random.randint(-$random_range, $random_range)/" create_points.py 

exit

