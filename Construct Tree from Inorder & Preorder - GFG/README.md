# Construct Tree from Inorder & Preorder
## Medium 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal.&nbsp;</span></p>

<p style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Example 1:</span></strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Input:
</span></strong><span style="font-size: 18px; user-select: auto;">N = 4
inorder[] = {1&nbsp;6 8 7}
preorder[] = {1 6 7 8}
<strong style="user-select: auto;">Output: </strong>8 7 6 1</span>
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Example 2:</span></strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Input:
</span></strong><span style="font-size: 18px; user-select: auto;">N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
<strong style="user-select: auto;">Output: </strong>3 4 1 5 2 0<strong style="user-select: auto;">
Explanation: </strong>The tree will look like
&nbsp; &nbsp;    0
&nbsp; &nbsp;&nbsp;/&nbsp; &nbsp; &nbsp;\
&nbsp; &nbsp;1&nbsp; &nbsp; &nbsp; &nbsp;2
&nbsp;/&nbsp; &nbsp;\&nbsp; &nbsp; /
3&nbsp; &nbsp; 4&nbsp; &nbsp;5</span></pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your Task:</strong><br style="user-select: auto;">
Your task is to complete the function <strong style="user-select: auto;">buildTree()&nbsp;</strong>which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity</strong>: O(N*N).<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space:</strong>&nbsp;O(N).</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1&lt;=Number of Nodes&lt;=1000</span></p>
 <p style="user-select: auto;"></p>
            </div>