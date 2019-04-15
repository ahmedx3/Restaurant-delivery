#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "Restaurant.h"
#include "../Events/ArrivalEvent.h"
#include "../Events/CancelationEvent.h"
#include "../Events/PromotionEvent.h"

using namespace std;

class load
{
	Restaurant* restaurant;
	int sn;		//Normal motocycles speed
	int sf;		//Frozen motocycles speed
	int sv;		//vip motocycles speed
	int n[4];
	int f[4];
	int v[4];
	int autoS;
	int m;
	
public:
	load(string path, Restaurant* restaurant);
	void printInfo();
	~load();
	// getters
	int getNormalSpeed();
	int getFrozenSpeed();
	int getVIPSpeed();
	int* getNormalMotorsNumber();
	int* getVIPMotorsNumber();
	int* getFrozenMotorsNumber();
	int getTimeLimit();
private:
	void addOrder(int timeStamp, char type, int ID, int distance, double money, char region);
	void cancelOrder(int timeStamp, int ID);
	void promoteOrder(int timeStamp, int ID, double money);
	
};

