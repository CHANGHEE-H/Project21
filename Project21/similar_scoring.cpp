#include <iostream>
#include <string>

using std::string;

class SimilarityMeasurement {
public:
	int cmpLength(const string& str1, const string& str2) {
		int gap = getGap(str1, str2);

		double score = getScore(str1, str2, gap);
		if (0 > score) score = 0;

		return score;
	}

private:
	const int lengthMaxScore = 60;
	int getGap(const string& str1, const string& str2) {
		if (str1.length() > str2.length()) {
			return str1.length() - str2.length();
		}
		return str2.length() - str1.length();
	}

	double getScore(const string& str1, const string& str2, int gap) {
		if (0 == gap) 
			return lengthMaxScore;
		else if (str1.length() > str2.length()) 
			return (1 - (double)gap / str2.length()) * 60;
		else 
			return (1 - (float)gap / str1.length()) * 60;
	}
};