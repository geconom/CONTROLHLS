int pid(float y, float kp, float ki, float kd, float yp, float *u)
{
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
