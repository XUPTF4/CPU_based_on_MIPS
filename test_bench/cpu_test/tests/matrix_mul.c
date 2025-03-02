#include <trap.h>

#define N 10
int a[N][N] = {{31, -73, -67, -28, 87, -17, -15, -35, -53, -54},
               {52, 36, 9, -91, -27, -78, 42, 82, 19, -6},
               {41, -56, 31, 32, -52, 74, 28, 20, 55, -72},
               {-59, 2, -79, -8, 44, 55, -83, -95, -45, 50},
               {-95, 61, -63, 62, -16, 52, 40, 92, -32, -26},
               {-99, 52, 96, 63, -75, -74, -82, 82, -95, 42},
               {11, -22, 27, -27, -27, -76, -71, 58, -40, -65},
               {91, -53, -67, 72, 36, -77, -3, 93, -24, 97},
               {-52, -11, -77, -93, -92, -24, 70, 18, 56, 88},
               {-43, -41, -26, 11, -84, -14, -41, 83, 27, -11}};
int b[N][N] = {
    {-48, -70, -40, -82, -74, -63, -59, -72, -100, -72},
    {5, -84, 28, 56, 60, -33, -42, -50, -83, -83},
    {-5, 5, 48, 75, -78, -9, 9, 2, 88, 70},
    {69, 23, 66, 66, -11, 50, 67, 18, -58, 76},
    {30, 45, 32, 25, -73, 57, -67, -14, 53, -33},
    {98, -86, -63, 80, -45, -88, 80, -64, 58, -84},
    {-55, -39, -13, -27, -37, 8, -96, 84, -89, 31},
    {-82, 58, 81, -41, -58, 36, 76, -79, -29, 23},
    {86, -46, 16, -18, 81, 90, 35, -90, 43, 55},
    {-38, -19, -40, 82, -76, 57, -29, -2, 79, -48},
};

int ans[N][N] = {
    {-1317, 10379, -5821, -14322, -4330, -3114, -9940, 7033, -1883, -6027},
    {-24266, -861, 4044, -19824, -223, 886, -11988, -6442, -13846, -1054},
    {9783, -7073, -918, -5911, -967, -7100, 14605, -7556, -3439, 9607},
    {15980, -520, -13297, 15043, 6185, -3654, 1325, 4193, 16925, -17761},
    {2566, 3187, 10248, 7925, 6318, 1421, 14648, 700, -12193, 1083},
    {-12603, 19006, 20952, 18599, -1539, 5184, 17408, 6740, 6264, 15114},
    {-12715, 15121, 9963, -13717, 2411, -2196, 6147, -1698, -3389, 8200},
    {-19007, 12417, 5723, -11309, -19242, 15740, -3791, -3949, -13130, -21},
    {-12557, -5970, -11570, -8905, 12227, 7814, -5094, 4532, 1071, -1309},
    {-2955, 9381, 6372, -6898, 9117, 5753, 20778, -5045, 1047, 12115}};

int c[N][N];

int main() {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            c[i][j] = 0;
            for (k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            check(c[i][j] == ans[i][j]);
            check(k == N);
        }
        check(j == N);
    }

    check(i == N);

    return 0;
}