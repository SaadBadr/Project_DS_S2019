#pragma once
#include "Event.h"

class PromotionEvent : public Event
{
	 int ExMoney;				// Extra money the customer paid

public : 

	PromotionEvent (const int eTime, const int oID , const int exMoney) ;

	virtual void Execute(Restaurant* pRest)const;

};

