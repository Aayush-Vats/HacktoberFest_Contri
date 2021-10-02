#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LEN 320

extern double InputSignal_f32_1kHz_15kHz[320];
double output_rex[SIG_LEN/2];
double output_imx[SIG_LEN/2];

void calc_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_len);


int main()
{
    FILE *fptr1,*fptr2,*fptr3;

    calc_dft((double *)&InputSignal_f32_1kHz_15kHz[0], (double *)&output_rex[0], (double *)&output_imx[0], (int) SIG_LEN);

    fptr1 = fopen("input_signal.dat","w");
    fptr2 = fopen("output_rex.dat","w");
    fptr3 = fopen("output_imx.dat","w");

    for(int i = 0;i<SIG_LEN;i++)
    {
        fprintf(fptr1,"\n%f",InputSignal_f32_1kHz_15kHz[i]);
    }
    for(int i = 0;i<SIG_LEN/2;i++)
    {
        fprintf(fptr2,"\n%f",output_rex[i]);
        fprintf(fptr3,"\n%f",output_imx[i]);
    }
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);

    return 0;
}

void calc_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_len)
{
    int i,j,k;
    double PI = 3.14159265359;

    for(j=0;j<sig_len/2;j++)
    {
        sig_dest_rex_arr[j] = 0;
        sig_dest_imx_arr[j] = 0;
    }

    for(k=0;k<sig_len/2;k++)
    {
        for(i=0;i<sig_len;i++)
        {
            sig_dest_rex_arr[k] = sig_dest_rex_arr[k]+sig_src_arr[i]*cos(2*PI*k*i/sig_len);
            sig_dest_imx_arr[k] = sig_dest_imx_arr[k]-sig_src_arr[i]*sin(2*PI*k*i/sig_len);
        }

    }
}
