# Goals

## Leading Question
In our project, we are hoping to find some pattern between buying habits and how Amazon presents items that are frequently bought together. Specifically, we would like to explore the extent of importance of certain items, to see which items Amazon recommends together and if we can find any vertices that act as "hubs" for many items, meaning that it is more popular and bought with more other items. 
The final deliverable should rank these items by the number of items that are recommended with these "hub" nodes which reveals how likely it is to get from one place to another just through frequently bought together items.

The difference in the output we get from Betweenness Centrality and PageRank is that PageRank shows where all the edges lead to, while the Betweenness Centrality shows where all the shortests paths will go through as opposed to where they will end up.

## Dataset Acquisition and Processing
We will use the dataset from: http://snap.stanford.edu/data/amazon0302.html. The data is in a list of edges, so we will load each of these edges into a graph data structure. 

Further processing is not necessary since the data set is already cleaned. We will remove any edges that are not complete where both nodes exist in the data set. We can directly load the data by parsing the .txt file using the c++ file read.

A fully loaded graph will look similar to what we covered in class with an adjacency list. There will be a vertex map of linked lists. Each linked list node head will be a vertex, which is a product on Amazon. With the corresponding nodes being the directional edges to each other vertex (ie. this product in the linked list was frequently bought with this other item). If an vertex i is connected to vertex j, then this denotes that the item i, is frequently bought together with item j, and this is not necessarily a bidirectional relationship. 

## Graph Algorithms
### DFS
We will use DFS traversals to store the final graph into a file. The input will just be the starting node on the graph that we want to start our traversal from. The output will just be a file output illustrating the structure of our graph. 

As we go through the traversal, we will keep track of the number of connected components to see the connectivity of different groups of products and whether a certain product can reach another. In case there is more than one connected component, we will keep track of the different nodes that make up the connected components and store them to help prevent errors in later algorithms.

- Big O: O(N)

### Betweenness Centrality

To calculate Betweenness Centrality we will run a variation of the Floyd-Warshall algorithm. Since we have determined above, which nodes are in which components, we will run the Betweenness Centrality Algorithm on each connected component if there are more than one. 

We will use Betweenness Centrality to determine which nodes are traversed the most through in order to reach other products. Since the Betweenness Centrality determines the number of shortests paths that go through the vertices, we can use it to determine which products experience the most traffic when traversing through the recommended products. In essence, we get another metric for determining "hub" nodes within the Amazon frequently bought together recommendations.

The input to this algorithm will be the whole Graph, and we will output a list of all the vertices with their corresponding betweenness centrality score.

The runtime for determining Betweenness Centrality is the same as Floyd-Warshal's shortest path algorithm, since we are just running Floyd-Warshall and then calculating the weights of each vertex. 

- Big O: O(N^3)


### Page Rank

We will use the Page Rank algorithm to determine how important and how popular a certain product is. The input to this algorithm will be the Graph once again. The output of this algorithm will be a graph with the each node storing the importance/popularity of this node. More specifically, pagerank will tell us about "hub nodes" in which more outgoing edges are connected to a singular vertex than others.

- Big O: O(N + M)

## Timeline

### Sprint 0

- Parse the data
- Setup Repo
- Write Test Cases

### Sprint 1

- Implement DFS
- Write Test Cases

### Sprint 2

- Implement PageRank
- Write Test Cases

### Sprint 3

- Implement Betweenness Centrality calculation
- Write Test Cases

### Sprint 4

- Write report
- Create video
- Create ReadME
- Clean-Up Code
