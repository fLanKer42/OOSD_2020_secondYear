#include <iostream>

using namespace std;



/***************************************************************************************************************
*ear cutting method
*the algorithm: 1. select three consecutive vertices in the polygon
*               2. check if the form an ear (an ear is a triangle that is completely inside the polygon)
*               3. exclude this ear from the polygon and recurisvely apply the algorith on the remaining polygon                  
*               4. the side of the ear that is not common with the polygon will be a triangulation diagonal.
****************************************************************************************************************/
/*
Time Complexity : N^2
Algorith has time complexity of n^2, n time for checking an ear multiplied by n time for looping through the polygon vertices.
*/

class Coordinate {
    public:
        double x;
        double y;
};

class Line {
    public:
        Coordinate A;
        Coordinate B;
        double m;
        Line( Coordinate a, Coordinate b) {
            A = a;
            B = b;
            if(A.x == B.x) {
                if(A.y - B.y) {
                    m = double(INT8_MAX);
                }
                else {
                    m = double((-1)*(INT8_MAX));                  
                }
            }
            else {
                m = (A.y - B.y)/(A.x - B.x);
            }
            
        }
        int collide_point(Coordinate U, Coordinate V) {
            //finds collision point between UV line and AB line
            double a = B.y - A.y;
            double b = A.x - B.x;
            double c = a*(A.x) + b*(A.y);
            double a1 = V.y - U.y;
            double b1 = U.x - V.x;
            double c1 = a1*(U.x) + b1*(U.y);
            double det = a*b1 - a1*b;
            if(det == 0) {
                return 0;
            }
            else {
                double x1 = (b1*c - b*c1)/det;
                double y1= (a*c1 - a1*c)/det;
                if( (( x1 < A.x && x1 > B.x) || ( x1 > A.x && x1 < B.x )) && (( y1 < A.y && y1 > B.y) || ( y1 > A.y && y1 < B.y ))) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }

};

class Polygon {
    private:
        int n;
        //n is the number of vertices
    public:
        Coordinate* X;
        //X is the array of vertices
        void add_val(int N, Coordinate* T) {
            n = N;
            X = T;
        }
        void add() {
            cout << "Enter the value of n: ";
            cin >> n ;
            Coordinate arr[n];
            int i;
            for(i=0;i<n;i++) {
                cout << "Enter the " << i+1 << "th coordinate\nx: \n";
                cin >> arr[i].x;
                cout << "y: \n";
                cin >> arr[i].y;
            }
            X = arr;
        };
        void cut_ear() {
            int i;
            double M;
            if( n == 3 ) {
                return;
            }
            else {
                for(i=0;i<(n-2);i++) {
                    Line a1(X[i],X[i+1]);
                    Line a2(X[i+1],X[i+2]);
                    M = a1.m - a2.m;
                    if(M)  // angle checks out 
                    {
                        Line a3(X[i],X[i+2]);
                        int j,k=0;
                        int collide;
                        for(j=0;j<(n-1);j++) {
                            //check collision
                            collide = a3.collide_point(X[j],X[j+1]);
                            if(collide) {
                                goto pass;
                            }
                        }
                        //print out the diagonal
                        cout << "{(" << X[i].x << "," << X[i].y << "),(" << X[i+2].x << "," << X[i+2].y << ")}";
                        Coordinate T[n-1];
                        for(j=0;j<n;j++) {
                            //form a new polygon without the ear
                            if( j == (i+1)) {
                                continue;
                            }
                            else {
                                T[k] = X[j];
                                k = k + 1;
                            }
                        }
                        //polygon without the ear
                        Polygon recurse;
                        recurse.add_val(n-1,T);
                        //recursive call
                        recurse.cut_ear();
                    }
                    else {
                        //continue to next vertices
                        continue;
                    }
                    pass: 
                    //continue to next vertices
                    continue;
                }
                
            }
        }    
};

int main() {
    Polygon main;
    main.add();
    cout << "{ ";
    main.cut_ear();
    cout << " }";
}
