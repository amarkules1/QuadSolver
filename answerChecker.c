#include "answerChecker.h"

//returns 0 if x is accurate, -1 if 0.99x is more accurate, and 1 if 1.01x is more accurate
int checkAnswer(double a, double b, double c, double x){
	double val = fabs((a * x * x) + (b * x) + c);
	double xSmall = 0.99 * x;
	double valSmall = fabs((a * xSmall * xSmall) + (b * xSmall) + c);
	double xBig = 1.01 * x;
	double valBig = fabs((a * xBig * xBig) + (b * xBig) + c);

	if(val <= valSmall && val <= valBig){
		return 0;
	}
	else if(val > valSmall){
		return -1;
	}
	else{
		return 1;
	}
}