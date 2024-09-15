#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

Time add_Time(Time t1, Time t2) {
    Time result;
    
    result.seconds = t1.seconds + t2.seconds;
    
    result.minutes = t1.minutes + t2.minutes + result.seconds / 60;
    result.seconds %= 60;
    
    result.hours = t1.hours + t2.hours + result.minutes / 60;
    result.minutes %= 60;
    
    return result;
}

void display_Time(Time t) {
    int totalSeconds = (t.hours * 3600) + (t.minutes * 60) + t.seconds;
    int days = totalSeconds / 86400;
    totalSeconds %= 86400;
    int hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    
    printf("Days : %d\n", days);
    printf("Hours: %d\n", hours);
    printf("Mins : %d\n", minutes);
    printf("Seconds: %d\n", seconds);
}

int main() {
    Time t1, t2, sum;
    
    printf("Enter the first time (hh mm ss): ");
    scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);
    
    printf("Enter the second time (hh mm ss): ");
    scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);
    
    sum = add_Time(t1, t2);
    
    display_Time(sum);
    
    return 0;
}
