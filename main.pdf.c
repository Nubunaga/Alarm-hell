#include <stdio.h>
#include <windows.h>
int H_calc(int);
int M_calc(int);
int S_calc(int);
int Clock(int,int);

int main()
{
    int Present_time;                               /*Function for the present time input.*/
    int Time_for_alarm;                             /*Function for the alarm time input.*/

    printf("Enter start time: HH:MM:SS\n");
    scanf("%d",&Present_time);                  /* Scans for input of present time.*/

    printf("Enter Alarm Time: HH:MM:SS \n");
    scanf("%d",&Time_for_alarm);                /* Scans for input of alarm time.*/

    Clock(Present_time,Time_for_alarm);

return 0;
}
int Clock(Time,Alarm)/* This external function is the "clock" and will be responsible for printing and calculating the times and set the alarm.*/
{
    int H = H_calc(Time),M = M_calc(Time),S = S_calc(Time);
    int H_M= H_calc(Alarm),M_M= M_calc(Alarm),S_M = S_calc(Alarm);

    printf("Current time is: %02d:%02d:%02d \n",H_calc(Time),M_calc(Time),S_calc(Time));
    Sleep(700);
    printf("Time for Alarm: %02d:%02d:%02d\n",H_calc(Alarm), M_calc(Alarm),S_calc(Alarm));

    while (!(S==S_M && M == M_M && H == H_M))
    {
        printf("%02d:%02d:%02d\n",H,M,S);
        S+=1;
        if(S > 59)
        {
            S=0;        /* each time s>59 (other words 60) it turns to 0 and gives M 1. Same follows all function below.*/
            M++;
        }
        if (M>59)
        {
            M=0;
            H++;
        }
        if (H>23)
        {
            H=0;
        }
    }
    (MB_ICONWARNING);     /* plays the windows warning sound*/
    printf("ALARM!");

    return 0;
}
int H_calc(Time) /*This function calculate the hour for the program*/
{
 return Time/10000; /* this will divide the input number to the 10000 and will give a decimal number, since it is not a float the value will be a whole number. *//* H = X (XX0000)*/
}
int M_calc(Time) /*This function calculate the minute for the program*/
{
return (Time/100)%100; /* it will divide buy the 100 and then % will divide the rest to give the M value XX (00XX00).*/
}
int S_calc(Time) /* this function will calculate the second for the program*/
{
 return Time%100; /* will divide % to give "0000XX" as S= XX*/
}
