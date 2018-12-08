#ifndef _MYSTRING_H
#define _MYSTRING_H

#include<iostream>
#include<string>
#include<string.h>
#include<iterator>

using namespace std;

class MyString:public iterator<random_access_iterator_tag, char, char, char*, char>
{
private:
	char* arrCh;
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

	//MyString(const MyString& str);

	//----------Detructor---------
	~MyString();
	
	char* begin();
	char* end();
	
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

	MyString& erase(size_t pos, size_t len);

	MyString& replace(size_t pos, size_t len, const MyString& str);
	MyString& replace(size_t pos, size_t len, const MyString& str,size_t subpos, size_t sublen);
	MyString& replace(size_t pos, size_t len, const char* s);
	MyString& replace(size_t pos, size_t len, const char* s, size_t n);
	MyString& replace(size_t pos, size_t len, size_t n, char c);

	void swap(MyString& str);

	void pop_back();

	//------String operations-------
	const char* c_str()const;
	const char* data()const;
	char* get_allocator() const;
	size_t copy(char *s, size_t len, size_t pos);

	size_t Find(const MyString& , size_t )const;
	size_t Find(const char* s, size_t pos)const;
	size_t Find(const char* s, size_t pos, size_t n)const;
	size_t Find(char c, size_t pos)const;

	size_t rFind(const MyString&, size_t)const;
	size_t rFind(const char* s, size_t pos)const;
	size_t rFind(const char* s, size_t pos, size_t n)const;
	size_t rFind(char c, size_t pos)const;

	size_t Find_First_of(const MyString& str, size_t pos = 0) const;
	size_t Find_First_of(const char* s, size_t pos = 0) const;
	size_t Find_First_of(const char* s, size_t pos, size_t n) const;
	size_t Find_First_of(char c, size_t pos = 0) const;

	size_t Find_Last_of(const MyString& str, size_t pos ) const;
	size_t Find_Last_of(const char* s, size_t pos) const;
	size_t Find_Last_of(const char* s, size_t pos, size_t n) const;
	size_t Find_Last_of(char c, size_t pos ) const;

	size_t find_first_not_of(const MyString& str, size_t pos) const;
	size_t find_first_not_of(const char* s, size_t pos) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos) const;

	size_t find_last_not_of(const MyString& str, size_t pos) const;
	size_t find_last_not_of(const char* s, size_t pos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos) const;

	MyString substr(size_t pos , size_t len ) const;

	int compare(const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str,size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;

	friend istream& Getline(istream& is, MyString& str);

	friend void swap(MyString& x, MyString& y);

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

	friend bool operator== (const MyString& lhs, const MyString& rhs);
	friend bool operator== (const char*   lhs, const MyString& rhs);
	friend bool operator== (const MyString& lhs, const char*   rhs);

	friend bool operator!= (const MyString& lhs, const MyString& rhs);
	friend bool operator!= (const char* lhs, const MyString& rhs);
	friend bool operator!= (const MyString& lhs, const char*   rhs);
	
	friend bool operator<  (const MyString& lhs, const MyString& rhs);
	friend bool operator<  (const char*   lhs, const MyString& rhs);
	friend bool operator<  (const MyString& lhs, const char*   rhs);

	friend bool operator<= (const MyString& lhs, const MyString& rhs);
	friend bool operator<= (const char*   lhs, const MyString& rhs);
	friend bool operator<= (const MyString& lhs, const char*   rhs);

	friend bool operator>  (const MyString& lhs, const MyString& rhs);
	friend bool operator>  (const char*   lhs, const MyString& rhs);
	friend bool operator>  (const MyString& lhs, const char*   rhs);

	friend bool operator>= (const MyString& lhs, const MyString& rhs);
	friend bool operator>= (const char*   lhs, const MyString& rhs);
	friend bool operator>= (const MyString& lhs, const char*   rhs);

};

#endif // !1


