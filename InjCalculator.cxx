#include "InjCalculator.hxx"
#include "Calculator.hxx"
#include "ui_calculator.h"
#include <qwidget.h>

InjCalculator::InjCalculator( Calculator *parent ) : Calculator(), parent( parent )
{
    ui->buttonTg->setHidden( false );
    ui->buttonCos->setHidden( false );
    ui->buttonSin->setHidden( false );
    ui->buttonPi->setHidden( false );
    ui->buttonE->setHidden( false );
    ui->buttonAng->setHidden( false );
    ui->buttonSqrt->setHidden( false );
    ui->buttonPow->setHidden( false );
    ui->buttonInj->setDisabled( true );
    parent->childs.append( this );
}

InjCalculator::~InjCalculator()
{
    parent->childs.removeOne( this );
}
void InjCalculator::on_buttonInj_clicked()
{
}