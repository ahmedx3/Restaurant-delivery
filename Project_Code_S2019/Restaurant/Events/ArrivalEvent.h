#ifndef __ARRIVAL_EVENT_H_
#define __ARRIVAL_EVENT_H_

#include "Event.h"


//class for the arrival event
class ArrivalEvent: public Event
{
	//info about the order ralted to arrival event
	int OrdDistance;	//order distance
	ORD_TYPE OrdType;		//order type: Normal, Frozen, VIP
	REGION OrdRegion;  //Region of this order	                
	double OrdMoney;	//Total order money
	int arrivalTime;
public:
	ArrivalEvent(int eTime, int oID, ORD_TYPE oType, REGION reg);
	//Add more constructors if needed

	ArrivalEvent(int eTime, int oID, ORD_TYPE oType, REGION reg, double money, int distance);
	int getArrivaltime();
	double getOrderMoney();
	ORD_TYPE getOrderType();
	REGION getOrderRegion();
	int getOrderDistqance();
	virtual void Execute(Restaurant *pRest);	//override execute function

};

#endif