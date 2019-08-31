#include "calcexamlpe.h"
#include "ui_calcexamlpe.h"
#include <QtMath>

CalcExamlpe::CalcExamlpe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalcExamlpe)
{
    ui->setupUi(this);
    connect (ui->knopka_1, &QPushButton::clicked, this, &CalcExamlpe::press_num);
    connect (ui->knopka_2, &QPushButton::clicked, this, &CalcExamlpe::press_num);
    connect (ui->knopka_3, &QPushButton::clicked, this, &CalcExamlpe::press_num);
    connect (ui->knopka_4, &QPushButton::clicked, this, &CalcExamlpe::press_num);
    connect (ui->knopka_5, &QPushButton::clicked, this, &CalcExamlpe::press_num);
    connect (ui->knopka_6, &QPushButton::clicked, this, &CalcExamlpe::press_num);
    connect (ui->knopka_7, &QPushButton::clicked, this, &CalcExamlpe::press_num);
    connect (ui->knopka_8, &QPushButton::clicked, this, &CalcExamlpe::press_num);
    connect (ui->knopka_9, &QPushButton::clicked, this, &CalcExamlpe::press_num);
    connect (ui->knopka_0, &QPushButton::clicked, this, &CalcExamlpe::press_0);
    connect (ui->knopka_dot, &QPushButton::clicked, this, &CalcExamlpe::nazhal_knopku_dot);
    connect (ui->knopka_clear, &QPushButton::clicked, this, &CalcExamlpe::nazhal_knopku_clear);
    connect (ui->b_plusOrMinus, &QPushButton::clicked, this, &CalcExamlpe::nazhal_knopku_plus_or_minus);
    connect (ui->operation_plus, &QPushButton::clicked, this, &CalcExamlpe::Operations);
    connect (ui->operation_minus, &QPushButton::clicked, this, &CalcExamlpe::Operations);
    connect (ui->operation_multi, &QPushButton::clicked, this, &CalcExamlpe::Operations);
    connect (ui->operation_div, &QPushButton::clicked, this, &CalcExamlpe::Operations);
    connect (ui->operation_equals, &QPushButton::clicked, this, &CalcExamlpe::Equal);
    connect(ui->operation_sqr, &QPushButton::clicked, this, &CalcExamlpe::Sqr_f);
    connect(ui->operation_sqrt, &QPushButton::clicked, this, &CalcExamlpe::Sqrt_f);
    ui->operation_plus->setCheckable(true);
    ui->operation_minus->setCheckable(true);
    ui->operation_multi->setCheckable(true);
    ui->operation_div->setCheckable(true);
}

CalcExamlpe::~CalcExamlpe()
{
    delete ui;
}

void CalcExamlpe::press_num()
{
    QPushButton *button = (QPushButton *) sender();
     if (ui->tablo->text().size()<15)
     {
        double numbers = (ui->tablo->text() + button->text()).toDouble();
        ui->tablo->setText(QString::number(numbers, 'g', 15));
     }
}

void CalcExamlpe::press_0()
{
    if (ui->tablo->text().size()<15)
        ui->tablo->setText(ui->tablo->text()+"0");
}

void CalcExamlpe::nazhal_knopku_dot()
{
    if (ui->tablo->text().size()<15)
        if (ui->tablo->text()=="")
            ui->tablo->setText("0.");
        else
            if(!(ui->tablo->text().contains('.')))
                 ui->tablo->setText(ui->tablo->text() + ".");
}

void CalcExamlpe::nazhal_knopku_clear()
{
    ui->operation_plus->setChecked(false);
    ui->operation_minus->setChecked(false);
    ui->operation_multi->setChecked(false);
    ui->operation_div->setChecked(false);
    ui->tablo->setText("0");
    ui->result->setText("Result: ");
}

void CalcExamlpe::nazhal_knopku_plus_or_minus()
{
     QPushButton *button = (QPushButton *) sender();
     double numbers = (ui->tablo->text()).toDouble();
     numbers = numbers * -1;
     ui->tablo->setText(QString::number(numbers, 'g', 15));
}

double first_num = 0 ;
short count = 0;

void CalcExamlpe::Operations()
{
     QPushButton *button = (QPushButton *) sender();
     if (ui->operation_plus->isChecked())
         count++;
     if (ui->operation_minus->isChecked())
         count++;
     if (ui->operation_multi->isChecked())
         count++;
     if (ui->operation_div->isChecked())
         count++;
     if (count == 1)
        first_num = ui->tablo->text().toDouble();
     ui->operation_plus->setChecked(false);
     ui->operation_minus->setChecked(false);
     ui->operation_multi->setChecked(false);
     ui->operation_div->setChecked(false);
     ui->tablo->clear();
     button->setChecked(true);
     count = 0;
}

void CalcExamlpe::Equal()
{
    double sec_num = 0;
    sec_num = ui->tablo->text().toDouble();
    if(ui->operation_plus->isChecked())
    {
        ui->result->setText("Result: " + QString::number(first_num, 'g',15) + " + " + QString::number(sec_num, 'g',15) + " = " + QString::number(first_num + sec_num, 'g',15));
        ui->operation_plus->setChecked(false);
    }
    else if (ui->operation_minus->isChecked())
    {
        ui->result->setText("Result: " + QString::number(first_num, 'g',15) + " - " + QString::number(sec_num, 'g',15) + " = " + QString::number(first_num - sec_num, 'g', 15));
        ui->operation_minus->setChecked(false);
    }
    else if (ui->operation_multi->isChecked())
    {
        ui->result->setText("Result: " + QString::number(first_num, 'g',15) + " * " + QString::number(sec_num, 'g',15) + " = " + QString::number(first_num * sec_num, 'g', 15));
        ui->operation_multi->setChecked(false);
    }
    else if (ui->operation_div->isChecked())
    {
        if (sec_num == 0.0)
            ui->result->setText("Result: " + QString::number(first_num, 'g',15) + " / " + QString::number(sec_num, 'g',15) + " = " + " Error ");
        else
            ui->result->setText("Result: " + QString::number(first_num, 'g',15) + " / " + QString::number(sec_num, 'g',15) + " = " + QString::number(first_num / sec_num, 'g', 15));
        ui->operation_div->setChecked(false);
    }
}

void CalcExamlpe::Sqr_f()
{
    double num = ui->tablo->text().toDouble();
    ui->result->setText("Result: sqr(" + QString::number( num, 'g', 15) + ") = " + QString::number( qPow(num, 2) , 'g', 15));
}

void CalcExamlpe::Sqrt_f()
{
    double num = ui->tablo->text().toDouble();
    if (num < 0)
        ui->result->setText("Result: sqrt(" + QString::number( num, 'g', 15) + ") = " + "Error");
    else
        ui->result->setText("Result: sqrt(" + QString::number( num, 'g', 15) + ") = " + QString::number( qSqrt(num) , 'g', 15));
}
