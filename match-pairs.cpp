#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// helper to calculate prefix sum
long long getSumRange (const vector<long long>& prefixSum, int left, int right) {
    if (left > right) return 0;
    return prefixSum[right+1] - prefixSum[left];
}

// solution 
long long matchPairs(vector<int> & nums, long long numCount) {
    int n = nums.size();

    // part 1 - sorting. O(nlogn) time 
    sort(nums.begin() , nums.end());

    // part 2 - prefix sums. O(n) time, O(n) space.
    vector<long long> prefixSum(n+1, 0);
    for (int i=0; i<n; i++) {
        prefixSum[i+1] = prefixSum[i] + nums[i];
    }

    // part 3 - binary search for threshold pair sum value
    // O(logn) time
    long long low = (long long) nums[0] + nums[0];
    long long high = (long long) nums[n-1] + nums[n-1];
    long long threshold = low;

    while (low <= high) {
        long long mid = low + (high-low) / 2;

        long long count = 0;
        for (int i=0; i<n; i++) {
            long long target = mid - nums[i];

            // O(logn) lower_bound
            auto it = lower_bound(nums.begin(), nums.end(), target);
            int index = distance(nums.begin(), it);

            count += (n-index);
        }

        if (count >= numCount) {
            threshold = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    // part 4 - sum all the values together
    long long total = 0;
    long long pairsFound = 0;

    // O(nlogn) to iterate thru each element + lower_bound()
    for (int i=0; i<n; i++) {
        long long target = threshold + 1 - nums[i];

        auto it = lower_bound(nums.begin(), nums.end(), target);
        int index = distance(nums.begin(), it);

        long long countValid = n - index;

        if (countValid > 0) {
            pairsFound += countValid;

            total += (long long) nums[i] * countValid;

            // O(1) retrieval
            total += getSumRange(prefixSum, index, n-1);
        }
    }

    // part 5 - fill gap of remaining pairs at the threshold value
    // O(1) calculation
    long long remaining_pairs = numCount - pairsFound;
    if (remaining_pairs > 0) {
        total += remaining_pairs * threshold;
    }

    return total;

} // total time O(nlogn), space O(n)


int main () {
    vector<int> bw = {6,4,7};
    long long sc = 4;

    cout << "Max Pair Sum: " << matchPairs(bw, sc) << '\n' << flush;

    return 0;
}
