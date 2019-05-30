#include <iostream>
#include <string>
#include "SortedArray.h"

using namespace std;


int main()
{
	SortedArray<int> saad;
	saad.insert(3);
	saad.insert(40);
	saad.insert(52);
	saad.insert(61);
	saad.insert(71);
	saad.insert(8);
	saad.insert(1);
	saad.insert(40);
	saad.insert(52);
	saad.insert(61);
	saad.insert(71);
	saad.insert(8);
	saad.insert(1);
	saad.insert(40);
	saad.insert(40);

	
	saad.print(cout);

	cout << endl;
	
	saad.deleteMax();
	saad.deleteMax();

	saad.print(cout);

	cout << endl;

	saad.deleteMin();
	saad.deleteMin();

	saad.print(cout);

	cout << endl << saad.binarySearch(3);

	cout << "Hello World" << endl;
	

	getchar();
	return 0;
}