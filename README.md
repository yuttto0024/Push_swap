[English](#english) | [日本語](#japanese)

&nbsp;
&nbsp;

<a id="english"></a>

# Push_swap

_This Project has been created as part of the 42 curriculum by yuonishi_

## Table of Contents
1. [Overview](#overview)
2. [Learning Objectives](#learning-objectives)
3. [Project Details](#project-details)
4. [Data Structure Selection](#data-structure-selection)
5. [Hardware Level Comparison](#hardware-level-comparison)
6. [Sort Algorithm Selection](#sort-algorithm-selection)
7. [Usage](#usage)
8. [References](#references)
9. [AI Usage](#ai-usage)

&nbsp;  
&nbsp;  

## Overview
In this assignment, we sort data within a stack using a limited set of instructions.
The primary objective is to sort the data using the **minimum possible number of operations**.

## Learning Objectives

### 1. Awareness of Complexity
If the goal were simply to sort, Bubble Sort would suffice. However, that results in a massive number of operations.
The requirement is not just "it works," but "it is efficient." It requires a mindset of "how can we reduce wasted movements?"
Furthermore, it is necessary to select appropriate processes from existing sorting methods.

### 2. Algorithm Implementation under Constraints
Normally, swapping array index `i` and `j` is an instantaneous operation. However, with the data structure in this project, there is a constraint that only the top element can be accessed.
The ability to implement algorithms within this restrictive environment is required.

### 3. Practical Data Structure Manipulation
The ability to manipulate stack structures in an actual program and implement processes to move data between Stack A and Stack B is required.

&nbsp;  
&nbsp;  

## Project Details
In this project, you will create a program that sorts data in Stack A, using Stack B as temporary storage, utilizing only a limited instruction set.
The critical point is the **minimization of the operation count** output until the sort is complete.

## Data Structure Selection: Doubly Linked List vs Ring Buffer
In this project, I adopted a **Doubly Linked List** to prioritize flexible stack operations.

### Data Structure Comparison Table

| Comparison Item | **Ring Buffer (Circular Array)** | **Doubly Linked List** |
| :--- | :--- | :--- |
| **Access Speed** | **Very Fast** `O(1)`.<br>Immediate access via index. High cache efficiency. | **Slow** `O(n)`.<br>Must traverse pointers sequentially to reach specific elements. |
| **Push / Pop** | **Fast but restricted** `O(1)`.<br>Simply increment/decrement top index.<br>Fast at ends, but shifting occurs for intermediate operations. | **Very Fast** `O(1)`.<br>Only involves pointer reassignment. Intermediate insertion is easy if pointers are held. |
| **Memory Efficiency** | **Static Allocation (Fixed Length)**<br>Must allocate max size beforehand, leading to unused space. | **Dynamic Allocation (Variable Length)**<br>Nodes created when needed. No wasted space. |
| **Implementation Issues** | **Index Calculation**<br>Modulo arithmetic when crossing the `0` and `MAX` boundary is complex. | **Pointer Management**<br>Preventing NULL dereferences and managing memory via malloc/free. |
| **Learning Goal** | Array manipulation, Memory efficiency. | Pointer manipulation, Structs (List ops), Memory management. |

### Reasons for Selection

#### 1. Suitability for Data Movement
The essence of `push_swap` is passing data between stacks (`pa`, `pb`) and rotating elements (`ra`, `rra`).
- **Advantage of Lists:** Lists complete insertion/deletion by rewriting a few pointers. Even with 100 or 500 elements, the processing time for reconnecting pointers (`next`, `pre`) remains constant `O(1)`.
- **Disadvantage of Arrays:** Normal arrays require shifting elements. While a Ring Buffer avoids this for top/bottom operations, the stack size changes dynamically, necessitating the allocation of a huge array initially.

#### 2. Flexibility of Memory Management
- Lists allow dynamic changes to the expansion area, resulting in no wasted space.
- In this project, I designed it to `malloc` only the necessary elements via `make_node` and release them all at once with `free_stack`. This allows flexible memory usage independent of the number of runtime arguments.

#### 3. Traversal Cost
The algorithm implemented (Greedy) scans all elements in the stack to calculate the move with the lowest cost.
Lists take `O(n)` to scan from the top. However, the metric for `push_swap` is "number of instructions," not the execution speed (CPU cycles) of the program itself. Therefore, I believe the list structure, where structural changes (pointer connection) are intuitive and less prone to bugs, is more suitable than raw access speed.

## Hardware Level Comparison
Here, we compare the characteristics and suitable fields of both based on the physical behavior of the CPU and memory.

### 1. Array (Ring Buffer)
Arrays are allocated in a continuous region in physical memory.

* **Cache Lines:**
    When the CPU accesses array element `arr[i]`, the memory controller loads not just `arr[i]` but also adjacent `arr[i+1]`, `arr[i+2]`, etc., into the CPU cache (L1/L2) as a **cache line (typically ~64 bytes)** at once.
* **High-Speed Sequential Access:**
    Due to this "spatial locality," the frequency of accessing main memory (DRAM) decreases drastically during sequential data reading, allowing the CPU's computational performance to be fully utilized.

**[Suitability: Embedded Systems / Hardware Control]**
From these characteristics, arrays are optimal for fields where "Real-time performance" is critical.
* **Embedded Systems:** Prevents `malloc` overhead and segmentation faults in microcontroller controls where memory resources are strictly limited.

### 2. Linked List
Each node of a linked list is `malloc`'d at random positions (discontinuous addresses) on the heap area.

* **Pointer Chasing:**
    To access the next element, the address of the `next` pointer held by the current node must be read, and that address must be accessed anew.
* **Cache Misses and Latency:**
    Because access jumps to scattered addresses, the probability of data not existing in the CPU cache (cache miss) increases. Each miss generates a wait (stall) for data transfer from slow main memory, consuming more processing cycles compared to arrays.

**[Suitability: Software Applications]**
From these characteristics, list structures are suitable for fields requiring "flexibility" or "complex data structures."
* **OS / Middleware:** Environments like process management or file systems where element addition/deletion is frequent and total data volume is unpredictable.
* **High-Level Applications:** Areas where maintaining "relationships" between data and ease of algorithm implementation are prioritized over memory access speed, such as editor history management (Undo/Redo) or complex sorting logic like this project.

### Conclusion
While arrays have the advantage of better cache efficiency and minimal read/write overhead, I selected the **Doubly Linked List** for this project, prioritizing the ease of node addition/deletion and optimization of memory consumption.

&nbsp;  
&nbsp;  

## Sort Algorithm Selection
In this project, I started with "Merge Sort," which has a theoretical complexity of `O(N log N)`, but faced the wall of instruction costs specific to `push_swap`. Ultimately, I adopted a **"Cost-based Greedy Algorithm."**
The comparison and selection history are described below.

### 1. Algorithm Comparison

Comparison of characteristics of general sorting algorithms and their suitability for `push_swap` (stack operations).

| Algorithm | Complexity (Avg) | Stack Suitability | Characteristics | Verdict |
| :--- | :--- | :--- | :--- | :--- |
| **Bubble / Selection** | `O(N^2)` | × Unsuitable | Implementation is simple, but comparison/swap counts are too high, exceeding limits. | Rejected |
| **Quick Sort** | `O(N log N)` | △ Average | Uses partitioning with pivots. Implementable on stacks, but avoiding worst cases and managing recursion depth is complex. | On Hold |
| **Merge Sort** | `O(N log N)` | ◯ Theoretically Good | Stable sort. Compatible with linked lists, but accessing the "bottom" of a stack is costly. | **Initial Choice** |
| **Greedy** | `O(N^2)` * | ◎ Optimal | Calculates movement costs for all elements and continually selects the local optimum (cheapest node). | **Final Choice** |

* *Note: The Greedy method here specializes in minimizing the "number of output instructions" rather than comparison counts, resulting in the best effective score.*

---

### 2. Initial Implementation: Bottom-up Merge Sort
Initially, I implemented "Natural Merge Sort," which utilizes naturally occurring sorted subsequences (Runs).

#### Concept
Find "accidentally sorted parts (Runs)" within the random number sequence and merge them using Stack B.

#### Implementation Phase Record
Development proceeded in the following steps:
1.  **Run Detection:**
    - Scan from the stack top and recognize monotonically increasing (or decreasing) parts as one "mountain" (Run).
    - Manage variable-length Runs via a `check_sorted_length(stack)` function.
2.  **Merge Function:**
    - Compare the tops of Stack A and Stack B.
    - Confirm the smaller (or larger) one as "sorted."
3.  **Sending to Bottom:**
    - Send the confirmed node to the bottom of the stack using `ra` (Rotate A) to prepare for the next merge operation.

#### The Problem Encountered: The Wall of Rotation Costs
The results after implementation were as follows:
* **Sorting 100 args:** 1746 instructions (Goal: < 700)
* **Sorting 500 args:** 10743 instructions (Goal: < 5500)

**Failure Analysis:**
Merge Sort is excellent for arrays or lists with random access, but in a stack structure, the operation of **"sending sorted data to the Bottom"** was fatal. Every time one element was merged, an `ra` (rotation) occurred. For `N` elements, nearly `N` rotations were required, causing an explosive increase in instructions.

---

### 3. Final Implementation: Greedy Algorithm
Based on the failure with Merge Sort, I changed the policy to an algorithm specialized in "reducing instructions by even one" rather than "sorting beauty."

#### Concept
Simulate the "moves required to return to the correct position in Stack A" for all elements in Stack B, and actually move only the element that can be moved with the fewest moves (lowest cost).

#### Algorithm Behavior
1.  **Initial Partitioning:**
    - Move elements from Stack A to Stack B based on rough ranges (e.g., quartiles) (`pb`).
2.  **Cost Calculation:**
    - Calculate the following costs for all elements in Stack B:
        - Count of `rb` (Cost to bring to top of B)
        - Count of `ra` (Cost to bring A's acceptance position to top)
3.  **Optimization (Simultaneous Rotation):**
    - Since performing `ra` and `rb` individually increases cost, prioritize common rotation instructions **`rr` (Rotate Both)** and **`rrr` (Reverse Rotate Both)**.
    - Example: Rotating A 3 times and B 2 times -> Use `rr` 2 times and `ra` 1 time (Total 3 instructions).
4.  **Execution:**
    - Move the calculated "cheapest" element.

#### Improvement Results
-   **Sorting 100 args:** **Approx. 600 instructions** (1/3 of Merge Sort)
-   **Sorting 500 args:** **Approx. 4500~5000 instructions** (1/2 of Merge Sort)

#### Conclusion
In `push_swap`, utilizing common instructions (`rr`, `rrr`) to reduce wasteful single rotations affects the score more directly than the theoretical complexity of the algorithm.
An approach that keeps choosing the "optimal solution for that moment" even at a calculation cost was more suitable for the stack operation constraints of this assignment than an approach like Merge Sort that maintains global order.

&nbsp;
&nbsp;

## Usage

### Compilation
Using the Makefile, you can compile and clean up with the following commands.

| Command | Description |
| :--- | :--- |
| `make` | Compiles the program and generates the executable `push_swap`. |
| `make clean` | Deletes object files (`*.o`) generated during compilation. |
| `make fclean` | Deletes the executable and libraries (libft, etc.) in addition to object files. |
| `make re` | Executes `fclean` and then `make` to rebuild. |

### Basic Execution
Run by passing the "list of integers to sort" as arguments.
```bash
./push_swap 2 1 3 6 58
```

**Output:**
Instructions required for sorting (`sa`, `pb`, `ra`, etc.) are displayed on the standard output.

### Verification and Benchmark

You can efficiently test using random numbers with the following shell commands.

**1. Verification with Checker**
Generates 1 to 100 non-duplicate random numbers, passes `push_swap` output to the `checker` program to verify the sort result.

```bash
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
```

**2. Instruction Count Measurement**
Counts the number of instructions (lines) taken to complete the sort.

```bash
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

**3. Infinite Loop Test**
Executes repeatedly to check if instruction counts are stable and no crashes occur. (Stop with `Ctrl + C`)

```bash
while true; do ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l; done;
```

**4. Using Python Tester**
If `push_swap_tester.py` is available in the environment, statistical testing is possible with:

```bash
python3 push_swap_tester.py -l 100
python3 push_swap_tester.py -l 500
```

## References

* [Arrays and Linked Lists (Japanese)](https://www.momoyama-usagi.com/entry/info-algo-list)
* [Stacks and Queues (Japanese)](https://www.momoyama-usagi.com/entry/info-algo-stack-queue)
* [Doubly Linked Lists (Japanese)](https://ufcpp.net/study/algorithm/col_blist.html)
* [What is Greedy Algorithm? (Japanese)](https://techgym.jp/column/greed/)
* [Push Swap - Sorting without Coordinate Compression (Japanese)](https://zenn.dev/grigri_grin/articles/ea2690feac54fa)

## AI Usage

In this project, I used an AI tool (Gemini Pro) as follows.

### Tasks Performed

1. **Concept Clarification and Documentation:**
Used for brainstorming/validating the differences in behavior at the hardware level (CPU cache lines, memory stalls) between Doubly Linked Lists and Ring Buffers (Arrays), beyond just computational complexity.
2. **Algorithm Selection Deep Dive:**
Used for analyzing the reasons why the instruction count of the initially implemented Merge Sort would not decrease (identifying the rotation cost bottleneck).

&nbsp;  
&nbsp;  



<a id="japanese"></a>

# Push_swap

_This Project has been created as part of the 42 curriculum by yuonishi_

## 目次
1. [概要](#概要)
2. [この課題で学ぶべきこと](#この課題で学ぶべきこと)
3. [プロジェクト詳細](#プロジェクト詳細)
4. [データ構造の技術選定](#データ構造の技術選定)
5. [ハードウェアレベルでの比較](#ハードウェアレベルでの比較)
6. [ソートアルゴリズムの技術的選定](#ソートアルゴリズムの技術的選定)
7. [使い方](#使い方)
8. [参考文献](#参考文献)
9. [AIの使用について](#aiの使用について)

&nbsp;  
&nbsp;  

## 概要
当課題では、決められたコマンドを用い、スタック内をソートする。  
その際、可能な限り少ない操作回数でのソートを行うことが、最大の目的である。

## この課題で学ぶべきこと

### 1. 計算量の意識
普通にソートするのであれば、バブルソート等で済む。しかし、それでは手数が増えてしまう。  
よって、「動けばいい」ではなく、「効率的であること」が求められる。「どうすれば無駄な動きを削減できるか」の意識が重要だ。  
また、既存のソート法の中から、適切な処理を選定する必要がある。

### 2. 制約のある環境下でのアルゴリズム実装
普段であれば、「配列の何番と何番を交換」を一瞬で行えるが、今回のデータ構造では、一番上のデータしか触れない（FIFO）という制約がある。  
この不自由な環境下での、どうアルゴリズムを実装するか、という力が求められる。

### 3. データ構造の実践的な操作
スタックの構造を、実際のプログラムとして動かし、データを スタックA ⇔ スタックB と移動させる処理を実装する力が求められる。

&nbsp;  
&nbsp;  

## プロジェクト詳細
この課題では、スタックAにあるデータを、スタックBを一時領域として利用し、「限られた命令セット」のみを使用してソートするプログラムを作成する。  
重要な点は、ソート完了までに出力される「命令回数の最小化」である。

## データ構造の技術選定：双方向連結リスト vs リングバッファ
本プロジェクトでは、スタックの柔軟な操作を考慮し、双方向連結リストを採用した。

### データ構造比較表

| 比較項目 | **リングバッファ（循環配列）** | **双方向リスト** |
| :--- | :--- | :--- |
| **アクセス速度** | **非常に高速** `O(1)`。<br>インデックスで即座にアクセス可能。キャッシュ効率が良い。 | **低速** `O(n)`。<br>特定の要素へはポインタを順に辿る必要がある。 |
| **Push・Pop** | **高速だが制約あり** `O(1)`。<br>Topインデックスを増減させるだけ。<br>端（Top/Bottom）なら速いが、中間操作はシフトが発生。 | **非常に高速** `O(1)`。<br>ポインタの付け替えのみ。中間挿入もポインタ保持で容易。 |
| **メモリ効率** | **静的確保（固定長）**<br>事前に最大数確保するため、未使用領域が発生。 | **動的確保（可変長）**<br>必要な時にノードを生成。無駄な領域が発生しない。 |
| **実装の課題** | **インデックス計算**<br>`0`と`MAX`の境界を超える際の剰余演算が複雑。 | **ポインタ管理**<br>NULL参照防止や、malloc/freeによるメモリ管理。 |
| **学習の狙い** | 配列操作、メモリ効率 | ポインタ操作、構造体（リスト操作）、メモリ管理。 |

### 選定理由

#### 1. データ移動の適性
`push_swap` の本質は、スタック間でのデータの受け渡し（`pa`, `pb`）と、要素の回転（`ra`, `rra`）である。
- **リストの利点**:  
リストは、ポインタをいくつか書き換えるだけで挿入・削除が完了する。要素が100個、500個と増えても、ポインタの繋ぎ変え（`next`, `pre`）の処理時間は一定`O(1)`。
- **配列の欠点**:  
通常の配列では要素のズラし作業が発生するが、リングバッファや実装次第では可能（キャッシュでtopやsizeを保持）。しかし、スタックのサイズが動的に変化するため、最初に巨大な配列を確保する必要がある。

#### 2. メモリ管理の柔軟性
- リストでは、動的に拡張領域を変更でき、無駄な領域が発生しない。
- 実際に当課題でも、`make_node` により必要な要素分だけ `malloc` し、`free_stack` で一括解放する設計にしている。これにより、実行時の引数の数に依存しない柔軟なメモリ使用が可能。

#### 3. 走査コスト
当課題で実装したアルゴリズム（Greedy）では、スタック内の全要素を走査し、最もコストの低い移動数を計算する。  
リストは先頭から辿るため走査に`O(n)`かかってしまう。しかし、`push_swap` における条件は「命令回数（手数）」であり、プログラム自体の実行速度（CPUサイクル）ではない。そのため、アクセス速度よりも、構造の変更（ポインタの繋ぎ変え）が直感的であり、ミスが起きにくいリスト構造のほうが向いていると考える。

## ハードウェアレベルでの比較
ここでは、CPUとメモリの物理的な挙動に基づき、両者の特性および適性分野を比較する。

### 1. 配列（リングバッファ）
配列は、物理メモリ上でデータが連続した領域に確保される。

* **キャッシュライン:**
    CPUが配列の要素 `arr[i]` にアクセスする際、メモリコントローラは `arr[i]` だけでなく、隣接する `arr[i+1]`, `arr[i+2]` ... も含めた**キャッシュライン（通常64byte程度）**を一気にCPUキャッシュ（L1/L2）へ読み込む。
* **高速なシーケンシャルアクセス:**
    キャッシュラインによる空間局所性から、次々とデータを読む処理ではメインメモリ（DRAM）へのアクセス頻度が激減し、CPUの演算性能を引き出すことができる。

**【適性：組み込み・ハードウェア制御】**
これらの特性から、配列は「リアルタイム性」が重要視される分野に最適である。
* **組み込みシステム:** メモリリソースが厳格に制限されたマイコン制御において、`malloc` のオーバーヘッドやセグメンテーション違反を防げる。

### 2. 連結リスト  
連結リストの各ノードは、ヒープ領域上のランダムな位置（不連続なアドレス）に `malloc` される。

* **ポインタ:**
    次の要素にアクセスするには、現在のノードが持つ `next` ポインタのアドレスを読み取り、そのアドレスへ改めてアクセスする必要がある。
* **キャッシュミスとレイテンシ:**
    飛び飛びのアドレスへアクセスするため、CPUキャッシュにデータが存在しない確率（キャッシュミス）が高くなる。ミスのたびに低速なメインメモリへのデータ転送待ち（ストール）が発生し、配列に比べて処理サイクルを多く消費する。

**【適性：ソフトウェア・アプリケーション】**
これらの特性から、リスト構造は「柔軟性」や「複雑なデータ構造」が求められる分野に適している。
* **OS周り・ミドルウェア:** プロセス管理やファイルシステムなど、要素の追加・削除が頻繁で、データ総量が予測できない環境。
* **高水準アプリケーション:** エディタの履歴管理（Undo/Redo）や本課題のような複雑な並べ替えロジックなど、メモリアクセスの速度よりも、データの「関係性」の維持やアルゴリズムの実装しやすさが優先される領域。

### 結論
配列の方がキャッシュ効率が良く、read/writeが最小限で済むという利点があるが、本課題においてはノードの追加・削除の容易さとメモリ消費の最適化を優先し、双方向連結リストを選択した。

&nbsp;  
&nbsp;  

## ソートアルゴリズムの技術的選定
本プロジェクトでは、計算量 `O(N log N)` の理論値を持つ「マージソート」から着手したが、`push_swap` 特有の命令コストの壁に直面し、最終的に「コスト計算に基づく貪欲法（Greedy）」を採用した。
以下にその比較と選定の経緯を記す。

### 1. アルゴリズム比較検討

一般的なソートアルゴリズムの特性と、`push_swap`（スタック操作）における適合性の比較。

| アルゴリズム | 計算量 (平均) | スタック操作適性 | 特徴 | 判定 |
| :--- | :--- | :--- | :--- | :--- |
| **バブル / 選択** | `O(N^2)` | × 不向き | 実装は単純だが、比較と交換の回数が多すぎて規定回数を超過する。 | 却下 |
| **クイックソート** | `O(N log N)` | △ 普通 | ピボットを用いた分割を行う。スタックでも実装可能だが、最悪ケースの回避や再帰深さの管理が複雑。 | 保留 |
| **マージソート** | `O(N log N)` | ◯ 理論上良 | 安定ソート。リンクリストとの相性が良いが、スタックでは「底」へのアクセスにコストがかかる。 | **初期採用** |
| **貪欲法 (Greedy)** | `O(N^2)`※ | ◎ 最適 | 全要素の移動コストを計算し、局所最適解（その時点で最も安く動かせるノード）を選び続ける。 | **最終採用** |

※ ここでの貪欲法は比較回数ではなく、「命令出力数」の最小化に特化しているため、実効スコアが最も良くなる。

---

### 2. 初期実装：ボトムアップ型マージソート
当初は、自然配列（すでに並んでいる部分列：（Run））を活用する「自然マージソート」を実装した。

#### コンセプト
ランダムな数値列の中にある「偶然ソートされている部分（Run）」を見つけ、それらをスタックBを利用してマージさせていく手法。

#### 実装フェーズの記録
以下の手順で開発を進めた。
1. **Runの検出**
    - スタックtopから走査し、単調増加（または減少）している部分を1つの「山」として認識。
    - `check_sorted_length(stack)` 関数により、可変長のRunを管理。
2. **マージ機能**
    - スタックAとスタックBのトップ同士を比較。
    - 小さい（または大きい）方を「ソート済み」として確定させる。
3. **底送り**
    - 確定したノードを `ra` (Rotate A) でスタックの底へ送ることで、次のマージ操作に備える。

#### 直面した問題：回転コストの壁
実装後の結果は以下の通りであった。
* **100個のソート:** 1746 手 （目標：700手未満）
* **500個のソート:** 10743 手 （目標：5500手未満）

**失敗の原因分析:**
マージソートは「配列」や「ランダムアクセス可能なリスト」では優秀だが、スタック構造においては「整列したデータを底（Bottom）に送る」という操作が致命的であった。1つの要素をマージするたびに `ra` (回転) が発生し、データの個数`N`に対して`N`回近い回転が必要となるため、命令数が爆発的に増加した。

---

### 3. 最終実装：貪欲法
マージソートでの失敗を踏まえ、「整列の美しさ」よりも「1手でも命令を減らす」ことに特化したアルゴリズムへ方針を変更した。

#### コンセプト
スタックBにある全ての要素について、「スタックAの正しい位置に戻すために必要な手数」をシミュレーションし、最も少ない手数（コスト）で移動できる要素だけを実際に動かす。

#### アルゴリズムの動作
1. **初期分割**:
    - スタックAの要素を、大まかな範囲（四分位数など）でスタックBへ移動させる（`pb`）。
2. **コスト計算**:
    - スタックBの全要素について、以下のコストを計算する。
        - `rb` の回数（Bのトップに持ってくるコスト）
        - `ra` の回数（Aの受け入れ位置をトップにするコスト）
3. **最適化（同時回転）**:
    - `ra` と `rb` を個別に行うとコストがかさむため、共通の回転命令 **`rr` (Rotate Both)** および **`rrr` (Reverse Rotate Both)** を優先的に使用する。
    - 例: Aを3回、Bを2回回す場合 → `rr` を2回、`ra` を1回（計3手）で済ませる。
4. **実行**:
    - 計算された「最安値」の要素を移動させる。

#### 改善結果
- **100個のソート:** **約 600 手**（マージソート比 1/3）
- **500個のソート:** **約 4500〜5000 手**（マージソート比 1/2）

#### 結論
`push_swap` においては、アルゴリズムの理論的な計算量よりも、「共通命令 (`rr`, `rrr`) をいかに多く使い、無駄な単独回転を減らすか」がスコアに直結する。
マージソートのような「全体をきれいに保つ」アプローチよりも、計算コストを払ってでも「その瞬間毎の最適解」を選び続けるアプローチが、本課題のスタック操作には最適であった。

&nbsp;
&nbsp;

## 使い方

### コンパイル方法
Makefileより、以下のコマンドでコンパイル、クリーンアップが可能。

| コマンド | 説明 |
| :--- | :--- |
| `make` | プログラムをコンパイルし、実行ファイル `push_swap` を生成する。 |
| `make clean` | コンパイル時に生成されたオブジェクトファイル（`*.o`）を削除する。 |
| `make fclean` | オブジェクトファイルに加え、実行ファイルとライブラリ（libft等）も全て削除する。 |
| `make re` | `fclean` を実行した後、再度 `make` を行いリビルドする。 |

### 基本的な実行
引数として「ソートしたい整数のリスト」を渡して実行する。
```bash
./push_swap 2 1 3 6 58
```

**出力結果:**
ソートに必要な命令（`sa`, `pb`, `ra` 等）が標準出力に表示される。

### 動作検証とベンチマーク

以下のシェルコマンドを使用することで、ランダムな数値を用いたテストを効率的に行える。

**1. Checkerによる正誤判定**
1〜100の重複しない乱数を生成し、`push_swap` の出力を `checker` プログラムに渡してソート結果を検証する。

```bash
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
```

**2. 命令回数の計測**
ソート完了までにかかった命令数（行数）をカウントする。

```bash
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

**3. 無限ループ**
命令数が安定しているか、クラッシュしないかを確認するために繰り返し実行する。(停止は `Ctrl + C`)

```bash
while true; do ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l; done;
```

**4. Pythonテスターの使用**
`push_swap_tester.py` が環境にある場合、以下のコマンドで統計的なテストが可能。

```bash
python3 push_swap_tester.py -l 100
python3 push_swap_tester.py -l 500
```

## 参考文献

* [うさぎでもわかる配列と連結リスト](https://www.momoyama-usagi.com/entry/info-algo-list)
* [うさぎでもわかるスタックとキュー](https://www.momoyama-usagi.com/entry/info-algo-stack-queue)
* [双方向連結リストとは](https://ufcpp.net/study/algorithm/col_blist.html)
* [【初心者向け】貪欲法とは？グリーディアルゴリズムの基本から応用まで完全解説 ](https://techgym.jp/column/greed/)
* [Push Swap 〜座標圧縮せずにソートする方法〜](https://zenn.dev/grigri_grin/articles/ea2690feac54fa)

## AIの使用について

本課題では、AIツール（Gemini Pro）を以下の通りで使用した。

### 使用したタスク

1. **概念の整理と文書化:**
双方向連結リストとリングバッファ（配列）の特性比較において、計算量だけでなく、CPUキャッシュラインやメモリストールといったハードウェアレベルでの挙動の違いを理解するための壁打ち。
2. **選択アルゴリズムの深堀:**
初期実装したマージソートの手数が減らない原因の分析の壁打ち。