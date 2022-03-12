# Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)
## Easy 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 20px; user-select: auto;">Given a binary tree of size&nbsp;<strong style="user-select: auto;">N.</strong>&nbsp;Your task is to complete the function&nbsp;<strong style="user-select: auto;">sumOfLongRootToLeafPath(),</strong>&nbsp;that find the sum of all nodes on the longest path from root to leaf node.<br style="user-select: auto;">
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.</span></p>

<p style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 20px; user-select: auto;">Example 1:</span></strong></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:</strong> 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
<strong style="user-select: auto;">Output:</strong> 13
<strong style="user-select: auto;">Explanation:</strong>
        <strong style="user-select: auto;">4</strong>        
       / \       
      <strong style="user-select: auto;">2</strong>   5      
     / \ / \     
    7  <strong style="user-select: auto;">1</strong> 2  3 
      /
     <strong style="user-select: auto;">6</strong>

The highlighted nodes <strong style="user-select: auto;">(4, 2, 1, 6)</strong> above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13</span></pre>

<p style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Example 2:</span></strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Input: </span></strong><span style="font-size: 18px; user-select: auto;">
&nbsp;         1
&nbsp;       /   \
&nbsp;      2     3
&nbsp;     / \   / \
&nbsp;    4   5 6   7</span>
<strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Output: </span></strong><span style="font-size: 18px; user-select: auto;">11</span>
</pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your Task:</strong></span><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;">You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong style="user-select: auto;">sumOfLongRootToLeafPath</strong></span><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">()&nbsp;</strong>which takes root node of the tree as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree. If the tree is empty, return 0.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity:</strong>&nbsp;O(N)<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1 &lt;= Number of nodes &lt;= 10</span><sup style="user-select: auto;"><span style="font-size: 15px; user-select: auto;">4</span></sup><br style="user-select: auto;">
<span style="font-size: 18px; user-select: auto;">1 &lt;= Data of a node &lt;= 10<sup style="user-select: auto;">4</sup></span></p>
 <p style="user-select: auto;"></p>
            </div>