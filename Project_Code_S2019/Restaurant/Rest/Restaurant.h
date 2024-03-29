#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_
#include <iostream>
#include <string>
#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"
#include "..\Generic_DS\PriorityQueue.h"
#include "..\Generic_DS\LinkedList.h"
#include "Motorcycle.h"

#include "Order.h"
#include "load.h"

// it is the maestro of the project
class Restaurant  
{	
private:

	PROG_MODE mode;

	GUI *pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file

	int totalWaitingOrders;

	int Normal[4];	//number of normal motorcycles for each region (changes during the simulation when a motorcycle is assigned an order or when it comes back)
	int Frozen[4];	//number of frozen motorcycles for each region (changes during the simulation when a motorcycle is assigned an order or when it comes back)
	int VIP[4];		//number of VIP motorcycles for each region (changes during the simulation when a motorcycle is assigned an order or when it comes back)
	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	Queue<Order*> DEMO_Queue;	//Important: This is just for demo
	/// ==>
	
	//
	// TODO: Add More Data Members As Needed
	//

	PriorityQueue<Order*> VIPOrdersRegionA;	// Queue of all active VIP orders of region A
	PriorityQueue<Order*> VIPOrdersRegionB;	// Queue of all active VIP orders of region B
	PriorityQueue<Order*> VIPOrdersRegionC;	// Queue of all active VIP orders of region C
	PriorityQueue<Order*> VIPOrdersRegionD;	// Queue of all active VIP orders of region D

	Queue<Order*> frozenOrdersRegionA;	// Queue of all active Frozen orders of region A
	Queue<Order*> frozenOrdersRegionB;	// Queue of all active Frozen orders of region B
	Queue<Order*> frozenOrdersRegionC;	// Queue of all active Frozen orders of region C
	Queue<Order*> frozenOrdersRegionD;	// Queue of all active Frozen orders of region D

	LinkedList<Order*> normalOrdersRegionA;	// Queue of all active Normal orders of region A
	LinkedList<Order*> normalOrdersRegionB;	// Queue of all active Normal orders of region B
	LinkedList<Order*> normalOrdersRegionC;	// Queue of all active Normal orders of region C
	LinkedList<Order*> normalOrdersRegionD;	// Queue of all active Normal orders of region D

	Queue<Motorcycle*> VIPMCA;				// Available MC in region A VIP
	Queue<Motorcycle*> VIPMCB;				// Available MC in region B VIP
	Queue<Motorcycle*> VIPMCC;				// Available MC in region C VIP
	Queue<Motorcycle*> VIPMCD;				// Available MC in region D VIP

	Queue<Motorcycle*> FrozenMCA;			// Available MC in region A Frozen
	Queue<Motorcycle*> FrozenMCB;			// Available MC in region B Frozen
	Queue<Motorcycle*> FrozenMCC;			// Available MC in region C Frozen
	Queue<Motorcycle*> FrozenMCD;			// Available MC in region D Frozen

	Queue<Motorcycle*> NormalMCA;			// Available MC in region A Normal
	Queue<Motorcycle*> NormalMCB;			// Available MC in region B Normal
	Queue<Motorcycle*> NormalMCC;			// Available MC in region C Normal
	Queue<Motorcycle*> NormalMCD;			// Available MC in region D Normal

	PriorityQueue<Motorcycle*> occupiedA;	// in use MC in Region A
	PriorityQueue<Motorcycle*> occupiedB;	// in use MC in Region B
	PriorityQueue<Motorcycle*> occupiedC;	// in use MC in Region C
	PriorityQueue<Motorcycle*> occupiedD;	// in use MC in Region D

	Queue<Motorcycle*> repairingA;			// in repair MC in region A
	Queue<Motorcycle*> repairingB;			// in repair MC in region B
	Queue<Motorcycle*> repairingC;			// in repair MC in region C
	Queue<Motorcycle*> repairingD;			// in repair MC in region D

	int waitingVIPA;
	int waitingVIPB;
	int waitingVIPC;
	int waitingVIPD;

	int waitingFrozenA;
	int waitingFrozenB;
	int waitingFrozenC;
	int waitingFrozenD;

	int waitingNormalA;
	int waitingNormalB;
	int waitingNormalC;
	int waitingNormalD;

	int brokenA;
	int brokenB;
	int brokenC;
	int brokenD;

	// data members for motorcycle info
	int sn;		//Normal motocycles speed
	int sf;		//Frozen motocycles speed
	int sv;		//vip motocycles speed
	int* n;		// no of normal for each region[array of 4] (They are gotten from the input file and they're Constant numbers that won't be changed during the simulation)
	int* f;		// no of frozen for each region[array of 4]	(They are gotten from the input file and they're Constant numbers that won't be changed during the simulation)
	int* v;		// no of vip for each region[array of 4]	(They are gotten from the input file and they're Constant numbers that won't be changed during the simulation)
	int autoS;	// time limit

	ofstream outputFile;
	// data members for no of orders
	int noOfNormOrdersA;
	int noOfNormOrdersB;
	int noOfNormOrdersC;
	int noOfNormOrdersD;

	int noOfFrozenOrdersA;
	int noOfFrozenOrdersC;
	int noOfFrozenOrdersB;
	int noOfFrozenOrdersD;

	int noOfVipOrdersA;
	int noOfVipOrdersB;
	int noOfVipOrdersC;
	int noOfVipOrdersD;

	double totalWaitingA;
	double totalWaitingC;
	double totalWaitingB;
	double totalWaitingD;

	double totalServA;
	double totalServB;
	double totalServC;
	double totalServD;
	// ouput info
	struct info;
	info* infoArr;
	int curr;
public:
	
