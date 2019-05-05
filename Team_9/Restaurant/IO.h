#pragma once
#include<string>
#include<fstream>
#include"Rest/Restaurant.h"
#include"Events/ArrivalEvent.h"
#include"Events/CancelationEvent.h"
#include"Events/PromotionEvent.h"
#include"Rest/Motorcycle.h"
#include"Defs.h"
#include"GUI/GUI.h"

//class GUI;
class Resturant;

class Io{
private:
	string FileName;
	Restaurant* pRest;
	GUI* pGUI;
	ifstream fileIN;
	ofstream fileOUT;
	int NmberEvent, vO[4], nO[4], fO[4], vM[4], nM[4], fM[4];
	int sum(int*x, int size);
public:
	Io(Restaurant* pR, GUI* pG);
	void load();
	void print(int, int, int, int, int, int, int, int, int, int, int, int); //phase 2...
	int getEventsNum();

	void PrintStatusBar( int ,int ,int ,int ,int ,int ,int ,int ,int ,int ,int ,int );

	~Io();

};
