#pragma once
#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <memory>
#include <vector>
#include <assert.h>
#include <string>
#include <windows.h>

#define REQUIRE(condition) assert(condition)
#define PROMISE(condition) assert(condition)

using namespace std;

inline ostream& blue(ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
		| FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return s;
}

inline ostream& red(ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline ostream& green(ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return s;
}

inline ostream& yellow(ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline ostream& white(ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return s;
}