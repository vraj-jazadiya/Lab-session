import heapq

# Initial state
initial = (1, 2, 3,
           4, 0, 6,
           7, 5, 8)

# Goal state
goal = (1, 2, 3,
        4, 5, 6,
        7, 8, 0)


# Manhattan Distance heuristic
def heuristic(state):
    distance = 0

    for i in range(9):
        tile = state[i]

        # Ignore blank space
        if tile != 0:
            current_row = i // 3
            current_col = i % 3

            goal_index = goal.index(tile)
            goal_row = goal_index // 3
            goal_col = goal_index % 3

            distance += abs(current_row - goal_row)
            distance += abs(current_col - goal_col)

    return distance


# Generate possible next states
def get_neighbors(state):
    neighbors = []

    blank = state.index(0)
    row = blank // 3
    col = blank % 3

    moves = [
        (-1, 0),  # Up
        (1, 0),   # Down
        (0, -1),  # Left
        (0, 1)    # Right
    ]

    for dr, dc in moves:
        new_row = row + dr
        new_col = col + dc

        if 0 <= new_row < 3 and 0 <= new_col < 3:
            new_blank = new_row * 3 + new_col

            new_state = list(state)

            # Swap blank with adjacent tile
            new_state[blank], new_state[new_blank] = (
                new_state[new_blank],
                new_state[blank]
            )

            neighbors.append(tuple(new_state))

    return neighbors


# A* Search
def solve():
    # (f, g, state, path)
    priority_queue = [
        (heuristic(initial), 0, initial, [initial])
    ]

    visited = set()

    while priority_queue:
        f, g, current, path = heapq.heappop(priority_queue)

        if current in visited:
            continue

        visited.add(current)

        # Goal reached
        if current == goal:
            return path

        for next_state in get_neighbors(current):
            if next_state not in visited:
                new_g = g + 1
                new_f = new_g + heuristic(next_state)

                heapq.heappush(
                    priority_queue,
                    (new_f, new_g, next_state, path + [next_state])
                )

    return None


# Display puzzle
def print_puzzle(state):
    for i in range(0, 9, 3):
        print(state[i], state[i + 1], state[i + 2])
    print()


# Solve the puzzle
solution = solve()

if solution:
    print("Solution found!")
    print("Number of moves:", len(solution) - 1)
    print("\nSteps:\n")

    for step, state in enumerate(solution):
        print("Step", step)
        print_puzzle(state)
else:
    print("No solution found.")