#pragma once
#include "Event.h"
#include "..\Rest\Restaurant.h"
#include"..\Rest\Order.h"
#include"..\Defs.h"


class PromotionEvent : public Event
{
	 int ExMoney;				// Extra money the customer paid

public : 

	PromotionEvent (const int eTime, const int oID , const int exMoney = 0) ;

	virtual void Execute(Restaurant* pRest)const;

};

