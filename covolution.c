/*

This program creates a convolution algorithm and covolves two signals, which first signal is the .txt input signal from waveforms.c (1khz and 15khz component) 
and the inpulse response in filter_kernel.c (a low pass filter with cutoff frequency at 6khz), so the convolution should bypass all frequencies over 6khz.

The code writes to existing or creates new two .dat files containing raw audio data and filter coefficients, they will be filled with the imp response 
and input signal values in vertical column way. These .dat files can be used for plotting in MATLAB, GNUPLOT or with python libs.

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIGNAL_LENGHT 320
#define IMP_RESP_LENGHT 29

extern double InputSignal_f32_1kHz_15kHz[SIGNAL_LENGHT];
extern double Impulse_response[IMP_RESP_LENGHT];

double Output_signal[SIGNAL_LENGHT+IMP_RESP_LENGHT];

void convolution( double *sig_src_arr, double *sig_dest_arr, double *imp_resp_arr, int sig_src_len, int imp_resp_len);

int main(){


    FILE  *input_sig_fptr, *imp_resp_fptr, *output_sig_fptr;  // creating pointers that will be used to write the data to the new files

    convolution(&InputSignal_f32_1kHz_15kHz[0], &Output_signal[0], &Impulse_response[0], SIGNAL_LENGHT, IMP_RESP_LENGHT);


    input_sig_fptr = fopen("input_signal.dat","w"); // open existing or creating new one with w - write option
    imp_resp_fptr = fopen("impulse_response.dat","w");
    output_sig_fptr = fopen("output_signal.dat", "w"); // creating the file to write the output of the convolution into

    for(int i = 0; i<SIGNAL_LENGHT;i++)
    {
        fprintf(input_sig_fptr,"\n%f", InputSignal_f32_1kHz_15kHz[i]);  //write into the file input_sig_fptr from the input signal from waveforms.c in colum order so we use new line
    }
    fclose(input_sig_fptr);

    for(int i = 0; i<IMP_RESP_LENGHT;i++)
    {
        fprintf(imp_resp_fptr,"\n%f", Impulse_response[i]);  //writing to imp_resp from each value from the Impulse_response
    }
    fclose(imp_resp_fptr);

    for(int i =0; i<SIGNAL_LENGHT+IMP_RESP_LENGHT; i++)
    {
        fprintf(output_sig_fptr, "\n%f", Output_signal[i]);
    }
    fclose(output_sig_fptr);
    
    return 0;
}


// Convolution algorithm

void convolution( double *sig_src_arr, double *sig_dest_arr, double *imp_resp_arr, int sig_src_len, int imp_resp_len)
{
    int i,j;
    for(i=0;i<sig_src_len+imp_resp_len;i++)
    {
        sig_dest_arr[i] = 0; //initialise the destination array to 0
    }

    for(i=0;i<sig_src_len;i++)
    {
        for(j=0;j<imp_resp_len;j++) // limiting the dest signal by the imp response cutoff setting to 6khz
        {
                sig_dest_arr[i+j] = sig_dest_arr[i+j] + sig_src_arr[i]*imp_resp_arr[j]; //convoluting the two signals and storing the result in the dest array
        }
    }
}