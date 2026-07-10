# 🛒 Smart Cart — Budget-Constrained Shopping Assistant

> An intelligent shopping assistant that helps you get the most satisfaction out of every rupee — powered by the classic **0/1 Knapsack Algorithm**.

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C Language"/>
  <img src="https://img.shields.io/badge/Algorithm-Dynamic%20Programming-orange?style=for-the-badge" alt="Dynamic Programming"/>
  <img src="https://img.shields.io/badge/Topic-0%2F1%20Knapsack-blueviolet?style=for-the-badge" alt="0/1 Knapsack"/>
  <img src="https://img.shields.io/badge/Made%20with-GitHub-181717?style=for-the-badge&logo=github&logoColor=white" alt="GitHub"/>
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" alt="License"/>
</p>

<p align="center">
  <b>Course:</b> Design and Analysis of Algorithms (PCC-CS404) &nbsp;|&nbsp;
  <b>Institution:</b> Academy of Technology &nbsp;|&nbsp;
  <b>Session:</b> 2025–2026
</p>

---

## 📑 Table of Contents

- [Introduction](#-introduction)
- [Problem Statement](#-problem-statement)
- [Features](#-features)
- [Technologies Used](#-technologies-used)
- [Data Structures Used](#-data-structures-used)
- [Algorithm Overview](#-algorithm-overview)
- [Project Structure](#-project-structure)
- [Installation and Compilation](#-installation-and-compilation)
- [Usage](#-usage)
- [Sample Input](#-sample-input)
- [Sample Output](#-sample-output)
- [Time Complexity](#-time-complexity)
- [Space Complexity](#-space-complexity)
- [Future Improvements](#-future-improvements)
- [Team Members](#-team-members)
- [References](#-references)
- [License](#-license)


## 📖 Introduction

Every shopper faces the same everyday dilemma: **a limited budget and a long list of tempting products.** Buying everything is rarely an option, so the real challenge lies in *choosing wisely* — picking the combination of items that brings the greatest satisfaction without exceeding what you can afford.

**Smart Cart** simulates exactly this scenario. Given a fixed budget and a set of products — each with a price and a "utility" (satisfaction) score — the program acts as a virtual shopping assistant that recommends the optimal set of items to purchase, maximizing total satisfaction while staying within budget.

This project demonstrates how a well-known algorithmic technique, **Dynamic Programming**, can be applied to solve a relatable, real-world optimization problem.


## ❓ Problem Statement

> Given a shopper's budget `B` and a list of `n` products, where each product `i` has a price `price[i]` and a utility value `utility[i]`, determine the subset of products to purchase such that:
>
> - The **total price** of the selected products does **not exceed** the budget `B`.
> - The **total utility** of the selected products is **maximized**.
> - Each product can either be **bought once or not at all** (no partial purchases, no repeats).

This is a direct real-world mapping of the classical **0/1 Knapsack Problem**, where:
- `Budget` → Knapsack capacity
- `Price` → Weight of an item
- `Utility` → Value/profit of an item



## ✨ Features

- 🧮 Computes the **maximum achievable utility** within a given budget.
- 🛍️ Determines the **exact combination of products** to buy.
- 💰 Ensures the total cost **never exceeds** the specified budget.
- ⚡ Uses an efficient **Dynamic Programming (Bottom-Up)** approach — no redundant recomputation.
- 📊 Displays a clear, readable summary of selected items, total cost, and total utility.
- 🧩 Simple, modular C code that's easy to read, extend, and reuse.
- 🖥️ Lightweight — runs on any system with a standard C compiler.



## 🛠️ Technologies Used

| Technology | Purpose |
|------------|---------|
| **C Language** | Core implementation of the algorithm |
| **GCC Compiler** | Compiling and building the executable |
| **Standard C Library** (`stdio.h`, `stdlib.h`) | I/O and memory handling |
| **Git & GitHub** | Version control and project hosting |



## 🗃️ Data Structures Used

<details>
<summary><b>Click to expand — Data Structures Overview</b></summary>


| Structure | Description |
|-----------|--------------|
| **1D Arrays** | Store the `price[]` and `utility[]` values of each product |
| **2D DP Table** | `dp[i][b]` stores the maximum utility achievable using the first `i` products with a budget `b` |
| **Boolean/Selection Table (optional)** | Used to backtrack and identify which items were included in the optimal solution |

The 2D DP table is the heart of this project — it systematically builds up the solution to the overall problem from solutions to smaller subproblems.

</details>



## 🧠 Algorithm Overview

Smart Cart solves the problem using the **0/1 Knapsack Dynamic Programming approach**. Here's the intuition, explained simply:

### 🔑 The Core Idea
For every product, we have exactly two choices:
1. **Skip it** — the budget remains unchanged, satisfaction stays the same.
2. **Buy it** — the budget reduces by the product's price, satisfaction increases by its utility (only possible if we can afford it).

At each step, we pick whichever choice gives **higher total utility**.

### 📐 The Recurrence Relation

```
dp[i][b] = dp[i-1][b]                                        if price[i] > b
dp[i][b] = max(dp[i-1][b], dp[i-1][b - price[i]] + utility[i])   otherwise
```

Where:
- `i` → index of the current product being considered
- `b` → remaining budget at this stage
- `dp[i][b]` → maximum utility achievable using the first `i` products within budget `b`

### 🪜 Step-by-Step Approach

1. **Initialize** a 2D table `dp[n+1][B+1]` with the first row and column set to `0` (zero products or zero budget → zero utility).
2. **Iterate** through each product `i` from `1` to `n`.
3. For each possible budget `b` from `0` to `B`:
   - If the product's price exceeds the current budget, **skip it**.
   - Otherwise, **compare** buying vs. not buying, and store the better option.
4. The final answer — the **maximum utility** — is found at `dp[n][B]`.
5. **(Optional) Backtrack** through the table to identify exactly *which* products were chosen.

### 💡 Why Dynamic Programming?

A naive (brute-force) approach would try **every possible subset** of products — an exponential `O(2ⁿ)` disaster. Dynamic Programming avoids this by **reusing previously computed results** instead of recalculating them, bringing the complexity down to a very manageable polynomial time.

> Think of it like filling out a table where each cell answers a small question — *"what's the best I can do with these many products and this much money?"* — and every new cell reuses the answers already sitting in the table.



## 📁 Project Structure

```
smart-cart/
│
├── main.c
├── examples/
│   └── sample_input.txt 
├── LICENSE                
└── README.md                
```



## ⚙️ Installation and Compilation

<details>
<summary><b>Click to expand — Setup Instructions</b></summary>

### ✅ Prerequisites
- A C compiler — **GCC** is recommended.
- Git (optional, for cloning the repository).

### 📥 1. Clone the Repository

```bash
git clone https://github.com/<your-username>/smart-cart.git
cd smart-cart
```

### 🔨 2. Compile the Program

```bash
gcc -o smart_cart src/smart_cart.c
```

### ▶️ 3. Run the Executable

```bash
./smart_cart
```

> 💻 On Windows (using GCC/MinGW), run:
> ```bash
> smart_cart.exe
> ```

</details>



## 🚀 Usage

1. Run the compiled executable.
2. When prompted, enter:
   - The **number of products** available.
   - The **price** and **utility** value of each product.
   - Your **total shopping budget**.
3. The program will process the inputs using the 0/1 Knapsack DP algorithm and display:
   - The **maximum achievable utility**.
   - The **list of recommended products** to purchase.
   - The **total cost** of the selected products.



## 📝 Sample Input

```
Enter number of products: 4
Enter price and utility for each product:
Product 1: Price = 60   Utility = 10
Product 2: Price = 100  Utility = 20
Product 3: Price = 120  Utility = 30
Product 4: Price = 80   Utility = 15

Enter your budget: 200
```



## 📤 Sample Output

```
==========================================
        SMART CART - RECOMMENDATION
==========================================
Maximum Utility Achievable : 50

Recommended Products:
  -> Product 2  (Price: 100, Utility: 20)
  -> Product 3  (Price: 120, Utility: 30)

Total Cost      : 220
------------------------------------------
```

> ⚠️ *Note: The sample values above are illustrative only — actual output depends on the specific price/utility combinations and budget entered.*



## ⏱️ Time Complexity

| Case | Complexity |
|------|------------|
| Building the DP Table | `O(n × B)` |
| Backtracking (finding selected items) | `O(n)` |
| **Overall** | **`O(n × B)`** |

Where `n` = number of products, `B` = budget.



## 💾 Space Complexity

| Approach | Complexity |
|----------|------------|
| Standard 2D DP Table | `O(n × B)` |
| Space-Optimized (1D rolling array) | `O(B)` |

> 💡 The 2D table is used here for clarity and ease of backtracking, but the algorithm can be optimized to use a single 1D array if item selection isn't required.



## 🔮 Future Improvements

- [ ] Add **space-optimized** DP implementation (1D array).
- [ ] Support **file-based input/output** for larger datasets.
- [ ] Build a simple **GUI or web interface** for better usability.
- [ ] Add **category-based shopping** (e.g., groceries, electronics).
- [ ] Include **unit tests** for edge cases (zero budget, zero items, etc.).
- [ ] Visualize the DP table generation step-by-step for educational purposes.



## 👥 Team Members

| # | Name | Roll Number |
|---|------|--------------|
| 1 | Trisha Mukherjee | 16900124081 |
| 2 | Harshit Shaw | 16900124100 |
| 3 | Jagat Prasanna Shaw | 16900124103 | 
| 4 | Joydeep Saha | 16900124104 |
| 5 | Juhi Agarwal | 16900124105 |




## 📚 References

- Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. *Introduction to Algorithms* — Chapter on Dynamic Programming.
- GeeksforGeeks — [0/1 Knapsack Problem](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)
- Course materials — *Design and Analysis of Algorithms (PCC-CS404)*, Academy of Technology.



## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](./LICENSE) file for details.



<p align="center">
  Made with ❤️ by the Smart Cart Team — Academy of Technology, Session 2025–2026
</p>