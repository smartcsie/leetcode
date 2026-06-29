vector<int> factor(int n) {
    vector<int> res;
	  for(int i =1; i * i <=n; i++) {
		  if(n % i == 0) res.push_back(i);
	  }
	  for (int i = (int)sqrt(n); i >= 1; i--) {
		  if (n % i == 0 && i * i != n) res.push_back(n / i);
	  }
	  return res;
}
