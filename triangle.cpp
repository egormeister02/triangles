#include "triangle.h"

Text::Text()
{    
    std::cin.seekg (0, std::cin.end);
    sz = std::cin.tellg();
    std::cin.seekg (0, std::cin.beg);

    buff = new char[sz];

    //std::setvbuf(stdin, buff, _IOFBF, sz);
    std::fread(buff, 1, sz, stdin);
};

Text::~Text()
{
    delete[] buff;
    buff = nullptr;
    sz = NAN;
};

double Vector::modul() const
{
    return sqrt(x*x + y*y + z*z);
};

Vector Vector::operator+(const Vector& right) const
{
    Vector res;

    res.x = x + right.x;
    res.y = y + right.y;
    res.z = z + right.z;

    return res;
};

Vector Vector::operator-(const Vector& right) const
{
    Vector res;
    
    res.x = x - right.x;
    res.y = y - right.y;
    res.z = z - right.z;
    return res;
};

Vector Vector::operator*(const double l) const
{
    Vector res;

    res.x = x * l;
    res.y = y * l;
    res.z = z * l;

    return res;
};

Vector Vector::operator/(const double l) const
{
    Vector res;
    
    res.x = x / l;
    res.y = y / l;
    res.z = z / l;

    return res;
};

Vector Vector::direction() const
{
    return *this / this->modul();
};

bool Vector::operator==(const Vector& right) const
{
    return (((x-right.x) < EPSILON) && ((y-right.y) < EPSILON) && ((z-right.z) < EPSILON));
};

Vector Vector::projec(const Vector& a)
{
    return a.direction() * scal_mul(*this, a);
}

double scal_mul(const Vector& a, const Vector& b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
};

Vector vec_mul(const Vector& a, const Vector& b)
{
    Vector res;

    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;

    return res; 
};

Vector get_normal(const Vector& r1, const Vector& r2, const Vector& r3)
{
    Vector a = r1 - r2;
    Vector b = r3 - r2;

    Vector n = vec_mul(a, b);

    return n.direction();
}

Vector Line_X_plane(const Line& line, const Plane& plane)
{
    return line.r0 + line.dir * (scal_mul(plane.r0 - line.r0, plane.norm) / scal_mul(line.dir, plane.norm));
};

bool co_dir(const Vector& a, const Vector& b) 
{
    return (a.direction() == b.direction());
};

bool Triangles_X(const Triangle& t1, const Triangle& t2)
{
    Line l1 = {t1.a1, t1.b1}; // a3 :: a1
    Line l2 = {t1.a2, t1.b2}; // a1 :: a2
    Line l3 = {t1.a3, t1.b3}; // a2 :: a3

    Plane p = {t2.a1, t2.normal};

    Vector x1 = Line_X_plane(l1, p);
    
    //Print_vector(x1);

    if (!x1.isnanv() && !((x1 - t1.a3).modul() + (x1 - t1.a1).modul() - t1.b1.modul() > EPSILON) && Point_in_triang(x1, t2))
        return 1;

    //std::cout << "l1 lose\n";

    Vector x2 = Line_X_plane(l2, p);

    //Print_vector(x2);

    if (!x2.isnanv() && !((x2 - t1.a1).modul() + (x2 - t1.a2).modul() - t1.b2.modul() > EPSILON) && Point_in_triang(x2, t2))
        return 1;

    //std::cout << "l2 lose\n";

    Vector x3 = Line_X_plane(l3, p);

    //Print_vector(x3);

    if (!x3.isnanv() && !((x3 - t1.a2).modul() + (x3 - t1.a3).modul() - t1.b3.modul() > EPSILON) && Point_in_triang(x3, t2))
        return 1;

    //std::cout << "l3 lose\n";

    return 0;
};

void Triangle::Ctor_triangle(Vector const * vector_ptr)
{
    
    a1 = vector_ptr[0];
    a2 = vector_ptr[1];
    a3 = vector_ptr[2];

    b1 = a3 - a1;
    b2 = a2 - a1;
    b3 = a3 - a2;

    Vector s = vec_mul(b1, b2);

    normal = s.direction();
    square = s.modul();

    R_circle = (b1.modul() * b2.modul() * b3.modul()) / (2 * vec_mul(b1, b2).modul());
    center = Line_X_plane({a1 + b2 / 2, vec_mul(b2, normal)}, {a2 + b3 / 2, b3});
};

bool Point_in_triang(const Vector& v, const Triangle& t)
{
    double s1 = vec_mul(v - t.a1, t.b1).modul();
    double s2 = vec_mul(v - t.a1, t.b2).modul();
    double s3 = vec_mul(v - t.a2, t.b3).modul();

    if (s1 + s2 + s3 - t.square > EPSILON)
        return 0;
    
    return 1;
};

size_t Make_arr_double(double * const array, Text& text)
{
    size_t index     = 0; 
    size_t index_arr = 0;
    while(index < text.size() - 1)
    {
        array[index_arr] = atof(text.buff + index);
        ++index_arr;

        while (!((text.buff[index] >= '0' && text.buff[index] <= '9') || (text.buff[index] == '.')) && index < text.size())
            ++index;
        while (((text.buff[index] >= '0' && text.buff[index] <= '9') || (text.buff[index] == '.')) && index < text.size())
            ++index;
    }

    return index_arr;
};

size_t Make_arr_triangles(Triangle * const & triag_arr, Vector * const & vec_arr, const size_t n_triangles)
{
    for (size_t t_index = 0; t_index < n_triangles; ++t_index)
    {
        triag_arr[t_index].Ctor_triangle(vec_arr + (t_index * 3));
    }

    return 0;
};

void Print_vector(Vector v)
{
    printf("(%f, %f, %f)\n", v.x, v.y, v.z);
};
