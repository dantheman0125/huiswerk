// Exercise_14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Creature  //abstract class
{
public:
	Creature(int health = 100);
	virtual void Greet() const = 0;   //pure virtual member function
	virtual void DisplayHealth() const;

protected:
	int m_Health;
};

Creature::Creature(int health) :
	m_Health(health)
{}

void Creature::DisplayHealth() const
{
	cout << "Health: " << m_Health << endl;
}

class Orc : public Creature
{
public:
	Orc(int health = 120);
	virtual void Greet() const;
};

Orc::Orc(int health) :
	Creature(health)
{}

void Orc::Greet() const
{
	cout << "The orc grunts hello.\n";
}

class OrcBoss : public Orc
{
public:
	OrcBoss(int health = 180);
	virtual void Greet() const;
};

OrcBoss::OrcBoss(int health) :
	Orc(health)
{}

void OrcBoss::Greet() const
{
	cout << "The orc boss growls hello.\n";
}

int main()
{
	Creature* pCreature = new Orc();
	pCreature->Greet();
	pCreature->DisplayHealth();

	delete pCreature;
	pCreature = 0;

	pCreature = new OrcBoss();
	pCreature->Greet();
	pCreature->DisplayHealth();

	delete pCreature;
	pCreature = 0;

	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
