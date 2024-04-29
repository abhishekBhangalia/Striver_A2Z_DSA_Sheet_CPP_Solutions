class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor){
            return 1;
        }
        int sign = true;
        if ((dividend < 0 and divisor > 0) or (dividend >= 0 and divisor < 0)){
            sign = false;
        }
        long ans = 0;
        
        long divid = abs(dividend);
        long divis = abs(divisor);

        while(divid >= divis){
            int pow = 0;
            while(divis << (pow+1) <= divid){ // divis * 2^pow <= divid
                pow++;
            }
            cout<<pow<<endl;
            ans += (long)1 << pow; // if 1 is not casted to long then it will not be able to store 2^31 in case of -2^31/-1

            divid -= divis << pow; 
        }
        
        if (sign and ans > INT_MAX){ // -2^31/-1
            ans = INT_MAX;
        }

        return sign ?  ans : -ans;

    }
};
