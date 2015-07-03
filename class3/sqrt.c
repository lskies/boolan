double mySqrtHelper(double x, double lowBound, double highBound) {
    double precision = 0.00001;
    double sqrt = lowBound / 2 + highBound / 2;
    if (abs(sqrt * sqrt - x) <  precision) {
        return sqrt;
    } else if (sqrt * sqrt - x > 0) {
        return mySqrtHelper(x, lowBound, sqrt);
    } else {
        return mySqrtHelper(x, sqrt, highBound);
    }
}

double mySqrt(double x) {
    if (x < 0)
        return ERROR;
    if (x == 0) {
        return 0;
    }

    if (x == 1) {
        return 1;
    }

    if (x < 1) {
        return mySqrtHelper(x, x, 1);
    } else {
        return mySqrtHelper(x, 1, x);
    }
}
