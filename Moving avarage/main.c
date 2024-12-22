#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIGNAL_LEN 500
#define WIN_LEN 100

/* Moving avarage filter takes an input signal with a number of point, window size(steps, N - the number of samples to be avaraged) and creates an output signal file with a noise reduction equal to the square root of the SIGNAL_LEN number, it will have a sharp step response, and if more points are used more linearity it gains in the stop bands and pass bands but the roll off will get more and more longer */

extern double 

int main()
{
	FILE *fptr1, *fptr2;

	fptr1 = fopen("input_signal.dat", "w");
	fptr2 = fopen("output_signal.dat","w");


	for (int i = 0; i < SIGNAL_LEN; i++) 
	{
		fprintf(fptr1, "\n%f", extrn);
		fprintf(fptr2, "\n%f", extrn);
	}



	fclose(fptr1);
	fclose(fptr2);

}

void	moving_avarage(double *inp_sig, double *out_sig_dest, double avarage_sum, int step_len, int sig_len)
{
	int i = 0;
	for (i = 0; i < sig_len; i++)
	{
		double avarage_sum = 0.0;

		for (int j = 0; j < step_len; j++)
		{
			if(i + j < sig_len)
			{
			 avarage_sum += inp_sig[i + j];
		
			}
		}
	}
	out_sig_dest[i] = avarage_sum/step_len;

}


