/*
 * Program that takes the race distance, in miles, from the user
 * and finds the number of days in the training schedule.
 *
 * Author: Noah Young
 */

#include <iostream>

using namespace std;

long training(int dist, int a);

int main() {
  // user inputs the race distance
  cout << "Enter the distance of the race in miles: ";
  int dist;
  cin >> dist;

  // output the length of the training schedule
  cout << "Length of training schedule: " 
  << training(dist, 1) << " days." << endl;
}

long training(int dist, int a) {
  static long training_days = 0;

  // if the sum of the intervals equals dist,
  // add a day in the training schedule
  if (dist == 0) {
    training_days++;
  }

  // loop through interval sizes from 1 to dist.
  for (int i = a; i <= dist; i++) {
    training(dist - i, i); // reduce dist by interval i
  }

  return training_days;
} 