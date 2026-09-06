import heapq

# Maze Escape with Keys
# S = Start
# K = Key
# D = Locked Door
# G = Goal
# # = Wall
# . = Empty cell

maze = [
    list("########"),
    list("#S....K#"),
    list("#.##D###"),
    list("#......G"),
    list("########")
]

rows = len(maze)
cols = len(maze[0])

# Find Start, Key and Goal
for i in range(rows):
    for j in range(cols):
        if maze[i][j] == 'S':
            start = (i, j)
        elif maze[i][j] == 'K':
            key = (i, j)
        elif maze[i][j] == 'G':
            goal = (i, j)


# Manhattan distance
def distance(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


# Heuristic:
# If key is not collected:
#     distance(Current, Key) + distance(Key, Goal)
# Otherwise:
#     distance(Current, Goal)
def heuristic(position, has_key):
    if not has_key:
        return distance(position, key) + distance(key, goal)
    else:
        return distance(position, goal)


# Generate valid moves
def get_neighbors(position, has_key):
    x, y = position

    moves = [
        (x - 1, y),  # Up
        (x + 1, y),  # Down
        (x, y - 1),  # Left
        (x, y + 1)   # Right
    ]

    neighbors = []

    for nx, ny in moves:

        # Check boundaries
        if 0 <= nx < rows and 0 <= ny < cols:

            cell = maze[nx][ny]

            # Cannot move through walls
            if cell == '#':
                continue

            # Cannot cross locked door without key
            if cell == 'D' and not has_key:
                continue

            neighbors.append((nx, ny))

    return neighbors


# A* Search
def solve():

    # State = current position + whether key is collected
    initial_state = (start, False)

    # (f, g, position, has_key, path)
    priority_queue = [
        (
            heuristic(start, False),
            0,
            start,
            False,
            [start]
        )
    ]

    visited = set()

    while priority_queue:

        f, g, position, has_key, path = heapq.heappop(
            priority_queue
        )

        state = (position, has_key)

        if state in visited:
            continue

        visited.add(state)

        # Goal reached
        if position == goal:
            return path

        for next_position in get_neighbors(position, has_key):

            new_has_key = has_key

            # Collect key
            if next_position == key:
                new_has_key = True

            new_g = g + 1

            new_f = new_g + heuristic(
                next_position,
                new_has_key
            )

            heapq.heappush(
                priority_queue,
                (
                    new_f,
                    new_g,
                    next_position,
                    new_has_key,
                    path + [next_position]
                )
            )

    return None


# Run the program
solution = solve()

if solution:
    print("Path from Start to Goal:")
    print("------------------------")

    for step, position in enumerate(solution):
        print("Step", step, ":", position)

    print("\nTotal moves:", len(solution) - 1)
    print("Key collected and goal reached successfully.")

else:
    print("No solution found.")