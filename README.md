# lem_in
42 school [subject](https://cdn.intra.42.fr/pdf/pdf/81328/en.subject.pdf).

A program in c that takes an ant-farm description consisting of a start room, end room, rooms in between and tunnels between those rooms.<br>
The ants need to move from start to end room in the shortest time possible, knowing in-between rooms can only contain one ant at a time.<br>
We need to use graph-traversal-algorithms for this. I will implement the “Breadth First Search” algorithm and adapt it to this project of course. 

I chose the "Breadth First Search" (bfs) over the "Depth First Search" (dfs) because the bfs goes through the graph layer by layer, which means once it finds the end-room you know it used the (or one of the) shortest path(s).<br>
As an adaptation to this project:
* I deduce from the bfs' "visited" array and "origin" array (origin related to the "visited" array) the shortest path to the end-room.
* I let each ant go through the graph using bfs but I block access to the nodes that were visited by prior ants at the same time.
* If no accessible rooms are empty the ant waits in current room.

## Documentation
[Depth First Search or DFS for a Graph](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)<br>
[Breadth First Search or BFS for a Graph](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)<br>
[The 2 Most Popular Graph Traversal Algorithms](https://www.graphable.ai/blog/best-graph-traversal-algorithms/)<br>
[The 5 Most Powerful Pathfinding Algorithms](https://www.graphable.ai/blog/pathfinding-algorithms/)<br>
[Shortest path in an unweighted graph](https://www.geeksforgeeks.org/shortest-path-unweighted-graph/)
