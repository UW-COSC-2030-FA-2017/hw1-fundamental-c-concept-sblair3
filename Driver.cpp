#include <iostream>
using namespace std;

template <class T>
class collection {
private:
	int size;
	T* col;
public:
	inline collection(int s);//builds thee class
	collection();
	~collection();//destroys the class
	void setSize(int n);
	void assignArray(T array[]);
	void makeEmpty();//puts null in all elements in the class
	bool isEmpty();
	void insertX(T val);//inserts an object into the class
	void removeX(T val);//removes an object from the class
	void removeRandom();//Removes a random element
	bool notContained(T val);//Returns true of the element is not in the class and returns false if element is in class
	int returnSize();// returns the length of the array
	void print();

};
template <class T>
inline collection<T>::collection(int s)
{
	size = s;
	col = new T[size];
	
	
}
template <class T>
collection<T>::collection()
{
	return;
}
template <class T>
collection<T>::~collection()
{
	
}
template <class T>
void collection<T>::setSize(int n)
{
	size = n;

}
template<class T>
void collection<T>::assignArray(T array[])
{
	for (int i = 0; i < size; i++)
	{
		col[i] = array[i];
	}
}
template <class T>
void collection<T>::makeEmpty()
{
	for (int i = 0; i < size; i++)
	{
		col[i] = NULL;
	}
}
template<class T>
bool collection<T>::isEmpty()
{
	for (int i = 0; i < size; i++)
	{
		if (col[i] != NULL)
			return false;
	}
	return true;
}
template <class T>
void collection<T>::insertX(T val)
{
	T* new_array = new T[size + 1];
	int i = 0;
	for (i = 0; i < size; i++)
	{
		new_array[i] = col[i];
	}
	new_array[i] = val;
	delete col;
	size++;
	assignArray(new_array);
}

template <class T>
void collection<T>::removeX(T val)
{
	int count(0);
	int i = 0;
	for ( i = 0; i<size; i++)
	{
		if (col[i] == val)
		{
			for (int j = i; j<(size - 1); j++)
			{
				col[j] = col[j + 1];
			}
			count++;
			break;
		}
	}
	if (count == 0)
	{
		cout << "Element not found..!!";
		return;
	}
	else
	{
		col[size-1] = 0;
	}
}
template <class T>
void collection<T>::removeRandom()
{
	int random = rand() % size;
	
	for (int i = 0; i< size; i++)
	{
		if (i == random)
		{
			for (int j = i; j < size - 1; j++)
			{
				col[j] = col[j + 1];
			}
			break;
		}
	}
	col[size - 1] = 0;
}
template <class T>
bool collection<T>::notContained(T val)
{
	for (int i = 0; i < size; i++)
	{
		if (val == col[i])
		{
			return false;
		}
	}
	return true;
}
template <class T>
int collection<T>::returnSize()
{
	cout << "The size of the array is " << size << endl;
	return size;
}
template<class T>
void collection<T>::print()
{
	cout << "The elements in the array are: ";
	for (int i = 0; i < size; i++)
	{
		if (i != size - 1)
		{
			cout << col[i] << ", ";
		}
		else
		{
			cout << col[i] << endl;
		}
	}
}
int main()
{
	int randArray[5] = { 2, 66, 4, 9, 3 };
	collection<int> single(5);
	single.assignArray(randArray);
	single.print();
	single.returnSize();
	single.insertX(5);
	single.print();
	single.removeX(2);
	single.print();
	single.removeRandom();
	single.print();
	//Test if it contains number
	{cout << "Will now test if array has the number 46" << endl;
	cout << "Array ";
	if (!single.notContained(46)) {
		cout << "does ";
	}
	else
	{
		cout << "does not ";
	}
	cout << "have 46" << endl;
	cout << endl;
	cout << "will now test if array has the number 66" << endl;
	cout << "Array ";
	if (!single.notContained(66)) {
		cout << "does ";
	}
	else
	{
		cout << "does not ";
	}
	cout << "have 66" << endl;
	}
	cout<<endl;
	//Make Empty
	{single.makeEmpty();
	single.print(); }	
	cout << endl;
	//Test if Empty
	{	cout << "Array being empty is ";
	if (single.isEmpty()) {
		cout << "True";
	}
	else
	{
		cout << "false";
	}
	cout << endl;
	}
	
	return 0;
}