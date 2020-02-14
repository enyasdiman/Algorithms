unsigned long int Ackermann(unsigned int x, unsigned int y) {
    if(x==0)
        return 2*y;
    if(x>0 && y==0)
        return 0;
    if(x>0)
        if(y==1)
            return 2;
        else
            return Ackermann(x-1, Ackermann(x, y-1));
}
