Bully Algorithm Implementation in C

Overview

This project implements the Bully Algorithm in C, which is a leader election algorithm used in distributed systems. The program allows users to simulate real-time communication between processes, determine failures, and elect a new coordinator dynamically.

Features

User-driven process communication simulation.

Real-time failure detection and leader election.

Dynamic leader reassignment when the previous coordinator rejoins.

Menu-driven interface for ease of use.

How It Works

The user inputs the number of processes and their unique process IDs.

The highest process ID is initially assigned as the coordinator.

A process checks the coordinator’s response; if no response is received, an election is triggered.

The election propagates among higher-ID processes until a new coordinator is selected.

If the initial coordinator comes back, it can reclaim leadership if it has the highest ID.

Compilation & Execution

Compile the Code:

gcc bully_algorithm.c -o bully_algorithm

Run the Program:

./bully_algorithm

Example Simulation

Choose an option:
1. Enter the number of nodes
2. Enter individual node IDs
3. Declare initial coordinator
4. Simulate process communication with coordinator
5. Initiate election algorithm
6. Initial coordinator comes up
7. Exit

File Structure

|-- bully_algorithm.c  # Main implementation file
|-- README.md          # Project documentation

Contributing

Feel free to contribute by submitting issues or pull requests!

License

This project is licensed under the MIT License.

