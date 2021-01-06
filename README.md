# ICRA_shortest_path

本版本暂时通过文件流调试

### 输入格式：

map.in：

n,m//行数，列数

{

map|

n line, m code per line

"010111000"

"1"代表有障碍物

}

x,y,xx,yy（起点(x,y), 终点(xx,yy)）

### 输出格式：

map.out：

X（代表路径长度）

{

map|"2"代表路径

}

x,y（起点）

{

x^[i],y^[i]|
平滑后的路径的关键节点

"this is a new part"

}

t（代码运行用时|ms）
