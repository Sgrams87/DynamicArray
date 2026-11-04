#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void enter_attendance(int* attendance, int size) {
	for (int i = 0; i < size; i++){
		cout << "Enter attendance for Event " << i + 1 << ": ";
		cin >> attendance[i];

		//validate attendance (int/positive number)
		while (cin.fail() || attendance[i] < 0){
			cout << "Please enter a valid attendance number!: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> attendance [i];
		}
	}
}

void display_attendance(const int* attendance, int size){
	cout << "\nEVENT ATTENDANCE REPORT\n";

	for (int i = 0; i < size; i++){
		cout << "Event " << i + 1 << ": " << attendance[i] << " attendees\n";
	}
}

int calc_total(const int* attendance, int size){
	int total = 0;
	for (int i = 0; i < size; i++){
		total += attendance[i];
	}
	return total;
}

int find_highest_event(const int* attendance, int size){
	int highestIndex = 0;

	for (int i = 1; i < size; i++){
		if (attendance[i] > attendance[highestIndex]){
			highestIndex = i;
		}
	}
	return highestIndex;
}

int main()
{
	cout << "EVENT ATTENDANCE TRACKER\n";

	int numEvents;

	cout << "How many events would you like to track? ";
	cin >> numEvents;

	while (cin.fail() || numEvents <= 0){
                cout << "Please enter a valid number greater than 0!: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> numEvents;
         }

         int* attendance = new int[numEvents]{};


         enter_attendance(attendance, numEvents);
         display_attendance(attendance, numEvents);
         int total = calc_total(attendance, numEvents);
         double avg = static_cast<double>(total) / numEvents;
         int highest = find_highest_event(attendance, numEvents);

         cout << "\nATTENDANCE SUMMARY\n";

         cout << "Total Attendance: " << total << endl;
         cout << fixed << setprecision(2) << "Average Attendance: " << avg << endl;
         cout << "Highest Attendance: Event " << highest + 1  << " : " << attendance[highest] << "attendees\n";

         delete[] attendance;
         attendance = nullptr;

         cout << "\nMemory released successfully!\n";

         return 0;

}
