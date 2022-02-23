# Sum Tree
## Medium 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><div class="entry-content" style="user-select: auto;">
<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given a Binary Tree. Return <strong style="user-select: auto;">true</strong>&nbsp;if, for every node <strong style="user-select: auto;">X</strong>&nbsp;in the tree other than the&nbsp;leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return <strong style="user-select: auto;">false</strong>.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.</span></p>

<p style="user-select: auto;"><br style="user-select: auto;">
<strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Example 1:</span></strong></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:</strong>
    3
  /   \    
 1     2</span>

<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Output:</strong> 1</span>
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Explanation:
</strong>The sum of left subtree and right subtree is
1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a <strong style="user-select: auto;">sum tree</strong>.</span>
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Example 2:</span></strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Input:</span></strong>

<span style="font-size: 18px; user-select: auto;">          10
        /    \
      20      30
    /   \ 
   10    10</span>

<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Output: </strong>0</span>
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Explanation:
</strong>The given tree is not a sum tree.
For the root node, sum of elements
in left subtree is 40 and sum of elements
in right subtree is 30. Root element = 10
which is not equal to 30+40.</span></pre>

<p style="user-select: auto;"><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your Task:&nbsp; </strong><br style="user-select: auto;">
You don't need to read input or print anything. Complete the function <strong style="user-select: auto;">isSumTree() </strong>which takes <strong style="user-select: auto;">root </strong>node as input parameter and returns true if the tree is a SumTree else it returns false.</span></p>

<p style="user-select: auto;"><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity: </strong>O(N)<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space:</strong> O(Height of the Tree</span><span style="font-size: 18px; user-select: auto;">)</span></p>

<p style="user-select: auto;"><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1 ≤ number of nodes ≤ 10<sup style="user-select: auto;">4</sup></span></p>
</div>
 <p style="user-select: auto;"></p>
            </div>