# Report_Prim_MST

(Note: below MST is short for minimum spanning tree)

### Introduction:

- **MST Definition:**

    Graph is a set of edges and vertices represented as G(V, E) and tree is a connected graph having n vertices and n - 1 edges. 

    A minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight. (*definition from wiki*)

- **MST Importance:**

    Minimum spanning trees have their paramount influences in designing various real-world networks, such as computer networks, telecommunications networks, transportation networks, water supply networks, and electrical circuits. In these fields, to leverage the minimum spanning trees can largely decrease costs and increase efficiency as well as safety. 

- **Prim's Algorithm:**

    Prim's algorithm is a kind of greedy algorithm which is used to find a minimum spanning tree for a weighted undirected graph. The algorithm starts by taking any arbitrary vertex as the starting vertex and then adding the edges in such a manner that they produce the minimum weight. It follows the steps: 

    1. Start with choosing arbitrarily a vertex from the graph, set it as the root of the minimum spanning tree. 
    2. From the edges that connect the minimum spanning tree to the vertices which have not yet been put in the MST, we find the minimum-weight edge, and add it to the tree together with it's vertex
    3. Repeat step 2 until all vertices are in the minimum spanning tree.

- **Kruskal's Algorithm:**

    Kruskal algorithm is another greedy algorithm used for finding the minimum spanning tree in a graph. It follows the repeated steps of always selecting the minimum cost weight edge.

### Implementation of Prim's Algorithm:

- **Pseudo code:**
    1. For each vertex v in the graph, define an array Weight[v] to store the smallest weight value of the edge connecting v to the MST，and an array Edge[v] to store the edges that provides that smallest weight connection. And initialize all values in Weight[v] to $+\infty$ . 
    2. Initialize a set Q of vertices that have not yet been visited (initially, all vertices).
    3. Start with an arbitrarily chosen vertex v0, set Weight[v0] to 0, which is smaller than all other values in Cost array; set Edge[v0] to -1 (since it's the root of MST).
    4. Repeat the following steps until Q is empty:
    a. Find and remove a vertex v from Q having the minimum possible value of Weight[v]
    b. Loop over the edges with all vertices w connecting to v. For each such edge, if w still belongs to Q (not visited) and v-w has smaller weight than Weight[w], perform the following steps:
    1) Set Weight[w] to the cost of edge v-w
    2) Set Edge[w] to value v.
    5. Return Cost[v] and Edge[v] to form a MST

- **Illustrate using prim's algorithm to get the MST on the following graph:**

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled.png)

    1) Step1: Initialize the values:

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%201.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%201.png)

    2) Step2: We arbitrarily choose node 0 as the start node, then initialize the minimum weight value of node 0 as 0, and the edge it connect to MST as -1; and put the node 0 into the MST, so change the visited[0] status to True

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%202.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%202.png)

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%203.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%203.png)

    3）Step3: search and calculate the weights of unvisited nodes, and then update the weights values to the smallest value of their connected edges to MST visited nodes; the unvisited nodes are 1, 2, 3 and 4.

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%204.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%204.png)

    4) Step4: Repeating step2. From all nodes that are not visited, find the one has minimum weight[v] value, which is node 1 with value 4. Then set node 1 as visited, and add and edges from 1 to 0 into MST. 

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%205.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%205.png)

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%206.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%206.png)

    5). Step5: Repeating step3. calculate the weights of unvisited nodes, and then update the weights values to the smallest value of their connected edges to MST visited nodes; the unvisited nodes are 2, 3 and 4.

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%207.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%207.png)

    6) Step6: Repeating step2.  From all nodes that are not visited, find the one has minimum weight[v] value, which is node 4 with value 2. Then set node 4 as visited, and add and edges from 4 to 1 into MST. 

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%208.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%208.png)

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%209.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%209.png)

    7). Step7: Repeating step3. calculate the weights of unvisited nodes, and then update the weights values to the smallest value of their connected edges to MST visited nodes; the unvisited nodes are 2 and 3.

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%209.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%209.png)

    8). Step8: Repeating step2.  From all nodes that are not visited, find the one has minimum weight[v] value, which is node 2 with value 3. Then set node 2 as visited, and add and edges from 2 to 1 into MST. 

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2010.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2010.png)

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2011.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2011.png)

    9). Step9: Repeating step3. calculate the weights of unvisited nodes, and then update the weights values to the smallest value of their connected edges to MST visited nodes; the unvisited nodes are 3, and 6 is already the smallest.

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2011.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2011.png)

    10). Step10. Repeating step2.  From all nodes that are not visited, find the one has minimum weight[v] value, which is node 3 with value 6. Then set node 3 as visited, and add and edges from 3 to 0 into MST. 

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2012.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2012.png)

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2013.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2013.png)

    **Result** 

    Now all nodes are visited, and we got the minimum spanning tree:

    **Edge Pair 	Weight**

    **[0] - [1]     	4**

    **[1] - [2] 	         3**

    **[0] - [3]   	6**

    **[1] - [4]           2**

