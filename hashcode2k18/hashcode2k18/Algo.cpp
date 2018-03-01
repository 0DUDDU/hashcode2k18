#include "stdafx.h"
#include "SDR.hpp"
#include <memory>
#include <fstream> 
#include <algorithm>
#include <ctime> 

void	algo(std::shared_ptr<SDR> infos)
{
	std::srand(unsigned(std::time(0)));
	std::ofstream outfile("rendu.txt");

	std::random_shuffle(infos->ridesList.begin(), infos->ridesList.end());
	int i = 0;
	for (auto it = infos->ridesList.begin(); it != infos->ridesList.end(); it++)
	{
		infos->cars.at(i++ % infos->cars.size)->rides.push_back(*it);
	}
	i = 0;
	for (auto it = infos->cars.begin(); it != infos->cars.end(); it++)
	{
		outfile << i++;
		for (auto jt = (*it)->rides.begin(); jt != (*it)->rides.end(); jt++)
			outfile << " " << (*jt)->_id;
	}
	outfile.close();
}