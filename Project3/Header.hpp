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

#define REQUIRE(condition) assert(condition)
#define PROMISE(condition) assert(condition)

using namespace std;