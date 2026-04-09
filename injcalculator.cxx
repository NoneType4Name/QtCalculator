#include "injcalculator.hxx"
#include "ui_injcalculator.h"
#include <cmath>
#include <qobject.h>
#include <string>

#define T_DEFINE_BUTTON_CLICKED( N ) \
    void InjCalculator::on_button##N##_clicked()

#define T_DEFINE_DIGITAL_BUTTON_CLICKED( N )                                  \
    void InjCalculator::on_button##N##_clicked()                              \
    {                                                                         \
        auto d { ui->lineEdit->text().toStdString() };                        \
        if ( afterOp )                                                        \
        {                                                                     \
            ui->lineEdit->setText( "0" );                                     \
            afterOp = false;                                                  \
        }                                                                     \
        for ( auto s : d )                                                    \
        {                                                                     \
            if ( s == 'e' || s == 'p' )                                       \
            {                                                                 \
                return;                                                       \
            }                                                                 \
        }                                                                     \
        if ( cEnj.previous )                                                  \
            ui->lineEdit->setText( #N );                                      \
        else                                                                  \
            ui->lineEdit->setText( ui->lineEdit->text() + #N );               \
        if ( !cEnj.operation )                                                \
        {                                                                     \
            cEnj.previous = std ::stod( ui->lineEdit->text().toStdString() ); \
        }                                                                     \
    }

#define T_DEFINE_OPERATION_BUTTON_CLICKED( N )   \
    void InjCalculator::on_button##N##_clicked() \
    {                                            \
        cEnj.operation = &Calcus::operations::operator##N;

InjCalculator::InjCalculator( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::InjCalculator )
{
    ui->setupUi( this );
    ui->buttonTg->setHidden( true );
    ui->buttonCos->setHidden( true );
    ui->buttonSin->setHidden( true );
    ui->buttonPi->setHidden( true );
    ui->buttonE->setHidden( true );
    ui->buttonAng->setHidden( true );
    ui->buttonSqrt->setHidden( true );
    ui->buttonPow->setHidden( true );
}

InjCalculator::~InjCalculator()
{
    delete ui;
}

T_DEFINE_DIGITAL_BUTTON_CLICKED( 0 )
T_DEFINE_DIGITAL_BUTTON_CLICKED( 1 )
T_DEFINE_DIGITAL_BUTTON_CLICKED( 2 )
T_DEFINE_DIGITAL_BUTTON_CLICKED( 3 )
T_DEFINE_DIGITAL_BUTTON_CLICKED( 4 )
T_DEFINE_DIGITAL_BUTTON_CLICKED( 5 )
T_DEFINE_DIGITAL_BUTTON_CLICKED( 6 )
T_DEFINE_DIGITAL_BUTTON_CLICKED( 7 )
T_DEFINE_DIGITAL_BUTTON_CLICKED( 8 )
T_DEFINE_DIGITAL_BUTTON_CLICKED( 9 )
T_DEFINE_BUTTON_CLICKED( C )
{
    cEnj.previous  = 0;
    cEnj.operation = 0;
    ui->lineEdit->setText( "0" );
}

T_DEFINE_OPERATION_BUTTON_CLICKED( Plus )
// ui->lineEdit->setText( ui->lineEdit->text() + "+" );
afterOp = true;
}

T_DEFINE_OPERATION_BUTTON_CLICKED( Min )
// ui->lineEdit->setText( ui->lineEdit->text() + "-" );
afterOp = true;
}

T_DEFINE_OPERATION_BUTTON_CLICKED( Mult )
// ui->lineEdit->setText( ui->lineEdit->text() + "x" );
afterOp = true;
}

T_DEFINE_OPERATION_BUTTON_CLICKED( Div )
// ui->lineEdit->setText( ui->lineEdit->text() + "/" );
afterOp = true;
}

T_DEFINE_OPERATION_BUTTON_CLICKED( Pow )
// ui->lineEdit->setText( ui->lineEdit->text() + "^" );
afterOp = true;
}

T_DEFINE_OPERATION_BUTTON_CLICKED( Sqrt )
// ui->lineEdit->setText( "√" );
}

T_DEFINE_OPERATION_BUTTON_CLICKED( Tg )
// ui->lineEdit->setText( "tg" );
}

T_DEFINE_OPERATION_BUTTON_CLICKED( Cos )
// ui->lineEdit->setText( "cos" );
}

T_DEFINE_OPERATION_BUTTON_CLICKED( Sin )
// ui->lineEdit->setText( "sin" );
}

T_DEFINE_OPERATION_BUTTON_CLICKED( Pers )
// ui->lineEdit->setText( ui->lineEdit->text() + "%" );
}

T_DEFINE_BUTTON_CLICKED( Equal )

{
    if ( cEnj.operation )
    {
        cEnj.previous = ( cEnj.ops.*( cEnj.operation ) )( std::stod( ui->lineEdit->text().toStdString() ) );
    }
    if ( cEnj.previous == INFINITY )
    {
        ui->lineEdit->setText( "ДЕЛЕНИЕ НА 0" );
        return;
    }

    auto d { std::to_string( cEnj.previous ) };
    d.erase( d.find_last_not_of( '0' ) + 1, std::string::npos );
    d.erase( d.find_last_not_of( '.' ) + 1, std::string::npos );
    ui->lineEdit->setText( QString::fromStdString( d ) );
}

T_DEFINE_BUTTON_CLICKED( Dot )
{
    if ( ui->lineEdit->text().isEmpty() )
        ui->lineEdit->setText( "0" );
    else
    {
        for ( auto s : ui->lineEdit->text().toStdString() )
            if ( s == '.' ) return;
    }
    ui->lineEdit->setText( ui->lineEdit->text() + "." );
}

T_DEFINE_BUTTON_CLICKED( E )
{
    ui->lineEdit->setText( "e" );
    cEnj.previous = M_E;
}

T_DEFINE_BUTTON_CLICKED( Pi )
{
    ui->lineEdit->setText( "p" );
    cEnj.previous = M_PI;
}

T_DEFINE_BUTTON_CLICKED( Bs )
{
    auto d { ui->lineEdit->text() };
    d.resize( d.size() - 1 );
    if ( d.isEmpty() )
        ui->lineEdit->setText( "0" );
    else
        ui->lineEdit->setText( d );
}

T_DEFINE_BUTTON_CLICKED( Ang )
{
    cEnj.Rad = !cEnj.Rad;
    ui->buttonAng->setText( cEnj.Rad ? "Rad" : "Deg" );
}

T_DEFINE_BUTTON_CLICKED( Inj )
{
    ui->buttonTg->setHidden( !ui->buttonTg->isHidden() );
    ui->buttonCos->setHidden( !ui->buttonCos->isHidden() );
    ui->buttonSin->setHidden( !ui->buttonSin->isHidden() );
    ui->buttonPi->setHidden( !ui->buttonPi->isHidden() );
    ui->buttonE->setHidden( !ui->buttonE->isHidden() );
    ui->buttonAng->setHidden( !ui->buttonAng->isHidden() );
    ui->buttonSqrt->setHidden( !ui->buttonSqrt->isHidden() );
    ui->buttonPow->setHidden( !ui->buttonPow->isHidden() );
}
