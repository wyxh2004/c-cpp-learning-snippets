struct a
{
    int f1;
};

struct b
{
    struct a _aa;
    int f2;
};

struct c
{
    struct b _bb;
    char f3[8];
};

struct d
{
    struct c _cc;
    int *f4;
};

void blah()
{
    struct d v;
    struct d *pv;
    int j; // To prevent the compiler from optimizing out the accesses.

    pv = &v;

    j = *pv->f4;
    j = pv->_cc._bb._aa.f1;
    // j = &pv->_cc._bb._aa.f1;
}
