#include "kalkulator.h"
#include "ui_kalkulator.h"
#include <QString>


static double calVal = 0.0;
static bool multTrigger = false;
static bool divTrigger = false;
static bool addTrigger =false;
static bool subTrigger = false;


kalkulator::kalkulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::kalkulator)
{
    ui->setupUi(this);


    ui->display->setText(QString::number(calVal));
    QPushButton *numButtons[10];
    for(int i= 0; i < 10; i++){
        QString butName = "button" + QString::number(i);
        numButtons[i] = kalkulator::findChild<QPushButton *>(butName);
        connect(numButtons[i],SIGNAL(released()),this,SLOT(NumPressed()));

    }

    connect(ui->add,SIGNAL(released()),this,SLOT(MathButtonPressed()));
    connect(ui->substract, SIGNAL(released()),this,SLOT(MathButtonPressed()));
    connect(ui->divide,SIGNAL(released()),this,SLOT(MathButtonPressed()));
    connect(ui->multiply,SIGNAL(released()),this,SLOT(MathButtonPressed()));
     connect(ui->equals,SIGNAL(released()),this,SLOT(EqualButton()));
     connect(ui->changeSign,SIGNAL(released()),this,SLOT(changeNumberSign()));

}

kalkulator::~kalkulator()
{
    delete ui;
}

void kalkulator::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butval = button->text();
    QString displayVal = ui->display->text();
    if((displayVal.toDouble() == 0) || (displayVal.toDouble()==0.0)){
        ui->display->setText(butval);
    } else {
        QString newVal = displayVal + butval;
        double dblNewVal = newVal.toDouble();
        ui->display->setText(QString::number(dblNewVal, 'g', 16));


    }




}
void kalkulator::MathButtonPressed(){
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = ui->display->text();
    calVal = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butval = button->text();
    if(QString::compare(butval, "/", Qt::CaseInsensitive)==0){
        divTrigger = true;
    } else if(QString::compare(butval,"*",Qt::CaseInsensitive)==0){
        multTrigger = true;
    } else if(QString::compare(butval,"+", Qt::CaseInsensitive)==0){
        addTrigger = true;
    } else if(QString::compare(butval,"-", Qt::CaseInsensitive)==0){
        subTrigger = true;
    }
    ui->display->setText("");
}

void kalkulator::EqualButton(){
    double solution = 0.0;
    QString displayVal = ui->display->text();
    double dblDisplayVal = displayVal.toDouble();
    if(addTrigger || subTrigger ||multTrigger || divTrigger){
        if(addTrigger){
            solution = calVal + dblDisplayVal;
        }else if(subTrigger){
            solution = calVal - dblDisplayVal;

        }else if(multTrigger){
            solution = calVal * dblDisplayVal;
        }else if(divTrigger){
            solution = calVal / dblDisplayVal;

        }


    }
    ui->display->setText(QString::number(solution));
}

void kalkulator::ChangeNumberSign(){

    QString displayVal = ui->display->text();
    QRegExp reg("[-]?[0-9.]*");
    if(reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1*dblDisplayVal;
        ui->display->setText(QString::number(dblDisplayValSign));
    }
}







