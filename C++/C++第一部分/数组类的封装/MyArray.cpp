#include "MyArray.h"

//无参构造函数，用户没有指定容量，则初始化为100
	MyArray::MyArray()
	{
		this->mCapacity = 100;
		this->mSize = 0;
		this->pAdress = new int[this->mCapacity] ;
	}
	//有参构造函数，用户指定容量初始化
	MyArray::MyArray(int capacity)
	{
		this->mCapacity = capacity;
		this->mSize = 0;
		this->pAdress = new int[this->mCapacity] ;
	}
	//用户操作接口
	//根据位置添加元素
	void MyArray::SetData(int pos, int val)
	{
		if(pos < 0 || pos > this->mCapacity -1)
			return ;
		*(this->pAdress + pos) = val;
	}
	//获得指定位置数据
	int MyArray::GetData(int pos)
	{
		return (*(this->pAdress+pos)) ;
	}
	//尾插法
	void MyArray::PushBack(int val)
	{
		if(this->mSize >= this->mCapacity)
			return;
		pAdress[this->mSize] = val;
		this->mSize++;
	}
	//获得长度
	int MyArray::GetLength()
	{
		return this->mSize ;
	}

	//析构函数，释放数组空间
	MyArray::~MyArray()
	{
		if(this->pAdress != nullptr)
		{
			delete []this->pAdress;
			this->pAdress = nullptr ;
		}
		
	}

/*
	int mCapacity; //数组一共可容纳多少个元素
	int mSize; //当前有多少个元素
	int* pAdress; //指向存储数据的空间
*/