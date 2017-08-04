#include <iostream>
#include <time.h>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/moment.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>

using namespace boost::accumulators;

#pragma once

template <class T>
void accNormal(T &acc, size_t n)
{
	// 创建一个正态分布数据生成器，种子为系统时间
	boost::variate_generator<boost::mt19937, boost::normal_distribution<> >
		generator(boost::mt19937(time(0)),
			boost::normal_distribution<>());

	for (size_t i = 0; i < n; ++i)
	{
		acc(generator());
	}
}

void accumulator_test_fun();