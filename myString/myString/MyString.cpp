#include "MyString.h"

MyString::MyString()
{
	m_str = NULL;
	m_size = 0;
}

MyString::MyString(char* newStr)
{
	m_str = new char[strlen(newStr) + 1];
	strcpy_s(m_str, sizeof m_str, newStr);
	m_size = strlen(newStr) + 1;
}

MyString::MyString(const MyString &newStr)
{
	m_str = new char[strlen(newStr.m_str) + 1];
	strcpy_s(m_str, sizeof m_str, newStr.m_str);
	m_size = strlen(newStr.m_str) + 1;
}

MyString::~MyString()
{
	if (m_str != NULL)
	{
		delete m_str;
	}
}

char* MyString::GetStr()
{
	return m_str;
}

int MyString::GetLength()
{
	return strlen(m_str);
}

void MyString::Assign(char* newStr)
{
	if (strlen(newStr) < m_size)
	{
		strcpy_s(m_str, sizeof m_str + 1, newStr);
	}
	else
	{
		delete m_str;
		m_str = new char[strlen(newStr) + 1];
		strcpy_s(m_str, sizeof m_str, newStr);
		m_size = strlen(newStr) + 1;
	}
}

void MyString::Assign(MyString &newStr)
{
	if (strlen(newStr.m_str) < m_size)
	{
		strcpy_s(m_str, sizeof m_str + 1, newStr.m_str);
	}
	else
	{
		delete m_str;
		m_str = new char[strlen(newStr.m_str) + 1];
		strcpy_s(m_str, sizeof m_str, newStr.m_str);
		m_size = strlen(newStr.m_str) + 1;
	}
}

void MyString::Append(char* newStr)
{
	if (strlen(m_str) + strlen(newStr) < m_size)
	{
		strcat_s(m_str, sizeof m_str, newStr);
	}
	else
	{
		char* tmp = new char[strlen(m_str) + strlen(newStr) + 1];
		strcpy_s(tmp, sizeof m_str, m_str);
		strcat_s(tmp, sizeof tmp, newStr);
		delete m_str;
		m_str = tmp;
		m_size = strlen(m_str) + 1;
	}
}

void MyString::Append(MyString &newStr)
{
	if (strlen(m_str) + strlen(newStr.m_str) < m_size)
	{
		strcat_s(m_str, sizeof m_str, newStr.m_str);
	}
	else
	{
		char* tmp = new char[strlen(m_str) + strlen(newStr.m_str) + 1];
		strcpy_s(tmp, sizeof m_str, m_str);
		strcat_s(tmp, sizeof tmp, newStr.m_str);
		delete m_str;
		m_str = tmp;
		m_size = strlen(m_str) + 1;
	}
}

char MyString::CharAt(unsigned int &index)
{
	char ans = NULL;
	if (index < strlen(m_str))
	{
		ans = m_str[index];
	}
	return ans;
}

int MyString::Compare(MyString &rhs, MyString &lhs)
{
	int ans = 0;
	if (rhs.m_str != NULL && lhs.m_str != NULL)
	{
		ans = strcmp(rhs.m_str, lhs.m_str);
	}
	else if (rhs.m_str != NULL)
	{
		ans = 1;
	}
	else
	{
		ans = -1;
	}
	return ans;
}

bool MyString::IsEmpty()
{
	bool ans = false;
	if (m_str == NULL)
	{
		ans = true;
	}
	return ans;
}

void MyString::Clear()
{
	if (m_str != NULL)
	{
		delete m_str;
		m_str = NULL;
		m_size = 0;
	}	
}