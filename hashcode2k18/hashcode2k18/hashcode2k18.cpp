// hashcode2k18.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <memory>
#include "SDR.hpp"
#include "Algo.cpp"
#include "ParseFile.cpp"

int main(int ac, char **av)
{
	std::shared_ptr<SDR> sdr = std::make_shared<SDR>();
	ParseFile p(av[0], sdr);
	p.readFile();
	algo(sdr);
    return 0;
}