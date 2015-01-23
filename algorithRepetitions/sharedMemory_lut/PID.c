int pid(float read[5], float *write)
{
  float local_read[5];
  float local_write[1];
  register int counter;
  pid_label0:for (counter=0; counter<5; counter++)
    local_read[counter]=read[counter];

#define y local_read[0]
#define kp local_read[1]
#define ki local_read[2]
#define kd local_read[3]
#define yp local_read[4]
#define u local_write

	float e, p, i, d;
	static float laste = 0;
	static float sum = 0;

	register int cn;
	for (cn=0; cn<524288; cn++)
	{
	e = y - yp;
	p = kp * e;
	sum = sum + e;
	i = ki * sum;
	d = kd * (e - laste);
	laste = e;
	*u = p + i + d;
	}
	*write=*local_write;
	
	return 0;
}
