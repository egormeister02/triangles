
#include <iostream>
#include <cmath>
#include <vector>

const double EPSILON = 1e-8;

class Text
{
    size_t sz = NAN;

    public:
    char* buff = nullptr;
    Text();
    
    auto size() {return sz;}

    ~Text();
};

class Vector
{   
    public:

    double x = NAN;
    double y = NAN;
    double z = NAN;

    double modul() const;

    Vector direction() const;

    Vector projec(const Vector& a);

    Vector operator+(const Vector& right) const;

    Vector operator-(const Vector& right) const;

    Vector operator*(const double l) const;

    Vector operator/(const double l) const;

    bool operator==(const Vector& right) const;

    bool isnanv() {return isnanl(x) || isnanl(y) || isnanl(z);}
    
};

double scal_mul(const Vector& a, const Vector& b);

Vector vec_mul(const Vector& a, const Vector& b);

Vector get_normal(const Vector& r1, const Vector& r2, const Vector& r3);

class Line
{
    public:

    Vector r0  = {};
    Vector dir = {};

};

class Plane
{
    public:

    Vector r0   = {};
    Vector norm = {};
};

void Print_vector(Vector v);

Vector Line_X_plane(const Line& line, const Plane& plane);

class Triangle
{
    public:

    Vector a1, a2, a3 =  {};
    Vector b1, b2, b3 =  {};
    Vector normal     =  {}; 
    Vector center     =  {}; 
    double R_circle   = NAN;
    double square     = NAN;
    bool intersec     =   0;

    void Ctor_triangle(Vector const * vector_ptr);
};

size_t Make_arr_double(double * const array, Text& text);

size_t Make_arr_triangles(Triangle * const & triag_arr, Vector * const & vec_arr, const size_t n_triangles);

void Print_vector(Vector v);

bool Triangles_X(const Triangle& t1, const Triangle& t2);

bool Point_in_triang(const Vector& v, const Triangle& t); 


