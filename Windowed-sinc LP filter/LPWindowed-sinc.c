#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Cutoff frequency is normalized and must be between 0 and 0.5, where 0.5 represents Nyquist frequency.
    In this example the signal was sampled at 48khz, then the nyquist frequency is 24khz
    then 24khz --- 0.5,
         10khz --- 0.2 : (10/24)*0.5 = 0.2 - to find the value for desired freq we devide it by the nyquist freq and multiply by 0
*/

#define SIGNAL_LEN 320
#define KERNEL_LEN 29

extern double InputSignal_f32_1kHz_15kHz[SIGNAL_LEN];
double Output_filter_kernel[KERNEL_LEN];
double Output_signal[SIGNAL_LEN - KERNEL_LEN];

void lp_windowed_sinc(double *sig_src_arr, double *sig_dest_arr, double *fk_dest_arr, double cutoff_freq, int filter_len, int sig_len);


int main (){

    FILE *ptr1, *ptr2, *ptr3;

    lp_windowed_sinc(&InputSignal_f32_1kHz_15kHz[0], &Output_signal[0], &Output_filter_kernel[0], 0.2, KERNEL_LEN, SIGNAL_LEN);
     
    ptr1 = fopen("Output_signal.dat", "w");
    ptr2 = fopen("Input signal.dat", "w");
    ptr3 = fopen("Output_kernel.dat", "w");

    for(int i = 0; i<SIGNAL_LEN; i++)
    {
        fprintf(ptr2,"\n%lf", InputSignal_f32_1kHz_15kHz[i]);
    if( i > KERNEL_LEN)    
        {
            fprintf(ptr1,"\n%lf", Output_signal[i]);
        }
        

    }
    for(int i = 0; i<KERNEL_LEN; i++)
    {
        fprintf(ptr3,"\n%lf", Output_filter_kernel[i]);
    }

    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);

    return 0;
}

void lp_windowed_sinc(double *sig_src_arr, double *sig_dest_arr, double *fk_dest_arr, double cutoff_freq, int filter_len, int sig_len)
{
//Calculate low pas filter kernel 
for(int i = 0; i<filter_len;i++)
{
     {
        fk_dest_arr[i] = 2*M_PI*cutoff_freq;
    }
    if(i-filter_len/2 != 0){
        fk_dest_arr[i] = sin(2*M_PI*cutoff_freq*(i-filter_len/2))/(i-filter_len/2);
        fk_dest_arr[i] = fk_dest_arr[i] *(0.54-0.46*cos(2*M_PI*i/filter_len));
    }
}
//Convolve the input signal and filter kernel 
 
 for(int j = filter_len;j<sig_len;j++)
 {
    sig_dest_arr[j] = 0;
    for(int i = 0; i<filter_len;i++)
    {
        sig_dest_arr[j] = sig_dest_arr[j] + sig_src_arr[j-i]*fk_dest_arr[i];
    }
 }

}