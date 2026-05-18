# Implementing Depth-First Search (DFS) for a connected directed graph
class Graph:
    def __init__(self):
        # Dictionary to store the graph
        self.graph = {}
        # Set to keep track of visited nodes
        self.visited = set()

    # Function to add an edge to graph
    def add_edge(self, v, w):
        # If the vertex 'v' is not in the graph, add it
        if v not in self.graph:
            self.graph[v] = []
        # Add the edge from vertex v to vertex w
        self.graph[v].append(w)

    # DFS traversal of the vertices reachable from v
    def dfs(self, v):
        # Mark the current node as visited and print it
        self.visited.add(v)
        print(v, end=" ")

        # Recur for all the vertices adjacent to this vertex
        if v in self.graph:  # Check if v has any edges
            for neighbor in self.graph[v]:
                if neighbor not in self.visited:
                    self.dfs(neighbor)

# Driver's code
if __name__ == "__main__":
    # Create a graph given in the above diagram
    g = Graph()
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(2, 0)
    g.add_edge(2, 3)
    g.add_edge(3, 3)

    print("Following is Depth First Traversal (starting from vertex 2):")
    # Function call to start DFS from vertex 2
    g.dfs(2)


# Implementing DFS for a disconnected undirected graph using recursion
class GraphDFS:
    def __init__(self):
        self.visited = {}  # Dictionary to track visited nodes
        self.adj = {}      # Adjacency list to store graph

    # Function to add an edge to the graph
    def add_edge(self, v, w):
        if v not in self.adj:
            self.adj[v] = []
        self.adj[v].append(w)

    # Utility function for DFS
    def dfs_util(self, v):
        self.visited[v] = True
        print(v, end=" ")

        for i in self.adj.get(v, []):
            if not self.visited.get(i, False):
                self.dfs_util(i)

    # Function to do DFS traversal for the complete graph
    def dfs(self):
        for node in self.adj:
            if not self.visited.get(node, False):
                self.dfs_util(node)

# Driver code
g = GraphDFS()
g.add_edge(0, 1)
g.add_edge(0, 9)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)
g.add_edge(9, 3)

print("\nFollowing is Depth First Traversal For Disconnected Undirected Graph:")
g.dfs()


# Implementing Breadth-First Search (BFS) for an undirected graph


class GraphBFS:
    def __init__(self, V):
        self.V = V                          # Number of vertices
        self.adj = [[] for _ in range(V)]    # Adjacency list to store graph

    # Function to add an edge to the graph
    def add_edge(self, v, w):
        self.adj[v].append(w)

    # Function to perform BFS traversal from a given starting vertex
    def bfs(self, s):
        visited = [False] * self.V          # List to keep track of visited vertices
        queue = []                          # Initialize queue for BFS

        visited[s] = True
        queue.append(s)

        while queue:
            s = queue.pop(0)
            print(s, end=" ")

            for i in self.adj[s]:
                if not visited[i]:
                    visited[i] = True
                    queue.append(i)

# Driver code
g = GraphBFS(4)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)
g.add_edge(3, 3)

print("\nFollowing is Breadth First Traversal (starting from vertex 2):")
g.bfs(2)
