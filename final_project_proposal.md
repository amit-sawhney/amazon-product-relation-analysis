# Final Project Proposal

## Leading Question
We are hoping to find some pattern between buying habits and how Amazon presents items that are frequently bought together. We also would like to explore the extent
to which these items are connected to one another and in what cases they create a cycle. The final deliverable should be able to detect cycles in amazon products that
are frequently bought together and also detect if they can create connected components between all nodes.

## Dataset Acquisition and Processing
We will use the dataset from: http://snap.stanford.edu/data/amazon0302.html. The data is in a list of edges, so we will load each of these edges into a graph data structure.
Furthere processing is not necessary since the data set is already cleaned. We will remove any edges that are not complete where both nodes exist in the data set.

## Graph Algorithms
We will use DFS traversals to store the final graph into a file. The input should just be  


## Timeline
