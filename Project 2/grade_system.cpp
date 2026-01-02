#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

char getGrade(float score);
float calculateAverage(const vector<float> &scores);

int main() {
  int numScores;
  cout << "How many scores do you want to input ? ";
  cin >> numScores;

  vector<float> scores(numScores);

  cout << "Enter " << numScores
       << " scores (separated by space or enter): " << endl;

  for (int i = 0; i < numScores; i++) {
    cout << "Score " << (i + 1) << ": ";
    cin >> scores[i];
  }

  cout << "\n--- Final Result --" << endl;
  for (int i = 0; i < scores.size(); ++i) {
    cout << "Score " << (i + 1) << ": " << scores[i] << endl;
  }

  float avg = calculateAverage(scores);
  cout << "\n===============" << endl;
  cout << "Average Score: " << avg << endl;
  cout << "Overall Grade: " << getGrade(avg) << endl;

  return 0;
}

float calculateAverage(const vector<float> &scores) {
  float sum = 0.0f;

  for (float s : scores) {
    sum += s;
  }

  return sum / scores.size();
}

char getGrade(float score) {
  if (score >= 90.0) {
    return 'A';
  } else if (score >= 70.0) {
    return 'B';
  } else if (score >= 50.0) {
    return 'C';
  } else if (score >= 30.0) {
    return 'D';
  } else {
    return 'E';
  }
}
