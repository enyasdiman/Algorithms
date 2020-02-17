float top(float a, int n) {
  if(a==0)
  return(0);
    if(a>&&n==0)
    return(1);
if(a>0 && n==1)
  return(a);
if(a>0 && n>1)
  return a*(top(a, (n-1));
}
