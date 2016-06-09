/********************************************************************************
** Form generated from reading UI file 'dialogsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSEARCH_H
#define UI_DIALOGSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialogsearch
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;
    QTableView *tableView;

    void setupUi(QDialog *Dialogsearch)
    {
        if (Dialogsearch->objectName().isEmpty())
            Dialogsearch->setObjectName(QStringLiteral("Dialogsearch"));
        Dialogsearch->resize(383, 298);
        layoutWidget = new QWidget(Dialogsearch);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 351, 251));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(Dialogsearch);

        QMetaObject::connectSlotsByName(Dialogsearch);
    } // setupUi

    void retranslateUi(QDialog *Dialogsearch)
    {
        Dialogsearch->setWindowTitle(QApplication::translate("Dialogsearch", "Dialog", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Dialogsearch", "number", 0)
         << QApplication::translate("Dialogsearch", "fio", 0)
         << QApplication::translate("Dialogsearch", "group", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class Dialogsearch: public Ui_Dialogsearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSEARCH_H
