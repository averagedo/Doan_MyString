#include"MyString.h"

//---------Contructor---------
MyString::MyString()
{
	arrCh = NULL;
	en = NULL;
	width = 0;
}

MyString::MyString(const MyString& str)
{
	arrCh = NULL;
	en = NULL;
	width = 0;
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

MyString::MyString(const MyString& str,unsigned int pos,unsigned int npos)
{
	arrCh = NULL;
	en = NULL;
	width = 0;
	if (str.length() < npos + pos)
	{
		for (int i = pos; i <= str.length()-pos; i++)
		{
			push_back(str[i]);
		}
	}
	else
	{
		for (int i = 0; i < npos; i++)
		{
			push_back(str[pos + i]);
		}
	}
}

MyString::MyString(const char* s)
{
	arrCh = NULL;
	en = NULL;
	width = 0;
	unsigned int i = 0;
	while (s[i]!='\0')
	{
		push_back(s[i]);
		i++;
	}
}

MyString::MyString(const char* s,unsigned int n)
{
	arrCh = NULL;
	en = NULL;
	width = 0;
	for (int i = 0; i < n; i++)
	{
		push_back(s[i]);
	}
}

MyString::MyString(unsigned int n, char c)
{
	arrCh = NULL;
	en = NULL;
	width = 0;
	for (int i = 0; i < n; i++)
	{
		push_back(c);
	}
}

/*MyString::MyString(const MyString& str)
{
	arrCh = new char[1];		//Tranh loi delete o operator=
	*this = str;
}*/

//----------Detructor---------
MyString::~MyString()
{
	delete[]arrCh;
	width = 0;
	en = NULL;
	arrCh = NULL;
}

char * MyString::begin()
{
	return arrCh;
}

char * MyString::end()
{
	return en;
}

//---------Iterators--------




/*reverse_iterator<char> MyString::rbegin()
{
	char a[] = "ffa";
	make_reverse_iterator(a);
	return ;
}*/

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
MyString & MyString::append(const MyString & str)
{
	for (auto i = 0; i < str.length(); i++)
	{
		push_back(str[i]);
	}
	return *this;
}

MyString & MyString::append(const MyString & str, size_t subpos, size_t sublen)
{
	if (str.length() < subpos + sublen)
	{
		for (int i = subpos; i <= str.length() - subpos; i++)
		{
			push_back(str[i]);
		}
	}
	else
	{
		for (int i = 0; i < sublen; i++)
		{
			push_back(str[subpos + i]);
		}
	}
	return *this;
}

MyString & MyString::append(const char * s)
{
	size_t i = 0;
	while (s[i] != '\0')
	{
		push_back(s[i]);
		i++;
	}
	return *this;
}

MyString & MyString::append(const char * s, size_t n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		push_back(s[i]);
	}
	return *this;
}

MyString & MyString::append(size_t n, char c)
{
	for (unsigned int i = 0; i < n; i++)
	{
		push_back(c);
	}
	return *this;
}

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
	this->append(str, subpos, sublen);
	return *this;
}

MyString& MyString::assign(const char* s)
{
	clear();
	this->append(s);
	return *this;
}

MyString& MyString::assign(const char* s, unsigned int n)
{
	clear();
	this->append(s, n);
	return *this;
}

MyString& MyString::assign(unsigned int n, char c)
{
	clear();
	this->append(n, c);
	return *this;
}

MyString & MyString::insert(size_t pos, const MyString & str)
{
	//chen vao vi tri truoc pos
	MyString a;
	for (int i = pos; i < length(); i++)
	{
		a.push_back(arrCh[i]);
	}
	if (pos == 0)
		assign(str);
	else
	{
		en = arrCh + pos - 1;
		append(str);
	}
	append(a);
	return *this;
}

MyString & MyString::insert(size_t pos, const MyString & str, size_t subpos, size_t sublen)
{
	//chen vao vi tri truoc pos
	MyString a;
	for (int i = pos; i < length(); i++)
	{
		a.push_back(arrCh[i]);
	}
	if (pos == 0)
		assign(str,subpos,sublen);
	else
	{
		en = arrCh + pos - 1;
		append(str,subpos,sublen);
	}
	append(a);
	return *this;
}

MyString & MyString::insert(size_t pos, const char * s)
{
	MyString a = s;
	insert(pos, a);
	return *this;
}

MyString & MyString::insert(size_t pos, const char * s, size_t n)
{
	MyString a = s;
	insert(pos, a, 0, n);
	return *this;
}

