#include "Calculator.hxx"

class InjCalculator : public Calculator
{
  public:
    explicit InjCalculator( Calculator *parent );
    ~InjCalculator();

  protected:
    Calculator *parent;
  protected slots:
    void on_buttonInj_clicked();
};
