#ifndef _PNG_H_
#define _PNG_H_

class png
{
private:
    unsigned char *r, *g, *b;
    unsigned char *buffer;
    unsigned int len,n,m;
    void print(unsigned char x);
    void printi(unsigned int x);
    void alder32(unsigned char *v,int n);
    void crc(unsigned char *a,int n);
    void HEAD();
    void IHDR();
    void IDAT();
    void IEND();

public:
    png();
    png(const int &, const int &);
    png(const int &, const int &, const unsigned char*, const unsigned char*, const unsigned char*);
    ~png();
    void setpix(const int &, const int &, const unsigned char &, const unsigned char &, const unsigned char &);
    void output(const char*);
};

#endif