#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//show matrix
void show(const vector<vector<double>>& A) {
    int n = A.size();
    cout << "Enter matrix: \n";
    for (int i = 0; i < n; i++) {
        cout << "[";
        for (int j = 0; j < A[i].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << "]\n";
    }
}

// Multiply matrix by vector
vector<double> multiply(const vector<vector<double>>& A, const vector<double>& x) {
    //determine # of rows in matrix
    int n = A.size();

    //create empty vector
    vector<double> result(n, 0.0);

    //interact with rows
    for (int i = 0; i < n; i++) {
        //interact with col
        for (int j = 0; j < A[i].size(); j++) {
            result[i] += A[i][j] * x[j];
        }
    }
    //return new vector 
    return result;
}

//xp = xp/(xpTdotxp)^1/2

// Compute norm of vector
double norm(const vector<double>& x) {
    double sum = 0.0;
    //find x dot x
    for (double val : x) sum += val * val;
    //return normolize number for convergence stability
    return sqrt(sum);
}

// Normalize vector
void normalize(vector<double>& x) {

    //call euclidean norm function
    double n = norm(x);

    //make sure that length 1, to avoid overflow
    for (double& val : x) val /= n;
}


// Rayleigh quotient find approx eigenvalue(lambda1)
double rayleighQuotient(const vector<vector<double>>& A, const vector<double>& x) {
    //multiply matrix by vector
    vector<double> Ax = multiply(A, x);

    double num = 0.0, den = 0.0;

    //lamda1 = xpT dot xp+1 / xpT dot xp
    for (int i = 0; i < x.size(); i++) {
        num += x[i] * Ax[i];
        den += x[i] * x[i];
    }
    return num / den;
}

int main() {

    cout << "These programm will use Power Method to find the bigest eigenvalue and its corissponting aigenvector\n";
    cout << " \n";

    int n;
    //user enter size of matrix
    cout << "Enter matrix size (n x n): ";
    cin >> n;

    //create matrix
    vector<vector<double>> A(n, vector<double>(n));

    //enter elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter element for matrix in position a" << i + 1 << j + 1 << endl;
            cin >> A[i][j];
        }
    }

    cout << " \n";

    //show matrix
    show(A);

    cout << " \n";

    // Initial vector (all ones)
    vector<double> x(n, 1.0);


    double eigenvalue = 0.0, prev = 0.0;

    int maxIter = 100000;
    double tol = 1e-6;
    int iter = 1;
    for (int k = 0; k < maxIter; k++) {
        
        cout << "\nIteration "<<iter <<" \n";
        //find xp
        vector<double> y = multiply(A, x);

        //normolize vector
        normalize(y);

        //update current vector
        x = y;

        //print eigenector in proccess 
        cout << "\nEigenvector: \n";
        for (double val : x) {
            cout << val << endl;
        }

        //update labda1
        eigenvalue = rayleighQuotient(A, x);


        cout << "\nEigenvalue: \n";
        cout << "xp+1: \n";
        cout << eigenvalue << endl;
        cout << "xp: \n";
        cout << prev << endl;
        cout << "xp+1 - xp: \n";
        cout << eigenvalue - prev << endl;
        cout << " \n";

        //check if diference between eigenvalue is below tolerance
        if (fabs(eigenvalue - prev) < tol) break;

        //update xp
        prev = eigenvalue;
        iter++;
    }

    cout << "\nApproximate largest eigenvalue: " << eigenvalue << endl;
    cout << "Corresponding eigenvector: < ";
    for (double val : x) cout << val << " ;";
    cout << ">";
    cout << endl;

    return 0;
}
