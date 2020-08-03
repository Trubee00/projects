#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <string>
#include <array>
using namespace std;

const int n = 50;

class Student {
private:
	string FirstName;
	string LastName;
	string MNumber;

public:
	Student(); //Constructor
	void SetFirst(string); //Gets the students First name
	void SetLast(string); //Gets the students Last name
	void SetMNum(string); //Gets the students M Number
	string GetFirst(); //Sends out the students First name to main function
	string GetLast(); //Sends out the students Last name to the main function
	string GetMNumber(); //Sends out the students M Number to the main function
};

Student::Student() {};

void Student::SetFirst(string first) {
	FirstName = first;
}

void Student::SetLast(string last) {
	LastName = last;
}

void Student::SetMNum(string Mnum) {
	MNumber = Mnum;
}

string Student::GetFirst()
{
	return FirstName;
}

string Student::GetLast() {
	return LastName;
}

string Student::GetMNumber()
{
	return MNumber;
}

template<class T>

class LinkedList
{
private:
	typedef struct node {
		T data; 
		node* next; 
	} *nodePtr; 

	nodePtr head; 
	nodePtr curr; 
	nodePtr temp; 
	int counter = 0;

public:
	LinkedList();
	T item;
	void AddItem(T); //Adds Item
	void PrintList(); //Prints the list
	~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList() //Sets all the pointers to null
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}

template<class T>
void LinkedList<T>::AddItem(T AddData) { //This is the mainly used function
	nodePtr n = new node; 
	n->next = NULL; 
	n->data = AddData; 

	if (head != NULL) { 
		curr = head; 
		while (curr->next != NULL) { 
			curr = curr->next; 
		}
		curr->next = n; 
	}
	else {
		head = n; 
	}
}


template<class T>
void LinkedList<T>::PrintList() { //Prints list
	curr = head; 
	while (curr != NULL) { 
		cout << curr->data << endl; 
		curr = curr->next; 
	}
};

template<class T> //Destructor
LinkedList<T>::~LinkedList()
{
}


string FirstRand(int); //Creates the first name
string LastRand(int); //Creates the last name
string MNumRand(int); //Creates the MNumber
char randomGenerator(int, int); //Creates random character to add to a string 
int randomGeneratorInt(int, int); //Creates a random number for length of the names.

LinkedList<string> bubbleSort(LinkedList<string>[], int, int); //buuble sort function
LinkedList<string> InsertionSort(LinkedList<string>[], int, int); // Insertion sort function
LinkedList<string> QuickSort(LinkedList<string>[], int, int, int); //Quicksort function

int main()
{
	int lenFirst = 0; //This will be randomly generated later
	int lenLast = 0; //This will be randomly generated later
	int lenMnum = 6; //MNumber length is 6
	string First;
	string Last;
	string mnum;

	LinkedList<string> AJ[n]; //Array of linked lists
	Student Persons; //Information for each person

	string arr[n]; //Array for firstnames
	string arr2[n]; //Array for lastnames
	string arr3[n]; //Array for mnumbers

	//This whole loop actually assigns and creates the arrays for use in the linked list section
	for (int i = 0; i < n; i++) {
		lenFirst = randomGeneratorInt(2, 12); //Random length
		lenLast = randomGeneratorInt(3, 12);
		First = FirstRand(lenFirst); //Creates the first
		Last = LastRand(lenLast); //Creats the last
		mnum = "M29" + MNumRand(lenMnum); //Creates the MNumber

		//Sets all the information for the student class to send to the arrays
		Persons.SetFirst(First);
		Persons.SetLast(Last);
		Persons.SetMNum(mnum);

		//Randomly generates information
		string firstGet = Persons.GetFirst(); //Gets the information from the student class
		string lastGet = Persons.GetLast();
		string MGet = Persons.GetMNumber();

		//Sets the array values
		arr[i] = firstGet;
		arr2[i] = lastGet;
		arr3[i] = MGet;
	}


	int input, input2;
	bool works = false;

	cout << "Options: 1 for bubble sort accending, 2 for Insert accending, 3 for quick accending, 4 for bubblesort decending, 5 Insertion decending, 6 quicksort" << endl;
	cin >> input;
	cout << "Choose what order to display: 1 for first names, 2 for last names, 3 for MNumbers" << endl;
	cin >> input2;

	if (input2 == 1) {
		for (int j = 0; j < n; j++) {
			AJ[j].AddItem(arr[j]);
			AJ[j].AddItem(arr2[j]);
			AJ[j].AddItem(arr3[j]);
		}
	}
	else if (input2 == 2) {
		//This adds Items to the linked list array
		for (int j = 0; j < n; j++) {
			AJ[j].AddItem(arr2[j]);
			AJ[j].AddItem(arr[j]);
			AJ[j].AddItem(arr3[j]);
		}
	}
	else if (input2 == 3) {
		//This adds Items to the linked list array
		for (int j = 0; j < n; j++) {
			AJ[j].AddItem(arr3[j]);
			AJ[j].AddItem(arr[j]);
			AJ[j].AddItem(arr2[j]);
		}
	}
	else {
		cout << "Not correct input for what to to sort by." << endl;
	}

	LinkedList<string> arrNew[n];
	while (works == false) {
		if (input == 1) {
			for (int spot = 0; spot < n; spot++) {
				arrNew[spot] = bubbleSort(AJ, n, spot);
			}
			works = true;
		}
		else if (input == 4) {
			for (int spot = 0; spot < n; spot++) {
				arrNew[(n - 1) - spot] = bubbleSort(AJ, n, spot);
			}
			works = true;
		}
		else if (input == 2) {
			for (int spot = 0; spot < n; spot++) {
				arrNew[spot] = InsertionSort(AJ, n, spot);
			}
			works = true;
		}
		else if (input == 5) {
			for (int spot = 0; spot < n; spot++) {
				arrNew[(n - 1) - spot] = InsertionSort(AJ, n, spot);
			}
			works = true;
		}
		else if (input == 3) {
			for (int spot = 0; spot < n; spot++) {
				arrNew[spot] = QuickSort(AJ, 0, n - 1, spot);
			}
			works = true;
		}
		else if (input == 6) {
			for (int spot = 0; spot < n; spot++) {
				arrNew[(n - 1) - spot] = QuickSort(AJ, 0, n - 1, spot);
			}
			works = true;
		}
		else {
			cout << "You did not input a correct file" << endl;
		}
	}
	cout << endl;

	//This will print the array asked for
	for (int m = 0; m < n; m++) {
		arrNew[m].PrintList();
		cout << endl;
	}

	return 0;
}

