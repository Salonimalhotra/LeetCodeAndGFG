# Check for Balanced Tree
## Easy 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given a binary tree, find if it is height balanced or not.&nbsp;<br style="user-select: auto;">
A tree is height balanced if difference between heights of left and right subtrees is <strong style="user-select: auto;">not more than one</strong> for all nodes of tree.&nbsp;</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">A height balanced tree</strong><br style="user-select: auto;">
&nbsp; &nbsp; &nbsp; &nbsp; 1<br style="user-select: auto;">
&nbsp; &nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp; \<br style="user-select: auto;">
&nbsp;&nbsp; 10&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 39<br style="user-select: auto;">
&nbsp; /<br style="user-select: auto;">
5</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">An unbalanced tree</strong><br style="user-select: auto;">
&nbsp; &nbsp; &nbsp; &nbsp; 1<br style="user-select: auto;">
&nbsp; &nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp;<br style="user-select: auto;">
&nbsp;&nbsp; 10&nbsp;&nbsp;&nbsp;<br style="user-select: auto;">
&nbsp; /<br style="user-select: auto;">
5</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1
 &nbsp;&nbsp;&nbsp;/
&nbsp;&nbsp; 2
 &nbsp; &nbsp;\
 &nbsp; &nbsp; 3&nbsp;
<strong style="user-select: auto;">Output: </strong>0<strong style="user-select: auto;">
Explanation: </strong>The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced</span>
</pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10
 &nbsp;&nbsp;&nbsp;&nbsp;/&nbsp;&nbsp; \
 &nbsp;&nbsp;&nbsp;20&nbsp;&nbsp; 30 
&nbsp;&nbsp;/&nbsp;&nbsp; \
 40&nbsp;&nbsp; 60
<strong style="user-select: auto;">Output:</strong> 1<strong style="user-select: auto;">
Explanation: </strong>The max difference in height
of left subtree and right subtree is 1.
Hence balanced.<strong style="user-select: auto;"> </strong></span>
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Your Task:</span></strong><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;">You don't need to take input. Just complete the function<strong style="user-select: auto;"> isBalanced() </strong>that takes root <strong style="user-select: auto;">node </strong>as parameter and returns <strong style="user-select: auto;">true, </strong>if the tree is balanced else returns <strong style="user-select: auto;">false</strong>.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1 &lt;= Number of nodes &lt;= 10<sup style="user-select: auto;">5</sup><br style="user-select: auto;">
0 &lt;= Data of a node &lt;= 10<sup style="user-select: auto;">6</sup></span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected time complexity:&nbsp;</strong>O(N)</span><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected auxiliary space:&nbsp;</strong>O(h) , where h = height of tree</span></p>
 <p style="user-select: auto;"></p>
            </div>