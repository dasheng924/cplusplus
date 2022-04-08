#include <iostream>
#include <vector>
#include <algorithm>
 
 
using namespace std;
 
 
class IntSequence
{
private:
	int m_Value;
public:
	IntSequence(int value):m_Value(value){}		
	int operator()()
	{
		return m_Value++;
	}
};
 
 
int main()
{
	vector<int> IntVec(10);
    // 0 0 0 0 0 0 0 0 0 0 2 3 4 5 6 7 8 9 10 11 ,会产生新的元素
	generate_n(back_inserter(IntVec),10,IntSequence(2));//一个函数对象产生的值给一定的范围内指定数目的容器元素赋值
	for(vector<int>::iterator it=IntVec.begin();it!=IntVec.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

    //0 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 11，会把原来的元素进行覆盖
	generate(++IntVec.begin(),--IntVec.end(),IntSequence(10));
	for(vector<int>::iterator it=IntVec.begin();it!=IntVec.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	return 0;
}