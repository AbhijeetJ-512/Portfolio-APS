#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

const int capacity = 10; // Maximum number of tokens the bucket can hold
const int tokenRate = 5; // Rate at which tokens are added (tokens per second)
int tokens = 0;          // Current number of tokens in the bucket
auto lastTokenTime = chrono::steady_clock::now();

bool getToken() {
  // Calculate time elapsed since last token added
  auto currentTime = chrono::steady_clock::now();
  chrono::duration<double> elapsed = currentTime - lastTokenTime;

  // Calculate tokens to add since last request
  int tokensToAdd = static_cast<int>(elapsed.count() * tokenRate);

  tokens = min(capacity, tokens + tokensToAdd);

  if (tokens > 0) {
    tokens--;
    lastTokenTime = currentTime;
    return true; // Token granted
  }

  return false; // No token available
}

int main() {
  // Simulate requests
  for (int i = 1; i <= 15; ++i) {
    if (getToken()) {
      cout << "Request " << i << ": Token granted." << endl;
    } else {
      cout << "Request " << i << ": Token not granted (rate limited)." << endl;
    }
    this_thread::sleep_for(chrono::seconds(1));
  }

  return 0;
}
