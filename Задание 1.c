
#include <stdio.h>
int main(void){
double h_sm, w_sm, d_sm;
double p_dvp, p_dsp, p_der;

printf("Enter the height h(180-220 sm), widht w(80-120 sm) and depth d(50-90 sm):\n");
if (scanf_s("%lf %lf %lf", &h_sm, &w_sm, &d_sm) != 3) {
	printf("Input error\n");
	return 1;
}
printf("Enter the material densities (DVP, DSP, wood) in kg/m^3:\n");
if (scanf_s("%lf %lf %lf", &p_dvp, &p_dsp, &p_der) != 3) {
	printf("Input error\n");
	return 1;
}
double h = h_sm / 100;
double w = w_sm / 100;
double d = d_sm / 100;

const double t_1 = 0.005;
const double t_2 = 0.015;
const double t_3 = 0.01;
//накладная задняя стена
double v_1 = h * w * t_1;
double m_1 = v_1 * p_dvp;
//боковина(2 шт)
double v_2 = h * d * t_2;
double m_2 = v_2 * p_dsp;
//крышки(2 шт)
double v_3 = w * d * t_2;
double m_3 = v_3 * p_dsp;
//двери
double v_4 = h * w * t_3;
double m_4 = v_4 * p_der;
//кол-во полок
int n = (int)(h / 0.4) - 1;
if (n < 0) {
	n = 0;
}
//ширина полки
double w_5 = w - 2 * t_2;
double v_5 = w_5 * t_2 * (d - t_1);
double m_5 = v_5 * p_dsp;

//общая масса
double m = m_1 + 2 * m_2 + 2 * m_3 + m_4 + n * m_5;
printf("The total weight of the wardrobe: %.2f kg\n", m);
return 0;
}
