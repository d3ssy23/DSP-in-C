#include <stdio.h>
#include <stdlib.h>

#define SIG_LEN 320
extern double InputSignal_f32_1kHz_15kHz[SIG_LEN];
double calc_signal_mean(double *sig_src_arr, int sig_lenght);
double MEAN;

int main()
{
    MEAN = calc_signal_mean(&InputSignal_f32_1kHz_15kHz[0],SIG_LEN);
    printf("\n \n MEAN = %f \n \n ", MEAN);

    return 0;
}

double calc_signal_mean(double *sig_src_arr, int sig_lenght)
{
    double mean = 0.0;
    for(int i = 0;i<SIG_LEN;i++)
    {
        mean = mean + sig_src_arr[i];

    }
    mean = mean/(double)sig_lenght; //securecast double type
    return mean;
}