	Restaurant();
	~Restaurant();
	void AddEvent(Event* pE);			//adds a new event to the queue of events
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();

	//
	// TODO: Add More Member Functions As Needed
	//

	// Phase 1 simulation function
	void simulationTestRun();

	// All VIP Orders ------------------------------------------------------------------------------
	void addToVIPQueueRegionA(Order* ord);	// Adds orders to VIP queue
	Order* getVIPOrderRegionA();			// Returns the front VIP order

	void addToVIPQueueRegionB(Order* ord);	// Adds orders to VIP queue
	Order* getVIPOrderRegionB();			// Returns the front VIP order

	void addToVIPQueueRegionC(Order* ord);	// Adds orders to VIP queue
	Order* getVIPOrderRegionC();			// Returns the front VIP order

	void addToVIPQueueRegionD(Order* ord);	// Adds orders to VIP queue
	Order* getVIPOrderRegionD();			// Returns the front VIP order
	// -----------------------------------------------------------------------------------------------

	// All Frozen Orders -----------------------------------------------------------------------------
	void addToFrozenQueueRegionA(Order* ord);	// Adds orders to Frozen queue
	Order* getFrozenOrderRegionA();				// Returns the front Frozen order

	void addToFrozenQueueRegionB(Order* ord);	// Adds orders to Frozen queue
	Order* getFrozenOrderRegionB();				// Returns the front Frozen order

	void addToFrozenQueueRegionC(Order* ord);	// Adds orders to Frozen queue
	Order* getFrozenOrderRegionC();				// Returns the front Frozen order

	void addToFrozenQueueRegionD(Order* ord);	// Adds orders to Frozen queue
	Order* getFrozenOrderRegionD();				// Returns the front Frozen order
	// -----------------------------------------------------------------------------------------------

	// All Normal Orders -----------------------------------------------------------------------------
	void addToNormalQueueRegionA(Order* ord);	// Adds orders to Normal queue
	Order* getNormalOrderRegionA();				// Returns the front normal order

	void addToNormalQueueRegionB(Order* ord);	// Adds orders to Normal queue
	Order* getNormalOrderRegionB();				// Returns the front normal order

	void addToNormalQueueRegionC(Order* ord);	// Adds orders to Normal queue
	Order* getNormalOrderRegionC();				// Returns the front normal order

	void addToNormalQueueRegionD(Order* ord);	// Adds orders to Normal queue
	Order* getNormalOrderRegionD();				// Returns the front normal order
	// -----------------------------------------------------------------------------------------------
	void cancelOrder1(int id);					// Cancels an order from all normal orders
	void cancelOrder2(int id);
	// -----------------------------------------------------------------------------------------------
	void setMCs();
	// -----------------------------------------------------------------------------------------------
	bool promoteToVIP(int i, double extraMoney);//Promotion Event





	/// ==> 
	///  DEMO-related functions. Should be removed in phases 1&2
	void Just_A_Demo();				//just to show a demo and should be removed in phase1 1 & 2
	void AddtoDemoQueue(Order* po);	//adds an order to the demo queue
	Order* getDemoOrder();			//return the front order from demo queue
	/// ==> 

private:
	void drawOneQueue(Queue<Order*>& queue);						// Draws one queue
	void drawOneQueue(PriorityQueue<Order*>& queue);
	void drawOneQueue(LinkedList<Order*>& queue);
	void drawOrdersToScreen();										// Draws all active orders
	void deleteOrdersEachTimeStep(int timeStep,string &stringA, string &stringB, string &stringC, string &stringD, int & A, int & B, int & C, int & D);						// deletes orders each time step as if assigning them to bikes
	void printStatusBarInfo(int currentTimeStep, string& stringA, string& stringB, string& stringC, string& stringD, int & A, int & B, int & C, int & D);					// prints all info in status bar
	bool cancelFromCertainQueue(int id, Queue<Order*> & queue);		// Cancel order from certain queue
	bool cancelFromCertainQueue(int id, PriorityQueue<Order*>& queue);
	bool dequeueFromOneQueue(Queue<Order*> & queue, int timeStep, string& stringA, string& stringB, string& stringC, string& stringD, int & A, int & B, int & C, int & D);	// dequeue one order
	bool dequeueFromOneQueue(PriorityQueue<Order*>& queue, int noOFNormalAvailable, int noOFVIPAvailable, int noOfFrozenAvailable, int timeStep, string& stringA, string& stringB, string& stringC, string& stringD, int & A, int & B, int & C, int & D);
	bool dequeueFromOneQueue(LinkedList<Order*>& queue, int timeStep, string& stringA, string& stringB, string& stringC, string& stringD, int & A, int & B, int & C, int & D);
	bool cancelFromCertainQueue1(int id, LinkedList<Order*>& queue);
	bool cancelFromCertainQueue2(int id, LinkedList<Order*>& queue);
	void lastTimeStep(int currentTimeStep, string &stringA, string &stringB, string &stringC, string &stringD, int & A, int & B, int & C, int & D);							// To see last Time step

	// Assign functions
	bool AssignOrder(Order* & ord, int timeStep,Motorcycle* &m);
	bool VIPAssign(Order* & ord, int timeStep,Motorcycle* &m);
	bool FrozAssign(Order* & ord, int timeStep, Motorcycle* &m);
	bool NormAssign(Order* & ord, int timeStep, Motorcycle* &m);
	void ReturnMotors(int timeStep);
	void ReturnRepairedMotors(int timeStep);


	//For Promotion functions
	Order* getOrderById(int i);
	bool autoPromoteOrders(int TS);
	// sort outpur
	void sortInfo(info* in, int size);

};

#endif