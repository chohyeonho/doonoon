#pragma once
#include<vector>
#include<iostream>
#include<ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define TICKTIME 500000
#define ITEMCOOLTIME 20
#define GATECOOLTIME 40
#define MIN_SNAKEBODY 3
#define GROW_MAKE 2
#define POISON_MAKE 1