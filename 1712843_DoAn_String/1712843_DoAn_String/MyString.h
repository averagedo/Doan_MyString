#ifndef _MYSTRING_H
#define _MYSTRING_H

#include<iostream>
#include<string>
//#include<string.h>

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
	MyString(const MyString& str);
	MyString(const MyString& str,unsigned int pos,unsigned int npos);
	MyString(const char* s);
	MyString(const char* s,unsigned int n);
	MyString(unsigned int n, char c);
	template<class T>
	MyString(T first, T last);

	//MyString(const MyString& str);

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
	MyString& append(const MyString& str);
	MyString& append(const MyString& str, size_t subpos, size_t sublen);
	MyString& append(const char* s);
	MyString& append(const char* s, size_t n);
	MyString& append(size_t n, char c);
	template<class InputIterator>
	MyString& append(InputIterator first, InputIterator last);

	void push_back(char c);
	
	MyString& assign(const MyString& str);
	MyString& assign(const MyString& str,unsigned int subpos,unsigned int sublen);
	MyString& assign(const char* s);
	MyString& assign(const char* s, unsigned int n);
	MyString& assign(unsigned int n, char c);

	MyString& insert(size_t pos, const MyString& str);
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen);
	MyString& insert(size_t pos, const char* s);
	MyString& insert(size_t pos, const char* s, size_t n);
	MyString& insert(size_t pos, size_t n, char c);
	char* insert(char* p, char c);
	template <class InputIterator>
	void insert(char* p, InputIterator first, InputIterator last);

	MyString& erase(size_t pos, size_t len);
	char* erase(char* p);
	char* erase(char* first, char* last);

	//------String operations-------
	const char* c_str()const;
	const char* data()const;
	char* get_allocator() const;
	size_t copy(char *s, size_t len, size_t pos);

	size_t Find(const string& , size_t )const;
	size_t Find(const char* s, size_t pos)const;
	size_t Find(const char* s, size_t pos, size_t n)const;
	size_t Find(char c, size_t pos)const;

	size_t rfind(const string&, size_t)const;
	size_t rfind(const char* s, size_t pos)const;
	size_t rfind(const char* s, size_t pos, size_t n)const;
	size_t rfind(char c, size_t pos)const;
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

	MyString& operator +=(const MyString& str);
	MyString& operator +=(const char* s);
	MyString& operator +=(char c);

	char& operator[](unsigned int pos);
	const char& operator[](unsigned int pos)const;


	char getEn();

};

#endif // !1