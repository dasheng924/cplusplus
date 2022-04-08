#include "MyArray.h"


/*
//无参构造函数，用户没有指定容量，则初始化为100
	MyArray();
	//有参构造函数，用户指定容量初始化
	explicit MyArray(int capacity);
	//用户操作接口
	//根据位置添加元素
	void SetData(int pos, int val);
	//获得指定位置数据
	int GetData(int pos);
	//尾插法
	void PushBack(int val);
	//获得长度
	int GetLength();
*/

int main(void)
{
    MyArray * array = new MyArray;
    cout<<"size"<<array->GetLength()<<endl;

    return 0;
}

