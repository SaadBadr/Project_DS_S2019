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
	int NmberEvent;
public:
	Io(Restaurant* pR, GUI* pG);
	void load();
	void print(); //phase 2...
	int getEventsNum();

	void PrintStatusBar( int ,int ,int ,int ,int ,int ,int ,int ,int ,int ,int ,int );

	~Io();

};
