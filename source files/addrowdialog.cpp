#include "addrowdialog.h"
#include "ui_addrowdialog.h"
#include "tablebighw.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>

AddRowDialog::AddRowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRowDialog)
{
    ui->setupUi(this);

    //check whether the input string is int
    ui->lineEdit_4->setValidator( new QIntValidator);
    ui->lineEdit_3->setValidator(new QIntValidator);
    ui->lineEdit_5->setValidator(new QIntValidator);

    //check whether the input string is double
    ui->lineEdit_6->setValidator( new QDoubleValidator);
    ui->lineEdit_7->setValidator(new QDoubleValidator);
    ui->lineEdit_8->setValidator(new QDoubleValidator);
    ui->lineEdit_9->setValidator(new QDoubleValidator);
    ui->lineEdit_10->setValidator(new QDoubleValidator);

    connect(ui->ok, SIGNAL(clicked()), this, SLOT(saveRow()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(reject()));
}

void AddRowDialog::saveRow()
{
    newrow.push_back(ui->lineEdit->text());
    newrow.push_back(ui->lineEdit_2->text());
    newrow.push_back(ui->lineEdit_3->text());
    newrow.push_back(ui->lineEdit_4->text());
    newrow.push_back(ui->lineEdit_5->text());
    newrow.push_back(ui->lineEdit_6->text());
    newrow.push_back(ui->lineEdit_7->text());
    newrow.push_back(ui->lineEdit_8->text());
    newrow.push_back(ui->lineEdit_9->text());
    newrow.push_back(ui->lineEdit_10->text());

    accept();
}

const QList<QVariant>& AddRowDialog::NewRow()
{
    return newrow;
}

AddRowDialog::~AddRowDialog()
{
    delete ui;
}