MyString & MyString::insert(size_t pos, size_t n, char c)
{
	MyString a;
	a.assign(n, c);
	insert(pos, a);
	return *this;
}

MyString & MyString::erase(size_t pos, size_t len)
{
	if (length() < pos + len )
	{
		if (pos == 0)
			en = NULL;
		else
			en = &arrCh[pos-1];
	}
	else
	{
		size_t size= length();
		for (size_t i = 0; i < size-pos-len; i++)
		{
			arrCh[pos + i] = arrCh[pos + len + i];
		}
		en = en - len;
	}
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, const MyString & str)
{
	erase(pos, len);
	insert(pos, str);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, const MyString & str, size_t subpos, size_t sublen)
{
	erase(pos, len);
	insert(pos, str, subpos, sublen);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, const char * s)
{
	erase(pos, len);
	MyString str(s);
	insert(pos, str);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, const char * s, size_t n)
{
	erase(pos, len);
	MyString str(s,n); 
	insert(pos, str);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, size_t n, char c)
{
	erase(pos, len);
	MyString str(c, n);
	insert(pos, str);
	return *this;
}

void MyString::swap(MyString & str)
{
	size_t len = str.length();
	char* a = new char[len+1];
	str.copy(a, len, 0);
	a[len] = '\0';
	str = arrCh;
	assign(a);
	delete[] a;
}

void MyString::pop_back()
{
	if (en != arrCh)
	{
		en = en - 1;
		en[1] = '\0';
	}
	else
	{
		clear();
	}
}

const char * MyString::c_str() const
{
	return arrCh;
}

const char * MyString::data() const
{
	return arrCh;
}

char * MyString::get_allocator() const
{
	char* a = new char[length()];
	memcpy(a, arrCh, length());
	a[length()] = '\0';
	return a;
}

size_t MyString::copy(char * s, size_t len, size_t pos)
{
	for (size_t i = 0; i < len; i++)
	{
		s[i] = arrCh[pos + i];
	}
	return len;
}

size_t MyString::Find(const MyString&str, size_t pos)const
{
	if (pos < length())
	{
		size_t k, j = 0;
		for (size_t i = pos; i < length(); i++)
		{
			j = 0;
			while (arrCh[i + j] == str[j])
			{
				j++;
				if (j == str.length())
				{
					return i;
				}
			}
		}
	}
	else
		return -1;
}

size_t MyString::Find(const char * s, size_t pos) const
{
	MyString str = s;
	if (pos < length())
	{
		size_t k, j = 0;
		for (size_t i = pos; i < length(); i++)
		{
			j = 0;
			while (arrCh[i + j] == str[j])
			{
				j++;
				if (j == str.length())
				{
					return i;
				}
			}
		}
	}
	else
		return -1;
}

size_t MyString::Find(const char * s, size_t pos, size_t n) const
{
	MyString str = s;
	if (pos < length() && n < str.length())
	{
		size_t k, j = 0;
		for (size_t i = pos; i < length(); i++)
		{
			j = 0;
			while (arrCh[i + j] == str[j])
			{
				j++;
				if (j == n)
				{
					return i;
				}
			}
		}
	}
	else
		return -1;
}

size_t MyString::Find(char c, size_t pos) const
{
	if (pos < length())
	{
		for (size_t i = pos; i < length(); i++)
		{
			if (c == arrCh[i])
				return i;
		}
	}
	else
		return -1;
}

size_t MyString::rFind(const MyString & str, size_t pos) const
{
	if (pos < length())
	{
		for (size_t i = 1; length() - str.length()*i >= 0; i++)
		{
			return Find(str, length() - str.length()*i);
		}
	}
	return -1;
}

size_t MyString::rFind(const char * s, size_t pos) const
{
	if(pos < length())
	{
		for (size_t i = 1; length() - strlen(s)*i >= 0; i++)
		{
			return Find(s, length() - strlen(s)*i);
		}
	}
	return -1;
}

size_t MyString::rFind(const char * s, size_t pos, size_t n) const
{
	if (pos < length() && n < strlen(s))
	{
		for (size_t i = 1; length() - n*i >= 0; i++)
		{
			return Find(s, length() - strlen(s)*i,n);
		}
	}
	return -1;
}

size_t MyString::rFind(char c, size_t pos) const
{
	if (pos < length())
	{
		for (size_t i = length()-1; i>=0; i++)
		{
			return Find(c, i);
		}
	}
	return -1;
}

