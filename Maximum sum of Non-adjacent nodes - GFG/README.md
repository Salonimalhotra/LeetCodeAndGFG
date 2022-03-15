# Maximum sum of Non-adjacent nodes
## Medium 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<img alt="" src="http://cdncontribute.geeksforgeeks.org/wp-content/uploads/nodeSubsetWithMaxSum.png" style="height: 263px; width: 600px; user-select: auto;" class="img-responsive"></span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>     11
&nbsp;   /  \
&nbsp;  1    2
<strong style="user-select: auto;">Output: </strong>11<strong style="user-select: auto;">
Explanation: </strong>The maximum sum is sum of
node&nbsp;11.</span></pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
&nbsp;       </strong>1
<strong style="user-select: auto;">      /   \
&nbsp;    </strong>2     3
&nbsp;   /     /  \
&nbsp;  4     5    6
<strong style="user-select: auto;">Output: </strong>16<strong style="user-select: auto;">
Explanation: </strong>The maximum sum is sum of
nodes 1 4 5 6<strong style="user-select: auto;"> </strong>, i.e 16. These nodes are
non adjacent.</span></pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your Task:</strong><br style="user-select: auto;">
You don't need to read input or print anything. You just&nbsp;have to complete&nbsp;function&nbsp;<strong style="user-select: auto;">getMaxSum() </strong>which accepts root node of the tree as parameter and returns the maximum sum as described.</span></p>

<p dir="ltr" style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity: </strong>O(Number of nodes in the tree).<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space: </strong>O(Height of the Tree).</span></p>

<div style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1 ≤ Number of nodes in the tree ≤ 10000</span></div>

<div style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">1 ≤ Value of each node ≤ 100000</span></div>
 <p style="user-select: auto;"></p>
            </div>