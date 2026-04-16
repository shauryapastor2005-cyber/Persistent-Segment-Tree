```markdown
# CS201- DSA Project: Persistent Segment Tree

**Instructor / Guide:** Dr. Apurva Mudgal  

### Team Members
* Shourya Pastor - 2024MCB1389
* Jaskaran Kora - 2024MCB1353
* Aditya Singh - 2024MCB1285

---

## How to run the files?
Just clone or download the repository to your local device. Navigate to the `src` folder. 
Because these are standard C++ programs, they can be compiled and run using the g++ compiler on any device.

To run the Path Copying method:
```bash
g++ src/path_copying.cpp -o path_copy
./path_copy
```

To run the Node Copying (Driscoll's) method:
```bash
g++ src/driscoll_node_copying.cpp -o driscoll
./driscoll
```

## What to input?
Currently, the `main()` functions in both files contain hardcoded test cases to mathematically prove the persistence and memory-sharing mechanics. You do not need to provide manual input; just run the executables to see the state of the trees across different historical versions.

## What to expect as a result?
The console will fetch and print the results of range sum queries across Version 0, Version 1, and Version 2 of the arrays, proving that historical states are preserved without altering the original data.

---

## Introduction
This repository contains the code for the implementation and mathematical analysis of **Persistent Segment Trees**. A data structure is considered persistent if multiple historical versions remain accessible after subsequent updates. The primary objective of this project is to implement and compare two methods for achieving full persistence: the Path-Copying Method and Driscoll's Node-Copying Method.

## Algorithms & Complexities
The project implements two distinct structural approaches:
* **Path Copying:** Duplicates nodes strictly along the root-to-leaf update path. Achieves $O(\log N)$ worst-case time and space complexity per update.
* **Node Copying (Driscoll's Method):** Utilizes a "Fat Node" approach with bounded extra modification slots ($e$). Delays node duplication until overflow occurs, achieving superior $O(1)$ amortized space complexity per update.

## Project Structure
* `src/`: Contains the raw C++ implementations of both algorithms.
* `docs/`: Contains our comprehensive LaTeX report, which includes rigorous formal proofs using the potential method of amortized analysis.

## Output
Running the source code demonstrates the program's functionality, confirming that queries on older root versions return mathematically accurate historical data, and verifying via memory addresses that unmodified subtrees are correctly shared across versions.

## Conclusions
The project successfully implements persistent segment trees from scratch. Through our formal analysis and C++ implementations, we concluded that while Path Copying offers consistent worst-case bounds, Driscoll's Node Copying method is vastly superior in memory-constrained environments due to its $O(1)$ amortized space overhead.

## Acknowledgements
We would like to express our gratitude to our Course Instructor and Guide, Dr. Apurva Mudgal, for the guidance and support throughout this DSA course project. 

## References
* Driscoll, J. R., Sarnak, N., Sleator, D. D., & Tarjan, R. E. (1989). *Making Data Structures Persistent*. Journal of Computer and System Sciences.
```
