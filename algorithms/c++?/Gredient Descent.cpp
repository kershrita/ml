#include <iostream>
#include <cmath>
using namespace std;

double sum(double arr[], int size){
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum = sum + arr[i];
    }
    return sum;
}

void GD(double x[], double y[], int size){
    double ThetaZero = 0.0,
           ThetaOne = 0.0,
           LearningRate = 0.002;

    int iterations = 0;

    double yHat[size],
           summition[size],
           Gsum0[size],
           Gsum1[size],
           cost,
           GredientThtaZero,
           GredientThtaOne;

    while(iterations < 100000){
        for(int i = 0; i < size; i++){
            yHat[i] = ThetaZero + x[i] * ThetaOne;
        }
        
        for(int k = 0; k < size; k++){
            summition[k] = pow((yHat[k] - y[k]), 2);
        }
        cost = ((1.0 / (2.0 * size)) * sum(summition, size));

        for(int p = 0; p < size; p++){
            Gsum0[p] = yHat[p] - y[p];
            Gsum1[p] = x[p] * (yHat[p] - y[p]);
        }
        GredientThtaZero = (1.0 / size) * sum(Gsum0, size);
        GredientThtaOne = (1.0 / size) * sum(Gsum1, size);

        ThetaZero = ThetaZero - LearningRate * GredientThtaZero;
        ThetaOne = ThetaOne - LearningRate * GredientThtaOne;

        iterations++;
        cout << "θ0 = " << ThetaZero << " | " <<
                "θ1 = " << ThetaOne << " | " <<
                "Cost = " << cost << " | " <<
                "Iteration = " << iterations << endl;
        
    }
}

int main(){
    const int size = 23;
    double x[size] = {12.39999962, 14.30000019, 14.5, 14.89999962, 16.10000038,
                    16.89999962, 16.5, 15.39999962, 17, 17.89999962, 
                    18.79999924, 20.29999924, 22.39999962, 19.39999962, 15.5, 
                    16.70000076, 17.29999924, 18.39999962, 19.20000076, 17.39999962,
                    19.5, 19.70000076, 21.20000076};

    double y[size] = {11.19999981, 12.5, 12.69999981, 13.10000038, 14.10000038,
                    14.80000019, 14.39999962, 13.39999962, 14.89999962, 15.60000038,
                    16.39999962, 17.70000076, 19.60000038, 16.89999962, 14,
                    14.60000038, 15.10000038, 16.10000038, 16.79999924, 15.19999981,
                    17, 17.20000076, 18.60000038};

    GD(x, y, size);
    return 0;
}

