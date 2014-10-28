#include<iostream>
#include<ctime>
using namespace std;
void han(int count, int start, int finish, int temp) {
	if (count == 1) {
		cout << "move disk " << count << " from peg " << start << " to peg " << finish << endl;
	}
	if (count > 1) {
		han(count-1, start, temp, finish);
		cout << "move disk " << count << " from peg " << start << " to peg " << finish << endl;
		han(count-1, temp, finish, start); 
	}
}
int main() {
	clock_t begin, end;
	double totaltime;
	begin = clock();
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		han(n, 1, 3, 2);
	}
	end = clock();
	totaltime = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "It runs for " << totaltime << " seconds" << endl; 
	return 0;
}
