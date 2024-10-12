#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Animalのインスタンスは作成しない
	// Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();
	WrongAnimal* wc = new WrongCat();
	WrongCat* wcat = new WrongCat();
	WrongAnimal* wa = new WrongAnimal();

	std::cout << j->getType() << ": ";
	j->makeSound();

	std::cout << i->getType() << ": ";
	i->makeSound();

	std::cout << wcat->getType() << ": ";
	wcat->makeSound();

	std::cout << wc->getType() << ": ";
	wc->makeSound();

	std::cout << wa->getType() << ": ";
	wa->makeSound();

	// std::cout << meta->getType() << ": ";
	// meta->makeSound();

	delete j;
	delete i;
	delete wcat;
	delete wc;
	delete wa;
	// delete meta;

	return 0;
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q ex02");
// }


// 純粋仮想関数（pure virtual function）を持つクラスは、抽象クラス（abstract class）と呼ばれます。
// この特性は、C++の基本的な設計の一部としてあります。
// 以下に、なぜ純粋仮想関数を持つクラスを直接インスタンス化できないのかを説明します。

// 意味的な理由: 純粋仮想関数は、具体的な実装が存在しない関数です。
// そのため、この関数を持つクラスは「完全」でないと考えられます。
// この不完全なクラスを直接インスタンス化することは、意味がありません。
// 抽象クラスは、特定のインターフェースを強制するための「契約」のようなものとして考えられます。
// この契約を満たす具体的な実装は、サブクラスで提供されるべきです。

// 実装的な理由: オブジェクトがそのクラスのメソッドを呼び出す場合、具体的な実装が必要です。
// 純粋仮想関数はその実装を持っていないので、もしクラスをインスタンス化してその関数を呼び出そうとすると、
// プログラムはどの実装を呼び出すべきかわからなくなります。
// そのため、コンパイラは純粋仮想関数を持つクラスの直接的なインスタンス化を禁止しています。

// 例を使って考えると、Animalクラスが純粋仮想関数makeSoundを持つ場合、
// 具体的な音（例えば「ワン！」や「ニャー！」）を出す実装がAnimalクラスには存在しないため、
// Animalのオブジェクトを作成してmakeSoundを呼び出すことはできません。
// しかし、DogやCatのようなサブクラスでは、このmakeSound関数に具体的な実装を提供することができます。

// 以上の理由から、純粋仮想関数を持つクラスは直接インスタンス化できないのです。