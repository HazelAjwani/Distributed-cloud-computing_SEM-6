# Bully Algorithm Implementation in C

## Overview

This project implements the **Bully Algorithm** in C, which is a leader election algorithm used in distributed systems. The program allows users to simulate real-time communication between processes, determine failures, and elect a new coordinator dynamically. The Bully Algorithm ensures that the process with the highest ID always assumes leadership when necessary, making it a robust mechanism for distributed coordination.

## Features

- **User-driven process communication simulation** – Users can manually simulate the failure and recovery of processes.
- **Real-time failure detection and leader election** – The algorithm dynamically detects coordinator failure and initiates a new election.
- **Dynamic leader reassignment** – If the previous coordinator rejoins, it can reclaim leadership if it has the highest process ID.
- **Menu-driven interface** – Provides an easy-to-use interactive menu for users to execute different actions.

## How It Works

1. The user inputs the number of processes and their unique process IDs.
2. The process with the highest ID is initially assigned as the coordinator.
3. A process checks the coordinator’s response. If no response is received, an election is triggered.
4. The election propagates among higher-ID processes until a new coordinator is selected.
5. If the initial coordinator recovers, it can reclaim leadership if it has the highest ID.

## Compilation & Execution

### Compilation

To compile the program, use the following command:

```sh
gcc bully_algorithm.c -o bully_algorithm
```

### Execution

To run the program, execute:

```sh
./bully_algorithm
```

## Example Simulation

When you run the program, a menu-driven interface is presented:

```sh
Choose an option:
1. Enter the number of nodes
2. Enter individual node IDs
3. Declare initial coordinator
4. Simulate process communication with coordinator
5. Initiate election algorithm
6. Initial coordinator comes up
7. Exit
```

Users can select options to simulate process failures, start elections, and test dynamic leader reassignment.

## File Structure

```
|-- bully_algorithm.c  # Main implementation file
|-- README.md          # Project documentation
```

## Contributing

Contributions are welcome! If you find a bug or have an improvement, feel free to:

1. Fork the repository
2. Create a new branch
3. Submit a pull request

## License

This project is licensed under the **MIT License** – see the `LICENSE` file for details.
