# Postorder Traversal
## Easy
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given a binary tree, find the Postorder Traversal of it.<br style="user-select: auto;">
For Example, the postorder traversal of the following tree is: </span><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;">5 10 39 1</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">&nbsp; &nbsp; &nbsp; &nbsp; 1<br style="user-select: auto;">
&nbsp; &nbsp;&nbsp; / &nbsp; &nbsp; \<br style="user-select: auto;">
&nbsp;&nbsp; 10&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;39<br style="user-select: auto;">
&nbsp; /<br style="user-select: auto;">
5</span></p>

<p dir="ltr" style="user-select: auto;"><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>        19
 &nbsp; &nbsp;&nbsp;/&nbsp;&nbsp;&nbsp;&nbsp; \
 &nbsp; &nbsp;10&nbsp;&nbsp; &nbsp; &nbsp;8
  /&nbsp; &nbsp; \
 11&nbsp;  &nbsp;13
<strong style="user-select: auto;">Output: </strong>11 13 10 8 19<strong style="user-select: auto;">
</strong></span></pre>

<p dir="ltr" style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 11
 &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;/
 &nbsp; &nbsp; &nbsp; 15
 &nbsp; &nbsp; &nbsp;/
 &nbsp; &nbsp; 7
<strong style="user-select: auto;">Output:</strong> 7 15 11
</span></pre>

<p style="user-select: auto;"><br style="user-select: auto;">
<strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Your Task:</span></strong><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;">You don't need to read input or print anything. Your task is to complete the function</span><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;"> postOrder()&nbsp;</strong>that takes <strong style="user-select: auto;">root&nbsp;node </strong>as input and returns an array containing the postorder traversal of the given Binary Tree.</span></p>

<p style="user-select: auto;"><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity:&nbsp;</strong>O(N).<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space:&nbsp;</strong>O(N).</span></p>

<p style="user-select: auto;"><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1 &lt;= Number of nodes &lt;= 10<sup style="user-select: auto;">5</sup><br style="user-select: auto;">
0 &lt;= Data of a node &lt;= 10<sup style="user-select: auto;">6</sup></span></p>

<p dir="ltr" style="user-select: auto;">&nbsp;</p>
 <p style="user-select: auto;"></p>
            </div>