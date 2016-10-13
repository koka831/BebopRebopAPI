#include "CBebopInterface.h"
#include "Utility.h"
#include <iostream>

bool sendOperation()

using namespace rebop;
CBebopInterface bebop;

int main()
{
	bebop.Initialize();

	std::map<std::string,Status> eOperationMap;
	eOperationMap["takeoff"] = TAKEOFF;
	eOperationMap["land"] = LAND;
	eOperationMap["e"] = EMERGENCY;
	eOperationMap["front"] = FRONT;
	eOperationMap["back"] = BACK;
	eOperationMap["left"] = LEFT;
	eOperationMap["right"] = RIGHT;

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
			std::string s;
			getline(std::cin, s);
			Operation ope = eOperationMap[s];
			if(!sendOperation(ope)) break;
		}
	}

	bebop.Cleanup();

	return 0;

}

bool sendOperation(std::string operation)
{
	int _ope = operation_tag[operation];
    bool enableContinueOperation = true;

    switch(_ope) {
        case TAKEOFF:
            bebop.Takeoff();
            break;
        case LAND:
            bebop.Land();
            bebop.Cleanup();
            enableContinueOperation = false;
            break;
        case EMERGENCY:
            bebop.Emergency();
            bebop.Cleanup();
            enableContinueOperation = false;
            break;
        case LEFT:
            bebop.Flip(LEFT);
            break;
        case RIGHT:
            bebop.Flip(RIGHT);
            break;
        case FRONT:
            bebop.Flip(FRONT);
            break;
        case BACK:
            bebop.Flip(BACK);
            break;
        default:
            break;
    }
    return enableContinueOperation;
}

enum class eOperation
{
	TAKEOFF,
	LAND,
	E,
	LEFT,
	RIGHT,
	FRONT,
	BACK
};
