#ifndef __ARRIVAL_EVENT_H_
#define __ARRIVAL_EVENT_H_

#include "Event.h"


//class for the arrival event
class ArrivalEvent: public Event							// R
{
	
	int OrdDistance;	//order distance
	ORD_TYPE OrdType;		//order type: Normal, Frozen, VIP
	REGION OrdRegion;  //Region of this order	                
	double OrdMoney;	//Total order money
public:
	ArrivalEvent(int eTime, int oID, ORD_TYPE oType, REGION reg, double money);
	//Add more constructors if needed
	
	virtual void Execute(Restaurant *pRest)const;	//override execute function

	REGION get_region();
	ORD_TYPE get_type();
};

#endif