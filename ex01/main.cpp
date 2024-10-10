#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
		
	j->makeSound(); // Dogの音
	i->makeSound(); // Catの音

	delete j;
	delete i;

	const int NUM_ANIMALS = 10;
	Animal* animals[NUM_ANIMALS];

	// 半分のDogと半分のCatを作成
	for (int i = 0; i < NUM_ANIMALS / 2; ++i)
	{
		animals[i] = new Dog();
	}
	for (int i = NUM_ANIMALS / 2; i < NUM_ANIMALS; ++i)
	{
		animals[i] = new Cat();
	}
	
	// 各動物の音を確認
	for (int i = 0; i < NUM_ANIMALS; ++i)
	{
		animals[i]->makeSound();
	}

	// Dogの深いコピーをテスト
	Dog originalDog;
	Dog copiedDog = originalDog;

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
	for (int i = 0; i < NUM_ANIMALS; ++i)
	{
		delete animals[i];
	}

	return 0;
}
