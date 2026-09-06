import heapq

# Grid:
# S = Start
# T = Treasure
# # = Obstacle
# . = Empty cell

grid = [
    ['S', '.', '.', '.'],
    ['#', '#', '.', '#'],
    ['.', '.', '.', '.'],
    ['.', '#', '#', 'T']
]

rows = len(grid)
cols = len(grid[0])

# Find Start (S) and Treasure (T)
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == 'S':
            start = (i, j)
        elif grid[i][j] == 'T':
            goal = (i, j)


# Manhattan Distance heuristic
def heuristic(node):
    x, y = node
    gx, gy = goal
    return abs(gx - x) + abs(gy - y)


# A* Search
def a_star():
    # Priority queue: (f, g, position, path)
    # f(n) = g(n) + h(n)
    pq = [(heuristic(start), 0, start, [start])]

    visited = set()

    while pq:
        f, g, current, path = heapq.heappop(pq)

        if current in visited:
            continue

        visited.add(current)

        # Goal reached
        if current == goal:
            return path

        x, y = current

        # Up, Down, Left, Right
        moves = [
            (x - 1, y),
            (x + 1, y),
            (x, y - 1),
            (x, y + 1)
        ]

        for nx, ny in moves:

            # Check whether the cell is inside the grid
            if 0 <= nx < rows and 0 <= ny < cols:

                # Check that the cell is not an obstacle
                if grid[nx][ny] != '#':
                    new_g = g + 1
                    new_f = new_g + heuristic((nx, ny))

                    heapq.heappush(
                        pq,
                        (new_f, new_g, (nx, ny), path + [(nx, ny)])
                    )

    return None


path = a_star()

if path:
    print("Path from Start to Treasure:")

    for position in path:
        print(position)

    print("\nNumber of moves:", len(path) - 1)
else:
    print("No path found.")
    