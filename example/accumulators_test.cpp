//#include <boost/accumulators/accumulators.hpp>
//#include <boost/accumulators/statistics/stats.hpp>
//#include <boost/accumulators/statistics/mean.hpp>
//#include <boost/accumulators/statistics/moment.hpp>
//#include <time.h>
//#include <boost/random/normal_distribution.hpp>
//#include <boost/random/mersenne_twister.hpp>
//#include <boost/random/variate_generator.hpp>
#include <iostream>
#include "accumulators_test.h"

void accumulator_test_fun()
{
	// Define an accumulator set for calculating the mean and the 2nd moment ...
	accumulator_set<double, stats<tag::mean, tag::moment<2> > > acc1;

	// push in some data ...
	acc1(1.2);
	acc1(2.3);
	acc1(3.4);
	acc1(4.5);

	// display the results ...
	std::cout << "mean:   " << mean(acc1) << std::endl;
	std::cout << "moment: " << boost::accumulators::moment<2>(acc1) << std::endl;

	// 正态分布数据统计计算
	accumulator_set<double, stats<boost::accumulators::tag::mean, boost::accumulators::tag::moment<2>, boost::accumulators::tag::moment<6> > > acc2;

	accNormal(acc2, 1000);

	std::cout << "Mean: "
		<< mean(acc2) << std::endl
		<< "Moment 2: "
		<< moment<2>(acc2) << std::endl
		<< "Moment 6: "
		<< moment<6>(acc2) << std::endl;
}