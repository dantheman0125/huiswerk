// Exercise_13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Enemy
{
public:
	Enemy();
	void Attack() const;

protected:
	int m_Damage;
};

Enemy::Enemy() :
	m_Damage(10)
{}

void Enemy::Attack() const
{
	cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class Boss : public Enemy
{
public:
	Boss();
	void SpecialAttack() const;

protected:
	int m_DamageMultiplier;
};

Boss::Boss() :
	m_DamageMultiplier(3)
{}

void Boss::SpecialAttack() const
{
	cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage);
	cout << " damage points!\n";
}

class FinalBoss : public Boss
{
public:
	FinalBoss();
	void MegaAttack() const;
private:
	int m_DamageMultiplier;
};

FinalBoss::FinalBoss() :
	m_DamageMultiplier(10)
{}

void FinalBoss::MegaAttack() const
{
	cout << "Mega Attack inflicts " << (m_DamageMultiplier *Boss::m_DamageMultiplier* m_Damage);
	cout << " damage points!\n";
}

int main()
{
	cout << "Creating an enemy.\n";
	Enemy enemy1;
	enemy1.Attack();

	cout << "\nCreating a boss.\n";
	Boss boss1;
	boss1.Attack();
	boss1.SpecialAttack();

	cout << "\nCreating a final boss.\n";
	FinalBoss finalboss1;
	finalboss1.Attack();
	finalboss1.SpecialAttack();
	finalboss1.MegaAttack();

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
