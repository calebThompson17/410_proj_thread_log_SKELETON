//============================================================================
// Name        : 410_proj_thread_log.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <thread>
#include <iostream>
#include <vector>
#include <string>
#include "../includes/constants.h"
#include "../includes/Logger.h"
#include <pthread.h>

using namespace std;

//NOTE: you should have no mutexes in this file
//TODO linker errors?  Did you include the pthread library?   And set the proper dialect?
//TODO declare globals
vector<thread> vec;
bool doWork = true;

/***
 * TODO log info to both file and console. You can do this with 2 Logger objects. 
 * 		Note:  These logger objects cannot be local variables, they must be shared 
 * 		amongst the threads. (why?)
 * TODO this function should run until main (or another thread) asks it to quit
 * @param info  to log
 * returns void
 */
void fun(string info){
	while (doWork) {
		cout << "info:\t" << endl;
	}
}

int main() {
	
	//TODO start as many threads as you have cores (see std::thread::hardware_concurrency())
	unsigned int coreNum = thread::hardware_concurrency();

	//TODO save these threads in a vector
	for (unsigned int i=0; i<coreNum; i++) {
		// Create the unique string
		char character = 97 + i;
		string str = "";
		for (int j=0; j<5; j++) {
			str += character;
		}
		cout << "1st str:\t" << str << endl;
		// Create the thread
//		thread currentThread = thread(fun, str);
//		// Add the thread
//		vec.push_back(currentThread);

		vec.push_back(thread(fun, "aaaaa"));
	}

	//TODO let threads run a bit (5 seconds)
	this_thread::sleep_for(chrono::milliseconds(5000));
	
	//TODO ask them all to stop
	doWork = false;
	
	//TODO wait for all threads to finish
	for (auto& t: vec) t.join();
	
	return 0;
}
