#define _USE_MATH_DEFINES 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIG_LEN 320
#define PI 3.14159265359

extern double InputSignal_f32_1kHz_15kHz[SIG_LEN];
double Output_REX[SIG_LEN/2];
double Output_IMX[SIG_LEN/2];
void  dft(double *sig_src_arr, double *sig_dest_rex, double *sig_dest_imx, int len);

int main(){

    FILE *fptr1, *fptr2, *fptr3;

    dft(&InputSignal_f32_1kHz_15kHz[0], &Output_REX[0], &Output_IMX[0], SIG_LEN);


    fptr1 = fopen("input_signal.dat", "w");
    fptr2 = fopen("output_rex.dat", "w");       //also .txt format can be used for plotting with matlab and gnuplot
    fptr3 = fopen("output_imx.dat", "w");


    for(int i = 0; i<SIG_LEN;i++)
    {
    fprintf(fptr1,"\n%f",InputSignal_f32_1kHz_15kHz[i]);
    }
    fclose(fptr1);

    for(int i = 0; i<SIG_LEN/2;i++)
    {
        fprintf(fptr2,"\n%f", Output_REX[i]);
    }
    fclose(fptr2);

    for(int i = 0; i<SIG_LEN/2;i++)
    {
        fprintf(fptr3,"\n%f", Output_IMX[i]);

    }
    fclose(fptr3);

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