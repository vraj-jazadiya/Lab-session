# Program 1: Solve 8-Puzzle using Depth First Search (DFS)

# Function to display the puzzle board
def print_board(state):
    # Print 3 elements in each row
    for i in range(0, 9, 3):
        print(state[i:i+3])
    print()


# Function to generate all possible next states
def get_neighbors(state):
    neighbors = []

    # Find the position of blank space (0)
    zero = state.index(0)

    # Possible movements of blank space
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

    # Generate each possible move
    for pos in moves[zero]:
        new_state = state.copy()

        # Swap blank space with adjacent tile
        new_state[zero], new_state[pos] = \
            new_state[pos], new_state[zero]

        neighbors.append(new_state)

    return neighbors


# Depth First Search function
def dfs(start, goal):
    # Stack stores current state and path followed to reach it
    stack = [(start, [start])]

    # Set stores already visited states
    visited = set()

    # Continue until stack becomes empty
    while stack:
        state, path = stack.pop()

        # Convert list to tuple so it can be stored in a set
        state_tuple = tuple(state)

        # Skip the state if it was already visited
        if state_tuple in visited:
            continue

        # Mark current state as visited
        visited.add(state_tuple)

        # Check whether goal state is reached
        if state == goal:
            return path

        # Generate and explore neighboring states
        for next_state in get_neighbors(state):
            if tuple(next_state) not in visited:
                # Add new state and updated path to stack
                stack.append(
                    (next_state, path + [next_state])
                )

    # Return None if no solution exists
    return None


# Initial state of the 8-puzzle
start = [
    1, 2, 3,
    4, 0, 6,
    7, 5, 8
]

# Goal state
goal = [
    1, 2, 3,
    4, 5, 6,
    7, 8, 0
]


# Solve the puzzle using DFS
solution = dfs(start, goal)


# Display the solution
if solution:
    print("Solution found using DFS")
    print("Number of moves:", len(solution) - 1)

    # Print every state in the solution path
    for state in solution:
        print_board(state)
else:
    print("No solution found")