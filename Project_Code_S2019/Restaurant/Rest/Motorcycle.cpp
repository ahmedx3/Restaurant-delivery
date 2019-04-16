#include "Motorcycle.h"


Motorcycle::Motorcycle()
{
}

Motorcycle::Motorcycle(int i, ORD_TYPE t, int s, REGION r, STATUS ss , int hp)
{
	ID = i;
	type = t;
	speed = s;
	region = r;
	status = ss;
	HP = hp;
}

bool Motorcycle::operator>(Motorcycle & m2)
{
	return FT < m2.FT;
}


Motorcycle::~Motorcycle()
{
}

void Motorcycle::Assign(Order* & ord, int timeStep)
{
	ID = ord->GetID();
	status = SERV;

	FT = timeStep + (2 * (ord->GetDistance() / speed));
}

int Motorcycle::getFT() const
{
	return FT;
}

void Motorcycle::deAssign() {
	ID = -1;
	status = IDLE;
	FT = -1;
}

ORD_TYPE Motorcycle::getOrdType() const
{
	return type;
}
