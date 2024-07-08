#include <iostream>

// Structure to represent a job
struct Job {
  int id;       // Job ID
  int priority; // Job Priority
};

// Function to swap two jobs
void swap(Job &a, Job &b) {
  Job temp = a;
  a = b;
  b = temp;
}

// Function to sort jobs based on priority using bubble sort
void sortJobs(Job jobs[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (jobs[j].priority > jobs[j + 1].priority) {
        swap(jobs[j], jobs[j + 1]);
      }
    }
  }
}

// Function to schedule jobs based on priority
void scheduleJobs(Job jobs[], int n) {
  // Sort jobs by priority
  sortJobs(jobs, n);

  // Execute jobs in sorted order
  for (int i = 0; i < n; ++i) {
    std::cout << "Executing Job ID: " << jobs[i].id
              << " with Priority: " << jobs[i].priority << std::endl;
  }
}

int main() {
  // List of jobs
  Job jobs[] = {{1, 3}, {2, 1}, {3, 2}, {4, 4}};
  int n = sizeof(jobs) / sizeof(jobs[0]);

  // Schedule and execute jobs
  scheduleJobs(jobs, n);

  return 0;
}
