#include "CBebopInterface.h"
#include "Utility.h"
#include <iostream>

typedef enum
{
	TAKEOFF,
	LAND,
	EMERGENCY,
	LEFT,
	RIGHT,
	FRONT,
	BACK
}eOperation;

bool sendOperation(eOperation ope);

using namespace rebop;
CBebopInterface dev_bebop;

int main()
{
	dev_bebop.Initialize();

	std::map<std::string,eOperation> eOperationMap;
	eOperationMap["takeoff"] = TAKEOFF;
	eOperationMap["land"] = LAND;
	eOperationMap["e"] = EMERGENCY;
	eOperationMap["left"] = LEFT;
	eOperationMap["right"] = RIGHT;
	eOperationMap["front"] = FRONT;
	eOperationMap["back"] = BACK;

	if( dev_bebop.IsConnected() == false )
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
			eOperation ope = eOperationMap[s];
			if(!sendOperation(ope)) break;
		}
	}

	dev_bebop.Cleanup();

	return 0;

}

bool sendOperation(eOperation ope)
{
    bool enableContinueOperation = true;

    switch(ope) {
        case TAKEOFF:
            dev_bebop.Takeoff();
            break;
        case LAND:
            dev_bebop.Land();
            dev_bebop.Cleanup();
            enableContinueOperation = false;
            break;
        case EMERGENCY:
            dev_bebop.Emergency();
            dev_bebop.Cleanup();
            enableContinueOperation = false;
            break;
        case LEFT:
            dev_bebop.Flip(EFlipDirection::LEFT);
            break;
        case RIGHT:
            dev_bebop.Flip(EFlipDirection::RIGHT);
            break;
        case FRONT:
            dev_bebop.Flip(EFlipDirection::FRONT);
            break;
        case BACK:
            dev_bebop.Flip(EFlipDirection::BACK);
            break;
        default:
            break;
    }
    return enableContinueOperation;
}
