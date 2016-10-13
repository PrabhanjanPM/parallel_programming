#!/bin/bash

random_range=$1

sed -i "14s/.*/    x1 = random.randint(-$random_range, $random_range)/" raw.py 
sed -i "15s/.*/    y1 = random.randint(-$random_range, $random_range)/" raw.py 
sed -i "16s/.*/    z1 = random.randint(-$random_range, $random_range)/" raw.py 

exit

