S201- DSA Project || Project Title : Persistent Segment Tree || Instructor : Dr. Apurva Mudgal 
Shourya Pastor - 2024MCB1389
Jaskaran Kora - 2024MCB1353
Aditya Singh - 2024MCB1285

How to run file?
Just download the repository on your device and open the files in the `src` folder.
They are C++ programs so they can be run using a standard g++ compiler on any device. 
Example: `g++ src/path_copying.cpp -o path_copy` then `./path_copy`

What to input?
You do not need to provide manual input. The `main()` functions contain hardcoded test arrays designed to strictly prove the persistence mechanics across different versions. 

What to expect as a result?
The console will fetch and print the results of range sum queries across Version 0, Version 1, and Version 2 of the arrays. It will prove that historical states are mathematically preserved without altering the original data.

PERSISTENT SEGMENT TREE

Introduction

This repository contains the code for the implementation of an advanced data structure called the Persistent Segment Tree. A data structure is considered persistent if multiple historical versions remain accessible after subsequent updates. The primary objective of the project is to evaluate and compare two primary approaches to achieve persistence.

Methods

The project utilizes two algorithms for persistence:
1. Path Copying Method: Creates new nodes along the root-to-leaf path for every update.
2. Driscoll's Node Copying Method: Uses "Fat Nodes" with bounded extra modification slots to delay node duplication. Detailed mathematical proofs of these algorithms can be found in our LaTeX documentation.

Functions & Operations

The repository provides operations for both methods including:
- Building the initial Version 0 segment tree.
- Point Updates: O(log N) updates that generate and return a new historical root pointer.
- Range Queries: O(log N) sum queries that can be executed on any specific historical version of the tree.
- Fat Node State Retrieval: Iterating through version stamps to find the correct historical value of a node.

Output

The program outputs terminal text demonstrating the data structure's functionality, confirming that queries on older versions return accurate historical data, and verifying memory sharing.

Tables

The tables in the documentation showcase the benchmarks comparing the two methods. Path Copying guarantees O(log N) worst-case space per update, while Driscoll's Node Copying achieves superior O(1) amortized space per update.

Conclusions

The project successfully implements persistent segment trees from scratch. We successfully proved that while Path Copying is conceptually simpler, Driscoll's Node Copying method is vastly superior in memory-constrained environments.

Acknowledgements

We would like to express our gratitude to our Course Instructor and Guide (Dr. Apurva Mudgal) for his guidance and support throughout this DSA project. 

References

The project references James R. Driscoll's 1989 paper: "Making Data Structures Persistent" (Journal of Computer and System Sciences).