//Bubble Sort
LinkedList<string> bubbleSort(LinkedList<string> arr[], int len, int spot) {
	LinkedList<string> tempHold; 
	for (int i = 0; i < len; i++) { 
		for (int n = 0; n < len - i - 1; n++) { 
			if (arr[n] > arr[n + 1]) { 
				tempHold = arr[n]; 
				arr[n] = arr[n + 1]; 
				arr[n + 1] = tempHold; 
			}
		}
	}
	
	return arr[spot];
}

//Insertion sort
LinkedList<string> InsertionSort(LinkedList<string> arr[], int len, int spot) {
	LinkedList<string> TempVal; 
	int CompVal; 
	for (int i = 1; i < len; i++) { 
		TempVal = arr[i]; 
		CompVal = i - 1; 
		while (CompVal >= 0 && arr[CompVal] > TempVal) { 
			arr[CompVal + 1] = arr[CompVal]; 
			CompVal = CompVal - 1; 
		}
		arr[CompVal + 1] = TempVal; 
	}
	return arr[spot];
}

//Quick sort code
int sortStart(LinkedList<string> arr[], int spot1, int spot2) { 
	LinkedList<string> pivot = arr[spot2]; 
	int small = spot1 - 1; 

	for (int i = spot1; i < spot2; i++) { 
		if (arr[i] <= pivot) { 
			small++; 
			swap(arr[i], arr[small]); 
		}
	}
	swap(arr[spot2], arr[small + 1]); 
	return small + 1; 
}

LinkedList<string> QuickSort(LinkedList<string> arr[], int start, int end, int spot) { 
	if (start < end) { 
		int pos = sortStart(arr, start, end); 
		QuickSort(arr, start, pos - 1, spot); 
		QuickSort(arr, pos + 1, end, spot);
	}
	return arr[spot];
}

char randomGenerator(int start, int end) { //microsoft.com was used to help make this function
	random_device rd;   
	mt19937 gen(rd()); 
	uniform_int_distribution<> dist(start, end); //Returns a random number
	return static_cast<char> (dist(gen));
}

int randomGeneratorInt(int start, int end) {  //microsoft.com was used helped make this function
	random_device rd;   
	mt19937 gen(rd()); 
	uniform_int_distribution<> dist(start, end); //Returns a random number
	return (dist(gen));
}

//These functions are used to create the strings that are made from randomly generated characters
string FirstRand(int len) {
	string First;
	First += randomGenerator(65, 90);
	for (int i = 1; i < len; i++) {
		First += randomGenerator(97, 122);
	}
	return First;
}

string LastRand(int len) {
	string Last;
	Last += randomGenerator(65, 90);
	for (int i = 1; i < len; i++) {
		Last += randomGenerator(97, 122);
	}
	return Last;
}

string MNumRand(int len) {
	string MNumb;
	for (int i = 0; i < len; i++) {
		MNumb += randomGenerator(48, 57);
	}
	return MNumb;
}

/*
Microsoft, stack overflow, cplusplus, and wikipedia were all used to help on this lab
*/
