#include "calculator.hxx"

#include <QApplication>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    Calculator injCalc;
    injCalc.show();
    return a.exec();
}
