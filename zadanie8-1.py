
deti = [4, 5, 3, 5] 
stoly =  [3, 5, 2, 6, 4]

for i in range(len(stoly)):
    if stoly[i] > len(deti):
        stoly[i] = len(deti)

from collections import deque

class Edge:
    def __init__(self, u, v, w):
        self.source = u
        self.target = v
        self.capacity = w

class Graph:
    def __init__(self):
        self.adj = {}
        self.flow = {}

    def add_edge(self, u, v, w):
        if u not in self.adj:
            self.adj[u] = []
        if v not in self.adj:
            self.adj[v] = []
        self.adj[u].append(Edge(u, v, w))
        self.adj[v].append(Edge(v, u, 0))
        self.flow[(u, v)] = 0
        self.flow[(v, u)] = 0

    def bfs(self, s, t, parent):
        visited = set()
        queue = deque()
        queue.append(s)
        visited.add(s)

        while queue:
            u = queue.popleft()
            for edge in self.adj[u]:
                v = edge.target
                if v not in visited and self.flow[(u, v)] < edge.capacity:
                    parent[v] = (u, edge)
                    if v == t:
                        return True
                    queue.append(v)
                    visited.add(v)

        return False

    def ford_fulkerson(self, source, sink):
        parent = {}
        max_flow = 0

        while self.bfs(source, sink, parent):
            path_flow = float('inf')
            s = sink
            while s != source:
                u, edge = parent[s]
                path_flow = min(path_flow, edge.capacity - self.flow[(u, s)])
                s = u

            max_flow += path_flow

            s = sink
            while s != source:
                u, edge = parent[s]
                self.flow[(u, s)] += path_flow
                self.flow[(s, u)] -= path_flow
                s = u

        return max_flow
    


# create a graph
g = Graph()

# # add edges to the graph
j = 0


for i in deti:
    g.add_edge('S', str(j),i)
    k = len(deti)
    for l in stoly:
        g.add_edge(str(j), str(k),1)
        g.add_edge(str(k), "T", l)
        k += 1
    j += 1


# get the maximum flow from node 'S' to node 'T'
max_flow = g.ford_fulkerson('S', 'T')

if max_flow < sum(deti):
    print(0)
else:
    print(1)