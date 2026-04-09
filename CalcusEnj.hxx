#define CALCUS_TYPE long double

#define OPERATOR_SIGNATURE_DEFINE_1( N ) \
    CALCUS_TYPE operator##N( CALCUS_TYPE n );

#define OPERATOR_SIGNATURE_DEFINE_0( N ) \
    CALCUS_TYPE operator##N();

struct Calcus
{
    Calcus();
    struct operations
    {
        typedef CALCUS_TYPE ( Calcus::operations::*operation_T )( CALCUS_TYPE );
        operations( class Calcus *enj );
        class Calcus *enj;
        OPERATOR_SIGNATURE_DEFINE_1( Plus );
        OPERATOR_SIGNATURE_DEFINE_1( Min );
        OPERATOR_SIGNATURE_DEFINE_1( Mult );
        OPERATOR_SIGNATURE_DEFINE_1( Div );
        OPERATOR_SIGNATURE_DEFINE_0( Equal );
        OPERATOR_SIGNATURE_DEFINE_1( Sqrt );
        OPERATOR_SIGNATURE_DEFINE_1( Pow );
        OPERATOR_SIGNATURE_DEFINE_1( Tg );
        OPERATOR_SIGNATURE_DEFINE_1( Cos );
        OPERATOR_SIGNATURE_DEFINE_1( Sin );
        OPERATOR_SIGNATURE_DEFINE_1( Pers );
    };
    operations::operation_T operation { nullptr };
    operations ops;
    CALCUS_TYPE previous { .0f };
    bool Rad { 1 };
};