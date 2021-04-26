#include"iostream"
#include <map>
#include<vector>

class CurrentReadings {
public:

	virtual std::vector<int> sortCurrentSamples(std::vector<int>& samples) = 0;
	virtual std::vector<int> removeDuplicateFromCurrentSamples(std::vector<int>& samplesSamples) = 0;
	virtual std::map<int, int > countFrequency(std::vector<int>& samples) = 0;
	virtual void detectRange(std::vector<int>& continuousReadings, std::map<int, int > frequecyHandler) = 0;
};

class Icurrentreadings {
public:
	 std::map<int, int> frequency;
	 std::vector<int> sortCurrentSamples(std::vector<int>& samples);
	 std::vector<int> removeDuplicateFromCurrentSamples(std::vector<int>& samplesSamples);
	 std::map<int, int > countFrequency(std::vector<int>& samples);
	 void detectRange(std::vector<int>& continuousReadings, std::map<int, int > frequecyHandler);
	 int ifExist(std::vector<int>& checkReadings, std::map<int, int > frequecyHandler);
};