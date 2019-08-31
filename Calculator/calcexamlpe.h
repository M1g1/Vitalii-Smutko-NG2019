#ifndef CALCEXAMLPE_H
#define CALCEXAMLPE_H

#include <QMainWindow>

namespace Ui {
class CalcExamlpe;
}

class CalcExamlpe : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalcExamlpe(QWidget *parent = nullptr);
    ~CalcExamlpe();



private slots:
    void press_num();
    void press_0();
    void nazhal_knopku_dot();
    void nazhal_knopku_clear();
    void nazhal_knopku_plus_or_minus();
    void Operations();
    void Equal();
    void Sqr_f();
    void Sqrt_f();

private:
    Ui::CalcExamlpe *ui;
};

#endif // CALCEXAMLPE_H
