#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k, x, y;
		cin >> n >> k >> x >> y;
		// note: it would be better if you read and understand the problem first
		// there are only 4 possible coordinates, check in the image attached in this repository
		int position = k % 4;
		if (x == y) { 
			// if x == y then naturally, it will end it in the pocket hole
			// this condition is the only way to get into the pocket hole since
			// the restriction is that the shot will always be in 45 degrees
			cout << n << " " << n;
		} else if (x == 0 && y != 0) { 
			// this is the condition if cue ball is in the vertical side (left) of the board
			if (position == 0) {
				// if k mod 4 is 0, then the coordinates of the cue ball will the same
				cout << x << " " << y;
			} else {
				// store the inverse coordinates of the cue ball
				pair<int, int> partner_of_original = {y, x};
				int distance = n - y;
				x += distance;
				y = n;
				if (position == 1) {
					// if k mod 4 is 1, then the cue ball is in the horizontal side (top) of the board
					// get the distance between y and n, and add it to both coordinates 
					cout << x << " " << y;
				} else if (position == 2) {
					// if k mod 4 is 2, then the cue ball is in the vertical side (right) of the board
					// just print the inverse coordinates from the coordinates in the previous condition
					cout << y << " " << x;
				} else {
					// if k mod 4 is 3, then the cue ball is in the horizontal side (bottom) of the board
					// print the inverse coordinates of the original coordinates of the cue ball
					cout << partner_of_original.first << " " << partner_of_original.second;
				}
			}
		} else if (y == 0 && x != 0) {
			// this is the condition if the cue ball is in the horizontal side (bottom) of the board
			if (position == 0) {
				// if k mod 4 is 0, then the coordinates of the cue ball will be the same
				cout << x << " " << y;
			} else {
				// store the inverse coordinates of the cue ball
				pair<int, int> partner_of_original = {x, y};
				int distance = n - x;
				y += distance;
				x = n;
				if (position == 1) {
					// if k mod 4 is 1, then the cue ball is in the vertical side (right) of the board
					// get the distance between x and n, and add it to both coordinates
					cout << x << " " << y;
				} else if (position == 2) {
					// if k mod 4 is 2, then the cue ball is in the horizontal side (top) of the board
					// print the inverse coordinates from the coordinates in the previous condition
					cout << y << " " << x;
				} else {
					// if k mod 4 is 3, then the cue ball is in the vertical side (left) of the board
					// print the inverse coordinates of the original coordinates of the cue ball
					cout << partner_of_original.first << " " << partner_of_original.second;
				}
			}
		} else if (x == n && y != n) {
			// this is the condition if the cue ball is in the vertical side (right) of the board
			if (position == 0) {
				// k mod 4 is 0, then the coordinates of the cue ball will be the same
				cout << x << " " << y;
			} else if (position == 1) {
				// print the inverse of the original coordinates of the cue ball
				cout << y << " " << x;
			} else if (position == 2) {
				// if k mod 4 is 2, then the cue ball is in the vertical side (left) of the board
				// this is basicall the y - intercept
				// just find the difference of x and y and assign it to the y - coordinate while the x - coordinate is 0 
				cout << 0 << " " << x - y;
			} else {
				// if k mod 4 is 3, then the cue ball is in the horizontal side (bottom) of the board
				// this is basically the x - intercept
				// just find the difference of x and y and assign it to the the x - coordinate while the y - coordinate is 0
				cout << x - y << " " << 0;
			}
		} else if (y == n && x != n) {
			// this is the condition of the cue ball is in the horizontal side (top) of the board
			if (position == 0) {
				// if k mod 4 is 0, then the coordinates of the cue ball will be the same
				cout << x << " " << y;
			} else if (position == 1) {
				// print the inverse of the original coordinates of the cue ball
				cout << y << " " << x;
			} else if (position == 2) {
				// if k mod 4 is 2, then the cue ball is in the horizontal side (bottom) of the board
				// this is basically the x - intercept
				// just find the difference of y and x and assign it to the x - coordinate while the y - coordinate is 0
				cout << y - x << " " << 0;
			} else {
				// if k mod 4 is 3, then the cue ball is in the vertical side (left) of the board
				// this is basically the y - intercept
				// just find the difference of y and x and assign it the y - coordinate while the x - coordinate is 0
				cout << 0 << " " << y - x;
			}
		} else if (x > y) { 
			// this is the condition if x > y and the cue ball is somewhere in the middle of the board
			if (position == 0) {
				// if k mod 4 is 0, then the cue ball is in the horizontal side (bottom) of the board
				// this is basically the x - intercept
				// just subtract x and y and assign it to the x - coordinate while y - coordinate is 0
				cout << x - y << " " << 0;
			} else if (position == 3) {
				// if k mod 4 is 3, then the cue ball is in the vertical side (left) of the board
				// this is basically the y - intercept
				// just subtract x and y and assign it to the y - coordinate while the x - coordinate is 0
				cout << 0 << " " << x - y;
			} else {
				int distance = n - x;
				y += distance;
				x = n;
				if (position == 1) {
					// if k mod 4 is 1, then the cue ball is in the vertical side (right) of the board
					// add the distance between x and n to the x and y coordinates
					cout << x << " " << y;
				} else {
					// print the inverse coordinates of the coordinates in the previous conditon
					cout << y << " " << x;
				}
			}
		} else {
			// this is the condition if y > x and the cue ball is somewhere in the middle of the board
			int distance = n - y;
			x += distance;
			y = n;
			if (position == 1) {
				// if k mod 4 is 1, then the cue ball is in the horizontal side (top) of the board
				// add the distance of y and n to the x and y coordinates
				cout << x << " " << y;
			} else if (position == 2) {
				// if k mod 4 is 2, then the cue ball is in the vertical side (right) of the board
				// just print the inverse coordinates of the coordinates in the previous statement
				cout << y << " " << x;
			} else if (position == 3) {
				// if k mod 4 is 3, then the cue ball is in the horizontal side (bottom) of the board
				// this is basically the x - intercept
				// just subtract y and x, and assign it to the x - coordinate while the y - coordinate is 0
				cout << y - x << " " << 0;
			} else {
				// if k mod 4 is 0, then the cue ball is in the vertical side (left) of the board
				// this is basically the y - intercept
				// just subtract y and x, and assign it to the y - coordinate while the x - coordinate is 0 
				cout << 0 << " " << y - x;
			}
		}
		cout << '\n';
	}
	return 0;
}
