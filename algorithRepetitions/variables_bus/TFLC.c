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

float float_lsh1( float a )
{
  long temp1=(long)a & 0x007FFFFF;
  long temp2=(long)a & 0xFF800000;
  temp1<<=1;
  return temp1 | temp2;	
}

int tflc(float y,
         float NBai, float NBbi,
         float NSai, float NSbi,
         float PBai, float PBbi,
         float PSai, float PSbi,
         float Nai, float Nbi,
         float Zai, float Zbi,
         float Pai, float Pbi,
         float w1i, float w2i, float w3i, float w4i,
         float w5i, float w6i, float w7i, float w8i,
         float w9i, float w10i, float w11i, float w12i,
         float *NBao, float *NBbo,
         float *NSao, float *NSbo,
         float *PBao, float *PBbo,
         float *PSao, float *PSbo,
         float *Nao, float *Nbo,
         float *Zao, float *Zbo,
         float *Pao, float *Pbo,
         float *w1o, float *w2o, float *w3o, float *w4o,
         float *w5o, float *w6o, float *w7o, float *w8o,
         float *w9o, float *w10o, float *w11o, float *w12o,
         float Kin1, float Kin2, float Kout,
         float Ka, float Kb, float Kw,
         float yp, float *u)
{
  float rNBa, rNBb, rNSa, rNSb, rPBa, rPBb, rPSa, rPSb;
  float rNa, rNb, rZa, rZb, rPa, rPb;
  float rw1, rw2, rw3, rw4, rw5, rw6;
  float rw7, rw8, rw9, rw10, rw11, rw12;
  float rKout;
  float ry, ru;
  float e, de, x1, x2;
  float mNB, mNS, mPS, mPB, mN, mZ, mP;
  float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12;
  float mw1, mw2, mw3, mw4, mw5, mw6, mw7, mw8, mw9, mw10, mw11, mw12;
  float sNB, sNS, sPS, sPB, sN, sZ, sP, temp1, temp2;
  float dNBa, dNBb, dNSa, dNSb, dPSa, dPSb, dPBa, dPBb;
  float dNa, dNb, dZa, dZb, dPa, dPb;
  float dw1, dw2, dw3, dw4, dw5, dw6, dw7, dw8, dw9, dw10, dw11, dw12;
  float num, den, J, quot;
  float acoef, bcoef, wcoef;
  static float lastde = 0;
  static float lasty = 0;
  static float lastu = 0;

  rNBa = NBai;
  rNBb = NBbi;
  rNSa = NSai;
  rNSb = NSbi;
  rPBa = PBai;
  rPBb = PBbi;
  rPSa = PSai;
  rPSb = PSbi;
  rNa = Nai;
  rNb = Nbi;
  rZa = Zai;
  rZb = Zbi;
  rPa = Pai;
  rPb = Pbi;
  rw1 = w1i;
  rw2 = w2i;
  rw3 = w3i;
  rw4 = w4i;
  rw5 = w5i;
  rw6 = w6i;
  rw7 = w7i;
  rw8 = w8i;
  rw9 = w9i;
  rw10 = w10i;
  rw11 = w11i;
  rw12 = w12i;
  rKout = Kout;
  ry = y;

  e = ry - yp;
  de = e - lastde;
  x1 = e / Kin1;
  x2 = de / Kin2;
  mNB = float_abs(x1 - (rNBa)) / float_rsh1((rNBb));
  mNB = 1.0 - mNB;
  mNS = float_abs(x1 - (rNSa)) / float_rsh1((rNSb));
  mNS = 1.0 - mNS;
  mPS = float_abs(x1 - (rPSa)) / float_rsh1((rPSb));
  mPS = 1.0 - mPS;
  mPB = float_abs(x1 - (rPBa)) / float_rsh1((rPBb));
  mPB = 1.0 - mPB;
  mN = float_abs(x2 - (rNa)) / float_rsh1((rNb));
  mN = 1.0 - mN;
  mZ = float_abs(x2 - (rZa)) / float_rsh1((rZb));
  mZ = 1.0 - mZ;
  mP = float_abs(x2 - (rPa)) / float_rsh1((rPb));
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
  mw1 = m1 * (rw1);
  mw2 = m2 * (rw2);
  mw3 = m3 * (rw3);
  mw4 = m4 * (rw4);
  mw5 = m5 * (rw5);
  mw6 = m6 * (rw6);
  mw7 = m7 * (rw7);
  mw8 = m8 * (rw8);
  mw9 = m9 * (rw9);
  mw10 = m10 * (rw10);
  mw11 = m11 * (rw11);
  mw12 = m12 * (rw12);
  den = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + m11 + m12;
  num = mw1 + mw2 + mw3 + mw4 + mw5 + mw6 + mw7 + mw8 + mw9 + mw10 + mw11 + mw12;
  quot = num / den;
  ru = rKout * quot;
  *u = ru;
  temp1 = (ru) * (mN + mZ + mP);
  sNB = rKout * (mN * (rw1) + mZ * (rw5) + mP * (rw9)) - temp1;
  sNS = rKout * (mN * (rw2) + mZ * (rw6) + mP * (rw10)) - temp1;
  sPS = rKout * (mN * (rw3) + mZ * (rw7) + mP * (rw11)) - temp1;
  sPB = rKout * (mN * (rw4) + mZ * (rw8) + mP * (rw12)) - temp1;
  temp2 = (ru) * (mNB + mNS + mPS + mPB);
  sN = rKout * (mNB * (rw1) + mNS * (rw2) + mPS * (rw3) + mPB * (rw4)) - temp2;
  sZ = rKout * (mNB * (rw5) + mNS * (rw6) + mPS * (rw7) + mPB * (rw8)) - temp2;
  sP = rKout * (mNB * (rw9) + mNS * (rw10) + mPS * (rw11) + mPB * (rw12)) - temp2;
  dNBa = sNB / (den * (rNBb));
  dNBb = (1.0 - mNB) * dNBa;
  dNBa = float_lsh1(dNBa);
  if (x2 < (rNBa))
  {
  	dNBa = - dNBa;
  }
  dNSa = sNS / (den * (rNSb));
  dNSb = (1.0 - mNS) * dNSa;
  dNSa = float_lsh1(dNSa);
  if (x2 < (rNSa))
  {
  	dNSa = - dNSa;
  }
  dPSa = sPS / (den * (rPSb));
  dPSb = (1.0 - mPS) * dPSa;
  dPSa = float_lsh1(dPSa);
  if (x2 < (rPSa))
  {
  	dPSa = - dPSa;
  }
  dPBa = sPB / (den * (rPBb));
  dPBb = (1.0 - mPB) * dPBa;
  dPBa = float_lsh1(dPBa);
  if (x2 < (rPBa))
  {
  	dPBa = - dPBa;
  }
  dNa = sN / (den * (rNb));
  dNb = (1.0 - mN) * dNa;
  dNa = float_lsh1(dNa);
  if (x2 < (rNa))
  {
  	dNa = - dNa;
  }
  dZa = sZ / (den * (rZb));
  dZb = (1.0 - mZ) * dZa;
  dZa = float_lsh1(dZa);
  if (x2 < (rZa))
  {
  	dZa = - dZa;
  }
  dPa = sP / (den * (rPb));
  dPb = (1.0 - mP) * dPa;
  dPa = float_lsh1(dPa);
  if (x2 < (rPa))
  {
  	dPa = - dPa;
  } 
  dw1 = m1 / den;
  dw2 = m2 / den;
  dw3 = m3 / den;
  dw4 = m4 / den;
  dw5 = m5 / den;
  dw6 = m6 / den;
  dw7 = m7 / den;
  dw8 = m8 / den;
  dw9 = m9 / den;
  dw10 = m10 / den;
  dw11 = m11 / den;
  dw12 = m12 / den;
  J = (ry - lasty) / ((ru) - lastu);
  acoef = Ka * e * J;
  bcoef = Kb * e * J;
  wcoef = Kw * e * J;
  *NBao = (rNBa) + acoef * dNBa;
  *NSao = (rNSa) + acoef * dNSa;
  *PSao = (rPSa) + acoef * dPSa;
  *PBao = (rPBa) + acoef * dPBa;
  *Nao = (rNa) + acoef * dNa;
  *Zao = (rZa) + acoef * dZa;
  *Pao = (rPa) + acoef * dPa;
  *NBbo = (rNBb) + bcoef * dNBb;
  *NSbo = (rNSb) + bcoef * dNSb;
  *PSbo = (rPSb) + bcoef * dPSb;
  *PBbo = (rPBb) + bcoef * dPBb;
  *Nbo = (rNb) + bcoef * dNb;
  *Zbo = (rZb) + bcoef * dZb;
  *Pbo = (rPb) + bcoef * dPb;
  *w1o = (rw1) + wcoef * dw1;
  *w2o = (rw2) + wcoef * dw2;
  *w3o = (rw3) + wcoef * dw3;
  *w4o = (rw4) + wcoef * dw4;
  *w5o = (rw5) + wcoef * dw5;
  *w6o = (rw6) + wcoef * dw6;
  *w7o = (rw7) + wcoef * dw7;
  *w8o = (rw8) + wcoef * dw8;
  *w9o = (rw9) + wcoef * dw9;
  *w10o = (rw10) + wcoef * dw10;
  *w11o = (rw11) + wcoef * dw11;
  *w12o = (rw12) + wcoef * dw12;
  lastde = de;
  lastu = ru;
  lasty = ry;
  return 0;
}
