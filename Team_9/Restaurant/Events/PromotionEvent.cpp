#include"PromotionEvent.h"


PromotionEvent::PromotionEvent(const int eTime, const int oID, const int exMoney) : Event(eTime, oID)
{
	ExMoney = exMoney;
}

void PromotionEvent::Execute(Restaurant * pRest) const{
	
	int Arrivaltime, money, distance;


	bool Canceled = false;

	/////***************************************Region A***********************************

	Order * front = pRest->PeekNormalQueueA();
	Order * current;

	if (front && front->GetID() == OrderID) {
		pRest->DequeueNormalQueueA();
		Arrivaltime = front->GetArrTime();
		money		= front->GetMoney();
		distance	= front->GetDistance();
		pRest->AddtoVIPQueueA(new Order(OrderID, TYPE_VIP, A_REG, money+ExMoney, distance, Arrivaltime));
		delete front;
		return;
	}

	do {

		current = pRest->DequeueNormalQueueA();

		if (current && current->GetID() != OrderID)
			pRest->AddtoNormalQueueA(current);

		else if (current) {

			Arrivaltime = current->GetArrTime();
			money = current->GetMoney();
			distance = current->GetDistance();
			pRest->AddtoVIPQueueA(new Order(OrderID, TYPE_VIP, A_REG, money+ExMoney, distance, Arrivaltime));
			delete current;
			Canceled = true;
		}

	} while (pRest->PeekNormalQueueA() != front);

	if (Canceled)
		return;

	/////***************************************Region B***********************************

	front = pRest->PeekNormalQueueB();

	if (front && front->GetID() == OrderID) {

		pRest->DequeueNormalQueueB();
		Arrivaltime = front->GetArrTime();
		money = front->GetMoney();
		distance = front->GetDistance();
		pRest->AddtoVIPQueueB(new Order(OrderID, TYPE_VIP, B_REG, money+ExMoney, distance, Arrivaltime));
		delete front;
		return;
	}

	do {

		current = pRest->DequeueNormalQueueB();

		if (current && current->GetID() != OrderID)
			pRest->AddtoNormalQueueB(current);

		else if (current) {
			Arrivaltime = current->GetArrTime();
			money = current->GetMoney();
			distance = current->GetDistance();
			pRest->AddtoVIPQueueB(new Order(OrderID, TYPE_VIP, B_REG, money+ExMoney	, distance, Arrivaltime));
			delete current;
			Canceled = true;
		}

	} while (pRest->PeekNormalQueueB() != front);

	if (Canceled)
		return;

	/////***************************************Region C***********************************

	front = pRest->PeekNormalQueueC();

	if (front && front->GetID() == OrderID) {
		Arrivaltime = current->GetArrTime();
		money = current->GetMoney();
		distance = current->GetDistance();
		pRest->AddtoVIPQueueC(new Order(OrderID, TYPE_VIP, C_REG, money + ExMoney, distance, Arrivaltime));
		pRest->DequeueNormalQueueC();
		delete front;
		return;
	}

	do {

		current = pRest->DequeueNormalQueueC();

		if (current && current->GetID() != OrderID)
			pRest->AddtoNormalQueueC(current);

		else if (current) {
			Arrivaltime = current->GetArrTime();
			money = current->GetMoney();
			distance = current->GetDistance();
			pRest->AddtoVIPQueueC(new Order(OrderID, TYPE_VIP, C_REG, money + ExMoney, distance, Arrivaltime));
			delete current;
			Canceled = true;
		}

	} while (pRest->PeekNormalQueueC() != front);

	if (Canceled)
		return;


	/////***************************************Region D***********************************

	front = pRest->PeekNormalQueueD();

	if (front && front->GetID() == OrderID) {

		pRest->DequeueNormalQueueD();
		Arrivaltime = current->GetArrTime();
		money = current->GetMoney();
		distance = current->GetDistance();
		pRest->AddtoVIPQueueD(new Order(OrderID, TYPE_VIP, D_REG, money + ExMoney, distance, Arrivaltime));
		delete front;
		return;
	}

	do {

		current = pRest->DequeueNormalQueueD();

		if (current && current->GetID() != OrderID)
			pRest->AddtoNormalQueueD(current);

		else if (current) {
			Arrivaltime = current->GetArrTime();
			money = current->GetMoney();
			distance = current->GetDistance();
			pRest->AddtoVIPQueueD(new Order(OrderID, TYPE_VIP, D_REG, money + ExMoney, distance, Arrivaltime));
			delete current;
			Canceled = true;
		}

	} while (pRest->PeekNormalQueueD() != front);

}
