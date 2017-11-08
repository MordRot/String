#include <string.h>

class MyString
{
public:
	MyString();
	MyString(char* newStr);
	MyString(const MyString &newStr);
	~MyString();
	
	/*
	Output: the string
	*/
	char* GetStr();

	/*
	Output: the actually size of the string
	*/
	int GetLength();

	/*
	assign new string
	Input: the new string
	*/
	void Assign(char* newStr);
	void Assign(MyString &newStr);

	/*
	appends new string to the old string
	Input: new string
	*/
	void Append(char* newStr);
	void Append(MyString &newStr);

	/*
	Input: index of the charactor to return.
	Output: the charactor in the index place. Or NULL if the index is bigger then the size of the string.
	*/
	char CharAt(unsigned int &index);

	/*
	copmare between to strings.
	Input: tow strings.
	Output:	 1 if the left string is biggger.
			-1 if the right string is biggger.
			0 if there are equal.
	*/
	static int Compare(MyString &rh, MyString &lh);

	/*
	Output: True if the string is NULL.
			False otherwise.
	*/
	bool IsEmpty();

	/*
	erases the string
	*/
	void Clear();
	
private:
	// pointer to the string
	char* m_str;

	// size of the array of m_str. 0 if the pointer is NULL.
	unsigned int m_size;
};