# Development Log

## Week 1 (Thanksgiving Break)
This was our first week of work with the project proposal approved.
### Progress
  - We properly set up our repo with makefiles and catch testing so that we will be able to run and test our algorithms.
  - We properly parsed all the nodes and was able to put it into an adjacency list.
  - We were able to set up our DFS Traversal; however, we found that our graph only has one connected component. 
Additionally, we began to realize that we do not have a great use for our traversal yet, especially since the graph is only one componenet.
Lastly, we were wondering if maybe we should be tracking strongly connected components, since our graph is directed.
  - We began our implementation of PageRank, and we were able to get it to work properly run on smaller datasets. 
However, we found that we run out of memory for the actual graph, since our google page rank matrix is too big as it is 'n ^ 2' size. 
To fix this, we will probably have to use a sparse matrix so the size complexity will be closer to 'n' size.
  - We wrote the corresponding test cases for every part of the project that we have so far implemented.

## Week 2 
###### (We accidentally decided to make a new file for each log entry, so this week's progress was transferred from a file (IGNORE-dev-log-12-15.md) that was created a week ago).
### Progress so far:
  - Finished iterator for DFS along with print out traversal
  - Started implementing Floyd-Warshall for Betweenness Centrality
  - Working to fix PageRank
  - Writing more tests
 
 ### This following week we will:
  - Finish PageRank
  - Finish Betweenness centrality
  - Finish Tests
  - Finish documentation
  
## Week 3
### Progress
  - We adjusted PageRank to use sparse matrices to save time and space.
  - We added functionality to our code by including command line arguments. 
  - We completed the Betweenness Centrality Algorithm.
  - We optimized the Betweenness Centrality Shortest Path by using the Brandes Algorithm.
  - We wrote Tests for Betweenness Centrality.
  - We added a comparsion between Betweenness Centrality and PageRank. 
  - We documented all our code.
  - We created the ReadME.md and Results.md
  - We recorded our presentation
