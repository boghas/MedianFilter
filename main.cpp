#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

/*
 * Created a PGM struct
 * That is holds all the valuable informations about the PGM file we wish to edit
 * file_type is that of file we want to edit eg: P2
 * width, height are the width and height of the initial file
 * max_value is the maximum value of a pixel -> used to represent the white level
 * in stores all the pixel values of the original file
 */
struct pgmFile {
    std::string file_type;
    int width,height,max_value;
    std::vector<std::vector<int>> in;
};

/*
 * This function initializes the pgmFile object we created
 * First it initializes the file_type
 * Then it ignores all the commented lines in the original file
 * Commented lines start with '#'
 * It then initializes the width x height values followed by the max_value
 * Lastly copies all the pixel values of the matrix into our pgmFile.in 
 */

void initialize(pgmFile &myFile,std::string file_name) {
    bool stop = false;
    std::string word;
    int width, height,max_value;
    std::ifstream file(file_name);
    file>>myFile.file_type;
    while(!stop) {
        file>>word;
        if(isdigit(word.at(0))) {
            myFile.width = std::stoi(word);
            file>>word;
            myFile.height = std::stoi(word);
            stop = true;
        }
    }
    file>>myFile.max_value;
    std::vector<std::vector<int>> out(myFile.height, std::vector<int>(myFile.width, 0));
    for(int i=0;i<myFile.height;i++) {
        for(int j=0;j<myFile.width;j++) {
            file>>word;
            out[i][j] = std::stoi(word);
        }
    }
    myFile.in = out;
    file.close();
}

/*
 * Bubble Sort
 */

void bubbleSort(std::vector<int>&vec, int n) {
    int i, j, temp;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n-i-1; j++) {
            if( vec[j] > vec[j+1]){
                temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            } 
        }
    }
}

/*
 * This function returns the new pixel we want to write into our output file
 * Takes as arguments the position of the pixel inside the matrix,the window size,
 * And a pointer to our struct, and a string representing the sort algorithm we wish to perform
 * It creates a nxn matrix with our pixel in the middle
 * Sorts the vector, and returns the middle pixel
 * For the pixel outside the borders, just duplicate the nearest pixels 
 */

int getValue(int posX,int posY,int n, pgmFile *myFile, std::string algorithm) {
    std::vector<int>vec;
    int x,y;
    for (int i = posX - (n/2); i <= posX + (n/2); i++) {
        for (int j = posY - (n/2); j <= posY + (n/2); j++) {
            if(i < 0 || i > myFile->height - 1) {
                x = posX;
            }
            else {
                x = i;
            }
            if(j < 0 || j > myFile->width - 1) {
                y = posY;
            }
            else {
                y = j;
            }
            
            vec.push_back(myFile->in[x][y]);
        }
    }
    if(algorithm == "merge") {
        std::sort(vec.begin(),vec.end());
    }
    else if(algorithm == "bubble") {
        bubbleSort(vec, vec.size());
    }
    return vec[(n*n)/2];
}

int main() {
    int n;
    std::string algorithm;
    std::string file_name;
    std::string out_file_name;
    std::cin>>algorithm>>n>>file_name>>out_file_name;
    pgmFile myFile;
    initialize(myFile,file_name);
    std::ofstream out_file(out_file_name);
    out_file<<myFile.file_type<<std::endl;
    out_file<<myFile.width<<" "<<myFile.height<<std::endl;;
    out_file<<myFile.max_value<<std::endl;
    int pixel_values[n*n];
    for(int i = 0; i < myFile.height; i++) {
        for(int j = 0; j < myFile.width; j++) {
            out_file<<getValue(i,j,n,&myFile,algorithm)<<" ";
        }
        out_file<<std::endl;
    }
    return 0;
}