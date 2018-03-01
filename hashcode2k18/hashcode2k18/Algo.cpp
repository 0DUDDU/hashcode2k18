#include "stdafx.h"
#include "Header.h"

struct less_than_key
{
	inline bool operator() (shared_ptr<Ride> r1, shared_ptr<Ride> r2)
	{
		return (r1->latest < r2->latest && r1->earliest < r2->latest);
	}
};

void	algor(std::shared_ptr<SDR> infos, std::string file)
{
	std::srand(unsigned(std::time(0)));
	std::ofstream outfile(file+".out");
	
	//std::random_shuffle(infos->ridesList.begin(), infos->ridesList.end());
	std::sort(infos->ridesList.begin(), infos->ridesList.end(), less_than_key());
	int i = 0;
	for (auto it = infos->ridesList.begin(); it != infos->ridesList.end(); it++)
	{
		infos->cars.at(i++ % infos->cars.size()).rides.push_back(*it);
		
	}
	i = 1;
	for (auto it = infos->cars.begin(); it != infos->cars.end(); it++)
	{
		outfile << (*it).rides.size();
		for (auto jt = (*it).rides.begin(); jt != (*it).rides.end(); jt++)
			outfile << " " << (*jt)->_id;
		outfile << std::endl;
	}
	outfile.close();
}