#pragma once
#include "BIUtils.h"

bool sendOperation(std::string operation);

namespace rebop
{

class OperationManager
{
	private:
		ENUM(operation_tag,
			TAKEOFF,
			LAND,
			FRONT,
			BACK,
			LEFT,
			RIGHT,
			E)
		operation_tag::type operation;
};

}