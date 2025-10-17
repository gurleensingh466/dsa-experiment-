#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing one day's details
typedef struct {
    char *name;      // name of the day
    int dayNumber;   // date or day number
    char *task;      // description of the activity
} WeekDay;

// Function declarations
WeekDay* allocateWeek(int days);
void inputData(WeekDay *week, int days);
void showSchedule(const WeekDay *week, int days);
void releaseMemory(WeekDay *week, int days);

int main() {
    int days = 7;
    WeekDay *week = allocateWeek(days);

    inputData(week, days);
    showSchedule(week, days);

    releaseMemory(week, days);
    return 0;
}

// Function to allocate dynamic memory for week data
WeekDay* allocateWeek(int days) {
    WeekDay *week = (WeekDay*) malloc(days * sizeof(WeekDay));
    if (!week) {
        printf("Error: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    return week;
}

// Function to take input for each day
void inputData(WeekDay *week, int days) {
    char buffer[100];
    printf("Enter information for each day of the week:\n");

    for (int i = 0; i < days; i++) {
        printf("\nDay %d:\n", i + 1);

        printf("Name of the day: ");
        scanf(" %[^\n]", buffer);
        week[i].name = (char*) malloc(strlen(buffer) + 1);
        strcpy(week[i].name, buffer);

        printf("Enter the date: ");
        scanf("%d", &week[i].dayNumber);

        printf("Enter planned activity: ");
        scanf(" %[^\n]", buffer);
        week[i].task = (char*) malloc(strlen(buffer) + 1);
        strcpy(week[i].task, buffer);
    }
}

// Function to print the weekly schedule
void showSchedule(const WeekDay *week, int days) {
    printf("\n\n======= WEEKLY SCHEDULE =======\n");
    printf("---------------------------------\n");

    for (int i = 0; i < days; i++) {
        printf("Day: %s\n", week[i].name);
        printf("Date: %d\n", week[i].dayNumber);
        printf("Activity: %s\n", week[i].task);
        printf("---------------------------------\n");
    }
}

// Function to release allocated memory
void releaseMemory(WeekDay *week, int days) {
    for (int i = 0; i < days; i++) {
        free(week[i].name);
        free(week[i].task);
    }
    free(week);
}

