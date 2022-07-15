# Problem title

## Problem

### Description

In this problem, a matrix of `0` and `1` represents a map of tiles. With `0` meaning that the tile is **water**, and `1` meaning that the tile is **land**.

The goal is to write a function that returns the same map without the islands that do not touch the border of the original map.

An island is a set of `1` that are adjancent to each other either vertically or horizontally:

Example:
<pre><code>1   0   <b>1   1</b>
0   0   0   <b>1</b>
0   <b>1   1   1</b>
0   <b>1</b>   0   0
</code></pre>

The `1`'s in **bold** represent one island. Similarly, the `1` in the top left corner represents another island by itself.

### Input format

<!---
Eg:
* `int *array`: The input array
* 
* `size_t n`: The size of the input array
-->
The input to the solving function is as follows:

`int **matrix`: The input map

`int m`: The height of the map

`int n`: The width of the map

### Output format
<!---
Array of integers
-->

`int **`: An array of integers of size `m*n` representing the map without the island that are disconnected from the edge:

### Example test case

**Example 1:**

<pre><code><b>Input:</b>
matrix = {
    { 1, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 1, 1 },
    { 0, 0, 1, 0, 1, 0 },
    { 1, 1, 0, 0, 1, 0 },
    { 1, 0, 1, 1, 0, 0 },
    { 1, 0, 0, 0, 0, 1 }
},
m = 6,
n = 6

<b>Output:</b> 
{
    { 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 1 },
    { 0, 0, 0, 0, 1, 0 },
    { 1, 1, 0, 0, 1, 0 },
    { 1, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 0, 1 }
}
</code></pre>

**Example 2:**
<pre><code><b>Input:</b>
matrix = {
    { 0, 0, 0, 0 },
    { 0, 1, 1, 0 },
    { 0, 1, 1, 0 },
    { 0, 0, 0, 0 }
},
m = 4,
n = 4

<b>Output:</b> 
{
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 }
}
</code></pre>

**Example 3:**
<pre><code><b>Input:</b>
matrix = {
    { 0, 0, 0, 0 },
    { 0, 1, 1, 0 },
    { 0, 1, 1, 0 },
    { 0, 0, 1, 0 }
},
m = 4,
n = 4

<b>Output:</b> 
{
    { 0, 0, 0, 0 },
    { 0, 1, 1, 0 },
    { 0, 1, 1, 0 },
    { 0, 0, 1, 0 }
}
</code></pre>

### Constrains

```
0 < n, m <= 100
0 <= matrix[i][j] <= 1, ∀ i ∊ [0; m[, ∀ j ∊ [0; n[
```


## Solution details

<details>
<summary>Show hint (key words)</summary>
<br>
  <li>Depth First Search  
  <li>Graphs
</details>
<br>
<details>
<summary>Show solution details</summary>
<br>

We can consider the input matrix to be a set of graph were the nodes are the tiles with value `1`, two adjencent `1`'s are considered as linked.

The solver needs to iterate over the tiles on the edges, if a tile is `1` then explore the graph represented by the linked `1`s.

If we consider a single graph, then one of the common ways to explore all of its nodes is to use an algorithm called Depth First Search.

Depth First Search starts at a given node, then recursively explores each neighbour, marking them as `visited` once it reaches said node to avoid infinite looping.

Since the solution to the problem is to only return the graphs that are adjacent to the edges, we can run DFS on each edge tile that as value `1`. 

Let's now consider a `visited_nodes` 2d array. This array is the same size as the input matrix, and every value is set to `0` (we have not visited anything yet). When we run the DFS algorithm, we use this array to store which node (or tile) as been visited. For example if `matrix[0][5]` is `1`, then set the value `visited_nodes[0][5]` to `1`. 

By the end of the algorithm, the `visited nodes` array will contain every border adjacent islands. Islands that are not connected to the border will be ignored because we will only start from border nodes and consider nodes that are linked to them through land (or `1`s).

The complexity of this solution is O(m*n) in the worst case when every tile is an island and we have to explore them all. In best case senario, the complexity is O(2m+2n) (linear).
</details>
