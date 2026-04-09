#include "CalcusEnj.hxx"
#include <cmath>
#include <qmath.h>
#define OPERATOR_DEFINE_1( N ) \
    CALCUS_TYPE Calcus::operations::operator##N( CALCUS_TYPE n )
#define OPERATOR_DEFINE_0( N ) \
    CALCUS_TYPE Calcus::operations::operator##N()

// operations
Calcus::operations::operations( Calcus *enj ) : enj( enj )
{
}

OPERATOR_DEFINE_1( Plus )
{
    return enj->previous + n;
}

OPERATOR_DEFINE_1( Min )
{
    return enj->previous - n;
}

OPERATOR_DEFINE_1( Mult )
{
    return enj->previous * n;
}

OPERATOR_DEFINE_1( Div )
{
    if ( n )
        return enj->previous / n;
    else
        return INFINITY;
}

OPERATOR_DEFINE_0( Equal )
{
    return enj->previous;
}

OPERATOR_DEFINE_1( Sqrt )
{
    return sqrtl( n );
}

OPERATOR_DEFINE_1( Pow )
{
    return powl( enj->previous, n );
}

OPERATOR_DEFINE_1( Tg )
{
    if ( !enj->Rad )
        return tanl( enj->previous * M_PI / 180.l );

    return tanl( n );
}

OPERATOR_DEFINE_1( Cos )
{
    if ( !enj->Rad )
        return cosl( enj->previous * M_PI / 180.l );
    return cosl( n );
}

OPERATOR_DEFINE_1( Sin )
{
    if ( !enj->Rad )
        return sinl( enj->previous * M_PI / 180.l );
    return sinl( n );
}

OPERATOR_DEFINE_1( Pers )
{
    return ( n ) / 100.l;
}

// Calcus

Calcus::Calcus() : ops( this )
{
}
