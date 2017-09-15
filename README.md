# Shortest time to reach between two stations on New York Subway Map

*Brief description:*
The project calculates the shortest time to reach between two stations on a New York subway map.

*What is the project about?*
This project is a Simulation of New York Subway Map implemented in C++ to find the shortest time to reach from a source to destination among 356 unique stations considered

*It involves: *
1. First the program creates the state of the links by each station based on an array initialized, which is of 2D. 
2. By reading the topology matrix file of 2D matrix file, a network graph is determined by converting it into a 356 x 356 matrix.
3. Optimal path is computed with least weight(cost) between any two specific stations based on Dijkstra’s algorithm.
4. The application provides a Console Interface for the user to interact with the simulator.

*Simulation:*
You must have a C++ compiler to run this project. I would prefer to use an Unix machine to run the program, but you can consider using NetBeans or Eclipse IDE.

To run the code on Unix machine:
1. Copy the source code file attached along with this document in zip bundle to any Unix machine
2. Ensure you have g++ compiler, if not you may install it by running “sudo apt-get install g++” on Ubuntu machine.
3. Go to the location where source file exists, and run “g++ -o <output file name> cs430_nycsubwayproject_sandeep_vuzzini.c 
4. After an output is generated, an executable with <output file name> is generated. 
5. Run ./ <output file name> to execute the program.

NOTE: Before proceeding below, please refer to the excel sheet “AllStations” attached for station id.

6.	Enter the source station id and destination id, the output will show you the shortest time in minutes.
Runtime of my project: app. 10 sec


