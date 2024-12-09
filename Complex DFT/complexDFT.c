/*
Here we take a complex time domain signal, with ImX and ReX and preform a complex DFT which will result in two arguments ImX in Frequency dom and
ReX in Frequency domain.
*/

#include <stdio.h>
#include <math.h>


#define SIGNAL_LEN 501
void complex_dft(double *sig_src_time_dom_rex, double *sig_src_time_dom_imx, double *sig_dest_freq_rex, double *sig_dest_freq_imx, int len);

extern double p_501pts_20Hz_sig_imx[SIGNAL_LEN];  //second argument they are inputs
extern double p_501pts_20Hz_sig_rex[SIGNAL_LEN]; // first argument

double Output_imx[SIGNAL_LEN];  
double Output_rex[SIGNAL_LEN];

int main()
{
    FILE *ptr1,*ptr2,*ptr3,*ptr4;

    complex_dft(&p_501pts_20Hz_sig_rex[0], &p_501pts_20Hz_sig_imx[0],&Output_rex[0], &Output_imx[0], SIGNAL_LEN);

    ptr1 = fopen("output_rex.dat","w");
    ptr2 = fopen("output_imx.dat","w");
    ptr3 = fopen("input_rex.dat", "w");
    ptr4 = fopen("input_imx.dat", "w"); 

    for(int i = 0; i<SIGNAL_LEN; i++)
    {
        fprintf(ptr1,"\n%f",p_501pts_20Hz_sig_rex[i]);
        fprintf(ptr2,"\n%f",p_501pts_20Hz_sig_imx[i]);
        fprintf(ptr3, "\n%f",Output_rex[i]);
        fprintf(ptr4, "\n%f", Output_imx[i]);

    }
    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);
    fclose(ptr4);
    return 0;
}
void complex_dft(double *sig_src_time_dom_rex, double *sig_src_time_dom_imx, double *sig_dest_freq_rex, double *sig_dest_freq_imx, int len )
{
    double PI = 3.14159265358979f;
    double ans_rex, ans_imx;

    for (int k = 0; k<len-1;k++)
    {
        for (int i = 0; i<len-1;i++)
        {
            ans_rex = cos(2*PI*k*i/len);
            ans_imx = -sin(2*PI*k*i/len);

            sig_dest_freq_rex[k] = sig_dest_freq_rex[k] + sig_src_time_dom_rex[i]*ans_rex-sig_src_time_dom_imx[i]*ans_imx; // the formula to find the ReX in the freq domain
            sig_dest_freq_imx[k] = sig_dest_freq_imx[k] + sig_src_time_dom_imx[i]*ans_imx-sig_src_time_dom_imx[i]*ans_rex;       
        }

    }

}


