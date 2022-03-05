# Depth first search
## Complexity
Since recursion method is called once for every vertex and the cost of calling it on a vertex is the number of edges in its adj list + some constant work.
Sum of all work is the sum of all edges in the graph + v * constant amount of work. Which is O(V + E)
## Pseudocode
- V1
DFS(G, v):
   label v as discorvered
   for all neighbors u of v:
      if u is not discorvered:
          DFS(G, u)

- V2 (with coloring for cycle detection)
func DFS(G):
   label all vertices of G as WHITE
   for all WHITE vertices v of G:
      DFS(G, v)

- V3 (iterative DFS)
 
func DFSUtil(G, v):
   label v as GRAY
   for all neighbors u of v:
      if u is not discorvered:
          DFS(G, u)
   label v as BLACK
## Application
- Cycle detection: During DFS, if any neighbor is colored GRAY, we've found a cycle
- Topo sort: Run normal DFS. Topo sort order is the reversed finishing order. Note that in topo sort problems
an edge from u to v indicates u has to be done before v. Which also means u appear before v in the topo sort
order
