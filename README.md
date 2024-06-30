# Search-Algos
Finding the Number of steps for traversal in given user-input maze, start and end points for different search methods.</br>
Implemented Data structures and Algorithms in C++, STL library.
</br></br>
<h3>Breadth First Search</h3>
In BFS code, we first check if the start and end cells are valid. Then we perform BFS using a queue, marking visited cells and exploring neighbors in all four directions. If we reach the destination cell, we print "Path exists". If we exhaust all possibilities without finding a path, we print "No path exists".
</br>
<h3>Depth First Search</h3>
The DFS code uses DFS algorithm to find a path to the destination. The dfs function takes the grid, start, end, and visited matrices as input and returns true if a path is found, false otherwise. The isValid function checks if a cell is within the grid boundaries. The main function reads the grid, start, and end coordinates, and calls the dfs function to check if a path exists.
</br>
</br>
<h2>Note:</h2> This code assumes that the maze is a grid of 1s and 0s, where 1 represents a path and 0 represents a wall. The user is prompted to enter the number of rows and columns, followed by the maze itself. This code assumes that the grid is 0-indexed, i.e., the top-left cell is (0,0) and the bottom-right cell is (n-1,m-1). Also, it assumes that the start and end coordinates are valid and within the grid boundaries.
