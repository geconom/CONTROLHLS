float float_abs( float a )
{
	if (a<0)
	  return -a;
	else
	  return a;
}

float float_rsh1( float a )
{
  long temp1=(long)a & 0x007FFFFF;
  long temp2=(long)a & 0xFF800000;
  temp1>>=1;
  return temp1 | temp2;
}

int flc(float read[31], float *write)
{
  float local_read[31];
  float local_write[1];
  register int counter;
  flc_label1:for (counter=0; counter<31; counter++)
    local_read[counter]=read[counter];
	
#define y local_read[0]
#define NBa local_read[1]
#define NBb local_read[2]
#define NSa local_read[3]
#define NSb local_read[4]
#define PBa local_read[5]
#define PBb local_read[6]
#define PSa local_read[7]
#define PSb local_read[8]
#define Na local_read[9]
#define Nb local_read[10]
#define Za local_read[11]
#define Zb local_read[12]
#define Pa local_read[13]
#define Pb local_read[14]
#define w1 local_read[15]
#define w2 local_read[16]
#define w3 local_read[17]
#define w4 local_read[18]
#define w5 local_read[19]
#define w6 local_read[20]
#define w7 local_read[21]
#define w8 local_read[22]
#define w9 local_read[23]
#define w10 local_read[24]
#define w11 local_read[25]
#define w12 local_read[26]
#define Kin1 local_read[27]
#define Kin2 local_read[28]
#define Kout local_read[29]
#define yp local_read[30]
#define u local_write
	
  float e, de, x1, x2;
  float mNB, mNS, mPS, mPB, mN, mZ, mP;
  float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12;
  float num, den, quot;
  static float lastde = 0;

  e = y - yp;
  de = e - lastde;
  x1 = e / Kin1;
  x2 = de / Kin2;
  mNB = float_abs(x1 - NBa) / float_rsh1(NBb);
  mNB = 1.0 - mNB;
  mNS = float_abs(x1 - NSa) / float_rsh1(NSb);
  mNS = 1.0 - mNS;
  mPS = float_abs(x1 - PSa) / float_rsh1(PSb);
  mPS = 1.0 - mPS;
  mPB = float_abs(x1 - PBa) / float_rsh1(PBb);
  mPB = 1.0 - mPB;
  mN = float_abs(x2 - Na) / float_rsh1(Nb);
  mN = 1.0 - mN;
  mZ = float_abs(x2 - Za) / float_rsh1(Zb);
  mZ = 1.0 - mZ;
  mP = float_abs(x2 - Pa) / float_rsh1(Pb);
  mP = 1.0 - mP;
  m1 = mNB * mN;
  m2 = mNS * mN;
  m3 = mPS * mN;
  m4 = mPB * mN;
  m5 = mNB * mZ;
  m6 = mNS * mZ;
  m7 = mPS * mZ;
  m8 = mPB * mZ;
  m9 = mNB * mP;
  m10 = mNS * mP;
  m11 = mPS * mP;
  m12 = mPB * mP;
  den = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + m11 + m12;
  num = m1*w1 + m2*w2 + m3*w3 + m4*w4 + m5*w5 + m6*w6 + m7*w7 + m8*w8 + m9*w9 + m10*w10 + m11*w11 + m12*w12;
  quot = num / den;
  *u = Kout * quot;
  lastde = de;

  *write=*local_write;
  
  return 0;            
}
