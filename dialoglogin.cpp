#include "dialoglogin.h"
#include "ui_dialoglogin.h"

Dialoglogin::Dialoglogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoglogin)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}

Dialoglogin::~Dialoglogin()
{
    delete ui;
}

void Dialoglogin::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button==ui->buttonBox->button(QDialogButtonBox::Ok)){
       emit sendLogin(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
    }else close();
}
