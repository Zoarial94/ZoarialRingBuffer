#include "ZoarialStringBuffer.h"
#include <iostream>

int main(void)
{
	ZoarialStringBuffer buffer(256);


	buffer.addString("Testing String");
	std::cout << buffer.getString() << std::endl;
	buffer.addString("Test Again");
	std::cout << buffer.getString() << std::endl;
	buffer.addString("Testing String");
	std::cout << buffer.getString() << std::endl;
	buffer.addString("Test Again");
	std::cout << buffer.getString() << std::endl;
	buffer.addString("Testing String");
	std::cout << buffer.getString() << std::endl;
	buffer.addString("Test Again");
	std::cout << buffer.getString() << std::endl;
	buffer.addString("Testing String");
	std::cout << buffer.getString() << std::endl;
	buffer.addString("Test Again");
	std::cout << buffer.getString() << std::endl;
	buffer.addString("Testing String");
	std::cout << buffer.getString() << std::endl;
	buffer.addString("Test Again");
	buffer.addString("Test Again");
	buffer.addString("Test Again");
	buffer.addString("Test Again");
	buffer.addString("Test Again");
	buffer.addString("Test Again");
	std::cout << buffer.getString() << std::endl;
	std::cout << buffer.getString() << std::endl;
	std::cout << buffer.getString() << std::endl;
	std::cout << buffer.getString() << std::endl;
	std::cout << buffer.getString() << std::endl;
	std::cout << buffer.getString() << std::endl;
	std::cout << buffer.getString() << std::endl;

	return 0;
}