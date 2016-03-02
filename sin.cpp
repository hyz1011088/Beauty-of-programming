// C++ code to make task manager generate sine graph
//#include "Windows.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include<unistd.h>
const double SPLIT = 0.01;
const int COUNT = 200;
const double PI = 3.14159265;
const int INTERVAL = 300;
typedef unsigned long DWORD;


int main(int argc, char* argv[])
{
DWORD busySpan[COUNT]; // array of busy times
DWORD idleSpan[COUNT]; // array of idle times
int half = INTERVAL / 2;
double radian = 0.0;
for(int i = 0; i < COUNT; i++)
{
busySpan[i] = (DWORD)(half + (sin(PI * radian) * half));
idleSpan[i] = INTERVAL - busySpan[i];
radian += SPLIT;
}
DWORD timeuse = 0;
int j = 0;
while(true)
{
j = j % COUNT;

struct timeval start, end;
    gettimeofday( &start, NULL );
    gettimeofday( &end, NULL );
    timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec; 

while(timeuse <= busySpan[j])
;
sleep(idleSpan[j]/1000);
j++;
}
return 0;
}