- **Time complexity:**

    From above process of the algorithm, the step of finding the vertex with smallest weight cost from set Q can make a difference for the time complexity of the algorithm. 

    1). If we use an array to implement set Q:

    data size: number of vertices: n = |V|, number of edges: m = |E|

    As finding the minimum distance is (|V|-1) and in maximum for every edge in MST we have to select all edges and compare to find the minimum edge, so it would be:  (|V| - 1) *|E| .*

    So we can simplify the time complexity as: $O(V^2)$

    2). If we use a min heap to implement set Q, each time we just pop the root node from the min-heap, because root node value is always the smallest in a min-heap. 

    data size: number of vertices: |V|, number of edges: |E|

    Main operations: 

    - value initialization and assignment: |V|
    - comparisons: both explicit and implicit inside deleteRoot from minHeap and insertNode operation: we know the average or worst time complexity to perform min-heapify is log|V|, and when we insert all vertices into the heap the total time is approximately |E|log|V|; for comparisons of edge values  and pop out the smallest, the edge values needs to perform heapify processes again, so total would be approximately |V|log|V|. To sum, it is O((|V|+|E|)log|V|)

    So the total time complexity is O((|V|+|E|)log|V|). And since we can find a constant c = 4, and a N₀ = 2, and so long as N > N₀,  4|V|log|V| will always be greater than O(m + (n+m)logn). The time complexity can be simplified as O(|V|log|V|).

    So we can simplify the time complexity as: $O(VlogV)$.

    as illustrated step by step:

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2014.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2014.png)

    ### minHeap implementation

    Since one implementation of prim's algorithm is to use min heap, which is one kind of priority queue. We need to get clear the structure of min heap and implement it in c code including the main operation(packed in an header file as interfaces) we will use in our implementation of prim.

    - definition of minHeap:

        a minHeap is a binary heap with the root less than or equal to all its children, as the binary heap is defined as a binary tree with two additional constraints( *from wikipedia*):

        - Shape property: a binary heap is a ; that is, all levels of the tree, except possibly the last one (deepest) are fully filled, and, if the last level of the tree is not complete, the nodes of that level are filled from left to right.
        - Heap property: the key stored in each node is either greater than or equal to (≥) or less than or equal to (≤) the keys in the node's children, according to some [total order](https://en.wikipedia.org/wiki/Total_order).
    - key operations included in our implementation of minHeap:

        1). min-heapify

        Min-heapify function is implemented to maintain the min-heap property. When the min-heapify function is called on  a specified position i of the tree, it will sift-down the tree to compare with its children to check whether the parent node value is smaller than its children, if such property is violated, swaps the parent node value with the child node value to ensure the min-heap structure property.

        2). build-min-heap:

        Used to convert an array into a min-heap, by calling the precedures of min-heapify. This function is essential in heap data structure and will be implemented in our codes, but not actually used in our prim algorithm.

        3). get min-node from min-heap:

        To gain the min-value node from the heap, which will always be the root of min-heap.

        4). insert node into the min-heap:

        To insert a new node into the min-heap. During the process of searching and finding the min-node, new nodes with new edge values need to be inserted into the min-heap for next level operratin.

        5). delete root node from the min-heap:

        When the root node is marked as visited and put into the minimum spanning tree, it needs to be deleted.

        6). free min-heap:

        To delete the whole min-heap. 

    - the node structure of our min-heap:

        As we are to store the edge information in the node of the min-heap, we decide to put the weight value of the edge and two vertices connected in the edge into the node struct of our min-heap.

    - Below is the interfaces of our min-heap:

        ```c
        #ifndef minHeap_h
        #define minHeap_h

        typedef struct node {
          int data ;
          int vertex1;
          int vertex2;
        } node ;

        typedef struct minHeap {
          int size ;
          node *node ;
        } minHeap ;

        minHeap initMinHeap(void);
        void minHeapify(minHeap *hp, int i);
        void insertNode(minHeap *hp, int data, int vertexA, int vertexB);
        node minNode(minHeap *hp);
        void deleteNode(minHeap *hp);
        void freeMinHeap(minHeap *hp);

        #endif /* minHeap_h */
        ```

    ### Output of two implementations:

    ![Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2015.png](Report_Prim_MST%2070939bd28ef242e186c457e4acf9af1a/Untitled%2015.png)

    ### Conclusion of Prim's Algorithm:

    After studying the algorithm, we find that min heap data structure is helpful in optimizing the time complexity of prim's algorithm on MST. Although when the graph is not complicated with quite small number of vertices and edges, there is no need for min heap since min heap still needs maintenance costs. However when the graph is a large dense one, the implementation using minheap with vlogv time complexity will make a big improvement.