#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class MyString
{
private:
	char* arrCh;
	char* iter;
	char* en;			//Con tro cuoi tro vao ky tu cuoi
	unsigned int width;	//Chieu rong cua chuoi
public:
	//---------Contructor---------
	MyString();
	MyString(const string& str);
	MyString(const string& str,unsigned int pos,unsigned int npos);
	MyString(const char* s);
	MyString(const char* s,unsigned int n);
	MyString(unsigned int n, char c);
	template<class T>
	MyString(T first, T last);

	MyString(const MyString& str);

	//----------Detructor---------
	~MyString();

	//----------Iterators---------
	char begin();
	char end();


	//----------Capacity---------
	unsigned int length() const;

	unsigned int size()const;

	unsigned int max_size()const;

	void resize(unsigned int size);
	void resize(unsigned int size, char c);

	unsigned int capacity()const;

	void reserve(unsigned int n);

	void clear();

	bool empty();

	void shrink_to_fit();

	//---------Element access------------
	char& at(unsigned int pos);
	const char& at(unsigned int pos)const;

	char& back();
	const char& back()const;

	char& front();
	const char& front()const;


	//---------Modifiers----------
	void push_back(char c);
	
	MyString& assign(const MyString& str);
	MyString& assign(const MyString& str,unsigned int subpos,unsigned int sublen);
	MyString& assign(const char* s);
	MyString& assign(const char* s, unsigned int n);
	MyString& assign(unsigned int n, char c);

	//---------Operator-----------
	friend ostream& operator << (ostream& outDevice, MyString& str);
	friend istream& operator>>(istream& inDevice, MyString& str);

	MyString& operator=(const MyString& str);
	MyString& operator=(const char* s);
	MyString& operator=(char c);

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend MyString operator+(const MyString& lhs, const char* rhs);
	friend MyString operator+(const char* lhs, const MyString& rhs);
	friend MyString operator+(const MyString& lhs, char rhs);
	friend MyString operator+(char lhs, const MyString& rhs);

	char& operator[](unsigned int pos);
	const char& operator[](unsigned int pos)const;


	char getEn();

};

