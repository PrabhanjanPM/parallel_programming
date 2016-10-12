'''

Trivial Union Find implementation 
Currently accepting only positive integers < 100

'''

from sys import argv

if len(argv) != 2:
    print "Usage: python " + argv[0] + " file"
    exit(-1)

class UnionFind:
     
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0 for x in range(n)]
 
    def find(self, v):
        if not v == self.parent[v]:
            self.parent[v] = self.find(self.parent[v])
        return self.parent[v]
 
    def union(self, x, y):
        xRoot = self.find(x)
        yRoot = self.find(y)
        if xRoot == yRoot:
            return
        if self.rank[xRoot] > self.rank[yRoot]:
            self.parent[yRoot] = xRoot
        else:
            self.parent[xRoot] = yRoot
            if self.rank[xRoot] == self.rank[yRoot]:
                self.rank[yRoot] += 1

#read input
points = []
with open(argv[1]) as fp:
	n = int(fp.readline())
	result = [0] * n
	for i in range(0, n):
		pt = map(abs, map(int, fp.readline().split(',')))
		points.append(pt)

n = 101 # input coordinate varies from -100 to 100
mySet = UnionFind(n*n*n)
for i in range(0, n):
	for j in range(0, n):
		for k in range(0, n):
			if [i, j, k] not in points:
				continue
			try:
				if [i+1, j, k] in points:
					mySet.union(i*n*n + j*n + k, (i+1)*n*n + j*n + k)
				if [i, j+1, k] in points:
					mySet.union(i*n*n + j*n + k, i*n*n + (j+1)*n + k)
				if [i, j, k+1] in points:
					mySet.union(i*n*n + j*n + k, i*n*n + j*n + k+1)
			except IndexError:
				pass

partitions = i = 0
visited = {}
for p in points:
	x = mySet.find(p[0]*n*n + p[1]*n + p[2])
	if x in visited:
		result[i] = visited[x]
	else:
		partitions += 1
		result[i] = visited[x] = partitions
	i += 1

for i in range(0, len(result)):
	print points[i], "->", result[i]