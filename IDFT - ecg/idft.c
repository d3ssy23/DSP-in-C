/*

This program calculates the IDFT algorithm, by taking the already created DFT algorithm and it's ImX and ReX saved outputs
and return them back to the original time domain signal.

*/

#define _USE_MATH_DEFINES 

#include "waveforms.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIG_LEN 640
#define PI 3.14159265359

//extern double InputSignal_f32_1kHz_15kHz[SIG_LEN];
double Output_REX[SIG_LEN/2];
double Output_IMX[SIG_LEN/2];
double Output_MAG[SIG_LEN/2];
double Output_IDFT[SIG_LEN];
//double _640_points_ecg_[SIG_LEN];

void  dft(double *sig_src_arr, double *sig_dest_rex, double *sig_dest_imx, int len);
void dft_magnetude(double *sig_dest_mag);
void idft(double *idft_dest_arr, double *src_rmx_arr, double *src_imx_arr, int idft_len);

int main(){  

    FILE *fptr1, *fptr2, *fptr3, *fptr4, *fptr5;

    dft(&_640_points_ecg_[0], &Output_REX[0], &Output_IMX[0], SIG_LEN);
    dft_magnetude(&Output_MAG[0]);
    idft(&Output_IDFT[0], &Output_REX[0], &Output_IMX[0], SIG_LEN);

    fptr1 = fopen("input_signal.dat", "w");
    fptr2 = fopen("out_rex.dat", "w");       //also .txt format can be used for plotting with matlab and gnuplot
    fptr3 = fopen("out_imx.dat", "w");
    fptr4 = fopen("dft_magnetude.dat" , "w"); 
    fptr5 = fopen("idft.dat", "w");

    for(int i = 0; i<SIG_LEN;i++)
    {
    fprintf(fptr1,"\n%f",_640_points_ecg_[i]);
    fprintf(fptr5, "\n%f", Output_IDFT[i]);

    }
    fclose(fptr1);

    for(int i = 0; i<SIG_LEN/2;i++)
    {
        fprintf(fptr2,"%f,", Output_REX[i]);
    }
    fclose(fptr2);

    for(int i = 0; i<SIG_LEN/2;i++)
    {
        fprintf(fptr3,"%f,", Output_IMX[i]);

    }
    fclose(fptr3);

    for(int i = 0; i < SIG_LEN/2; i++)
    {
        fprintf(fptr4, "\n%f,", Output_MAG[i]);
    }
    fclose(fptr4);
    fclose(fptr5);

    return 0;

}

void  dft(double *sig_src_arr, double *sig_dest_rex, double *sig_dest_imx, int len)
{
    int i,j,k;
    for(j = 0; j< (len/2);j++)   //the signal lenght is divided by two since it has real and imaginary part both equal to N/2
    {
        sig_dest_imx[j] = 0;
        sig_dest_rex[j] = 0;

    }
    for(k=0;k<(len/2);k++)
    {
         for (i=0;i<len;i++)
         {
            sig_dest_rex[k] = sig_dest_rex[k] + sig_src_arr[i]*cos(2*PI*k*i/len);       //calculation of the real part
            sig_dest_imx[k] = sig_dest_imx[k] - sig_src_arr[i]*sin(2*PI*k*i/len);       //calculation of the imaginary part
         }
    }
}

void dft_magnetude(double *sig_dest_mag)
{
    int k;
    for(k = 0; k < SIG_LEN/2; k++)
    {
        sig_dest_mag[k] = sqrt(pow(Output_REX[k],2)+ pow(Output_IMX[k],2)) / SIG_LEN;
    }
}

void idft(double *idft_dest_arr, double *src_rmx_arr, double *src_imx_arr, int idft_len)
{
    int i,k;
    for(k=0;k<idft_len/2;k++)
    {
        src_imx_arr[k] = src_imx_arr[k]/(idft_len/2);
        src_rmx_arr[k] = src_rmx_arr[k]/(idft_len/2);
    }
    src_imx_arr[0] = src_imx_arr[0]/2;
     src_rmx_arr[0] = src_rmx_arr[0]/2;

    for(i = 0; i < idft_len; i++)
    {
        idft_dest_arr[i] = 0;
    }
        for (k=0;k<idft_len/2;k++)
        {
            for(i=0;i<idft_len;i++)
            {
                idft_dest_arr[i] = idft_dest_arr[i] + src_rmx_arr[k]*cos(2*PI*k*i/idft_len);    //here we add the idft equation
                idft_dest_arr[i] = idft_dest_arr[i] + src_imx_arr[k]*sin(2*PI*k*i/idft_len);     
            
            }
        }
        
    

}