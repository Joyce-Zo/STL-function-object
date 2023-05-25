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
		this->count = 0; // ��ʼ��Ϊ0
	}
	void  operator()(string s)
	{
		cout << s << endl;
		this->count++;
	}
	int count; // ��¼�Լ�״̬
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
void doPrint(MyPrint& mp,string s) // mp��Ϊһ���������д���
{
	mp(s); // ͬʱ����ʹ����������ӡs
}
void test03()
{
	MyPrint myprint;
	doPrint(myprint, "Hello my");
}

// һԪν��
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
	// ����GreateFive�º���������Ӧ���ȴ���һ������������ʹ��
	// ������ֱ��ʹ����������GreateFive();
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreateFive());
	if (it != v.end())
		cout << "���ˣ�" << *it;
	else
		cout << "û��" << endl;
}

// ��Ԫν��
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
	bool operator()(int x, int y) // ��Ԫν�ʣ�2������
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

	// ʹ�ú�������MyCompare()ʹ��ʵ�ֽ���
	sort(v.begin(), v.end(), MyCompare());
	printv(v);
}

//  �ڽ���������
#include<functional>
/*�����º���
template<class T> T plus<T>		 �ӷ��º���
template<class T> T minus<T>	 ����	
template<class T> T multiplies<T>�˷�
template<class T> T divides<T>	 ����
template<class T> T modulus<T>	 ȡģ
template<class T> T negate<T>	 ȡ��
*/
// negate ȡ���º���
void test06()
{	
	negate<int> n;
	cout << n(50) << endl;
}
// plus �ӷ��º���
void test07()
{
	plus<int> p; // Ĭ�ϴ�ͬ����������
	cout << p(5,10) << endl;
}
/*��ϵ�º���
template<class T> bool equal_to<T>		 ����
template<class T> bool not_equal_to<T>	 ������
template<class T> bool greater<T>		 ����
template<class T> bool greater_equal<T>  ���ڵ���
template<class T> bool less<T>			 С��
template<class T> bool less_equal<T>	 С�ڵ���
*/
// ����
void test08()
{
	vector<int> v;
	v.push_back(10);	v.push_back(40);	v.push_back(20);
	v.push_back(30);	v.push_back(50);	v.push_back(60);
	sort(v.begin(), v.end());
	printv(v);

	// ʹ�ú�������MyCompare()ʹ��ʵ�ֽ���
	//sort(v.begin(), v.end(), MyCompare());
	
	// ʹ���ڽ���������
	sort(v.begin(), v.end(), greater<int>());
	printv(v);
}

/*�߼��º���
template<class T> bool logical_and<T>	�߼��룬ͬʱΪ����棬����Ϊ��
template<class T> bool logical_or<T>	�߼���ͬʱΪ�ٲż٣�����Ϊ��
template<class T> bool logical_not<T>	�߼��ǣ�ȡ������
*/
void test09()
{
	vector<int > v;
	v.push_back(true);	v.push_back(false);	v.push_back(true);
	v.push_back(true);	v.push_back(false);
	printv(v);

	// ȡ����������һ������
	vector<int> v2;
	v2.resize(v.size()); // ָ��v2��sizeΪv��size
	transform(v.begin(), v.end(), v2.begin(),logical_not<int>());
	//�����㷨	 ��ʼ      ��ֹ    Ŀ�����ʼ   �߼���
	printv(v2);
}
int main()
{
	test09();
	return 0;
}
