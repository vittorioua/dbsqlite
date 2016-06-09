#include "dialogupdate.h"
#include "mainwindow.h"
#include "ui_dialogupdate.h"

DialogUpdate::DialogUpdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUpdate)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);
}

DialogUpdate::~DialogUpdate()
{
    delete ui;
}
void DialogUpdate::recieveData(QString str, QString str2, QString str3){
    ui->lineEdit->setText(str);
    ui->lineEdit_2->setText(str2);
    ui->lineEdit_3->setText(str3);
}
void DialogUpdate::onTable(QString str){
    tablename=str;
}
void DialogUpdate::on_buttonBox_clicked(QAbstractButton *button)
{
   if (button == ui->buttonBox->button(QDialogButtonBox::Ok)){
       QSqlQuery q;
       q.prepare("UPDATE "+tablename+" SET 'fio'=:fio, 'group'=:group WHERE number=:numb");
       q.bindValue(":numb",ui->lineEdit->text());
       q.bindValue(":fio",ui->lineEdit_2->text());
       q.bindValue(":group",ui->lineEdit_3->text());
       if(!q.exec()){
               QMessageBox::information(this,"Message","Error");
           }else
       {
           emit refresh();
           close();
       }
   }else{
       ui->lineEdit->clear();
       ui->lineEdit_2->clear();
       ui->lineEdit_3->clear();
       close();
   }
}
