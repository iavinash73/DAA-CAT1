kruskal wouldn't work because the cycles can't be correctly identified in directed graphs.
prim won't work because in a directed graph the algo can't traceback to find the smallest edge from the visited nodes. prim is a node based approach and it can't traceback in directed gragh.I've submitted the noraml prims code for undirected positive weighted graphs. 
dijkstra won't work for the negative edges because in the greedy approach the immediate next adges are only considered and the penalty in next edge wouldn't be considered.I didn't have time to code dijkstra.
