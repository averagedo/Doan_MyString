#include"MyString.h"

//---------Contructor---------
MyString::MyString()
{
	arrCh = NULL;
	en = NULL;
	width = 0;
}

MyString::MyString(const string& str)
{
	arrCh = new char[str.length()+1];
	width = str.length() + 1;
	en = arrCh;
	for (int i = 0; i < str.length(); i++)
	{
		arrCh[i] = str[i];
		en++;
	}
	en--;
	arrCh[str.length()] = '\0';
}

MyString::MyString(const string& str,unsigned int pos,unsigned int npos)
{
	if (str.length() < npos + pos + 1)
	{
		for (int i = pos; i <= str.length()-pos; i++)
		{
			push_back(str[i]);
		}
	}
	else
	{
		for (int i = 0; i <= npos; i++)
		{
			push_back(str[pos + i]);
		}
	}
}

MyString::MyString(const char* s)
{
	unsigned int i = 0;
	while (s[i]!='\0')
	{
		push_back(s[i]);
		i++;
	}
}

MyString::MyString(const char* s,unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		push_back(s[i]);
	}
}

MyString::MyString(unsigned int n, char c)
{
	for (int i = 0; i < n; i++)
	{
		push_back(c);
	}
}

MyString::MyString(const MyString& str)
{
	arrCh = new char[1];		//Tranh loi delete o operator=
	*this = str;
}

//----------Detructor---------
MyString::~MyString()
{
	delete[]arrCh;
	width = 0;
	en = NULL;
	arrCh = NULL;
}

//----------Capacity---------
unsigned int MyString::length() const
{
	unsigned int dem = 0;
	char* c;
	if (en != NULL) 
	{
		c = arrCh;
		while ( c != en)
		{
			dem++;
			c++;
		}
	}
	return dem + 1;
}

unsigned int MyString::size()const
{
	return length();
}

unsigned int MyString::max_size()const
{
	return 4294967295;
}

void MyString::resize(unsigned int size)
{
	if (size > length())
	{
		for (unsigned int i = length(); i <= size; i++)
		{
			push_back(' ');
		}
	}
	if (size < length())
	{
		arrCh[size] = '\0';
		en = arrCh + size - 1;
	}
}
void MyString::resize(unsigned int size, char c)
{
	if (size > length())
	{
		for (unsigned int i = length(); i <= size; i++)
		{
			push_back(c);
		}
	}
	if (size < length())
	{
		arrCh[size] = '\0';
		en = arrCh + size;
	}
}

unsigned int MyString::capacity()const
{
	return width;
}

void MyString::reserve(unsigned int n)
{
	if (n > width)
	{
		char* tro = new char[n];
		if (tro != NULL)
		{
			memcpy(tro, arrCh, width);
			delete[] arrCh;
			arrCh = tro;
			en = arrCh;
			en = en + width - 2;
			width = n;
		}
		else
		{
			cout << "Loi cap phat!!!" << endl;
			system("pause");
			exit(0);
		}
	}
}

void MyString::clear()
{
	delete[] arrCh;
	en = NULL;
	arrCh = NULL;
	width = 0;
}

bool MyString::empty()
{
	if (en == NULL)
	{
		return true;
	}
}

void MyString::shrink_to_fit()
{
	unsigned int l = length();
	char* tro = new char[l+1];
	if (tro != NULL)
	{
		memcpy(tro, arrCh, l);
		delete[] arrCh;
		arrCh = tro;
		en = arrCh;
		en = en + l - 1;
		width = l + 1;
		en[1] = '\0';
	}
	else
	{
		cout << "Loi cap phat!!!" << endl;
		system("pause");
		exit(0);
	}
}
//----------Element access-----------
char & MyString::at(unsigned int pos)
{
	return arrCh[pos];
}
const char& MyString::at(unsigned int pos)const
{
	return arrCh[pos];
}

char& MyString::back()
{
	return *en;
}
const char& MyString::back()const
{
	return *en;
}

