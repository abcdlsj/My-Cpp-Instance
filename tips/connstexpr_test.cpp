#include <bits/stdc++.h>
using namespace std;

// C++编译时可确定常量表达式的结果，因此可在编译时优化。C++规范在一些地方要求使用常量表达式，如声明数组的维数。但常量表达式不允许包含函数调用或者对象构造。因此下述代码无效：
// int get_five() {return 5;}
// int some_value[get_five() + 2];

// C++11引入了关键字constexpr，允许编程者保证函数或对象的构造函数是编译时常量。[1]上述代码可以改写为：
constexpr int get_five() {return 5;}
int some_value[get_five() + 2];
