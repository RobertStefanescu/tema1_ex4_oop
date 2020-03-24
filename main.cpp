#include <iostream>
#include <complex>
#include <algorithm>
using namespace std;

class vector_complex{
private:
    complex<double> *p;
    int nr_elem;
    bool static cmp(complex<double>nr1, complex<double>nr2){
        return(abs(nr1)<abs(nr2));
    }
public:
    vector_complex (complex<double> nr = 0, int nr_comp = 0 ); ///constructor initializare
    vector_complex (const vector_complex &v);
    ~vector_complex ();
    friend istream& operator >> (istream & input, vector_complex&v);
    friend ostream& operator << (ostream & output, vector_complex&v);
    void afisare_module();
    void sortare();
    complex<double> suma();
    complex<double> operator *(const vector_complex &v);

};

istream& operator >> (istream & input, vector_complex&v){
    double real, img;
    cout << "introduceti nr elemente: ";
    input >> v.nr_elem;
    delete[] v.p;
    complex<double>c;
    v.p=new complex<double>[v.nr_elem];
    cout << "format: \"real complex\"\n";
    for (int i=0;i<v.nr_elem;i++) {
        input >> real >> img;
        c.real(real);
        c.imag(img);
        v.p[i] = c;
    }
    return input;
}

ostream& operator << (ostream & output, vector_complex&v){
    output << v.nr_elem << "\n";
    for (int i=0;i<v.nr_elem;i++)
        output << v.p[i].real() << " "<< v.p[i].imag()<<" ; ";
    output << '\n';
    return output;
}

vector_complex::vector_complex(complex<double> nr, int nr_comp ) {//constr init
    nr_elem=nr_comp;
    p=new complex<double>[nr_comp];

    for (int i=0;i<nr_comp;i++)
        p[i]=nr;
}

vector_complex::vector_complex (const vector_complex &v) {//constr copiere
    nr_elem=v.nr_elem;
    p=new complex<double>[nr_elem];
    for (int i=0;i<nr_elem;i++)
        p[i]=v.p[i];
}

vector_complex::~vector_complex (){//desctructor
    nr_elem=0;
    delete[] p;
}

void vector_complex::afisare_module(){
    for (int i=0;i<nr_elem;i++)
        cout << abs(p[i]) <<" ";
    cout << '\n';
}

void vector_complex::sortare(){
    sort (p,p+nr_elem,cmp);
}

complex<double> vector_complex::suma(){
    complex<double> s=0;
    for (int i=0;i<nr_elem;i++)
        s=s+p[i];
    return s;
}

complex<double> vector_complex::operator*(const vector_complex &v){
    complex<double> produs=0;
    if (nr_elem!=v.nr_elem)
        return -1;
    for (int i=0;i<nr_elem;i++)
        produs=produs+p[i]*v.p[i];
    return produs;
}

int main() {
    complex <double> nr(2,2);
    vector_complex v;
    cin >> v;
    vector_complex v2(nr, 5);
    vector_complex v3(v2);
    cout << v;
    cout << v.suma() << "\n";
    v.afisare_module();
    v.sortare();
    cout << v;
    cout << v*v3;
    return 0;
}
