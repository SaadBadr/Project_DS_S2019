#include"PromotionEvent.h"


PromotionEvent::PromotionEvent(const int eTime, const int oID, const int exMoney) : Event(eTime, oID)
{
	ExMoney = exMoney;
}

void PromotionEvent::Execute(Restaurant * pRest) const{}
