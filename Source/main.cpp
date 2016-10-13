#include "CBebopInterface.h"
#include "Utility.h"
#include <iostream>
#include "BIBebopAPI.h"

using namespace rebop;
CBebopInterface bebop;

int main()
{
	bebop.Initialize();

	if( bebop.IsConnected() == false )
	{
		LOG( ERROR ) << "No connection";
	}
	else
	{
		LOG(INFO) << "ready. plz enter cmd.";
		LOG(INFO) << "(e.g)";
		LOG(INFO) << "takeoff, land, right, front, back, and e(e is emergercy cmd).";

		while(true) {
			std::string operation;
			getline(std::cin, operation);
			if(!sendOperation(operation)) break;
		}
	}

	bebop.Cleanup();

	return 0;

}


