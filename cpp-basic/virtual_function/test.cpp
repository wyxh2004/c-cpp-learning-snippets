class A
{
public:
    virtual int af1(int v);
    virtual int af2(int v);
};

class B
{
public:
    virtual int bf1(int v);
    virtual int bf2(int v);
    virtual int bf3(int v);
};

class C : public A, public B
{
private:
    int i;
    int j;

public:
    int af1(int v) override;
    int bf1(int v) override;
};