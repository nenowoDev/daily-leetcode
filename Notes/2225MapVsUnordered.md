# Map vs Unordered Map

Case 2225

|               | map                   | unordered map    |
| --------------| ---------------------| -----------------|
| **Order**     | increasing (default) | no order         |
| **Implementation** | binary tree      | hash table       |
| **Search Time**   | log(n)             | O(1) - best <br> O(n) - worst |
| **Insertion Time** | log(n) + rebalance | -                |
| **Deletion Time** | log(n) + rebalance | -                |
