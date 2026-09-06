# Program 4: Solve 8-Puzzle using A* Search

import heapq


# Function to display the puzzle board
def print_board(state):
    for i in range(0, 9, 3):
        print(state[i:i+3])
    print()


# Function to generate all possible next states
def get_neighbors(state):
    neighbors = []

    # Find the blank space (0)
    zero = state.index(0)

    # Possible movements of the blank space
    moves = {
        0: [1, 3],
        1: [0, 2, 4],
        2: [1, 5],
        3: [0, 4, 6],
        4: [1, 3, 5, 7],
        5: [2, 4, 8],
        6: [3, 7],
        7: [4, 6, 8],
        8: [5, 7]
    }

    # Generate possible states
    for pos in moves[zero]:
        new_state = state.copy()

        # Swap blank with adjacent tile
        new_state[zero], new_state[pos] = \
            new_state[pos], new_state[zero]

        neighbors.append(new_state)

    return neighbors


# Manhattan Distance heuristic
def heuristic(state, goal):
    distance = 0

    for i in range(9):

        # Ignore the blank space
        if state[i] == 0:
            continue

        # Current position
        row = i // 3
        col = i % 3

        # Goal position
        goal_index = goal.index(state[i])
        goal_row = goal_index // 3
        goal_col = goal_index % 3

        # Add Manhattan distance
        distance += abs(row - goal_row)
        distance += abs(col - goal_col)

    return distance


# A* Search
def a_star(start, goal):

    # Priority queue
    priority_queue = []

    # g(n) = cost from start to current state
    g = 0

    # h(n) = estimated cost from current state to goal
    h = heuristic(start, goal)

    # f(n) = g(n) + h(n)
    f = g + h

    # Add starting state
    heapq.heappush(
        priority_queue,
        (f, g, start, [start])
    )

    # Store visited states
    visited = set()

    # Continue while states are available
    while priority_queue:

        # Get state with lowest f(n)
        f, g, state, path = heapq.heappop(priority_queue)

        # Skip already visited states
        if tuple(state) in visited:
            continue

        # Mark state as visited
        visited.add(tuple(state))

        # Check whether goal is reached
        if state == goal:
            return path

        # Generate neighboring states
        for next_state in get_neighbors(state):

            if tuple(next_state) not in visited:

                # Cost of reaching next state
                new_g = g + 1

                # Estimated cost to goal
                new_h = heuristic(next_state, goal)

                # Total estimated cost
                new_f = new_g + new_h

                # Add next state to priority queue
                heapq.heappush(
                    priority_queue,
                    (
                        new_f,
                        new_g,
                        next_state,
                        path + [next_state]
                    )
                )

    # No solution found
    return None


# Initial puzzle state
start = [
    1, 2, 3,
    4, 0, 6,
    7, 5, 8
]

# Goal puzzle state
goal = [
    1, 2, 3,
    4, 5, 6,
    7, 8, 0
]


# Solve using A* Search
solution = a_star(start, goal)


# Display the solution
if solution:
    print("Solution using A* Search")
    print("Number of moves:", len(solution) - 1)

    for state in solution:
        print_board(state)

else:
    print("No solution found")