#include"CancelationEvent.h"



CancelationEvent::CancelationEvent(const int eTime, const int ID) : Event(eTime, ID) {}



void CancelationEvent::Execute(Restaurant* pRest)const{


	bool Canceled = false;

	/////***************************************Region A***********************************

	Order * front = pRest->PeekNormalQueueA();
	Order * current;

	if (front->GetID() == OrderID) {
		pRest->DequeueNormalQueueA();
		delete front;
		return;
	}

	do {

		current = pRest->DequeueNormalQueueA();

		if (current->GetID() != OrderID)
			pRest->AddtoNormalQueueA(current);
	
		else{

			delete current;
			Canceled = true;
		}

	} while (pRest->PeekNormalQueueA() != front);

	if (Canceled)
		return;

	/////***************************************Region B***********************************

	front = pRest->PeekNormalQueueB();

	if (front->GetID() == OrderID) {

		pRest->DequeueNormalQueueB();
		delete front;
		return;
	}

	do {

		current = pRest->DequeueNormalQueueB();

		if (current->GetID() != OrderID)
			pRest->AddtoNormalQueueB(current);
		
		else {
			delete current;
			Canceled = true;
		}

	}while(pRest->PeekNormalQueueB() != front);

	if (Canceled)
		return;

	/////***************************************Region C***********************************

	front = pRest->PeekNormalQueueC();

	if (front->GetID() == OrderID){

		pRest->DequeueNormalQueueC();
		delete front;
		return;
	}

	do {

		current = pRest->DequeueNormalQueueC();

		if (current->GetID() != OrderID)
			pRest->AddtoNormalQueueC(current);
		
		else{
		
			delete current;
			Canceled = true;
		}

	} while (pRest->PeekNormalQueueC() != front);

	if (Canceled)
		return;


	/////***************************************Region D***********************************

	front = pRest->PeekNormalQueueD();
	
	if (front->GetID() == OrderID) {

		pRest->DequeueNormalQueueD();
		delete front;
		return;
	}

	do {

		current = pRest->DequeueNormalQueueD();

		if (current->GetID() != OrderID)
			pRest->AddtoNormalQueueD(current);
		
		else {

			delete current;
			Canceled = true;
		}

	} while (pRest->PeekNormalQueueD() != front);

}