char& MyString::front()
{
	return arrCh[0];
}
const char& MyString::front()const
{
	return arrCh[0];
}

//---------Modifiers----------
void MyString::push_back(char c)
{
	if (arrCh == NULL)
	{
		arrCh = new char[128];
		if (arrCh != NULL)
		{
			width = 128;
			en = arrCh;
		}
		else
		{
			cout << "Loi cap phat!!!" << endl;
			system("pause");
			exit(0);
		}
		en[0] = c;
		en[1] = '\0';
		return;
	}
	if (width - 1 == length())
	{
		char* tro = new char[width + 128];
		if (tro != NULL)
		{
			memcpy(tro, arrCh, width);
			delete[] arrCh;
			arrCh = tro;
			en = arrCh;
			en = en + width - 2;
			width = width + 128;
		}
		else
		{
			cout << "Loi cap phat!!!" << endl;
			system("pause");
			exit(0);
		}
	}
	en[1] = c;
	en++;
	en[1] = '\0';
}

MyString& MyString::assign(const MyString& str)
{
	clear();
	for (unsigned int i = 0; i < str.length(); i++)
	{
		push_back(str[i]);
	}
	return *this;
}

MyString& MyString::assign(const MyString& str, unsigned int subpos, unsigned int sublen)
{
	clear();
	if (str.length() < subpos + sublen + 1)
	{
		for (int i = subpos; i <= str.length() - subpos; i++)
		{
			push_back(str[i]);
		}
	}
	else
	{
		for (int i = 0; i <= sublen; i++)
		{
			push_back(str[subpos + i]);
		}
	}
	return *this;
}

MyString& MyString::assign(const char* s)
{
	clear();
	unsigned int i = 0;
	while (s[i] != '\0')
	{
		push_back(s[i]);
		i++;
	}
	return *this;
}

MyString& MyString::assign(const char* s, unsigned int n)
{
	clear();
	for (unsigned int i = 0; i < n; i++)
	{
		push_back(s[i]);
	}
	return *this;
}

MyString& MyString::assign(unsigned int n, char c)
{
	clear();
	for (unsigned int i = 0; i < n; i++)
	{
		push_back(c);
	}
	return *this;
}

//----------Operator----------
ostream& operator << (ostream& outDevice, MyString& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		outDevice << str.arrCh[i];
	}
	return outDevice;
}

istream& operator>>(istream& inDevice, MyString& str)
{
	char a;
	while (inDevice.get(a))
	{	
		if (a == '\n')
			break;
		str.push_back(a);
	}
	return inDevice;
}

char& MyString::operator[](unsigned int pos)
{
	return arrCh[pos];
}

const char& MyString::operator[](unsigned int pos)const
{
	return arrCh[pos];
}

MyString& MyString::operator=(const MyString& str)
{
	assign(str);
	return *this;
}

MyString& MyString::operator=(const char* s)
{
	assign(s);
	return *this;
}

MyString& MyString::operator=(char c)
{
	assign(1,c);
	return *this;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString a;
	a = lhs;
	for (unsigned int i = 0; i < rhs.length(); i++)
	{
		a.push_back(rhs[i]);
	}
	return a;
}

MyString operator+(const MyString & lhs, const char * rhs)
{
	MyString str;
	str = lhs;
	for (int i = 0; rhs[i] != '\0'; i++)
	{
		str.push_back(rhs[i]);
	}
	return str;
}

MyString operator+(const char * lhs, const MyString & rhs)
{
	MyString str;
	str = lhs;
	for (int i = 0; i < rhs.length(); i++)
	{
		str.push_back(rhs[i]);
	}
	return str;
}

MyString operator+(const MyString & lhs, char rhs)
{
	MyString str;
	str = lhs;
	str.push_back(rhs);
	return str;
}

MyString operator+(char lhs, const MyString & rhs)
{
	MyString str;
	str.push_back(lhs);
	for (int i = 0; i < rhs.length(); i++)
	{
		str.push_back(rhs[i]);
	}
	return str;
}

char MyString::getEn()
{
	return *en;
}
