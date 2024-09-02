# FIFA Data Structs: Optimized Data Structures for World Cup Analysis

## Project Overview
This C++ project showcases the application of data structures and algorithms to efficiently manage and search FIFA World Cup data from 1930 to 2018. The primary focus is on achieving memory efficiency and fast data retrieval by employing advanced data structure techniques.

## Features and Goals
- **Memory Efficiency**: Store data in a way that minimizes memory usage by leveraging pointers and optimized data structures.
- **Fast Searching**: Implement AVL Trees for efficient searching of match data.
- **Quick Access**: Use Hash Tables for instant access to data, combined with Singly Linked Lists for easy traversal.
- **Data Structuring**: Focus on data structuring and management over creating extensive methods.

## Data Structures Used
1. **AVL Trees**: Store match data to ensure faster searching and balanced data access.
2. **Hash Tables**: Provide instant access to linked list nodes using a hash function, optimizing both memory consumption and speed.
3. **Singly Linked Lists**: Store items not directly used in searching, allowing for easy data traversal.

## Project Structure
- **`Match.h`**: Declares a class representing a match, including all relevant attributes.
- **`Matchnode.h`**: Defines a node class containing match data, along with pointers to left and right children for AVL Trees.
- **`Matchlist.h`**: Implements an AVL Tree, with functions to insert match nodes and search for head-to-head matches between teams.
- **`Matchtablenode.h`**: Declares a class for a node containing pointers to data in AVL Trees and the next node in a singly linked list.
- **`Matchtablelist.h`**: Implements a singly linked list to store `Matchtablenode` instances, each representing matches of a specific World Cup.
- **`Worldcupyear.h`**: Defines a Hash Table class that stores linked lists at each array index.
- **`Parser.h`**: Parses data from a CSV file, stores it in vectors, and populates the AVL Tree with nodes. This class orchestrates the interaction between other classes.
- **`Main.cpp`**: The entry point of the program, calling functions from `Parser.h` to execute the various functionalities.

## Running the Project
This C++ program can be run from the command line and provides the following options:

1. **Display All FIFA Matches (1930-2018)**: Lists all matches stored in the dataset.
2. **Find Head-to-Head Matches Between Two Countries**: Searches and displays matches between two specified countries.
3. **Find Matches from a Specific World Cup**: Lists matches from a specified World Cup year, using data stored in linked lists within hash tables.

### How to Run
1. Compile the project using a C++ compiler (e.g., `g++`):
    ```bash
    g++ -o fifa_project Main.cpp
    ```

2. Run the compiled executable:
    ```bash
    ./fifa_project
    ```

3. Follow the on-screen prompts to choose one of the three options.

## Example Usage
```bash
Welcome to FIFA Data Structs!

Please select an option:
1. Display all FIFA matches (1930-2018)
2. Find head-to-head matches between two countries
3. Find matches of a specific World Cup
```

## Project Goals

- **Memory Optimization**: Focus on storing data in a compact form and using pointers to avoid redundant storage.
- **Efficient Data Retrieval**: Use AVL Trees and Hash Tables to balance speed and memory efficiency.
- **Traversal Simplicity**: Implement linked lists to facilitate easy traversal of data without compromising search efficiency.


