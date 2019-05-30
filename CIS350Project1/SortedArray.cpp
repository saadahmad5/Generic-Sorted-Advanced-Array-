/**
*  File:  SortedArray.cpp
*
*  Description: Implementation of the class template SortedArray<Object>
*
*  Date Created: May 20, 2019
*  Last Modified: May 26, 2019
*
*  Written by Saad Ahmad at University of Michigan
*  This file is the implementation of the SortedArray_H which is the Project 1
*  of CIS 350 class. This uses an array at the backend which can store data
*  of generic type. This data structure the report the size and max capacity of
*  items too. Additionally it has capability to expand its size if it reaches its
*  capacity. You can retrieve the minimum and maximum items from a list of objects
*  too. Moreover, it features to delete minimum or maximum item in objects too.
*  It has a builtin function to display the items. You can even search for a specific
*  item by using the Binary search algorithm.
*/

#ifdef SortedArray_H

//Constant integer for the initial size of empty array
const int initSize = 0;

//Constructor
//Declares the memory of initial size plus the spare capacity for the objects data
template <typename Object>
SortedArray<Object>::SortedArray() : theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
{
	objects = new Object[theCapacity];
}

//Copy Constructor
//Takes the same object as a parameter and deep copies the instance of the object
template <typename Object>
SortedArray<Object>::SortedArray(const SortedArray <Object> &from) : objects(NULL)
{
	operator=(from);
}

//Destructor
//Deletes the object from the memory to free up space. A kind of Garbage disposal 
template <typename Object>
SortedArray<Object>::~SortedArray()
{
	delete[] objects;
}

//Operator Overloading for = operator
//Assigns one object the another object
template <typename Object>
const SortedArray<Object>& SortedArray<Object>:: operator= (const SortedArray<Object> &from)
{
	if (this != &from)
	{
		delete[] objects;
		theSize = from.size();
		theCapacity = from.capacity();
		objects = new Object[capacity()];
		for (int i = 0; i < theSize; ++i)
		{
			objects[i] = from.objects[i];
		}
	}
	return *this;
}

//Operator overloading for [] operator
//Returns the item in the specified index in objects
template <typename Object>
const Object & SortedArray<Object>::operator[](int idx) const
{
	return objects[idx];
}

//Equality identifier
//Returns true or false based up if the two objects have same items
template <typename Object>
bool SortedArray<Object>::equals(const SortedArray <Object> &rhs)
{
	if (size() == rhs.size())
	{
		for (int i = 0; i < theSize; ++i)
		{
			if (objects[i] != rhs.objects[i])
				return false;
		}
		return true;
	}
	return false;
}

//Empty identifier
//Returns true or false based up on whether the objects are empty or otherwise
template <typename Object>
bool SortedArray<Object>:: empty() const
{
	if (theSize == 0)
		return true;
	return false;
}

//Size of objects
//Returns the size of objects items
template <typename Object>
int SortedArray<Object>::size() const
{
	return theSize;
}

//Capacity of objects
//Returns the capacity of objects items
template <typename Object>
int SortedArray<Object>::capacity() const
{
	return theCapacity;
}

//Reserve function
//Reserve additional space in memory when the array size reaches its capacity
//Furthermore, deletes the older memory item too
template <typename Object>
void SortedArray<Object>::reserve(int newCapacity)
{
	if (newCapacity > theSize)
	{
		Object *old = objects;
		objects = new Object[newCapacity];
		for (int i = 0; i < theSize; ++i)
		{
			objects[i] = old[i];
		}
		theCapacity = newCapacity;
		delete[] old;
	}
}

//Print function
//Prints the items in the objects
template <typename Object>
void SortedArray<Object>:: print(ostream &out, char delimiter) const
{
	for (int i = 0; i < theSize; ++i)
	{
		out << objects[i] << delimiter;
	}
}

//Clear function
//Clears the items in objects
template <typename Object>
void SortedArray<Object>::clear()
{
	for (int i = 0; i < theSize; ++i)
	{
		objects[i] = NULL;
	}
	theSize = 0;
}

//Insert function
//Insert the item in objects sorted
template <typename Object>
void SortedArray<Object>::insert(const Object &obj)
{
	if(theSize == theCapacity)
	{
		//cout << "Before Rs Now Size: " << theSize << " Now Capacity: " << theCapacity << endl;
		reserve(2*theSize + 1);
		//cout << "After Rs Now Size: " << theSize << " Now Capacity: " << theCapacity << endl;
	}

	if(theSize == 0)
	{
		objects[0] = obj;
	}
	else
	{
		int i; 
		for (i=theSize-1; ( i >= 0  && objects[i] > obj); i--) 
			objects[i+1] = objects[i]; 

		objects[i+1] = obj; 
	}
	theSize++;
}

//Delete minimum
//Deletes the minimum item in objects plus shifts items leftwards
template <typename Object>
void SortedArray<Object>::deleteMin()
{
	for(int i = 0; i < theSize-1; ++i)
	{
		objects[i] = objects[i+1];	
	}
	theSize--;
}

//Delete maximum
//Deletes the maximum item in objects
template <typename Object>
void SortedArray<Object>::deleteMax()
{
	theSize--;
	
}

//Find Minimum
//Returns the item addressed at the minimum location of objects
template <typename Object>
const Object & SortedArray<Object>::findMin() const
{
	return objects[0];
}

//Find Maximum
// Returns the item addressed at the maximum location of objects
template <typename Object>
const Object & SortedArray<Object>::findMax() const
{
	return objects[theSize-1];
}

//Binary Search function
//Function called by binary search method
template <typename Object>
int bSearch(Object arr[], int l, int r, Object x)
{
	if (r >= l) 
	{ 
		int mid = l + (r - l) / 2; 

		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return bSearch(arr, l, mid - 1, x);

		return bSearch(arr, mid + 1, r, x);
	}
	return -1;
}

//Binary Search
//Searches for given item in the objects using the Binary search algorithm
template <typename Object>
int SortedArray<Object>::binarySearch(const Object &obj)
{
	return bSearch(objects, 0, theSize, obj);
}

#endif