size_t MyString::Find_First_of(const MyString & str, size_t pos) const
{
	if (pos < length())
	{
		for (size_t i = pos; i < length(); i++)
		{
			for (size_t j = 0; j < str.length(); j++)
			{
				if (arrCh[i] == str[j])
					return i;
			}
		}
	}
	else
		return -1;
}

size_t MyString::Find_First_of(const char * s, size_t pos) const
{
	MyString a = s;
	return Find_First_of(a, pos);
}

size_t MyString::Find_First_of(const char * s, size_t pos, size_t n) const
{
	MyString str = s;
	if (pos < length() && n<str.length())
	{
		for (size_t i = pos; i < length(); i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (arrCh[i] == str[j])
					return i;
			}
		}
	}
	else
		return -1;
}

size_t MyString::Find_First_of(char c, size_t pos) const
{
	if (pos < length())
	{
		for (size_t i = pos; i < length(); i++)
		{
			if (arrCh[i] == c)
				return i;
		}
	}
	else
		return -1;
}

size_t MyString::Find_Last_of(const MyString & str, size_t pos) const
{
	if (pos < length())
	{
		for (size_t i = length() - 1; i >= pos; i--)
		{
			return Find_First_of(str, i);
		}
	}
	else
		return -1;
}

size_t MyString::Find_Last_of(const char * s, size_t pos) const
{
	MyString str = s;
	return Find_Last_of(str, pos);
}

size_t MyString::Find_Last_of(const char * s, size_t pos, size_t n) const
{
	if (pos < length())
	{
		for (size_t i = length() - 1; i >= pos; i--)
		{
			return Find_First_of(s, i, n);
		}
	}
	else
		return -1;
}

size_t MyString::Find_Last_of(char c, size_t pos) const
{
	if (pos < length())
	{
		for (size_t i = length() - 1; i >= pos; i--)
		{
			return Find_First_of(c, i);
		}
	}
	else
		return -1;
}

size_t MyString::find_first_not_of(const MyString & str, size_t pos) const
{
	if (pos < length())
	{
		for (size_t i = pos; i < length(); i++)
		{
			for (size_t j = 0; j <= str.length(); j++)
			{
				if (j == str.length())
					return i;
				if (arrCh[i] == str[j])
					break;
			}
		}
		return -1;
	}
	else
		return -1;
}

size_t MyString::find_first_not_of(const char * s, size_t pos) const
{
	MyString str = s;
	return find_first_not_of(str, pos);
}

size_t MyString::find_first_not_of(const char * s, size_t pos, size_t n) const
{
	MyString str = s;
	if (pos < length())
	{
		for (size_t i = pos; i < length(); i++)
		{
			for (size_t j = 0; j <= n; j++)
			{
				if (j == n)
					return i;
				if (arrCh[i] == str[j])
					break;
			}
		}
		return -1;
	}
	else
		return -1;
}

size_t MyString::find_first_not_of(char c, size_t pos) const
{
	if (pos < length())
	{
		for (size_t i = pos; i < length(); i++)
		{
			if (c != arrCh[i]);
				return i;
		}
		return -1;
	}
	else
		return -1;
}

size_t MyString::find_last_not_of(const MyString & str, size_t pos) const
{
	if (pos < length())
	{
		for (size_t i = length()-1; i >= pos; i++)
		{
			for (size_t j = 0; j <= str.length(); j++)
			{
				if (j == str.length())
					return i;
				if (arrCh[i] == str[j])
					break;
			}
		}
		return -1;
	}
	else
		return -1;
}

size_t MyString::find_last_not_of(const char * s, size_t pos) const
{
	MyString str = s;
	return find_last_not_of(str, pos);
}

size_t MyString::find_last_not_of(const char * s, size_t pos, size_t n) const
{
	MyString str = s;
	if (pos < length())
	{
		for (size_t i = length() - 1; i >= pos; i++)
		{
			for (size_t j = 0; j <= n; j++)
			{
				if (j == n)
					return i;
				if (arrCh[i] == str[j])
					break;
			}
		}
		return -1;
	}
	else
		return -1;
}

size_t MyString::find_last_not_of(char c, size_t pos) const
{
	if (pos < length())
	{
		for (size_t i = length() - 1; i >= pos; i++)
		{
			if (c != arrCh[i])
				return i;
		}
		return -1;
	}
	else
		return -1;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	MyString a(*this, pos, len);
	return a;
}

