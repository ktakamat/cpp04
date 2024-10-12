#include "Cat.hpp"

Cat::Cat()
{
	brain = new Brain();
	type = "Cat";
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	brain = new Brain(*other.brain);  // 深いコピーを行う
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;  // 現在のBrainオブジェクトを削除
		brain = new Brain(*other.brain);  // コピー元のBrainオブジェクトを深くコピーする
	}
	std::cout << "Cat assignment operator called." << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrainAddress() const
{
	return brain;
}
