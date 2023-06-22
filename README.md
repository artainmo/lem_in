# lem_in
42 school [subject](https://cdn.intra.42.fr/pdf/pdf/81328/en.subject.pdf).

A program in c that takes an ant-farm description consisting of a start room, end room, rooms in between and tunnels between those rooms.<br>
The ants need to move from start to end room in the shortest time possible, knowing in-between rooms can only contain one ant at a time.<br>
We need to use graph-traversal-algorithms for this. I will implement the “Breadth First Search” algorithm and adapt it to this project of course.

### First algorithm
I chose the "Breadth First Search" (bfs) over the "Depth First Search" (dfs) because the bfs goes through the graph layer by layer, which means once it finds the end-room you know it used the (or one of the) shortest path(s).<br>
As an adaptation to this project:
* I deduce from the bfs' "visited" array and "origin" array (origin related to the "visited" array) the shortest path to the end-room.
* I let each ant go through the graph using bfs but I block access to the nodes that were visited by prior ants at the same time.
* If a room for an ant is blocked by another ant, I create an alternative path, that consists of the ant waiting until the room is free and then following the other ant on its path. The alternative paths are compared with the path that has been found or not and the shortest one is kept.
* If no accessible rooms are empty the ant is forced to wait in current room.

### Second algorithm
I used the bfs (as explained above) to find all the non-overlapping paths that exist in the graph. Once I have all the paths I assign each ant the shortest one, knowing the paths become longer as ants take them due to having to wait for the path to become free.<br>
This algorithm is way shorter than the previous one, it is way faster when the amount of ants is high because the prior algorithm did a bfs for each ant individually while this algorithm does one bfs for each non-overlapping path to be found.

### Use
```
./lem-in < tests/subject.map
./lem-in -v2 < tests/subject.map //Better way to visualize output
./lem-in -v < tests/subject.map //Simple graph visualization in terminal
./lem-in -q < tests/subject.map //Only display results
./lem-in -q2 < tests/subject.map //Do not display nor input advanced checks (to test speed)
./lem-in -s < tests/subject3.map //Use the special algo (first algo), this one is better for small amount of ants
cd tests && ./automated.sh //Launches advanced tests automatically
```

## Documentation
[Depth First Search or DFS for a Graph](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)<br>
[Breadth First Search or BFS for a Graph](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)<br>
[The 2 Most Popular Graph Traversal Algorithms](https://www.graphable.ai/blog/best-graph-traversal-algorithms/)<br>
[The 5 Most Powerful Pathfinding Algorithms](https://www.graphable.ai/blog/pathfinding-algorithms/)<br>
[Shortest path in an unweighted graph](https://www.geeksforgeeks.org/shortest-path-unweighted-graph/)
