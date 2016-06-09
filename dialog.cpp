#include "dialog.h"
#include "mainwindow.h"
#include "ui_dialog.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;

}
void Dialog::onTable(QString str){
    tablename=str;
}

void Dialog::on_buttonBox_clicked(QAbstractButton *button)
{
     if (button == ui->buttonBox->button(QDialogButtonBox::Ok)){
         QSqlQuery q;
         q.prepare("INSERT INTO "+tablename+" ('number', 'fio', 'group') VALUES (?, ?, ?);");

         q.addBindValue(ui->lineEdit->text());
         q.addBindValue(ui->lineEdit_2->text());
         q.addBindValue(ui->lineEdit_3->text());
         if(!q.exec()){
                 QMessageBox::information(this,"Message","Error");
             }else
         {
             emit refresh();
             close();

         }
     }
     else{
         close();
     }
}
