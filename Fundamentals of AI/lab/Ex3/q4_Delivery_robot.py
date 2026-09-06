import heapq

# Delivery Robot
# W = Warehouse
# A, B, C = Houses
# # = Obstacle
# . = Empty cell

grid = [
    ['W', '.', '.', '.', 'A'],
    ['.', '#', '#', '.', '.'],
    ['.', '.', '.', '.', '.'],
    ['B', '.', '#', '.', 'C']
]

rows = len(grid)
cols = len(grid[0])

# Find warehouse and houses
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == 'W':
            warehouse = (i, j)

houses = {}

for house in ['A', 'B', 'C']:
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == house:
                houses[house] = (i, j)


# Manhattan distance
def distance(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


# Minimum Spanning Tree cost for remaining houses
def mst_cost(points):
    if len(points) <= 1:
        return 0

    points = list(points)
    visited = {points[0]}
    total = 0

    while len(visited) < len(points):
        minimum = float('inf')
        next_point = None

        for point in visited:
            for other in points:
                if other not in visited:
                    d = distance(point, other)

                    if d < minimum:
                        minimum = d
                        next_point = other

        total += minimum
        visited.add(next_point)

    return total


# Heuristic:
# Distance to nearest remaining house
# + MST cost of remaining houses
def heuristic(position, remaining_houses):

    if not remaining_houses:
        return 0

    remaining_positions = [
        houses[h] for h in remaining_houses
    ]

    nearest_distance = min(
        distance(position, house_position)
        for house_position in remaining_positions
    )

    return nearest_distance + mst_cost(remaining_positions)


# Generate valid robot movements
def get_neighbors(position):
    x, y = position

    moves = [
        (x - 1, y),  # Up
        (x + 1, y),  # Down
        (x, y - 1),  # Left
        (x, y + 1)   # Right
    ]

    neighbors = []

    for nx, ny in moves:
        if 0 <= nx < rows and 0 <= ny < cols:
            if grid[nx][ny] != '#':
                neighbors.append((nx, ny))

    return neighbors


# A* Search
def i_solve():

    remaining = frozenset(houses.keys())

    # State = current position + remaining houses
    initial_state = (warehouse, remaining)

    # (f, g, position, remaining_houses, path)
    priority_queue = [
        (
            heuristic(warehouse, remaining),
            0,
            warehouse,
            remaining,
            [warehouse]
        )
    ]

    visited = set()

    while priority_queue:

        f, g, position, remaining_houses, path = heapq.heappop(
            priority_queue
        )

        state = (position, remaining_houses)

        if state in visited:
            continue

        visited.add(state)

        # Goal: all houses have received packages
        if not remaining_houses:
            return path

        for next_position in get_neighbors(position):

            new_remaining = set(remaining_houses)

            # Check whether the robot reached a house
            for house, house_position in houses.items():
                if next_position == house_position:
                    new_remaining.discard(house)

            new_remaining = frozenset(new_remaining)

            new_g = g + 1

            new_f = new_g + heuristic(
                next_position,
                new_remaining
            )

            heapq.heappush(
                priority_queue,
                (
                    new_f,
                    new_g,
                    next_position,
                    new_remaining,
                    path + [next_position]
                )
            )

    return None


# Run the program
solution = i_solve()

if solution:
    print("Delivery Robot Path:")
    print("---------------------")

    for step, position in enumerate(solution):
        print("Step", step, ":", position)

    print("\nTotal moves:", len(solution) - 1)
    print("All packages delivered successfully.")

else:
    print("No solution found.") #homoo