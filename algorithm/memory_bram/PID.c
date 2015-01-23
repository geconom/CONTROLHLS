int pid(float read[5], float *write)
{

#define y read[0]
#define kp read[1]
#define ki read[2]
#define kd read[3]
#define yp read[4]
#define u write

	float e, p, i, d;
	static float laste = 0;
	static float sum = 0;

	e = y - yp;
	p = kp * e;
	sum = sum + e;
	i = ki * sum;
	d = kd * (e - laste);
	laste = e;
	*u = p + i + d;

	return 0;
}