int MyString::compare(const MyString & str) const
{
	if (length() > str.length())
	{
		for (size_t i = 0; i <= str.length(); i++)
		{
			if (i == str.length())
				return 1;
			if (arrCh[i] > str[i])
				return 1;
			if (arrCh[i] < str[i])
				return -1;
		}
	}
	else if (length() < str.length())
	{
		for (size_t i = 0; i <= length(); i++)
		{
			if (i == length())
				return -1;
			if (arrCh[i] > str[i])
				return 1;
			if (arrCh[i] < str[i])
				return -1;
		}
	}
	else
	{
		for (size_t i = 0; i <= str.length(); i++)
		{
			if (i == str.length())
				return 0;
			if (arrCh[i] > str[i])
				return 1;
			if (arrCh[i] < str[i])
				return -1;
		}
	}
}

int MyString::compare(size_t pos, size_t len, const MyString & str) const
{
	MyString a = substr(pos, len);
	return a.compare(str);
}

int MyString::compare(size_t pos, size_t len, const MyString & str, size_t subpos, size_t sublen) const
{
	MyString a = substr(pos, len);
	MyString b;
	for (size_t i = subpos; i < sublen; i++)
	{
		b.push_back(str[i]);
	}
	return a.compare(b);
}

int MyString::compare(const char * s) const
{
	MyString str(s);
	return compare(str);
}

int MyString::compare(size_t pos, size_t len, const char * s) const
{
	MyString a = substr(pos, len);
	return a.compare(s);
}

int MyString::compare(size_t pos, size_t len, const char * s, size_t n) const
{
	MyString b(s,n);
	MyString a = substr(pos, len);
	return a.compare(b);
}



istream & Getline(istream & is, MyString & str)
{
	str.clear();
	char c;
	while (is.get(c))
	{
		if (c != '\0' && c != '\n')
		{
			str.push_back(c);
		}
		else
			break;
	}
	return is;
}

void swap(MyString & x, MyString & y)
{
	MyString str(x);
	x = y;
	y = str;
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

MyString & MyString::operator+=(const MyString & str)
{
	append(str);
	return *this;
}

MyString & MyString::operator+=(const char * s)
{
	append(s);
	return *this;
}

MyString & MyString::operator+=(char c)
{
	append(1,c);
	return *this;
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

bool operator==(const MyString& lhs, const MyString& rhs)
{
	if (lhs.compare(rhs) == 0)
		return true;
	else
		return false;
}

bool operator==(const char * lhs, const MyString & rhs)
{
	MyString str(lhs);
	if (str.compare(rhs) == 0)
		return true;
	else
		return false;
}

bool operator==(const MyString & lhs, const char * rhs)
{
	MyString str(rhs);
	if (str.compare(lhs) == 0)
		return true;
	else
		return false;
}

bool operator!=(const MyString & lhs, const MyString & rhs)
{
	if (lhs.compare(rhs) != 0)
		return true;
	else
		return false;
}

bool operator!=(const char * lhs, const MyString & rhs)
{
	MyString str(lhs);
	return str != rhs;
}

bool operator!=(const MyString & lhs, const char * rhs)
{
	MyString str(rhs);
	return str != lhs;
}

bool operator<(const MyString & lhs, const MyString & rhs)
{
	if (lhs.compare(rhs) < 0)
		return true;
	else
		return false;
}

bool operator<(const char * lhs, const MyString & rhs)
{
	MyString str(lhs);
	return str < rhs;
}

bool operator<(const MyString & lhs, const char * rhs)
{
	MyString str(rhs);
	return lhs < str;
}

bool operator<=(const MyString & lhs, const MyString & rhs)
{
	if (lhs.compare(rhs) <= 0)
		return true;
	else
		return false;
}

bool operator<=(const char * lhs, const MyString & rhs)
{
	MyString str(lhs);
	return str <= rhs;
}

bool operator<=(const MyString & lhs, const char * rhs)
{
	MyString str(rhs);
	return lhs <= str;
}

bool operator>(const MyString & lhs, const MyString & rhs)
{
	if (lhs.compare(rhs) > 0)
		return true;
	else
		return false;
}

bool operator>(const char * lhs, const MyString & rhs)
{
	MyString str(lhs);
	return str > rhs;
}

bool operator>(const MyString & lhs, const char * rhs)
{
	MyString str(rhs);
	return lhs > str;
}

bool operator>=(const MyString & lhs, const MyString & rhs)
{
	if (lhs.compare(rhs) >= 0)
		return true;
	else
		return false;
}

bool operator>=(const char * lhs, const MyString & rhs)
{
	MyString str(lhs);
	return str >= rhs;
}

bool operator>=(const MyString & lhs, const char * rhs)
{
	MyString str(rhs);
	return lhs >= str;
}
