import heapq

# Grid:
# R = Robot
# D = Dirt
# # = Obstacle
# . = Empty cell

grid = [
    ['R', '.', 'D'],
    ['D', '#', '.'],
    ['.', 'D', '.']
]

rows = len(grid)
cols = len(grid[0])

# Find robot and all dirty cells
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == 'R':
            start = (i, j)

dirty_cells = set()

for i in range(rows):
    for j in range(cols):
        if grid[i][j] == 'D':
            dirty_cells.add((i, j))


# Manhattan distance
def distance(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


# Heuristic:
# Distance to nearest dirt + remaining dirty cells
def heuristic(position, remaining_dirt):
    if not remaining_dirt:
        return 0

    nearest_distance = min(
        distance(position, dirt)
        for dirt in remaining_dirt
    )

    return nearest_distance + len(remaining_dirt)


# Generate valid moves
def get_neighbors(position):
    x, y = position

    moves = [
        (x - 1, y),  # Up
        (x + 1, y),  # Down
        (x, y - 1),  # Left
        (x, y + 1)   # Right
    ]

    valid_moves = []

    for nx, ny in moves:
        if 0 <= nx < rows and 0 <= ny < cols:
            if grid[nx][ny] != '#':
                valid_moves.append((nx, ny))

    return valid_moves


# A* Search
def solve():
    # State = (robot_position, remaining_dirt)
    initial_state = (start, frozenset(dirty_cells))

    # (f, g, position, remaining_dirt, path)
    priority_queue = [
        (
            heuristic(start, dirty_cells),
            0,
            start,
            frozenset(dirty_cells),
            [start]
        )
    ]

    visited = set()

    while priority_queue:

        f, g, position, remaining_dirt, path = heapq.heappop(
            priority_queue
        )

        state = (position, remaining_dirt)

        if state in visited:
            continue

        visited.add(state)

        # Goal: all dirt removed
        if not remaining_dirt:
            return path

        for next_position in get_neighbors(position):

            new_remaining_dirt = set(remaining_dirt)

            # Remove dirt when robot reaches that cell
            if next_position in new_remaining_dirt:
                new_remaining_dirt.remove(next_position)

            new_remaining_dirt = frozenset(new_remaining_dirt)

            new_g = g + 1

            new_f = new_g + heuristic(
                next_position,
                new_remaining_dirt
            )

            heapq.heappush(
                priority_queue,
                (
                    new_f,
                    new_g,
                    next_position,
                    new_remaining_dirt,
                    path + [next_position]
                )
            )

    return None


# Run the program
solution = solve()

if solution:
    print("Robot cleaning path:")
    
    for step, position in enumerate(solution):
        print("Step", step, ":", position)

    print("\nTotal moves:", len(solution) - 1)
    print("All dirt has been removed.")

else:
    print("No solution found.")