#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();

	std::cout << std::endl;
	std::cout << i->getType() << ": ";
	i->makeSound();
	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << meta->getType() << ": ";
	meta->makeSound();
	std::cout << wrong->getType() << ": ";
	wrong->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong;
	return 0;
}
