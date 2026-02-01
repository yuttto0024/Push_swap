[English](#english) | [日本語](#japanese)

&nbsp;
&nbsp;

<a id="english"></a>

# Project Name (English)

_This Project has been created as part of the 42 curriculum by yuonishi_

## Table of Contents
1. [Description](#description)
2. [Project Description](#project-description)
3. [Resources](#resources)
...

## Description
(English content...)

&nbsp;  
&nbsp;  

---













<a id="japanese"></a>

# Project Name (Japanese)

_This Project has been created as part of the 42 curriculum by yuonishi_

## 目次
1. [概要](#概要)
2. [プロジェクト詳細](#プロジェクト詳細)
3. [使い方](#使い方)
3. [参考文献](#参考文献)

&nbsp;  
&nbsp;  

---

## 概要
当課題での目的は、決められたコマンドのみを用い、スタック内をソートすること。その際、可能な限り少ない操作回数でのソートを目指す。

この課題で学ぶべきこと
1. 計算量の意識  
- 普通にソートするのであれば、バブルソート等で済むが、それだと手数が増えてしまう。
- 「動けばいい」ではなく、「効率的であること」が求められる。「どうすれば無駄な動きを削減できるか」を意識する
2. 制約のある環境下でのアルゴリズム実装
- 普段であれば、「配列の何番と何番を交換」を一瞬でできるが、スタック構造では、一番上のデータしか触れない（LIFO）という制約がある。
- この不自由な環境下での、どうアルゴリズムを実装するか、という力が求められる。
3. データ構造の実践的な操作
- スタックの構造を、実際のプログラムとして動かし、データを スタックA ⇔ スタックB と移動させる処理を実装する力が求められる。

&nbsp;  
&nbsp;  

---

## プロジェクト概要
この課題では、スタックAにあるデータを、スタックBを一時領域として利用し、「限られた命令セット」のみを使用してソートするプログラムを作成する。重要な点は、ソート完了までに出力される「命令回数の最小化」である。
### データ構造の選定
ra (Rotate A) や rra (Reverse Rotate A) 等の命令は、スタックのbottomデータとtopにあるデータを操作する。このため、適切なデータ構造を選ばなければ計算コストや実装の複雑さが跳ね上がる。

&nbsp;  
&nbsp;  

---

### データ構造比較：リンクリスト vs 配列
ここでは、「リングバッファ」と「双方向リスト」を比較する。
| 比較項目 | **A. リングバッファ（循環配列）** | **B. 双方向リスト（Doubly Linked List）** |
| :--- | :--- | :--- |
| **メモリ管理** | 静的/一括確保 (`malloc` 1回)<br>メモリが連続しておりキャッシュ効率が良い。 | 動的確保 (ノード毎に `malloc`)<br>メモリが分散するため管理が必要。 |
| **Push/Pop** | Topインデックスを増減させるだけ。 | ポインタの付け替えのみ。 |
| **Rotate (`ra`)** | Top/Bottomのインデックスをズラす。<br>(中身のコピーは発生しない) | 先頭と末尾のポインタを繋ぎ変える。 |
| **実装の難所** | **インデックス計算**<br>`0`と`MAX`の境界を超える際の剰余演算 (`%`) が複雑。 | **ポインタ管理**<br>`next`, `prev` の消失やNULL参照によるセグフォ。 |
| **学習の狙い** | 配列操作、メモリ効率 | ポインタ操作、構造体、メモリ管理の基礎 |

&nbsp;  
&nbsp;  

---

### 環境構築と実装方針 (Phase 1)
1. ディレクトリ構成

保守性と再利用性を高めるため、外部ライブラリを独立したディレクトリとして配置し、再帰的なビルド環境を構築した。
Plaintext

push_swap/
├── Makefile            # ルートMakefile（各ライブラリの呼び出しとリンク）
├── includes/           # プロジェクト共通ヘッダー
├── srcs/               # ソースコード
├── libft/              # Libftライブラリ（.git削除済み）
└── ft_printf/          # ft_printfライブラリ（.git削除済み）

2. Makefile設計

    再リンク防止 (Relink protection): ソース変更がない場合はコンパイルを行わない設計。

    ライブラリ統合: libft および ft_printf をサブディレクトリのMakefileに委譲 (make -C) し、生成された .a ファイルをリンク (-L -l) する構成を採用。

3. データ構造の定義 (push_swap.h)

比較実装を行うため、以下の2つの構造体を定義済み。

    t_ring: 循環バッファ用の構造体（データ配列、top/bottomインデックス、サイズ管理）。

    t_stack (t_node): 双方向リスト用の構造体（値、next/prevポインタ）。

---

### ソートの選択  
ソートの基本形は、主に「交換法」「選択法」「挿入法」の3つ

&nbsp;
&nbsp;

---

## 参考文献
- [うさぎでもわかるスタックとキュー](https://www.momoyama-usagi.com/entry/info-algo-stack-queue)
- [双方向連結リストとは](https://ufcpp.net/study/algorithm/col_blist.html)
&nbsp;  
&nbsp;  

---

### AIの使用について
本課題では、AIツール（Gemini Pro）を以下の通りで使用した。
### 使用したタスク
- 1
- 2
- 3

&nbsp;  
&nbsp;  

---

# 作業用メモ
- 参考記事：[うさぎでもわかるスタックとキュー（配列を使ったデータ構造）](https://www.momoyama-usagi.com/entry/info-algo-stack-queue)
- 
	- スタック  
		- ルール  
	  		LIFO (Last In, First Out) - 後に入れたものが先に出る。
		- 仕組み
	  		出入り口は「上 (top)」の1箇所のみ。
		- 特徴  
	  		データは消さずに top の位置をズラすだけで管理する（データは消さずに無視）。　　
		### 構造体：
		```c
		typedef struct	s_stack
		{
			int	elm[SIZE];
			int	top;
		}				t_stack;
		```
		### 動作
		```c
		void	push(t_stack *s, int x)
		{
		s->top += 1;
		s->elm[s->top] = x;
		}
		
		int		pop(t_stack *s)
		{
			int	out_data;

			out_data = s->elm[s->top];
			s->top -= 1;
			return (out_data);
		}
		```
	  - 実用例  
	  ChromeやFirefoxの「戻るボタン」がスタック。戻るボタンを押すと直前のページへ移動し、更に連打するとより古い履歴に遡っていく。	
	- キュー  
		- ルール  
	  		FIFO (First In, First Out) - 先に入れたものが先に出る。
		- 仕組み
	  		出入り口は「入口 (end)」と「出口 (start)」の2箇所。
		- 特徴  
	  		配列の端まで来たら、% SIZE で先頭に戻る（環状、リングキュー）。  
			start と end が重なると「空」かどうか区別できないため、count で個数を数える。
		### 構造体：
		```c
		typedef struct	s_queue
		{
			int	elm[SIZE];
			int	start;
			int	end;
			int	count;
		}				t_queue;
		```
		### 動作
		```c
		int	nextStep(int x)
		{
			return ((x + 1) % SIZE);
		}

		void	enqueue(t_queue *q, int x)
		{
			q->elm[q->end] = x;
			q->end = nextStep(q->end);
			q->count++;
		}

		int	dequeue(t_queue *q)
		{
			int	out_data;

			out_data = q->elm[q->start];
			q->start = nextStep(q->start);
			q->count--;
			return (out_data);
		}
		```