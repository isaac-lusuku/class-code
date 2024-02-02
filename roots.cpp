#include <iostream>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

double discriminant(double a, double b, double c) {
    double discriminant = (b * b) - (4 * a * c);
    return discriminant;
}


pair<double, double> roots_calc(double a, double b, double c, double discriminant) {
    

    // HANDLE REAL AND DISTINCT, REAL AND EQUAL

        double discriminant_sqrt = sqrt(discriminant);
        double first_root = (-b + discriminant_sqrt) / (2 * a);
        double sec_root = (-b - discriminant_sqrt) / (2 * a);
    
        return make_pair(first_root, sec_root);
    
}

int main() {
    double a, b, c;
    cout << "Enter the coefficient 'a': ";
    cin >> a;

    cout << "Enter the coefficient 'b': ";
    cin >> b;

    cout << "Enter the coefficient 'c': ";
    cin >> c;

    double dscnt = discriminant(a, b, c);

    if (dscnt < 0) {
        cout << "the root is 'COMPLEX'";
    }
    else {
        auto result = roots_calc(a, b, c, dscnt);


        cout << "First root: " << result.first << std::endl;
        cout << "Second root: " << result.second << std::endl;
    }

    

    return 0;
}