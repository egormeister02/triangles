#include "triangle.h"
#include <vector>
#include <limits>

int main()
{
    Text text;

    double* a = new double[text.size()/2];

    size_t n_numbers = Make_arr_double(a, text) - 1;

    size_t n_triangles = (size_t)a[0];

    //text.~Text();

    if (n_numbers % 9 != 0)
    {
        std:: cout << "EROOR: number of point coordinates is not equal to 9\n";
        return 0;
    }

    if (n_triangles != n_numbers / 9)
    {
        std:: cout << "EROOR: the  number of triangles entered is incorrect\n";
        return 0;
    }

    Vector* points = (Vector*)((double*)a + 1);

    Triangle* triangles = new Triangle[n_triangles];

    Make_arr_triangles(triangles, points, n_triangles);

    std::cout << (bool)(Triangles_X(triangles[0], triangles[1]) + Triangles_X(triangles[1], triangles[0])) << " \n";

    //delete[] a;

    //delete[] triangles;

    //Print_vector(Line_X_plane({{0,0,0},{2,-1,-1}}, {{3,3,3}, {1,1,1}}));

    return 0;
} 