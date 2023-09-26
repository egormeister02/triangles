#include "triangle.h"
#include <vector>
#include <limits>

int main()
{
    Text text;

    double* a = new double[text.size()/2];

    size_t n_numbers = Make_arr_double(a, text) - 1;

    size_t n_triangles = (size_t)a[0];

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

    //std::cout << "go to pizda\n";
    /*
    for (size_t i = 0; i < n_triangles; i++)
    {
        bool flag = 0;
        for (size_t j = 0; j < n_triangles && !flag; j++)
        {
            if (i != j && !(triangles[j].intersec && triangles[i].intersec) 
            && ((triangles[i].center - triangles[j].center).modul() < (triangles[i].R_circle + triangles[j].R_circle)))
            {
                if (Triangles_X(triangles[i], triangles[j]))
                {
                    triangles[i].intersec = 1;
                    triangles[j].intersec = 1;
                    flag = 1;
                }
                else if (Triangles_X(triangles[j], triangles[i]))
                {
                    triangles[i].intersec = 1;
                    triangles[j].intersec = 1;
                    flag = 1;
                }
            
            }
        }
    }*/

    for (size_t i = 0; i < n_triangles; i++)
    {
        for (size_t j = i; j < n_triangles; j++)
        {
            if (i != j && !(triangles[j].intersec && triangles[i].intersec) 
            && ((triangles[i].center - triangles[j].center).modul() < (triangles[i].R_circle + triangles[j].R_circle)))
            {
                if (Triangles_X(triangles[i], triangles[j]))
                {
                    triangles[i].intersec = 1;
                    triangles[j].intersec = 1;
                }
                else if (Triangles_X(triangles[j], triangles[i]))
                {
                    triangles[i].intersec = 1;
                    triangles[j].intersec = 1;
                }
            
            }
        }
    }

    for (size_t i = 0; i < n_triangles; i++)
    {
        if (triangles[i].intersec)
        {
            std::cout << i << " ";
        }
    }
    
    std::cout << "\n";
    /*
    std::cout << triangles[0].intersec<< " tr_1\n";
    std::cout << triangles[1].intersec<< " tr_2\n";
    */
    return 0;
} 