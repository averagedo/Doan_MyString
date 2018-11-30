#include"MyString.h"

int main()
{
	MyString a(100, 'x');
	cout << a.capacity() << endl;
	a.resize(2);
	cout << a.capacity() << endl;
	cout << a << endl;
	a.shrink_to_fit();
	cout << a.capacity() << endl;
	system("pause");
	return 0;
}