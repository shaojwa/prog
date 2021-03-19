
##182@duplicate emails  
@20151124  
这到题的关键还是GROUP BY语句和HAVING的用法。不过这里的语法层次稍微说下。 SELECT是一个statement，而GROUP BY 是一个clause，这是两个层次的问题。我们可以这么说，GROUP BY生成的是基于原表生成的新表。而select对新表的结果进行查询，而非原表。另外一个地方是HAVING，我们知道HAVING也是一个clause，在理解不深的情况下，我就当HAVING是和GROUP BY并列的clause，同样也是作用才在原表上的。


##197@rising temperature  
@20151125  
这题的第一反映表显然是某一行对另外一行的比较。但是没找到办法。不过多年不用sql已经忘记可以表格自己可以和自己JOIN。看了别人的讨论发现人家用的是逗号隔开，完全不用JOIN关键字，但是我用JOIN是一样的效果。
于是就找官网查看。

SELECT 是statement,查看SELECT syntax就发现FROM后面是table_references。然后查看table_references就能关联到JOIN syntax。第一条语法就看到逗号分割的语法:  
table_references:  
escaped_table_refreence [, escaped_table_refreence]  ...
文档里也提到逗号comma运算符和INNER JOIN的一些区别，不详细说。

##196@second hightest salary
这题有一个问题就是不能在delete的同时在select-from里引用同样的表，所以这里嵌套select，先用select把结果保存到另外一个表中：
`DELETE  FROM Person WHERE id NOT IN (SELECT * FROM`
`((SELECT MIN(id) FROM Person GROUP BY email) AS p));`

##176@second hightest salary
@20151130
这道题有网上有很多解法，其中有一个比较简单的解法是：
`SELECT MAX(salary) FROM Employee WHERE`
`salary < (SELECT MAX(salary) FROM Employee);`


但是这个解法没有什么语法可以学。然后有人就这么写：
`select distinct (Salary) from Employee`
`order by Salary Desc limit 1,1;`

但是这么写有问题，如果不存在第二高的工资，则返回的是空，而不是NULL。于是有人包了一层：
`select (select distinct (Salary) from Employee order by Salary Desc limit 1,1)`
`as salary;`

结果可以了，原因我现在也没清楚为什么包了一层就可以。这个方法一个很比较有意思的功能就是`LIMIT N，M`。还有人用union+limit来做，也很强大。
`(select distinct (Salary) from Employee order by Salary Desc limit 1,1)`
`union (select NULL) limit 1`