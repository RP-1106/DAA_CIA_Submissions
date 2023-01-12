#include <iostream>
using namespace std;

int max(int a, int b, int c){
    if ((a>=b) && (a>=c))
        return a;
    else if ((b>=a) && (b>=c))
        return b;
    else
        return c;
}

void traceback_seq(int )
int main()
{
    cout << "Alignment Matrix Program" << "\n" << endl;
    
    //define the variables to be used in the program
    int num=0;
    int traceback[9];
    cout<<endl;
    
    /*Input the sequences from the user
    NOTE : INPUT A HYPHEN ('-') AND THEN THE SEQUENCE OF 8 CHARACTERS */
    char a[9],b[9];
    cout << "Enter input sequence 1 : ";
    for (int i=0 ; i<9 ; i++){
        cin >> a[i];
    }
    cout << "Sequence 1 : "<< a << endl;

    cout << "Enter input sequence 2 : ";
    for (int i=0 ; i<9 ; i++){
        cin >> b[i];
    }
    cout << "Sequence 2 : "<< b << endl;

    //create the 2d alignment matrix and initialize it with 0
    int arr[9][9];
    for (int i=0 ; i<9 ; i++){
        for (int j=0 ; j<9 ; j++){
            arr[i][j]=0;
        }
    }
    
    //use the Scoring model of +2 for match and -1 for mismatch
    cout<<endl;
    for (int i=0 ; i<9 ; i++){
        for (int j=0 ; j<9 ; j++){
            if (i==0 || j==0){
                arr[i][j]=0;
            }
            else if(i>=1){
                if (a[j]==b[i]){
                    arr[i][j] = arr[i-1][j-1]+2;
                }
                else {
                    num = max(arr[i-1][j-1], arr[i-1][j], arr[i][j-1]);
                    if (num<0){
                        arr[i][j] = 0;
                    }
                    else {
                        arr[i][j] = num-1;
                    }
                }
            }
        }
    }
    
    for (int i=0 ; i<9 ; i++){
        for (int j=0 ; j<9 ; j++){
            cout << arr[i][j] << " " ;
        }
        cout<<endl;
    }
    
    //traceback using prims , djikstras and kruskals algorithm.
    return 0;
}
