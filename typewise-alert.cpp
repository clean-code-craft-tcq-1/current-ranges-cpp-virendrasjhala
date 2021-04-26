#include "typewise-alert.h"
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
int Icurrentreadings::ifExist(std::vector<int>& checkReadings, std::map<int, int > frequecyHandler) {
	Icurrentreadings Ifrequency;
	int temp = checkReadings.size();
	for(auto const & freq : frequecyHandler) {
		if (std::find(checkReadings.begin(), checkReadings.end(), freq.first) != checkReadings.end()) {
			temp = (checkReadings.size() - 1) + freq.second;
		}
	}
	return temp;
}
void Icurrentreadings::detectRange(std::vector<int>& continuousReadings, std::map<int, int > frequecyHandler) {
	Icurrentreadings checkReading;
	int half_size = ceil(continuousReadings.size() / 2);
	std::vector<int> lowRange(continuousReadings.begin(), continuousReadings.begin() + half_size);
	std::vector<int> highRange(continuousReadings.begin() + half_size, continuousReadings.end());
	int numberOfReadings1 = checkReading.ifExist(lowRange, frequecyHandler);
	int numberOfReadings2 = checkReading.ifExist(highRange, frequecyHandler);

	std::cout << "range" << " " << "readings"<<"\n";
	std::cout << lowRange.front() << "-" << lowRange.back() << " "<< numberOfReadings1<<"\n";
	std::cout << highRange.front() << "-" << highRange.back() << " " << numberOfReadings2<<"\n";
}
