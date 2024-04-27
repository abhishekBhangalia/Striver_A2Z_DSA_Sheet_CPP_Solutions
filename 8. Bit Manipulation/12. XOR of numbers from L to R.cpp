// it finds xor from 1 to n
int XOR(int n){
    int rem = n%4;
    switch (rem) {
        case 1 : return 1;
        case 2 : return n+1;
        case 3 : return 0;
        case 0 : return n;
    }
}


int findXOR(int L, int R){
   return XOR(R) ^  XOR(L-1);
}

