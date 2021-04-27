#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch/catch.hpp"
#include "typewise-alert.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include<map>

TEST_CASE(" detect the ranges and readings in each range") {
	
	std::vector<int> currentSamples = { 3, 3, 5, 4, 10, 11, 12 };
	Icurrentreadings currentreadings;
	
	auto const expectedSortedSamples = { 3, 3, 4, 5, 10, 11, 12 };
	std::vector<int> sorted = currentreadings.sortCurrentSamples(currentSamples);
	REQUIRE(std::equal(begin(sorted), end(sorted), begin(expectedSortedSamples), end(expectedSortedSamples)));

	/*count to frequency to add later*/
	std::map<int, int > frequecyHandler;
	frequecyHandler = currentreadings.countFrequency(sorted);

	auto const expectedContinuousReadings= { 3, 4, 5, 10, 11, 12 };
	std::vector<int> continuousReadings = currentreadings.removeDuplicateFromCurrentSamples(sorted);
	REQUIRE(std::equal(begin(continuousReadings), end(continuousReadings), begin(expectedContinuousReadings), end(expectedContinuousReadings)));


	/*detect range and readings*/
	currentreadings.detectRange(continuousReadings, frequecyHandler);

}

	
