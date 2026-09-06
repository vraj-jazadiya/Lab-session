# Program 2: Solve 8-Puzzle using Breadth First Search (BFS)

from collections import deque


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

    # Possible positions where the blank can move
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

        # Swap blank with adjacent tile
        new_state[zero], new_state[pos] = \
            new_state[pos], new_state[zero]

        neighbors.append(new_state)

    return neighbors


# Breadth First Search function
def i_bfs(start, goal):
    # Queue stores the current state and path
    queue = deque()

    queue.append((start, [start]))

    # Set stores visited states
    visited = set()

    # Mark starting state as visited
    visited.add(tuple(start))

    # Continue until queue is empty
    while queue:

        # Remove the first element from the queue
        state, path = queue.popleft()

        # Check whether goal is reached
        if state == goal:
            return path

        # Generate all possible next states
        for next_state in get_neighbors(state):

            state_tuple = tuple(next_state)

            # Process only unvisited states
            if state_tuple not in visited:
                visited.add(state_tuple)

                # Add new state and path to queue
                queue.append(
                    (next_state, path + [next_state])
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


# Solve the puzzle using BFS
solution = i_bfs(start, goal)


# Display the solution
if solution:
    print("Solution found using BFS")
    print("Number of moves:", len(solution) - 1)

    # Display every state in the solution
    for state in solution:
        print_board(state)

else:
    print("No solution found") #homoo