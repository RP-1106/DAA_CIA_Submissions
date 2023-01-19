#include <iostream>

int max(int a, int b, int c){
    if (a>b && a>c)
        return a;
    else if (b>a && b>c)
        return b;
    else    
        return c;
}

int traceback[20];
int index=0;
void traceback_seq(int matrix[9][9], int i, int j,char a[9],char b[9]){
    if (i==0 || j==0){
        traceback[index]=matrix[i][j];
        return;
    }
    if (index==0){
        traceback[index]=matrix[8][8];
        index++;
    }
    if (a[j-1]==b[i-1]){
        traceback[index]=matrix[i-1][j-1];
        index++;
        traceback_seq(matrix,i-1,j-1,a,b);
    }
    else{
        if (matrix[i][j-1]==matrix[i][j]+1){
            traceback[index]=matrix[i][j-1];
            index++;
            traceback_seq(matrix,i,j-1,a,b);
        }
        else if (matrix[i-1][j]==matrix[i][j]+1){
            traceback[index]=matrix[i-1][j];
            index++;
            traceback_seq(matrix,i-1,j,a,b);
        }
        else {
            traceback[index]=matrix[i-1][j-1];
            index++;
            traceback_seq(matrix,i-1,j-1,a,b);
        }
    }
    //return traceback;
}

int main(){
    std::cout << "\nAlignment Matrix Program" << std::endl;

    int num=0; //incase of a mismatch, find max of adjacent 3 and subtract 1
    //ENTER THE SEQUENCES
    char a[9], b[9];
    std::cout << "Enter input sequence 1 : ";
    for (int i=0 ; i<9 ; i++){
        std::cin >> a[i] ;
    }

    std::cout << "Enter input sequence 2 : ";
    for (int i=0 ; i<9 ; i++){
        std::cin >> b[i] ;
    }

    std::cout << "Sequence 1 : " << a << std::endl;
    std::cout << "Sequence 2 : " << b << std::endl;
    std::cout<<std::endl;

    //CREATE THE 2D ARRAY FOR THIS
    int arr[9][9];
    for (int i=0; i<9 ; i++){
        for (int j=0 ; j<9 ; j++){
            arr[i][j]=0;
        }
    }

    //FILL THE 2D ARRAY WITH THE REQUIRED SCORES
    for (int i=0 ; i<9 ; i++){
        for (int j=0 ; j<9 ; j++){
            if (i==0 || j==0){
                arr[i][j]=0;
            }
            else if (i>=1){
                if (b[i]==a[j]){
                    arr[i][j] = arr[i-1][j-1] + 2;
                }
                else {
                    num = max(arr[i-1][j-1] , arr[i-1][j] , arr[i][j-1]);
                    if (num-1 <0){
                        arr[i][j] = 0;
                    }
                    else {
                        arr[i][j] = num-1;
                    }
                }
            }
        }
    }

    std::cout<<std::endl;
    //printing the matrix
    for (int i=0 ; i<9 ; i++){
        for (int j=0 ; j<9 ; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout<<" "<<std::endl;
    //TRACEBACK SEQUENCE
    traceback_seq(arr,8,8,a,b);
    std::cout << "Traceback Sequence " << std::endl;
    for (int i=0 ; i<index; i++){
        std::cout << traceback[i] << "->" ;
    }

    return 0;
}

