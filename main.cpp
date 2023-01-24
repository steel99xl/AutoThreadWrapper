#include "autothread.hpp"

void TestFun(){
	std::cout << "Dog Function" << std::endl;

};


struct Test : autothread::Thread{
	
	void FunctionCallBack() override{
		TestFun();
	}

};


int main(){

	Test dog;
	dog.State = autothread::BOOLWAIT;
	dog.AutoLoop = true;
	dog.WaitTime = 1;


	autothread::StartWork(&dog);

	std::cout << "boop" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	dog.WaitTime = 0;

//	cat.FunctionCallBack();

	std::cout << "uwu" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	dog.State = autothread::STOP;

	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	return 0;
}
