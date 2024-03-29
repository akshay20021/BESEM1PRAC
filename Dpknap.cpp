#include <iostream>
using namespace std;
int main() {
int capacity;
int items;
cout << "Enter the capacity of the knapsack: ";
cin >> capacity;
cout << "Enter the number of items: ";
cin >> items;
int price[items + 1];
int wt[items + 1];
cout << "Enter the weight and price of each item:" << endl;
for (int i = 1; i <= items; i++) {
cout << "Item " << i << " (weight price): ";
cin >> wt[i] >> price[i];
}
int dp[items + 1][capacity + 1];
for (int i = 0; i <= items; i++) {
for (int j = 0; j <= capacity; j++) {
if (i == 0 || j == 0) {
dp[i][j] = 0;
} else if (wt[i] <= j) {
dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
} else {
dp[i][j] = dp[i - 1][j];
}
}
}
cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
return 0;
}