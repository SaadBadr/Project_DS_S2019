#pragma once
#include "Event.h"
#include "..\Rest\Restaurant.h"
#include"..\Rest\Order.h"
#include"..\Defs.h"


class CancelationEvent : public Event{

public : 

	CancelationEvent (const int eTime, const int ID) ;
	virtual void Execute(Restaurant* pRest)const;

};
