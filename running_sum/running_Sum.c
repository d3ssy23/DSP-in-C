/*

This program contains and executes the running sum algorithm of an .txt input signal, after execution it saves the
result to a .dat raw audio data file named output_signal.dat. It also creates another .dat file with column ordered raw data of the input signal.

*/


 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LEN 320

extern double InputSignal_f32_1kHz_15kHz[SIG_LEN];

double Output_signal[SIG_LEN];

void runningSum(double *inp_src_sig, double *out_dest_arr, int len);

int main(){

    FILE *inp_sig_fptr, *out_dest_fptr;

    runningSum(&InputSignal_f32_1kHz_15kHz[0],&Output_signal[0], SIG_LEN);

    inp_sig_fptr = fopen("input_sig.dat", "w");
    out_dest_fptr = fopen("running_sum.dat", "w");

    for(int i = 0; i<SIG_LEN;i++)
    {
        fprintf(inp_sig_fptr, "\n%f",InputSignal_f32_1kHz_15kHz[i]);
    }
    fclose(inp_sig_fptr);

    for (int i = 0; i < SIG_LEN; i++)
    {
        fprintf(out_dest_fptr, "\n%f", Output_signal[i]);
    }
    fclose(out_dest_fptr);


    return 0;
}

void runningSum(double *inp_src_sig, double *out_dest_arr, int len)
{
    for(int i = 0; i<len; i++)
    {

        out_dest_arr[i] = out_dest_arr[i-1] + inp_src_sig[i]; //running sum equation 

    }
}