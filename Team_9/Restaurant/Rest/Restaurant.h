#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include <fstream>
#include"..\IO.h"
#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"
#include "..\Generic_DS\PriorityQueue.h"
#include "Order.h"
#include"Motorcycle.h"
#include"..\Generic_DS\List.h"
// it is the maestro of the project

class Restaurant  
{	
private:
	GUI *pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file

	Queue <Order*> NormalQueueA ; 
	Queue <Order*> NormalQueueB ; 
	Queue <Order*> NormalQueueC ; 
	Queue <Order*> NormalQueueD ; 

	Queue <Order*> FrozenQueueA ; 
	Queue <Order*> FrozenQueueB ; 
	Queue <Order*> FrozenQueueC ; 
	Queue <Order*> FrozenQueueD ; 
				
	PriorityQueue <Order*> VIPQueueA ; 
	PriorityQueue <Order*> VIPQueueB ; 
	PriorityQueue <Order*> VIPQueueC ; 
	PriorityQueue <Order*> VIPQueueD ; 

	Queue<Motorcycle*>NormalMotorA;
	Queue<Motorcycle*>FrozenMotorA;
	Queue<Motorcycle*>VIPMotorA;

	Queue<Motorcycle*>NormalMotorB;
	Queue<Motorcycle*>FrozenMotorB;
	Queue<Motorcycle*>VIPMotorB;

	Queue<Motorcycle*>NormalMotorC;
	Queue<Motorcycle*>FrozenMotorC;
	Queue<Motorcycle*>VIPMotorC;

	Queue<Motorcycle*>NormalMotorD;
	Queue<Motorcycle*>FrozenMotorD;
	Queue<Motorcycle*>VIPMotorD;

	int AutoPromotionTimeLimit;

	PriorityQueue<Motorcycle*> InServiceMotorA;
	PriorityQueue<Motorcycle*> InServiceMotorB;
	PriorityQueue<Motorcycle*> InServiceMotorC;
	PriorityQueue<Motorcycle*> InServiceMotorD;

	List<Order*> AllOrders;
	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	//Queue<Order*> DEMO_Queue;	//Important: This is just for demo
	/// ==>
	
	int ABCD_VFN_motorcycle[12] ;									// initial numbers of motorcycles
	
	bool assign(Order * ord, int timestep);

public:
	
	Restaurant();
	~Restaurant();
	void AddEvent(Event* pE);	//adds a new event to the queue of events
	void ExecuteEvents(int TimeStep);	//executes all events at timestep
	void RunSimulation();

	/// ==> 
	///  DEMO-related functions. Should be removed in phases 1&2
	//void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
	void InteractiveMode();

	void AddtoNormalQueueA(Order* po);	//adds an order to the demo queue
	void AddtoNormalQueueB(Order* po);	//adds an order to the demo queue
	void AddtoNormalQueueC(Order* po);	//adds an order to the demo queue
	void AddtoNormalQueueD(Order* po);	//adds an order to the demo queue

	void AddtoFrozenQueueA(Order* po);	//adds an order to the demo queue
	void AddtoFrozenQueueB(Order* po);	//adds an order to the demo queue
	void AddtoFrozenQueueC(Order* po);	//adds an order to the demo queue
	void AddtoFrozenQueueD(Order* po);	//adds an order to the demo queue

	void AddtoVIPQueueA(Order* po);	//adds an order to the demo queue
	void AddtoVIPQueueB(Order* po);	//adds an order to the demo queue
	void AddtoVIPQueueC(Order* po);	//adds an order to the demo queue
	void AddtoVIPQueueD(Order* po);	//adds an order to the demo queue

	Order* DequeueNormalQueueA();
	Order* DequeueNormalQueueB();
	Order* DequeueNormalQueueC();
	Order* DequeueNormalQueueD();

	Order* PeekNormalQueueA();
	Order* PeekNormalQueueB();
	Order* PeekNormalQueueC();
	Order* PeekNormalQueueD();

	//Order* getDemoOrder();			//return the front order from demo queue
	/// ==> 

	void StoreInputFile () ;

	//
	// TODO: Add More Member Functions As Needed
	//

	ifstream InputFile ;

	void AddMototrcycle(Motorcycle * po);
	//the following will be needed in phase2(serving orders with motorcycles)
	Motorcycle* GetNormalMotorcycleA();
	Motorcycle* GetNormalMotorcycleB();
	Motorcycle* GetNormalMotorcycleC();
	Motorcycle* GetNormalMotorcycleD();

	Motorcycle* GetFrozenMotorcycleA();
	Motorcycle* GetFrozenMotorcycleB();
	Motorcycle* GetFrozenMotorcycleC();
	Motorcycle* GetFrozenMotorcycleD();

	Motorcycle* GetVIPMotorcycleA();
	Motorcycle* GetVIPMotorcycleB();
	Motorcycle* GetVIPMotorcycleC();
	Motorcycle* GetVIPMotorcycleD();
	int GetInitialNumOfMOTR( int i );					// return values from  ( ABCD_VFN )
	
	// set values from  ( ABCD_VFN )

	void SetInitialNumOfMOTR(int Av ,int Af ,int An , int Bv ,int Bf ,int Bn , int Cv ,int Cf ,int , int Dv ,int Df ,int Dn);
	void SortAllOrders(List<Order*>& list);		// sorting all orders for OutputFile
	Order* GetListFisrtItem();

	void SetAutoPromTime(int time);
	int GetAutoPromTime();
};

#endif