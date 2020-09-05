long long int modularExponentiation(long long int base, long long int exp, long long int mod){
    long long ans = 1;
    while(exp){
      if(exp % 2){
        ans = (ans * base) % mod;
      }
      base = (base * base) % mod;
      exp = exp / 2;
    }
    return ans % mod;
}
