int NthRoot(int n, int m) {
  // Write your code here.
  double root = pow(m, 1.0 / n);

  if (abs(root - round(root)) < 1e-9) {

    return round(root);

  } else {

    return -1;
  }
  }