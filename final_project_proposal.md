# Final Project Proposal

## Leading Question
We are hoping to find some pattern between buying habits and how Amazon presents items that are frequently bought together. We also would like to explore the extent
to which these items are connected to one another and in what cases they create a cycle. The final deliverable should be able to detect cycles in amazon products that
are frequently bought together and also detect if they can create connected components between all nodes.

## Dataset Acquisition and Processing
We will use the dataset from: http://snap.stanford.edu/data/amazon0302.html. The data is in a list of edges, so we will load each of these edges into a graph data structure.
Furthere processing is not necessary since the data set is already cleaned. We will remove any edges that are not complete where both nodes exist in the data set.

## Graph Algorithms

### DFS
We will use DFS traversals to store the final graph into a file. The input will just be the starting node on the graph that we want to start our traversal from. The output will just be a file output illustrating the structure of our graph. 

If the graph is not an entirely connected component, we will provide multiple starting nodes so that the DFS may traversal all parts of the graph.

- Big O: O(N)

### Eulerian path

We will use the Eulerian path to determine how connected each of the product "cycles" are. The input will be the Graph that we will determine if is connected or not. The output will be a vector of cycles of varying sizes that were detected within the Graph. 

- Big O: O(M)
- Algorithm: Hierholzer's

### Page Rank

We will use the Page Rank algorithm to determine how important and how popular a certain product is. The input to this algorithm will be the Graph once again. The output of this algorithm will be a graph with the each node storing the importance/popularity of this node.

- Big O: O(N + M)

## Timeline

### Week 0

- Parse the data
- Setup Repo

### Week 1

- Implement DFS

### Week 2

- Implement Hierholzer's algorithm

### Week 3

- Implement Page Rank

### Week 4

- Write report
- Create video
