#include "currentMonitoring.h"
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> Icurrentreadings::sortCurrentSamples(std::vector<int>& samples) {
	sort(samples.begin(), samples.end());
	return samples;
}
std::vector<int> Icurrentreadings::removeDuplicateFromCurrentSamples(std::vector<int>& samplesSamples) {

	samplesSamples.erase(unique(samplesSamples.begin(), samplesSamples.end()), samplesSamples.end());
	return samplesSamples;
}
std::map<int, int> Icurrentreadings::countFrequency(std::vector<int>& samples) {
	for (auto const & sample : samples) {
		int freq = std::count(samples.begin(), samples.end(), sample);
		if (freq >= 2) {
			frequency[sample] = freq;
		}
	}
	return frequency;
}
int Icurrentreadings::readingFromRange(std::vector<int>& checkReadings, std::map<int, int > frequecyHandler) {
	int temp = checkReadings.size();
	for(auto const & freq : frequecyHandler) {
		if (std::find(checkReadings.begin(), checkReadings.end(), freq.first) != checkReadings.end()) {
			temp = (checkReadings.size() - 1) + freq.second;
		}
	}
	return temp;
}
std::map<std::string, int>  Icurrentreadings::detectRange(std::vector<int>& continuousReadings, std::map<int, int > frequecyHandler) {
	Icurrentreadings checkReading;
	int half_size = ceil(continuousReadings.size() / 2);
	std::vector<int> lowRange(continuousReadings.begin(), continuousReadings.begin() + half_size);
	std::vector<int> highRange(continuousReadings.begin() + half_size, continuousReadings.end());

	int numberOfReadings1 = checkReading.readingFromRange(lowRange, frequecyHandler);
	int numberOfReadings2 = checkReading.readingFromRange(highRange, frequecyHandler);

	std::map<std::string, int> detectedrange;
	detectedrange["lowRangeLow"] = lowRange.front();
	detectedrange["lowRangeHigh"] = lowRange.back();
	detectedrange["lowRangeReading"] = numberOfReadings1;

	detectedrange["highRangeLow"] = highRange.front();
	detectedrange["highRangeHigh"] = highRange.back();
	detectedrange["highRangeReading"] = numberOfReadings2;

	return detectedrange;
}
