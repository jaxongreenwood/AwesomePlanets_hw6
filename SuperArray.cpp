// File: SuperArray
// Created by Hugo Valle on 10/31/2017.
// Copyright (c) 2017 WSU
//

#include "SuperArray.h"
#include <cstdint>
#include <cstring>
/*!
 * Constructor
 * @param begIndex User's low index
 * @param capacity Maximum array capacity
 */
SuperArray::SuperArray(const int begIndex, const unsigned int capacity)
{
	/* This is declaring a local variable, if you have data member
	 * called int* arr, the code on line ## will NOT refer to the data
	 * member, instead you created a second arr pointer, and this
	 * second pointer dies and is lost forever when the constructor ends
	 */
		arr = new int[capacity];
		SuperArray::capacity = capacity;
		lowIndex = begIndex;
		highIndex = begIndex + capacity - 1;
		// Other info below
}

/*!
 * Class Destructor
 */
SuperArray::~SuperArray()
{
	delete[] arr;
}


/*!
 * Convert int array to string.
 * Note: You do not need to modify this function
 * @param obj Instance of SuperArray to convert to string
 * @return string form of array
 */
string arrayToString(const SuperArray& obj)
{
	stringstream ss;

	for (int i = 0; i < obj.capacity; i++)
    {
        ss << obj.arr[i] << " ";
    }
	string str = ss.str();
	size_t found;
	found = str.find_last_not_of(" ");
	if (found != string::npos)
		str.erase(found + 1);
	else
		str.clear();            // str is all whitespace

	return str;
}

/*!
 * Index operator overload
 * @param index User's index notation
 * @return Actual index notation
 */
int &SuperArray::operator[](const int index)
{
		int realIndex = index - lowIndex;
		if (index < lowIndex){
			throw "Invalid index request, too low";
		}else if (index > highIndex){
			throw "Invalid index request, too high";
		}
		return arr[realIndex];
}


/*!
 * Ask for low Index
 * @return lowIndex
 */
int SuperArray::getLowIndex() const
{
	return lowIndex;
}


/*!
 * Ask for high Index
 * @return highIndex
 */
int SuperArray::getHighIndex() const
{
	return highIndex;
}


/*!
 * Ask for capacity
 * @return capacity
 */
unsigned int SuperArray::length() const
{
    return capacity;
}

/*!
 * Resizes the array by making a temporary array, copies values at the right index, then applies it to the existing array
 * @param begIndex
 * @param capacity
 */
void SuperArray::resize(const int begIndex, const unsigned int capacity) {

	int *temp = new int [capacity];

	int tlowIndex = lowIndex;
	int thighIndex = highIndex;

	tlowIndex = lowIndex - begIndex;

	for (int i = 0; i < lowIndex; i++){
		*(temp + i) = 0;
	}

	for (int i = 0; i < SuperArray::capacity; i++){
		temp[tlowIndex+i] = arr[i];
	}

	delete[] arr;
	arr = temp;

	lowIndex = begIndex;
	SuperArray::capacity = capacity;
	highIndex = begIndex + capacity - 1;



	/*int *temp = new int[capacity];
	memcpy(temp, arr, capacity);
	delete[] arr;
	*arr = *temp;*/
}
