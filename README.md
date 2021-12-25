# 李航老师的统计学习方法



## 感知机

初步实现了感知机的原始形式

对偶形式先鸽一鸽

12/25 写完了对偶形式，发现原始形式和对偶形式本质是一模一样的

<code>

w = w + LR * y * x

b  = b + LR * y

</code>



那就从算法本身考虑，因为对偶形式提前计算了Gram矩阵，所以在运算判断肯定会比原始形式要来的快，估计对偶形式名字的来源就是Gram是一个对称矩阵吧，再者，实际上运算还能减少，把y也对应乘到Gram中，虽然Gram不对称了，但是计算量进一步的减少了。

当然，这里减少计算量的前提是拿出一部分空间去存储不变的东西。这种形式的优化应该到处都是。

ps: 我写的代码里面看起来很赘余，因为我想在优化的时候选取random的点。现在想想，取random好像完全没有必要，可行但是没必要。所以这就导致了我写的代码里面对偶形式的计算量大于原始形式。但，写都写完了。开摸！！



## k近邻法

12/21: 目前是已经粗糙得实现了，没有报错。能得到树的root。但是没有验证树是否完整。

