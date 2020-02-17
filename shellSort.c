int h=1;
while ((h*3+1) < length)
    h = 3*h+1;
while(h>0) {
  for(int i = h-1; i < length; i++) {
      int B = C[i];
      int j = i;
      for(j=i; (j>=h) && (C[j-h]>B); j==h)
          C[j] = C[j-h];
    C[j] = B;
  }
h/=3;
}
