# Boundary Traversal of binary tree
## Medium 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:&nbsp;</span></p>

<ol style="user-select: auto;">
	<li style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Left boundary nodes:</strong>&nbsp;defined as the path from the root to the left-most node&nbsp;</span><span style="font-size: 18px; user-select: auto;">ie- the&nbsp;leaf node you could reach when you always travel preferring&nbsp;the left subtree over the&nbsp;right subtree.&nbsp;</span></li>
	<li style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Leaf nodes:&nbsp;</strong>All the leaf nodes except for the ones that are part of left or right boundary.</span></li>
	<li style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Reverse right boundary nodes:</strong>&nbsp;defined as the path from&nbsp;the right-most node to the&nbsp;root. The&nbsp;right-most node is&nbsp;the&nbsp;leaf node you could reach when you always travel preferring&nbsp;the right subtree over the&nbsp;left subtree.&nbsp;Exclude the root from this as it was already included in the traversal of left boundary nodes.</span></li>
</ol>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Note:</strong> If the root doesn't have a left subtree or right subtree, then the root itself is the left&nbsp;or right boundary.&nbsp;</span><br style="user-select: auto;">
<br style="user-select: auto;">
<strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Example 1:</span></strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Input:
        </span></strong><span style="font-size: 18px; user-select: auto;">1 
&nbsp;     /   \
&nbsp;    2     3</span><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">&nbsp; 
&nbsp;   </span></strong><span style="font-size: 18px; user-select: auto;">/ \   / \ 
&nbsp;  4   5 6   7
&nbsp;     / \
&nbsp;    8   9</span><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">
   
Output: </span></strong><span style="font-size: 18px; user-select: auto;">1 2 4 8 9 6 7 3</span><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">
Explanation:
</span></strong><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;"><img alt="" src="https://media.geeksforgeeks.org/wp-content/uploads/20211103204119/graph4-300x300.png" style="height: 300px; width: 300px; user-select: auto;" class="img-responsive"></strong></span><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">
</span></strong>
</pre>

<p style="user-select: auto;">&nbsp;</p>

<p style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Example 2:</span></strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Input:</span></strong>
<span style="font-size: 18px; user-select: auto;">&nbsp;           1
&nbsp;          / 
&nbsp;         2
&nbsp;       /  \
&nbsp;      4    9
&nbsp;    /  \    \
&nbsp;   6    5    3
&nbsp;            /  \
&nbsp;           7     8
</span><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">
Output: </span></strong><span style="font-size: 18px; user-select: auto;">1 2 4 6 5 7 8
<strong style="user-select: auto;">Explanation: 
</strong>As you can see we have not taken right
subtree. See <strong style="user-select: auto;">Note</strong></span>
<span style="font-size: 18px; user-select: auto;"><a href="https://contribute.geeksforgeeks.org/wp-content/uploads/boundary.png" target="_blank" style="user-select: auto;"><img alt="" src="https://media.geeksforgeeks.org/wp-content/uploads/20211103204646/graph1-300x300.png" style="float: left; height: 300px; width: 300px; user-select: auto;" class="img-responsive"></a></span>
</pre>

<p style="user-select: auto;">&nbsp;</p>

<p style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Y</span></strong><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">our Task:</span></strong><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;">This is a function problem. You don't have to take input. Just complete the <strong style="user-select: auto;">function boundary()&nbsp;</strong>that takes the root node<strong style="user-select: auto;">&nbsp;</strong>as input<strong style="user-select: auto;">&nbsp;</strong>and returns an array containing&nbsp;the boundary values in anti-clockwise.</span></p>

<p style="user-select: auto;">&nbsp;</p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity:</strong> O(N).&nbsp;<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space:</strong> O(Height of the Tree).</span></p>

<p style="user-select: auto;">&nbsp;</p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></span><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;">1 ≤ Number of nodes ≤ 10<sup style="user-select: auto;">5</sup></span><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;">1 ≤ Data of a node ≤ 10<sup style="user-select: auto;">5</sup></span></p>
 <p style="user-select: auto;"></p>
            </div>