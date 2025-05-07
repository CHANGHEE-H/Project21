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

	int cmpAlpha(const string& str1, const string& str2) {
		int sameCnt = 0;
		int totalCnt = 0;

		for (char c = 'A'; c <= 'Z'; c++) {
			size_t ret1 = str1.find(c);
			size_t ret2 = str2.find(c);

			if (string::npos == ret1 && string::npos == ret2) {
				continue;
			}
			else if (string::npos != ret1 && string::npos != ret2) {
				sameCnt++; totalCnt++;
			}
			else {
				totalCnt++;
			}
		}

		return (double)sameCnt / totalCnt * alphaMaxScore;
	}

private:
	const int lengthMaxScore = 60;
	const int alphaMaxScore = 40;
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
			return (1 - (double)gap / str2.length()) * lengthMaxScore;
		else 
			return (1 - (float)gap / str1.length()) * lengthMaxScore;
	}
};