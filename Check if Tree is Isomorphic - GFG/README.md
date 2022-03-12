# Check if Tree is Isomorphic
## Easy 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given two&nbsp;Binary Trees. Check whether they are&nbsp;Isomorphic or not.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Note:&nbsp;</strong><br style="user-select: auto;">
Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes.&nbsp;Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.<br style="user-select: auto;">
For example, the following two trees are isomorphic with the following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.<br style="user-select: auto;">
<a href="https://media.geeksforgeeks.org/wp-content/cdn-uploads/ISomorphicTrees-e1368593305854.png" target="_blank" style="user-select: auto;"><img alt="ISomorphicTrees" src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/ISomorphicTrees-e1368593305854.png" class="img-responsive" style="user-select: auto;"></a></span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
 T1    </strong>1     <strong style="user-select: auto;">T2:</strong>   1
&nbsp;    /   \        /  \
&nbsp;   2     3      3    2
&nbsp;  /            /
&nbsp; 4<strong style="user-select: auto;">&nbsp;           </strong>4<strong style="user-select: auto;">
Output: </strong>No<strong style="user-select: auto;">
</strong></span>
</pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
T1    </strong>1     <strong style="user-select: auto;">T2:</strong>    1
&nbsp;   /  \         /   \
&nbsp;  2    3       3     2
&nbsp; /                    \
&nbsp; 4<strong style="user-select: auto;">&nbsp;                    </strong>4<strong style="user-select: auto;">
Output: </strong>Yes<strong style="user-select: auto;">
</strong></span></pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your Task:</strong><br style="user-select: auto;">
You don't need to read input or print anything. Your task is to complete the function<strong style="user-select: auto;"> isomorphic() </strong>that takes<strong style="user-select: auto;">&nbsp;</strong>the root&nbsp;nodes of both the Binary Trees as its input&nbsp;and returns True if the two trees are isomorphic. Else, it returns False. (The driver code will print Yes if the returned values are true, otherwise false.)</span></p>

<p style="user-select: auto;">&nbsp;</p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity:&nbsp;</strong>O(min(M, N)) where M and N are the sizes of the two trees.<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space:&nbsp;</strong>O(min(H1, H2)) where H1 and H2 are the heights of the two trees.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1&lt;=Number of nodes&lt;=10<sup style="user-select: auto;">5</sup></span></p>
 <p style="user-select: auto;"></p>
            </div>