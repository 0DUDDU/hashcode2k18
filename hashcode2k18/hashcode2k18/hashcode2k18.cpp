// hashcode2k18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include "SDR.cpp"

int main()
{
	std::shared_ptr<SDR> sdr = std::make_shared<SDR>();
    return 0;
}

