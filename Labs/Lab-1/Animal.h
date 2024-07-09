#ifndef ANIMAL_H
#define ANIMAL_H
class Animal
{
public:
	virtual void makeSound() = 0;
};
class Dog:public Animal
{
public:
	void makeSound();
};
class Cat :public Animal
{
public:
	void makeSound();
};
class Mouse :public Animal
{
public:
	void makeSound();
};
#endif