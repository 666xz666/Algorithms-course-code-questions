//奶牛聚会
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

double s[50010];
double w[50010];
int n;

double fun(double x){
    double sum = 0;
    for(int i = 0; i < n; i++)
        sum += pow(abs(s[i] - x), 3) * w[i];
    return sum;
}

int main() {
    int Ca;
    cin >> Ca;
    for(int count = 1; count <= Ca; count++){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s[i];
            cin >> w[i];
        }
        //三分
        double midl, midr;
        double left =  -pow(10, 6) - 1;
        double right = pow(10, 6) + 1;
        while(right - left >= 1e-8){
            midl = (left + right) / 2;
            midr = (midl + right) / 2;
            if(fun(midl) < fun(midr))
                right = midr;
            else
                left = midl;
        }
        //cout<<round(fun(left))<<endl;
        printf("Case #%d: %.0f\n", count, round(fun(left)));
    }
    return 0;
}
