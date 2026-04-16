# CS201 - DSA Project  
## Persistent Segment Tree

**Instructor:** Dr. Apurva Mudgal  

**Group Members:**  
- Shourya Pastor (2024MCB1389)  
- Jaskaran Kora (2024MCB1353)  
- Aditya Singh (2024MCB1285)  

---

## ▶️ How to Run

1. Clone or download the repository  
2. Navigate to the `src` folder  
3. Compile and run using g++

Example:
```bash
g++ src/path_copying.cpp -o path_copy
./path_copy


⸻

📥 Input

No manual input is required.
All test cases are hardcoded inside the main() functions to demonstrate persistence across multiple versions.

⸻

📤 Output

The program prints results of range sum queries across:
	•	Version 0
	•	Version 1
	•	Version 2

This demonstrates that older versions remain unchanged after updates, confirming persistence.

⸻

📌 Introduction

A Persistent Segment Tree is a data structure where previous versions remain accessible even after updates.

This project explores and implements two approaches to achieve persistence and compares their behavior.

⸻

⚙️ Methods Used

1. Path Copying
	•	Creates new nodes along the root-to-leaf path for every update
	•	Shares unchanged subtrees with previous versions

2. Driscoll’s Node Copying
	•	Uses “fat nodes” with extra slots
	•	Stores modifications inside nodes
	•	Copies nodes only when slots overflow

Detailed proofs and analysis are included in the LaTeX report.

⸻

🔧 Supported Operations
	•	Build initial segment tree (Version 0)
	•	Point Update → creates a new version (O(log N))
	•	Range Query → works on any version (O(log N))
	•	Node state retrieval (for node copying method)

⸻

📊 What This Demonstrates
	•	Historical versions are preserved correctly
	•	Memory is optimized through node sharing
	•	Queries on old versions return correct results

⸻

📈 Comparison Summary

Feature	Path Copying	Node Copying
Update Time	O(log N)	O(log N) amortized
Space per Update	O(log N)	O(1) amortized
Query Time	O(log N)	O(log N)


⸻

🧾 Conclusion

This project implements persistent segment trees from scratch and compares two approaches.
	•	Path Copying is simpler and easier to implement
	•	Node Copying is more space efficient in the long run

⸻

🙏 Acknowledgements

We thank our course instructor Dr. Apurva Mudgal for guidance and support throughout the project.

⸻

📚 References
	•	Driscoll, J. R. (1989)
Making Data Structures Persistent
Journal of Computer and System Sciences

