

#ifndef GRAFOSSTD
#define GRAFOSSTD
/* @Documentacion:
 * Este archivo debe contener la clase para manejar los Grafos de cualquier tipo de dato
 * Por ahora esta clase no es capaz de cumplir estas espectativas por lo que se esta dessarrollando la manera de lograrlo
*/
template <typename T>
class Grafos
{
private:
    T data;
    size_t id;
    bool visited;
    Grafos **vertex;

public:
    Grafos(T b) {}
};

#endif