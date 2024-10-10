#include "Dog.hpp"


Dog::Dog()
{
	brain = new Brain();
	type = "Dog";
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	brain = new Brain(*other.brain);  // 深いコピーを行う
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;  // 現在のBrainオブジェクトを削除
		brain = new Brain(*other.brain);  // コピー元のBrainオブジェクトを深くコピーする
	}
	std::cout << "Dog assignment operator called." << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrainAddress() const
{
	return brain;
}
