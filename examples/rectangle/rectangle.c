#include "rectangle.h"

double ORectangle_area() {
    func_init(ORectangle);
    return this->width * this->height;
}

constructor(ORectangle, double width, double height) {
    create(ORectangle);
    def_func(ORectangle,area);
    def_prop(ORectangle,width) = width;
    def_prop(ORectangle,height) = height;
    def_destruct(ORectangle);

    return_class(ORectangle);
}

default_destructor(ORectangle);

