#include<iostream>
using namespace std;
#include<string>

class MyAdd
{
public:
	int operator()(int x,int y)
	{
		return x + y;
	}
};
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0; // 初始化为0
	}
	void  operator()(string s)
	{
		cout << s << endl;
		this->count++;
	}
	int count; // 记录自己状态
};
void test01()
{
	MyAdd myadd;
	cout << myadd(1, 5) << endl;
}
void test02()
{
	MyPrint myprint;
	myprint("Jocye is my ba");	myprint("Jocye is my ba");
	myprint("Jocye is my ba");	myprint("Jocye is my ba");
	cout << myprint.count << endl;
}
void doPrint(MyPrint& mp,string s) // mp作为一个参数进行传递
{
	mp(s); // 同时还能使用自身来打印s
}
void test03()
{
	MyPrint myprint;
	doPrint(myprint, "Hello my");
}

// 一元谓词
#include<vector>
#include<algorithm>
class GreateFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test04()
{
	vector <int> v;
	int i = 10;
	while (i--)
	{
		v.push_back(i);
	}
	// 上面GreateFive仿函数，正常应该先创建一个对象，下面再使用
	// 这里我直接使用匿名对象GreateFive();
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreateFive());
	if (it != v.end())
		cout << "有了：" << *it;
	else
		cout << "没有" << endl;
}

// 二元谓词
void printv(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
class MyCompare
{
public:
	bool operator()(int x, int y) // 二元谓词，2个参数
	{
		return x > y;
	}
};
void test05()
{
	vector<int> v;
	v.push_back(10);	v.push_back(40);	v.push_back(20);
	v.push_back(30);	v.push_back(50);	v.push_back(60);
	sort(v.begin(),v.end());
	printv(v);

	// 使用函数对象MyCompare()使其实现降序
	sort(v.begin(), v.end(), MyCompare());
	printv(v);
}

//  内建函数对象
#include<functional>
/*算数仿函数
template<class T> T plus<T>		 加法仿函数
template<class T> T minus<T>	 减法	
template<class T> T multiplies<T>乘法
template<class T> T divides<T>	 除法
template<class T> T modulus<T>	 取模
template<class T> T negate<T>	 取反
*/
// negate 取反仿函数
void test06()
{	
	negate<int> n;
	cout << n(50) << endl;
}
// plus 加法仿函数
void test07()
{
	plus<int> p; // 默认传同种数据类型
	cout << p(5,10) << endl;
}
/*关系仿函数
template<class T> bool equal_to<T>		 等于
template<class T> bool not_equal_to<T>	 不等于
template<class T> bool greater<T>		 大于
template<class T> bool greater_equal<T>  大于等于
template<class T> bool less<T>			 小于
template<class T> bool less_equal<T>	 小于等于
*/
// 大于
void test08()
{
	vector<int> v;
	v.push_back(10);	v.push_back(40);	v.push_back(20);
	v.push_back(30);	v.push_back(50);	v.push_back(60);
	sort(v.begin(), v.end());
	printv(v);

	// 使用函数对象MyCompare()使其实现降序
	//sort(v.begin(), v.end(), MyCompare());
	
	// 使用内建函数对象
	sort(v.begin(), v.end(), greater<int>());
	printv(v);
}

/*逻辑仿函数
template<class T> bool logical_and<T>	逻辑与，同时为真才真，其余为假
template<class T> bool logical_or<T>	逻辑或，同时为假才假，其余为真
template<class T> bool logical_not<T>	逻辑非，取反操作
*/
void test09()
{
	vector<int > v;
	v.push_back(true);	v.push_back(false);	v.push_back(true);
	v.push_back(true);	v.push_back(false);
	printv(v);

	// 取反，放入另一个容器
	vector<int> v2;
	v2.resize(v.size()); // 指定v2的size为v的size
	transform(v.begin(), v.end(), v2.begin(),logical_not<int>());
	//搬运算法	 起始      终止    目标的起始   逻辑非
	printv(v2);
}
int main()
{
	test09();
	return 0;
}
