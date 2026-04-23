# C Data Structures Exercises

A collection of basic Data Structure exercises written in C. This repository contains implementations of fundamental data structures including Stacks, Queues, and Linked Lists using both static arrays and dynamic memory allocation (pointers).

## 📂 File Overview

### Stacks (Checking Balanced Parentheses)
* **`ask_04_1.c`**: Implements a **Stack using an Array**. It reads mathematical expressions and checks if the parentheses/brackets (`()`, `{}`, `[]`) are correctly balanced.
* **`ask_04_2.c`**: Implements the exact same logic for checking balanced brackets, but uses a **Dynamic Linked List** for the Stack instead of a static array.

### Queues (FIFO - First In, First Out)
* **`ask_04_3.c`**: Implements a **Circular Queue using an Array** for integers. Features an interactive menu to insert, remove, and check the queue status.
* **`ask_04_4.c`**: Implements a **Queue using a Linked List** for floating-point numbers. Includes an interactive menu for enqueue, dequeue, and status checks.

### Linked Lists
* **`askisi_05_1.c`**: A basic **Singly Linked List** that stores characters (`char`). Includes an interactive menu to append elements to the end of the list, delete specific elements, search, and display the list.
* **`askisi_05_2.c`**: A **Sorted Singly Linked List** that stores integers (`int`). New elements are automatically inserted in the correct position to keep the list sorted from highest to lowest. Includes deletion, searching, and displaying functionality.

## ⚙️ Compilation and Execution

You can compile any of these files using `gcc` in your terminal. 

**Linux / macOS:**
```bash
gcc ask_04_1.c -o program
./program
