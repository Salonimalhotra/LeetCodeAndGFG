# Largest BST
##  Medium 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.<br style="user-select: auto;">
<strong style="user-select: auto;">Note: </strong>Here Size is equal to the number of nodes in the subtree.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:</strong>
&nbsp;       1
&nbsp;     /   \
&nbsp;    4     4
&nbsp;  /   \
&nbsp; 6     8<strong style="user-select: auto;">
Output: </strong>1<strong style="user-select: auto;">
Explanation: </strong>There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.</span>
</pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input: </strong>6 6 3 N 2 9 3 N 8 8 2
&nbsp;           6
&nbsp;       /       \
&nbsp;      6         3
&nbsp;       \      /   \
&nbsp;        2    9     3
&nbsp;         \  /  \
&nbsp;         8 8    2 <strong style="user-select: auto;">
Output: </strong>2<strong style="user-select: auto;">
Explanation: </strong>The following sub-tree is a
BST of size 2:&nbsp;
&nbsp; &nbsp; &nbsp;  2
&nbsp; &nbsp; /&nbsp; &nbsp; \&nbsp;
&nbsp;  N&nbsp; &nbsp; &nbsp; 8</span></pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your Task:</strong><br style="user-select: auto;">
You don't need to read input or print anything. Your task is to complete the function</span><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;"> largestBst()&nbsp;</strong>that takes the root node of the Binary Tree<strong style="user-select: auto;">&nbsp;</strong>as its input&nbsp;and returns the size&nbsp;of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree.&nbsp;</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity:&nbsp;</strong>O(N).<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space:&nbsp;</strong>O(Height of the BST).</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1 ≤ Number of nodes ≤ 10<sup style="user-select: auto;">5</sup><br style="user-select: auto;">
1 ≤ Data of a node ≤ 10<sup style="user-select: auto;">6</sup></span></p>
 <p style="user-select: auto;"></p>
            </div>