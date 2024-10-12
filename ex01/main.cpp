#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;
	std::cout << "1" << std::endl;
	j->makeSound(); // Dogの音
	i->makeSound(); // Catの音

	std::cout << std::endl;
	std::cout << "2" << std::endl;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "3" << std::endl;
	const int NUM_ANIMALS = 10;
	Animal* animals[NUM_ANIMALS];

	// 半分のDogと半分のCatを作成
	std::cout << std::endl;
	std::cout << "4" << std::endl;
	for (int i = 0; i < NUM_ANIMALS / 2; ++i)
	{
		animals[i] = new Dog();
	}
	for (int i = NUM_ANIMALS / 2; i < NUM_ANIMALS; ++i)
	{
		animals[i] = new Cat();
	}
	
	// 各動物の音を確認
	std::cout << std::endl;
	std::cout << "5" << std::endl;
	for (int i = 0; i < NUM_ANIMALS; ++i)
	{
		animals[i]->makeSound();
	}

	// Dogの深いコピーをテスト
	std::cout << std::endl;
	std::cout << "6" << std::endl;
	Dog originalDog;
	std::cout << std::endl;
	Dog copiedDog = originalDog;

	std::cout << std::endl;
	// WrongCatの浅いコピーをテスト
	WrongCat originalCat;
	WrongCat copiedCat = originalCat;

	// アドレスが異なる
	std::cout << "Original originalDog Brain Address: " << originalDog.getBrainAddress() << std::endl;
	std::cout << "Copied copiedDog Brain Address: " << copiedDog.getBrainAddress() << std::endl;

	// アドレスが同じ
	std::cout << "Wrong originalCat Brain Address: " << originalCat.getBrainAddress() << std::endl;
	std::cout << "Wrong copiedCat Brain Address: " << copiedCat.getBrainAddress() << std::endl;

	// すべての動物を削除
	std::cout << std::endl;
	std::cout << "7" << std::endl;
	for (int i = 0; i < NUM_ANIMALS; ++i)
	{
		delete animals[i];
	}

	return 0;
}
