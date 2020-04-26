# Median Filter

This is a C++ median filter for PGM files.It is used as a noise removal image processing.
The algorithm goes as follows: Surround every pixel in the pixel matrix, with an NxN vector, where N is an odd number read from the command line,
and the current pixel is in the middle. After that, just sort the NxN vector, and the resulting pixel is in the middle.

For example given this 3x3 matrix, if we want to apply the algorithm for the middle pixel with N = 3:

82  81  82
81  200 83        ----> Desired pixel: 200
80  83  84

Step #1: Take the pixel and surround it in a 3x3 vector:

82 81 82 81 200 83 80 83 84

Step #2: Sort the new vector:

80 81 81 82 82 83 83 84 200

Step #3: Take the new pixel and add in the new output file:

New pixel: NxN/2 => 3x3/2 => the desired pixel is in the forth position => 82

Step #4 Repeat all the steps above for every pixel

Threating border pixels:

Let's say we have this 4x4 Matrix and we want to filter the first pixel(10) with N = 5:

10 20 15 100
43 74 75 95
45 65 70 80
50 55 65 75

Then we will just have to surround it with a 5x5 matrix with our pixel in the middle by replicating the pixels at the borders:

10 10 10 20 15
10 10 10 20 15
10 10 10 20 15 100
43 43 43 74 75 95
45 45 45 65 70 80
      50 55 65 75

Now we will just repeat the steps from Step #2.
