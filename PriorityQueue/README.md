Priority Queue is an extension of queue with following properties:

	1. Every item has a priority associated with it.
	2. An element with high priority is dequeued before an element with low priority.
	3. If two elements have the same priority, they are served according to their order in the queue.

Applications of Priority Queue:
	1) CPU Scheduling
	2) Graph algorithms like Dijkstra’s shortest path algorithm, Prim’s Minimum Spanning Tree, etc
	3) All queue applications where priority is involved.
	
My Priority Queue is meant to work with multiple variables types or structures. For this example I created
a struct called Patient with just a few basic elements.

For this queue i set the priority in a decreasing order, which that means that 0 is maximum priority.