#include <iostream>
#include <vector>
#include <algorithm>

// Why Use & in for (auto &meeting : meetings)?
// The & in auto &meeting means we are using a reference instead of making a copy. This has two main advantages:

// Avoids Unnecessary Copies (Performance Improvement)

// If we used auto meeting, it would create a copy of each pair<int, int> in the meetings vector.
// This means extra memory usage and additional copying operations.
// Using auto &meeting allows us to directly access the elements in the vector without copying.
// Allows Modifying Elements (Not Required Here)

// If we needed to modify meeting, using auto &meeting ensures we are changing the original element in meetings rather than modifying a copy.
// In this specific case, we don't modify meeting, so this isn't a necessity.

using namespace std;

// Function to find the maximum number of meetings
int maxMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();

    // Step 1: Pair up start and end times and sort based on end times
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++) {
        meetings.push_back({end[i], start[i]});  // Sorting by end time
    }
    sort(meetings.begin(), meetings.end());

    // Step 2: Iterate through sorted meetings and select non-overlapping ones
    int count = 0, last_end_time = -1;
    for (auto &meeting : meetings) {
        int meeting_end = meeting.first;
        int meeting_start = meeting.second;

        if (meeting_start > last_end_time) {  // If meeting can be scheduled
            count++;
            last_end_time = meeting_end;
        }
    }
    
    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << "Maximum number of meetings: " << maxMeetings(start, end) << endl;
    return 0;
}
