
/*
Tmp array used and more .

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIGNAL_LEN 320
#define KERNEL 20

/*10khz cutoff ---- (10/24)* 0.5  = 0.2*/

void bandpassWindowedSincFltr(
    double *lower_cutoff_state_buff,
    double *upper_cutoff_state_buff,
    double *fltr_kernel_dest_arr,
    double lower_cutoff,
    double upper_cutoff,
    int filter_len,
    double *sig_src_arr,
    double *sig_dest_arr,
    int input_sig_len
);

extern double InputSignal_f32_1kHz_15kHz[SIGNAL_LEN];
double OutputSignal[SIGNAL_LEN-KERNEL];
double OutputFilter[KERNEL];

double state_lp_buff[KERNEL];
double state_up_buff[KERNEL]; 

int main()
{
    FILE *ptr,*ptr2,*ptr3;

    bandpassWindowedSincFltr(
     &state_lp_buff[0],
     &state_up_buff[0],
     &OutputFilter[0],
     0.002,  //for frequency 0.01hz
     0.11,  //for frequency 5.28khz \ nyquist(24) then multiplied by 0.5
     KERNEL,
     &InputSignal_f32_1kHz_15kHz[0],
     &OutputSignal[0],
     SIGNAL_LEN);

     ptr = fopen("input_signal.dat", "w");
     ptr2 = fopen("output_signal.dat", "w");
     ptr3 = fopen("output_kernel.dat", "w");

    for(int i = 0; i<SIGNAL_LEN; i++)
    {
        fprintf(ptr,"\n%lf", InputSignal_f32_1kHz_15kHz[i]);
        if(i<KERNEL)
        {
            fprintf(ptr3,"\n%lf", OutputFilter[i]);
        }
        if(i>KERNEL)
        {
            fprintf(ptr2,"\n%lf", OutputSignal[i]);
        }
    }
    return 0;
}
void bandpassWindowedSincFltr(
    double *lower_cutoff_state_buff,
    double *upper_cutoff_state_buff,
    double *fltr_kernel_dest_arr,
    double lower_cutoff,
    double upper_cutoff,
    int filter_len,
    double *sig_src_arr,
    double *sig_dest_arr,
    int input_sig_len
)
{
    // Calculate LP filter kernel
    for(int i  = 0; i<filter_len; i++)
    {
        if(i-filter_len/2 == 0)
        {
            lower_cutoff_state_buff[i] = 2*M_PI*lower_cutoff;
        }
        if(i-filter_len/2 != 0)
        {
            lower_cutoff_state_buff[i] = sin(2*M_PI*lower_cutoff*(i-filter_len/2))/(i-filter_len/2);
            lower_cutoff_state_buff[i] = lower_cutoff_state_buff[i]*(0.42-0.5*cos(2*M_PI*i/filter_len)+0.08*cos(4*M_PI*i/filter_len));
        }
    }

    // Calculate another LP filter

    for(int i = 0; i<filter_len;i++)
    {
        if(i - filter_len/2 == 0){
            upper_cutoff_state_buff[i] = 2*M_PI*upper_cutoff;
        }
        if(i - filter_len/2 != 0)
        {
            upper_cutoff_state_buff[i] = sin(2*M_PI*upper_cutoff*(i-filter_len/2))/(i-filter_len/2);
            upper_cutoff_state_buff[i] = upper_cutoff_state_buff[i]*(0.42-0.5*cos(2*M_PI*i/filter_len)+0.08*cos(4*M_PI*i/filter_len));
        }
    }

    //Spectral inversion to convert the LP filter to highpass

    for (int i = 0; i<filter_len;i++)
    {
        upper_cutoff_state_buff[i] = -(upper_cutoff_state_buff[i]);
    }
    upper_cutoff_state_buff[filter_len/2] = upper_cutoff_state_buff[filter_len/2]+1;

    // Add lowpass filter kernel to highpass to form band reject
    
    for(int i = 0; i<filter_len; i++)
    {
        fltr_kernel_dest_arr[i] =lower_cutoff_state_buff[i] + upper_cutoff_state_buff[i];
    }

    //Change band reject filter into bandpass filter using spectral inversion

    for(int i = 0; i<filter_len;i++)
    {
        fltr_kernel_dest_arr[i] = -(fltr_kernel_dest_arr[i]);
    }
        fltr_kernel_dest_arr[filter_len/2] = fltr_kernel_dest_arr[filter_len/2]+1;

    //Convolve the input signal and the filter kernel

    for(int j =filter_len; j<input_sig_len;j++)
    {
        sig_dest_arr[j] = 0;
        for(int i = 0; i<filter_len; i++)
        {
            sig_dest_arr[j] = sig_dest_arr[j] + sig_src_arr[j-i]*fltr_kernel_dest_arr[i];
        }
    }
}