#include "BIBebopAPI.h"
#include "Utility.h"
#include "CBebopInterface.h"

using namespace rebop;

bool sendOperation(std::string operation)
{
	int _ope = operation_tag.converter[operation];
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
        case E:
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