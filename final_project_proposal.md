# Final Project Proposal

## Leading Question
We are hoping to find some pattern between buying habits and how Amazon presents items that are frequently bought together. We also would like to explore the extent
to which these items are connected to one another and in what cases they create a cycle. The final deliverable should be able to detect cycles in amazon products that
are frequently bought together and also detect if they can create connected components between all nodes.

## Dataset Acquisition and Processing
We will use the dataset from: http://snap.stanford.edu/data/amazon0302.html. The data is in a list of edges, so we will load each of these edges into a graph data structure.
Further processing is not necessary since the data set is already cleaned. We will remove any edges that are not complete where both nodes exist in the data set. We can directly load the data by parsing the .txt file using the c++ file read.

## Graph Algorithms

### DFS
We will use DFS traversals to store the final graph into a file. The input will just be the starting node on the graph that we want to start our traversal from. The output will just be a file output illustrating the structure of our graph. 

If the graph is not an entirely connected component, we will provide multiple starting nodes so that the DFS may traversal all parts of the graph.

- Big O: O(N)

### Eulerian path

We will use the Eulerian path to determine how connected each of the product "cycles" are. The input will be the Graph that we will determine if is connected or not. The output will be a vector of cycles of varying sizes that were detected within the Graph. 

- Big O: O(M)
- Algorithm: Hierholzer's

### Shortest Path

We will use the shortest path algorithm to determine the least number of edges needed to go from one node to another. The input will be a node and the output will be an int of the number of edges. If they are not in the smae connected component we will return a -1 or some other marking value.

- Big O: O(N^2) (array) and O(M+N * Log(N)) (min priority queue) 
- Algorithm: Djikstra's

### Page Rank (Optional if extra time)

We will use the Page Rank algorithm to determine how important and how popular a certain product is. The input to this algorithm will be the Graph once again. The output of this algorithm will be a graph with the each node storing the importance/popularity of this node.

- Big O: O(N + M)

## Timeline

### Week 0

- Parse the data
- Setup Repo
- Write Test Cases

### Week 1

- Implement DFS
- Write Test Cases

### Week 2

- Implement Hierholzer's algorithm
- Write Test Cases

### Week 3

- Implement Page Rank
- Write Test Cases

### Week 4

- Write report
- Create video
- Create ReadME
- Clean-Up Code
