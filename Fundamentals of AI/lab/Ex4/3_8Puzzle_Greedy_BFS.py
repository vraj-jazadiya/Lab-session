# Program 3: Solve 8-Puzzle using Greedy Best First Search

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

    # Create each possible next state
    for pos in moves[zero]:
        new_state = state.copy()

        # Swap blank space with adjacent tile
        new_state[zero], new_state[pos] = \
            new_state[pos], new_state[zero]

        neighbors.append(new_state)

    return neighbors


# Manhattan Distance heuristic
def heuristic(state, goal):
    distance = 0

    # Check the position of every tile
    for i in range(9):

        # Ignore the blank space
        if state[i] == 0:
            continue

        # Current row and column
        current_row = i // 3
        current_col = i % 3

        # Find the tile's position in the goal
        goal_index = goal.index(state[i])
        goal_row = goal_index // 3
        goal_col = goal_index % 3

        # Add Manhattan distance
        distance += abs(current_row - goal_row)
        distance += abs(current_col - goal_col)

    return distance


# Greedy Best First Search
def i_greedy_best_first(start, goal):

    # Priority queue
    priority_queue = []

    # Calculate heuristic of starting state
    h = heuristic(start, goal)

    # Add starting state to priority queue
    heapq.heappush(
        priority_queue,
        (h, start, [start])
    )

    # Store visited states
    visited = set()

    # Continue until queue becomes empty
    while priority_queue:

        # Get state with smallest heuristic value
        h, state, path = heapq.heappop(priority_queue)

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

                # Calculate heuristic
                h = heuristic(next_state, goal)

                # Add state to priority queue
                heapq.heappush(
                    priority_queue,
                    (
                        h,
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


# Solve using Greedy Best First Search
solution = i_greedy_best_first(start, goal)


# Display the solution
if solution:
    print("Solution using Greedy Best First Search")
    print("Number of moves:", len(solution) - 1)

    for state in solution:
        print_board(state)

else:
    print("No solution found") #homoo