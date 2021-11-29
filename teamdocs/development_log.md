# Development Log

## Week 1 (Thanksgiving Break)
This was our first week of work with the project proposal approved.
### Progress
  - We properly set up our repo with makefiles and catch testing that we will be able to use to run and test our algorithms.
  - We properly parsed all the nodes and was able to put it into an adjacency list.
  - We were able to set up our DFS Traversal; however, we found that our graph only has one connected component. 
Additionally, we began to realize that we do not have a great use for our traversal yet, especially since the graph is only one componenet.
Lastly, we were wondering if maybe we should be tracking strongly connected components, since our graph is directed. 
  - We began our implementation of PageRank, and we were able to get it to work properly run on smaller datasets. 
However, we found that we run out of memory for the actual graph, since our google page rank matrix is to big as it is 'n ^ 2' size. 
To fix this, we will probably have to use a sparse matrix so the size complexity will be closer to 'n' size.
