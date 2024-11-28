/* 
----------------
This program uses the signal mean and the signal variance to  calculate the Standart Deviation of the signal.
----------------
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIGNAL_LENGHT 320         //modify this variable for different input signal
double signalMean(double *signal, int lenght);
double signalVariance(double *signal, int mean, int len);
double signalSTD(double sig_variance);

extern double InputSignal_f32_1kHz_15kHz[SIGNAL_LENGHT];  // modify this variable if used another .txt file data
double MEAN;
double VARIANCE;
double STANDART_DEVIATION;

int main () {
 
    MEAN = signalMean(&InputSignal_f32_1kHz_15kHz[0], SIGNAL_LENGHT);
    VARIANCE = signalVariance(&InputSignal_f32_1kHz_15kHz[0],MEAN,SIGNAL_LENGHT);
    STANDART_DEVIATION = signalSTD(VARIANCE);
    //printf("MEAN = %f \n", MEAN);
    //printf("Variance = %f \n", VARIANCE);
    printf("Standart Deviation = %f \n", STANDART_DEVIATION);
    return 0;
}

double signalMean(double *signal, int lenght)
{
    double mean = 0.0;          //initialising the mean value
    for (int i = 0; i < SIGNAL_LENGHT; i++)         // looping through all the samples
    {
        mean += signal[i];                  // each of the samples added to the mean variable
    }
    mean /= lenght;                 // get the mean by dividing it by the total SIGNAL_LENGHT
    return mean;
}

double signalVariance(double *signal, int mean, int len){

    //substract the mean from each data from the array during the loop

    double variance = 0.0;  //initializing the variance variable
    for (int i  = 0; i<len; i++) // looping through all the samples of SIGNAL_LENGHT
    {
        variance += pow((signal[i]-mean),2);  // taking each sample minus the mean to the power of 2 and add it to the total variance
    }
    variance = variance / (len - 1);   // variance is equal to the variance - (SIGNAL_LENGHT or N - 1)
    return variance; 
}

double signalSTD(double sig_variance)
{
    double std = sqrt(sig_variance);
    return std;
}
