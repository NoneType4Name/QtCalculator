#include "injcalculator.hxx"

#include <QApplication>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    InjCalculator injCalc;
    injCalc.show();
    return a.exec();
}
