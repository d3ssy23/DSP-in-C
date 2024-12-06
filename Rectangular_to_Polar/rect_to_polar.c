/*
Here we take a complex time domain signal, with ImX and ReX. Then we convert the rectangular notation of the complex number and convert it 
to polar deviring the phase and magnetude.
We get the exports from IDFT -ECG folder for the imx and rex components and create header file with them or use extern variable.
*/

#include <stdio.h>
#include "imx_rex_ecg.h"
#include <math.h>


#define SIGNAL_LEN 320
extern double ecg_imx[SIGNAL_LEN];
extern double ecg_rex[SIGNAL_LEN];

void rect_to_polar_conversion(double *src_rex_arr, double *src_imx_arr, double *sig_out_mag, double *sig_out_phase, int len);
double Output_magnitude[SIGNAL_LEN];
double Output_phase[SIGNAL_LEN];

int main()
{
    FILE *ptr1,*ptr2,*ptr3,*ptr4;

    rect_to_polar_conversion(&ecg_rex[0], &ecg_imx[0],&Output_magnitude[0], &Output_phase[0],SIGNAL_LEN);

    ptr1 = fopen("polar_magnitude.dat","w");
    ptr2 = fopen("polar_phase.dat","w");
    ptr3 = fopen("input_rex.dat", "w");
    ptr4 = fopen("input_imx.dat", "w"); 

    for(int i = 0; i<SIGNAL_LEN; i++)
    {
        fprintf(ptr3,"\n%f",ecg_rex[i]);
        fprintf(ptr4,"\n%f",ecg_imx[i]);
        fprintf(ptr1, "\n%f",Output_magnitude[i]);
        fprintf(ptr2, "\n%f", Output_phase[i]);

    }
    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);
    fclose(ptr4);
    return 0;
}

void rect_to_polar_conversion(double *src_rex_arr, double *src_imx_arr, double *sig_out_mag, double *sig_out_phase, int len)
{
    double PI = 3.14159265358979f;
    int k;
    for(k=0;k<len;k++)
    {
        sig_out_mag[k] = sqrt(pow(src_imx_arr[k],2)+pow(src_rex_arr[k],2));
        if(src_rex_arr[k]==0)
        {
            src_rex_arr[k] = pow(10,-20);
            sig_out_phase[k] = atan(src_imx_arr[k]/src_rex_arr[k]); 
        }
        if((src_imx_arr[k]<0)&&(src_rex_arr[k]<0))
        {
            sig_out_phase[k] = sig_out_phase[k]-PI;
        }
        if((src_imx_arr[k]>=0)&&(src_rex_arr[k]<0))
        {
            sig_out_phase[k] = sig_out_phase[k]+PI;
        }
    }
}
